#include<QDebug>
#include<QMessageBox>
#include<QString>
#include<QFileDialog>
#include<QPlainTextEdit>
#include<QUrl>
#include<QDesktopServices>

#include "rwindow.h"
#include "ui_rwindow.h"
#include"tab.h"

RWindow::RWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::RWindow)
{
    ui->setupUi(this);

    // removing extra tabs
    ui->tab_menu->removeTab(0);
    ui->tab_menu->removeTab(0);

    // adding a plaintexteditor tab
    ui->tab_menu->addTab(new Tab(),QString("Untitled %0").arg(ui->tab_menu->count()));

    // setting the window title
    int index = ui->tab_menu->currentIndex();
    QString tabName = ui->tab_menu->tabText(index);
    QString windowTitle = tabName + " - RNote";
    this->setWindowTitle(windowTitle);

    // selecting the default theme
    QAction *act = ui->actionLight;
    ui->menuTheme->setActiveAction(act);
    ui->menuTheme->activeAction()->setChecked(true);
}

// destructor
RWindow::~RWindow()
{
    delete ui;
}

// new tab
void RWindow::on_actionNew_triggered()
{
    int newIndex = ui->tab_menu->count();

    // creating a newtab
    Tab *tab = new Tab();
    ui->tab_menu->addTab(tab,QString("Untitled %0").arg(newIndex));
    ui->tab_menu->setCurrentIndex(newIndex);
}

// open a file
void RWindow::on_actionOpen_triggered()
{
    // create a new current tab
    ui->tab_menu->addTab(new Tab(),"temp");
    ui->tab_menu->setCurrentIndex(ui->tab_menu->count() - 1);
    int index = ui->tab_menu->currentIndex();

    // create a file object and open it
    QString file_dir = QFileDialog::getOpenFileName(this,"Open ",QDir::homePath());
    QFile OpenFile(file_dir);
    bool fileOpened = OpenFile.open(QFile::ReadOnly | QFile::Text);

    // file does not exists
    if(!fileOpened)
    {
        ui->tab_menu->removeTab(index);
        return;
    }

    // output file contents and rename file tab
    else{

        QWidget *widget = ui->tab_menu->widget(index);
        Tab* tabPtr = (Tab*) widget;

        // getting file contents in string
        QString text;
        text = OpenFile.readAll();

        // displaying file contents
        Tab::setPlainTextData(tabPtr,text);
        OpenFile.close();

        // cache the filepath inside fileLocations
        pathCount++;

        if(pathCount < 25)
        {
            fileLocations[pathCount] = file_dir;
        }

        // setting file name as Tab name
        QString tabName = file_dir.split("/").back();
        if(tabName != "")
        {
            // Setting tabName and windowTitle
            ui->tab_menu->setTabText(index,tabName);
            QString windowTitle = tabName + " - RNote";
            this->setWindowTitle(windowTitle);
        }
        return;
    }
}

// save file
void RWindow::on_actionSave_triggered()
{
    // check if file is already present
    bool filePathExists = false;
    QString filePath = "";
    filePathExists = findFilePath(&filePath);

    // run plain save
    if(filePathExists)
    {
        // write data to the file
        writeFile(filePath);

        // Showing the Save Prompt
        QMessageBox::information(this,"Save","File Saved Successfully");
    }
    // run save as
    else{
        saveAs();
    }
}

// save file as
void RWindow::on_actionSave_As_triggered()
{
    saveAs();
}

// close tab
void RWindow::on_tab_menu_tabCloseRequested(int index)
{
    // exit prompt
    QMessageBox tabClosePrompt;
    QString tabCloseTitle = "RNote";
    QString tabName = ui->tab_menu->tabText(index);
    QString tabCloseText = "Do you want to Save Changes to "+tabName+"?\n Changes will be lost if not Saved";
    tabClosePrompt.setWindowTitle(tabCloseTitle);
    tabClosePrompt.setText(tabCloseText);
    tabClosePrompt.addButton("Save",QMessageBox::YesRole);
    tabClosePrompt.addButton("Dont Save",QMessageBox::NoRole);
    tabClosePrompt.addButton(QMessageBox::Cancel);

    // user response
    int userResponse = tabClosePrompt.exec();

    // save response
    if(userResponse == 0){
        // check if file exists
        bool filePathExists = false;
        QString filePath = "";
        filePathExists = findFilePath(&filePath);
        if(filePathExists)
        {
            writeFile(filePath);
            QMessageBox::information(this,"Save","File Saved");
        }
        else{
            saveAs();
        }
        // remove the tab
        ui->tab_menu->removeTab(index);
        return;
    }

    // dont save response
    else if(userResponse == 1)
    {
        // closing current tab
        if(index == ui->tab_menu->currentIndex())
        {
            // removing current tab
            ui->tab_menu->removeTab(index);

            // then current tab
            int currentIndex = ui->tab_menu->currentIndex();
            QString windowName = ui->tab_menu->tabText(currentIndex);

            // setting tab name
            if(windowName != "")
            {
                this->setWindowTitle(windowName + " - RNote");
            }
            else
            {
                this->setWindowTitle("RNote");
            }
        }
        // closing non current tab
        else
        {
            ui->tab_menu->removeTab(index);
        }
    }
    // cancel response
    else{
        return;
    }
}

