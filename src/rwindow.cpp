// Qt System Libraries
#include<QDebug>
#include<QMessageBox>
#include<QString>
#include<QFileDialog>
#include<QPlainTextEdit>
#include<QUrl>
#include<QDesktopServices>

// RWindow and Tab Class
#include "rwindow.h"
#include "ui_rwindow.h"
#include "config.h"
#include"tab.h"

// ------------------------------- Member Functions of RWindow Class -------------------------------------//

// Constructor of RWindow
RWindow::RWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RWindow)
{
    ui->setupUi(this);
    rdebug("RWindow Constructor Called",RN_DBG,__FILE__);

    // Removal of Extra Tabs Supplied by Qt
    ui->tabWidget_Note->removeTab(0);
    ui->tabWidget_Note->removeTab(0);
    rdebug("Removed Default Extra Tabs",RN_DBG,__FILE__);

    // Adding a Plain Text Editor Tab
    ui->tabWidget_Note->addTab(new Tab(),QString("Untitled %0").arg(ui->tabWidget_Note->count()+1));
    int index = ui->tabWidget_Note->currentIndex();
    ui->tabWidget_Note->setCurrentIndex(ui->tabWidget_Note->count()-1);

    // Setting the New Window Title
    QString newTabName = ui->tabWidget_Note->tabText(index);
    QString newWindowTitle = newTabName + " - RNote";
    this->setWindowTitle(newWindowTitle);

    // Incrementing the TabCount
    TabCount = 1;

//    qDebug() << "Current Index is: " << ui->tabWidget_Note->currentIndex();

    // Selecting the Default theme --> setting the current action
    QAction *act = ui->actionLight;
    ui->menuTheme->setActiveAction(act);
    ui->menuTheme->activeAction()->setChecked(true);


    // Debugging
    QString plainTextAdded = QString("Added a Plain Text Tab (TabCount to One) Window Title is "
                                     + newWindowTitle);
    rdebug(plainTextAdded,RN_DBG,__FILE__);

}

// Destructor of RWindow
RWindow::~RWindow()
{
    delete ui;
    rdebug("Exited Main Window",RN_DBG,__FILE__);
}


// On New --> Create a new tab
void RWindow::on_actionNew_triggered()
{
    // Index and Tab Title
//    int index = ui->tabWidget_Note->currentIndex();
//    QString tabtext = ui->tabWidget_Note->tabText(index);

    // Incrementing the TabCount and Setting the NewIndex
    TabCount++;
    int newIndex = TabCount - 1;

    rdebug("TabCount Incremented",RN_DBG,__FILE__);
    QString debugInfo = QString("NewIndex is ") + QString(newIndex);
    rdebug(debugInfo,RN_DBG,__FILE__);

    // Creating a New Tab and Setting the Current Index
    Tab *tab = new Tab();
    ui->tabWidget_Note->addTab(tab,QString("Untitled %0").arg(TabCount));
    ui->tabWidget_Note->setCurrentIndex(newIndex);

    // Debugging
    rdebug("New Tab Created by User",RN_DBG,__FILE__);
    debugInfo = QString("Current Tab Number is ") + QString(ui->tabWidget_Note->currentIndex());
    rdebug(debugInfo,RN_DBG,__FILE__);
}


// On Open --> Open a file
void RWindow::on_actionOpen_triggered()
{
    // Creating a New Tab and setting it as current tab
    ui->tabWidget_Note->addTab(new Tab(),"Open Tab");
    TabCount++;
    ui->tabWidget_Note->setCurrentIndex(TabCount - 1);
    int index = ui->tabWidget_Note->currentIndex();

    // Create a file object, and open it
    QString file_dir = QFileDialog::getOpenFileName(this,"Open ",QDir::homePath());
    QFile OpenFile(file_dir);
    bool fileOpened = OpenFile.open(QFile::ReadOnly | QFile::Text);

    // If file does not exists --> return the FileNotFound Error
    if(!fileOpened)
    {
        ui->tabWidget_Note->removeTab(index);
        TabCount--;
//        QMessageBox::warning(this,"Error 404","File Not Found");
        rdebug("No File Selected",RN_DBG,__FILE__);
        return;
    }

    // Else output the file contents to plain text and rename the tab with fileName
    else{

        // Pointer to Tab Class
        QWidget *widget = ui->tabWidget_Note->widget(index);
        Tab* tabPtr = (Tab*) widget;

        // Getting the File contents in form of a String
        QString text;
        text = OpenFile.readAll();

        // Disply contents of the file
        Tab::setPlainTextData(tabPtr,text);

        // Close the file
        OpenFile.close();

        // Cache the Path inside tabStack
        int pathCount = 0;
        while(1)
        {
            if(tabStack[pathCount] == "" )
            {
                tabStack[pathCount] = file_dir;
                break;
            }
            pathCount++;
        }

        // Setting file name as Tab name
        QString newTabName = file_dir.split("/").back();
        if(newTabName != ""){
            // Setting newTabName and newWindowTitle
            ui->tabWidget_Note->setTabText(index,newTabName);
            QString newWindowTitle = newTabName + " - RNote";
            this->setWindowTitle(newWindowTitle);

            // Debugging
            QString debugInfo = QString("WindowTitle is " + newWindowTitle);
            rdebug(debugInfo,RN_DBG,__FILE__);
        }

        // Debugging
        QString debugInfo = QString("Opened file named " + newTabName);
        rdebug(debugInfo,RN_DBG,__FILE__);
        return;
    }
}

