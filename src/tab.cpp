// Qt System Libraries
#include<QColorDialog>
#include<QFontDialog>

// Tab Class
#include "tab.h"
#include "ui_tab.h"
#include "keydown.h"

// Declaring rdebug() and RN_DBG
void rdebug(QString,bool,QString);
#define RN_DBG true

// ------------------------------- Member Functions of RWindow Class -------------------------------------//
// Constructor of Tab
Tab::Tab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab)
{
    ui->setupUi(this);
    rdebug("Plain text constructor called",RN_DBG,__FILE__);

    // Adding a default Font Type to PlainTextEdit
    QFont defaultFont("Helvetica [Cronyx]", 12);
    ui->plainTextEdit->setFont(defaultFont);
}

// Destructor of Tab Widget Class
Tab::~Tab()
{
    delete ui;
    rdebug("Plain text destructor called",RN_DBG,__FILE__);
}

// Get Plain Text Data
QString Tab::getPlainTextData(Tab *tab){
    QString text = tab->ui->plainTextEdit->toPlainText();
    return text;
}

// Set Plain Text Data
void Tab::setPlainTextData(Tab *tab,QString plainText){
    tab->ui->plainTextEdit->setPlainText(plainText);
    return;
}

// Function to set dark theme on Plain Text Edit
void Tab::setDarkTheme()
{
    ui->plainTextEdit->setStyleSheet("background-color: black;color: white;");
}

// Function to set light theme on Plain Text Edit
void Tab::setLightTheme(){
    ui->plainTextEdit->setStyleSheet("background-color: #ffffff;color: black;");
}

// Function to set monokai theme on Plain Text Edit
void Tab::setMonokaiTheme(){
    ui->plainTextEdit->setStyleSheet("background-color: #555555;color: #ffff00;border-color:#555555");
}

// Function to set a new Font to PlainTextEdit
void Tab::setPlainTextFont()
{
    // Open a font Dialog and Store the Users response in Ok
    bool ok;
    QFont font = QFontDialog::getFont(
                    &ok, QFont("Helvetica [Cronyx]", 10), this);

    // If user clicks OK --> Set the Font
    if(ok)
    {
        this->ui->plainTextEdit->setFont(font);
        QString debugInfo = "User Set Font: " + font.family();
        rdebug(debugInfo,RN_DBG,__FILE__);
    }
    // Else --> Do Nothing
    else
    {
        rdebug("Nothing was Done",RN_DBG,__FILE__);
    }
}