// when tab is clicked
void RWindow::on_tab_menu_tabBarClicked(int index)
{
    // setting window title
    QString tabName = ui->tab_menu->tabText(index);
    QString windowTitle = tabName + " - RNote";
    this->setWindowTitle(windowTitle);
}

// support action
void RWindow::on_actionSupport_triggered()
{
    QString link = "https://github.com/RRkundkar777/RNote/blob/master/docs/about.md";
    QDesktopServices::openUrl(QUrl(link));
}

// about action
void RWindow::on_actionAbout_triggered()
{
    QString link = "https://github.com/RRkundkar777/RNote/";
    QDesktopServices::openUrl(QUrl(link));
}

// feedback action
void RWindow::on_actionSend_Feedback_triggered()
{
    QString link = "mailto:r4002001005025k@gmail.com";
    QDesktopServices::openUrl(QUrl(link));
}

//--------------------------------------- Editor Apperance --------------------------------------------//

// set theme peach
void RWindow::on_actionPeach_triggered()
{
    setEditorTheme(Tab::Peach);
}

// set theme light
void RWindow::on_actionLight_triggered()
{
    setEditorTheme(Tab::Light);
}

// set theme monokai
void RWindow::on_actionMonokai_triggered()
{
    setEditorTheme(Tab::Monokai);
}

void RWindow::on_actionLight_2_triggered()
{
    this->setTheme(Tab::LightBg);
}

void RWindow::on_actionMonokai_2_triggered()
{
    this->setTheme(Tab::MonokaiBg);
}

void RWindow::on_actionPeach_2_triggered()
{
    this->setTheme(Tab::PeachBg);
}

// change current font
void RWindow::on_actionFont_triggered()
{
    int index = ui->tab_menu->currentIndex();
    QWidget *widget = ui->tab_menu->widget(index);
    Tab* tabPtr = (Tab*) widget;
    tabPtr->setPlainTextFont();
}

// -------------------------------------- File I.O -----------------------------------------//

// write to file
void RWindow::writeFile(QString fileLocation)
{
        // file object using the file location
        QFile SaveFile(fileLocation);

        // file output object linked to savefile
        QTextStream outputTo(&SaveFile);

        // opening file
        SaveFile.open(QFile::WriteOnly | QFile::Text);

        // pointer to tab class
        int index = ui->tab_menu->currentIndex();
        QWidget *widget = ui->tab_menu->widget(index);
        Tab* tabPtr = (Tab*) widget;

        // getting plain text data
        QString text = Tab::getPlainTextData(tabPtr);

        // output the string to file object
        outputTo << text;

        // Flushing and Closing the file
        SaveFile.flush();
        SaveFile.close();
}

// save as
void RWindow::saveAs()
{
    // file location and tab index
    QString file_dir = QFileDialog::getSaveFileName(this,"Save As",QDir::homePath());
    int index = ui->tab_menu->currentIndex();

    // write file to a location
    writeFile(file_dir);

    // caching the path into fileLocations
    int tabCount = 0;
    while(1)
    {
        if(fileLocations[tabCount] == "" )
        {
            fileLocations[tabCount] = file_dir;
            break;
        }
        tabCount++;
    }

    // setting tab name to filename
    QString tabName = file_dir.split("/").back();
    if(tabName != ""){
        ui->tab_menu->setTabText(index,tabName);
        QString windowTitle = tabName + " - RNote";
        this->setWindowTitle(windowTitle);
    }
}

// check for an existing file location
bool RWindow::findFilePath(QString* Location)
{
    // current tabname and index
    int index = ui->tab_menu->currentIndex();
    QString tabName = ui->tab_menu->tabText(index);

    bool filePathExists = false;
    QString filePath = "";
    int i = 0;

    // checking the fileLocations for data
    while(fileLocations[i] != "")
    {
        if(fileLocations[i].split("/").back() == tabName)
        {
            filePathExists = true;
            filePath = fileLocations[i];
            break;
        }
        i++;
    }
    *Location = filePath;
    return filePathExists;
}

// get private QAction
QAction *RWindow::getExitAction()
{
    return ui->actionExit;
}

// set ide theme
void RWindow::setTheme(QString theme)
{
    // setting the theme on window
    QPalette pallet = this->palette();
    QColor WindowColor = QColor(theme);
    pallet.setColor(QPalette::Window,WindowColor);
    this->setPalette(pallet);
}

// set tab theme
void RWindow::setEditorTheme(QString theme)
{
    // current tab
    int index = ui->tab_menu->currentIndex();
    if(index == -1)
        return;

    QWidget *widget = ui->tab_menu->widget(index);
    Tab* tabPtr = (Tab*) widget;

    // setting the peach theme
    tabPtr->setEditorTheme(theme);
}
