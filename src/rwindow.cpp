// RWindow Class
#include "rwindow.h"

// UI of RWindow
#include "ui_rwindow.h"

// For Debugging
#include<QDebug>

// For using editor functionality
#include"tab.h"

// For Using Save Prompt Functionality
#include<QMessageBox>

// For Processing Strings
#include<QString>

// For Opening File Dialog Box
#include<QFileDialog>

// For Getting Plain Text Data
#include<QPlainTextEdit>

// For Opening Websites
#include<QUrl>
#include<QDesktopServices>

// Aliasing for maintaining the semantics
#define SavePlainTextFile() on_actionSave_triggered()
#define OpenNewTab() on_actionNew_triggered()
#define SaveAs() on_actionSave_As_triggered()

// Member Functions of RWindow Class

// Constructor of RWindow
RWindow::RWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RWindow)
{
    ui->setupUi(this);
    qDebug() << "RWindow Constructor Called";

    // Removal of Extra Tabs Supplied by Qt
    ui->tabWidget_Note->removeTab(0);
    ui->tabWidget_Note->removeTab(0);
    qDebug() << "Removed Default Extra Tabs";

    // Adding a Plain Text Editor Tab
    ui->tabWidget_Note->addTab(new Tab(),QString("New Page %0").arg(ui->tabWidget_Note->count()+1));
    int index = ui->tabWidget_Note->currentIndex();
    ui->tabWidget_Note->setCurrentIndex(ui->tabWidget_Note->count()-1);

    // Setting the New Window Title
    QString newTabName = ui->tabWidget_Note->tabText(index);
    QString newWindowTitle = newTabName + " - RNote";
    this->setWindowTitle(newWindowTitle);

    // Incrementing the TabCount
    TabCount = 1;

    // Selecting the Default theme --> setting the current action
    QAction *act = ui->actionLight;
    ui->menuTheme->setActiveAction(act);
    ui->menuTheme->activeAction()->setChecked(true);

    // Debugging
    qDebug() << "Added a Plain Text Tab (TabCount to One)"<<"Window Title is "<<newWindowTitle;

}

// Destructor of RWindow
RWindow::~RWindow()
{
    delete ui;
    qDebug() << "Exited Main Window";
}


// On New Clicked Open a New Tab
void RWindow::on_actionNew_triggered()
{
    // Index and Tab Title
    int index = ui->tabWidget_Note->currentIndex();
    QString tabtext = ui->tabWidget_Note->tabText(index);

    // Incrementing the TabCount and Setting the NewIndex
    TabCount++;
    int newIndex = TabCount;
    qDebug()<<"TabCount Incremented";
    qDebug() << "NewIndex is "<<newIndex;

    // Creating a New Tab and Setting the Current Index
    Tab *tab = new Tab();
    ui->tabWidget_Note->addTab(tab,QString("New Page %0").arg(newIndex));
    ui->tabWidget_Note->setCurrentIndex(newIndex);

    // Debugging
    qDebug() << "New Tab Created by User";
    qDebug()<< "Current Tab Number is "<<ui->tabWidget_Note->currentIndex();
}


// On Open Clicked --> Open a file
void RWindow::on_actionOpen_triggered()
{
    // Opening a New Tab
    ui->tabWidget_Note->addTab(new Tab(),"Open Tab");

    // Incrementing the Tab Count and Setting current index
    TabCount++;
    ui->tabWidget_Note->setCurrentIndex(TabCount-1);

    // Index of Current Tab
    int index = ui->tabWidget_Note->currentIndex();

    // Opening a file Open prompt
    // And saving file location as a string in file_dir
    QString file_dir = QFileDialog::getOpenFileName(this,"Open ",QDir::homePath());

    // Creating a file Object using the file location
    QFile OpenFile(file_dir);

    // Opening the file
    bool fileOpened = OpenFile.open(QFile::ReadOnly | QFile::Text);

    // If file does not exists --> return the FileNotFound Error
    if(!fileOpened)
    {
        ui->tabWidget_Note->removeTab(index);
        QMessageBox::warning(this,"Error 404","File Not Found");
        qDebug() << "No File Selected";
        return;
    }

    // Else output the file contents to plain text and rename the tab with fileName
    else{

        // Pointer to Tab Class
        QWidget *widget = ui->tabWidget_Note->widget(index);

        //Typecasting default QWidget Pointer to Tab Pointer
        Tab* tabPtr = (Tab*) widget;

        // Getting the File contents in form of a String
        QString text;
        text = OpenFile.readAll();

        // Calling the User-Defined function setPlainTextData to output the file content to plainText
        Tab::setPlainTextData(tabPtr,text);

        // Closing the file
        OpenFile.close();

        // Setting the Path inside tabStack
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

        // Setting the TabName with the name of file
        QString newTabName = file_dir.split("/").back();

        // If User Cancels Operation from the Open Prompt then filename will be NULL
        if(newTabName != ""){
            // Setting newTabName and newWindowTitle
            ui->tabWidget_Note->setTabText(index,newTabName);
            QString newWindowTitle = newTabName + " - RNote";
            this->setWindowTitle(newWindowTitle);

            //Debugging
            qDebug()<<"WindowTitle is "<<newWindowTitle;
        }

        // Debugging
        qDebug()<<"Opened file named "<<newTabName;
        return;
    }
}


// On Save Clicked --> Save the file
void RWindow::on_actionSave_triggered()
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

    // If file Exists then directly save it without prompt
    if(FilePathExists)
    {
        // Opening a SavaFile
        QFile SaveFile(filePath);

        // Output object
        QTextStream outputTo(&SaveFile);

        // Opening the file
        SaveFile.open(QFile::WriteOnly | QFile::Text);

        // Pointer to Tab Class
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

        // Showing the Save Prompt
        QMessageBox::information(this,"Save","File Saved");
    }

    // Else Open a Save Prompt and Save the File
    else{
        // Saving the File using Save File Prompt
        SaveAs();
    }
}


