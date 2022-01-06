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

// Editor Themes
QString Tab::MonokaiBg = "#555555";
QString Tab::LightBg = "#ffffff";
QString Tab::PeachBg = "#ffdaB9";
QString Tab::Monokai = "background-color: #555555;color: #ffff00;border-color:#555555";
QString Tab::Light = "background-color: #ffffff;color: black;";
QString Tab::Peach=  "background-color: #ffdaB9;color: black;";

// ------------------------------- Member Functions of Tab Class -------------------------------------//
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

// Function to set editor theme
void Tab::setEditorTheme(QString Theme)
{
    ui->plainTextEdit->setStyleSheet(Theme);
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