// On Save --> Save the file
void RWindow::on_actionSave_triggered()
{
    // To check if file is already saved
    bool FilePathExists = false;
    QString filePath = "";

    // Check if file path exists
    FilePathExists = findFilePath(&filePath);

    // If file exists --> save it without prompt
    if(FilePathExists)
    {
        // Write Data to the file
        WriteFile(filePath);

        // Showing the Save Prompt
        QMessageBox::information(this,"Save","File Saved");
    }

    // Else Open a Save Prompt and Save the File
    else{
        // Saving the File using Save File Prompt
        SaveAs();
    }
}

// On Save As --> Open a save prompt and Save the file
void RWindow::on_actionSave_As_triggered()
{
    SaveAs();
}

// On Tab Exit --> Prompt to Save
void RWindow::on_tabWidget_Note_tabCloseRequested(int index)
{
    // The Close Tab Prompt
    QMessageBox tabClosePrompt;
    QString tabCloseTitle = "RNote";
    QString tabName = ui->tabWidget_Note->tabText(index);
    QString tabCloseText = "Do you want to Save Changes to "+tabName+"?\n Changes will be lost if not Saved";

    // Setting Up the Close Tab Prompt
    tabClosePrompt.setWindowTitle(tabCloseTitle);
    tabClosePrompt.setText(tabCloseText);
    tabClosePrompt.addButton("Save",QMessageBox::YesRole);
    tabClosePrompt.addButton("Dont Save",QMessageBox::NoRole);
    tabClosePrompt.addButton(QMessageBox::Cancel);

    // Storing the User Response (Without this, tabClosePrompt will not show up)
    int userResponse = tabClosePrompt.exec();

    // If user clicks Save --> Save the File
    if(userResponse == 0){
        // To check if file is already saved
        bool FilePathExists = false;
        QString filePath = "";
        FilePathExists = findFilePath(&filePath);
        if(FilePathExists)
        {
            WriteFile(filePath);
            QMessageBox::information(this,"Save","File Saved");
        }
        else{
            SaveAs();
        }
        // Remove the Tab
        ui->tabWidget_Note->removeTab(index);
        TabCount--;
        return;
    }

    // Else if User clicks dont save --> Close the Tab Without Saving
    else if(userResponse == 1)
    {
        // If tab to be closed is current Tab --> Change WindowTitle
        if(index == ui->tabWidget_Note->currentIndex())
        {
            // Removing the Tab
            ui->tabWidget_Note->removeTab(index);
            TabCount--;
            // Current Index and TabText
            int CurrentIndex = ui->tabWidget_Note->currentIndex();
            QString newWindowName = ui->tabWidget_Note->tabText(CurrentIndex);

            // If TabName is not null --> set NewWindowTitle
            if(newWindowName != "")
            {
            this->setWindowTitle(newWindowName + " - RNote");
            }
            else
            {
                this->setWindowTitle("RNote");
            }
        }
        else
        {
            ui->tabWidget_Note->removeTab(index);
        }
    }

    // Else if user clicks cancel --> do nothing
    else{
        return;
    }

    // Debugging
    rdebug("Action is ",RN_DBG,__FILE__);
}


// On Tab Clicked --> show the file name in Title Bar
void RWindow::on_tabWidget_Note_tabBarClicked(int index)
{
    // Setting the New Window Title
    QString newTabName = ui->tabWidget_Note->tabText(index);
    QString newWindowTitle = newTabName + " - RNote";
    this->setWindowTitle(newWindowTitle);
}

// On Support Clicked --> Open Site
void RWindow::on_actionSupport_triggered()
{
    QString link = "https://github.com/RRkundkar777/RNote/blob/master/docs/about.md";
    QDesktopServices::openUrl(QUrl(link));
}

void RWindow::on_actionAbout_triggered()
{
    QString link = "https://github.com/RRkundkar777/RNote/";
    QDesktopServices::openUrl(QUrl(link));
}

void RWindow::on_actionSend_Feedback_triggered()
{
    QString link = "mailto:r4002001005025k@gmail.com";
    QDesktopServices::openUrl(QUrl(link));
}