// On Save As clicked --> Open a save prompt and Save the file
void RWindow::on_actionSave_As_triggered()
{
    // Opening a file Save prompt
    // And saving file location as a string
    QString file_dir = QFileDialog::getSaveFileName(this,"Save As",QDir::homePath());

    // Creating a file Object using the file location
    QFile SaveFile(file_dir);

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

    // Setting the TabName with the name of file
    QString newTabName = file_dir.split("/").back();

    // If User Cancels Operation from the Save Prompt then filename will be NULL
    if(newTabName != ""){
        // Setting TabText and Window Title
        ui->tabWidget_Note->setTabText(index,newTabName);

        QString newWindowTitle = newTabName + " - RNote";
        this->setWindowTitle(newWindowTitle);

        // Debugging
        qDebug()<<"WindowTitle is "<<newWindowTitle;
    }
}

// On Tab Exit Clicked --> Prompt a Save Prompt
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
        SavePlainTextFile();
        ui->tabWidget_Note->removeTab(index);
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
    qDebug() << "Action is ";
}


// If any tab is clicked --> show the file name in Title Bar
void RWindow::on_tabWidget_Note_tabBarClicked(int index)
{
    // Setting the New Window Title
    QString newTabName = ui->tabWidget_Note->tabText(index);
    QString newWindowTitle = newTabName + " - RNote";
    this->setWindowTitle(newWindowTitle);
}


// On Exit clicked --> Turn off notepad
void RWindow::on_actionExit_triggered()
{
       // The MessageBox Texts
       QString warning_title = "Exit RNote";
       QString warning_text = "Multiple Tabs are Opened\n If you close all tabs, you might lose data\n";

       // The MessageBox Object
       QMessageBox exitPrompt;

       // Setting the MessageBox title and content
       exitPrompt.setWindowTitle(warning_title);
       exitPrompt.setText(warning_text);

       // Adding the Buttons with text and events
       exitPrompt.addButton("Save Tabs",QMessageBox::YesRole);
       exitPrompt.addButton("Close All",QMessageBox::NoRole);
       exitPrompt.addButton(QMessageBox::Cancel);


       // Executing the Message Box and Storing the reply in 'reply variable'
       int reply;
       reply = exitPrompt.exec();

       qDebug()<<"OnExitCode: "<<reply;
}


// On Support Clicked --> Open Site
void RWindow::on_actionSupport_triggered()
{
    QString link = "https://github.com/RRkundkar777/RNote";
    QDesktopServices::openUrl(QUrl(link));
}

// On dark option chosen --> Set the editor theme to dark
void RWindow::on_actionDark_triggered()
{
    // Current Index
    int index = ui->tabWidget_Note->currentIndex();

    // Pointer to Tab Class
    QWidget *widget = ui->tabWidget_Note->widget(index);

    //Typecasting default QWidget Pointer to Tab Pointer
    Tab* tabPtr = (Tab*) widget;

    // Setting the dark theme to plain Text Widget
    tabPtr->setDarkTheme();

    // Setting the theme on Window
    QPalette pallet = this->palette();
    QColor WindowColor = QColor::fromRgb(0,0,0);
    QColor TextColor = QColor::fromRgb(255,255,255);
    pallet.setColor(QPalette::Window,WindowColor);
    pallet.setColor(QPalette::Text,TextColor);
    this->setPalette(pallet);
}

// On light option chosen --> Set the editor theme to light
void RWindow::on_actionLight_triggered()
{
    // Current Index
    int index = ui->tabWidget_Note->currentIndex();

    // Pointer to Tab Class
    QWidget *widget = ui->tabWidget_Note->widget(index);

    //Typecasting default QWidget Pointer to Tab Pointer
    Tab* tabPtr = (Tab*) widget;

    // Setting the theme
    tabPtr->setLightTheme();

    // Setting the theme on Window
    QPalette pallet = this->palette();
    QColor WindowColor = QColor::fromRgb(255,255,255);
    QColor TextColor = QColor::fromRgb(0,0,0);
    pallet.setColor(QPalette::Window,WindowColor);
    pallet.setColor(QPalette::Text,TextColor);
    this->setPalette(pallet);
}

// On cobalt option chosen --> Set the editor theme to cobalt
void RWindow::on_actionMonokai_triggered()
{
    // Current Index
    int index = ui->tabWidget_Note->currentIndex();

    // Pointer to Tab Class
    QWidget *widget = ui->tabWidget_Note->widget(index);

    //Typecasting default QWidget Pointer to Tab Pointer
    Tab* tabPtr = (Tab*) widget;

    // Setting the theme
    tabPtr->setMonokaiTheme();

    // Setting the theme on Window
    QPalette pallet = this->palette();
    QColor WindowColor = QColor::fromRgb(85,85,85);
    QColor TextColor = QColor::fromRgb(255,255,0);
    pallet.setColor(QPalette::Window,WindowColor);
    pallet.setColor(QPalette::Text,TextColor);
    this->setPalette(pallet);
}

void RWindow::on_actionFont_triggered()
{
    // Current Index
    int index = ui->tabWidget_Note->currentIndex();

    // Pointer to Tab Class
    QWidget *widget = ui->tabWidget_Note->widget(index);

    //Typecasting default QWidget Pointer to Tab Pointer
    Tab* tabPtr = (Tab*) widget;

    // Setting the new Font
    tabPtr->setPlainTextFont();
}