//--------------------------------------- Editor Apperance --------------------------------------------//

// Set theme Dark
void RWindow::on_actionDark_triggered()
{
    // Selecting current Tab
    int index = ui->tabWidget_Note->currentIndex();
    QWidget *widget = ui->tabWidget_Note->widget(index);
    Tab* tabPtr = (Tab*) widget;

    // Setting the dark theme to plain Text Widget and Window
    tabPtr->setEditorTheme(Tab::Dark);
    this->setTheme(Tab::DarkBg);
}

// Set theme Light
void RWindow::on_actionLight_triggered()
{
    // Selecting current Tab
    int index = ui->tabWidget_Note->currentIndex();
    QWidget *widget = ui->tabWidget_Note->widget(index);
    Tab* tabPtr = (Tab*) widget;

    // Setting the theme
    tabPtr->setEditorTheme(Tab::Light);
    this->setTheme(Tab::LightBg);
}

// Set theme Monokai
void RWindow::on_actionMonokai_triggered()
{
    // Selecting current Tab
    int index = ui->tabWidget_Note->currentIndex();
    QWidget *widget = ui->tabWidget_Note->widget(index);
    Tab* tabPtr = (Tab*) widget;

    // Setting the theme
    tabPtr->setEditorTheme(Tab::Monokai);
    this->setTheme(Tab::MonokaiBg);
}

void RWindow::on_actionFont_triggered()
{
    // Current Tab Index
    int index = ui->tabWidget_Note->currentIndex();

    // Pointer to Tab Class
    QWidget *widget = ui->tabWidget_Note->widget(index);

    // Typecasting default QWidget Pointer to Tab Pointer
    Tab* tabPtr = (Tab*) widget;

    // Setting the new Font
    tabPtr->setPlainTextFont();
}

// -------------------------------------- File I.O -----------------------------------------//
void RWindow::WriteFile(QString fileLocation)
{
        // Creating a file Object using the file location
        QFile SaveFile(fileLocation);

        // Using QTextStream to Save Text to file
        QTextStream outputTo(&SaveFile);

        // Opening the file
        SaveFile.open(QFile::WriteOnly | QFile::Text);

        // Pointer to Tab Class
        int index = ui->tabWidget_Note->currentIndex();
        QWidget *widget = ui->tabWidget_Note->widget(index);

        //Typecasting default QWidget Pointer to Tab Pointer
        Tab* tabPtr = (Tab*) widget;

        // Calling the User-Defined function getPlainTextData and storing it in string
        QString text = Tab::getPlainTextData(tabPtr);

        // Outputting the string to file object
        outputTo << text;

        // Flushing and Closing the file
        SaveFile.flush();
        SaveFile.close();
}

void RWindow::SaveAs()
{
    // Opening a file Save prompt
    // And saving file location as a string
    QString file_dir = QFileDialog::getSaveFileName(this,"Save As",QDir::homePath());
    int index = ui->tabWidget_Note->currentIndex();

    // Write file to a location
    WriteFile(file_dir);

    // Setting the Path inside tabStack
    int tabCount = 0;
    while(1)
    {
        if(tabStack[tabCount] == "" )
        {
            tabStack[tabCount] = file_dir;
            break;
        }
        tabCount++;
    }

    // Set the Tab name from filename
    QString newTabName = file_dir.split("/").back();
    if(newTabName != ""){
        // Setting TabText and Window Title
        ui->tabWidget_Note->setTabText(index,newTabName);

        QString newWindowTitle = newTabName + " - RNote";
        this->setWindowTitle(newWindowTitle);

        // Debugging
        QString debugInfo = QString("WindowTitle is " + newWindowTitle);
        rdebug(debugInfo,RN_DBG,__FILE__);
    }
}

// Checking for existing file location
bool RWindow::findFilePath(QString* Location)
{
    // Index of Current Tab and Current Tab Name
    int index = ui->tabWidget_Note->currentIndex();
    QString tabName = ui->tabWidget_Note->tabText(index);

    // To check if file is already saved
    bool FilePathExists = false;
    QString filePath = "";
    int i = 0;

    // Checking TabStack for file location
    while(tabStack[i] != "")
    {
        if(tabStack[i].split("/").back() == tabName)
        {
            FilePathExists = true;
            filePath = tabStack[i];
            break;
        }
        i++;
    }
    *Location = filePath;
    return FilePathExists;
}

// Getting private QAction
QAction *RWindow::getExitAction()
{
    return ui->actionExit;
}

// Function to set window theme
void RWindow::setTheme(QString theme)
{
    // Setting the theme on Window
    QPalette pallet = this->palette();
    QColor WindowColor = QColor(theme);
    pallet.setColor(QPalette::Window,WindowColor);
    this->setPalette(pallet);
}
