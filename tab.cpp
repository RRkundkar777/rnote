#include "tab.h"
#include "ui_tab.h"

// For changing theme
#include<QColorDialog>

// For Debugging
#include<QDebug>

// For Opening Font Dialog Box
#include<QFontDialog>

// Member Functions

// Constructor of Tab Widget Class
Tab::Tab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab)
{
    ui->setupUi(this);
    qDebug() << "Plain Text Constructor Called";

    // Adding a default Font Type to PlainTextEdit
    QFont defaultFont("Helvetica [Cronyx]", 12);
    ui->plainTextEdit->setFont(defaultFont);
}

// Destructor of Tab Widget Class
Tab::~Tab()
{
    delete ui;
    qDebug() << "Plain Text Destructor Called";
}

// Function to get Text from PlainText Widget and Storing it in QString "text"
// returns the plaintextdata as string
QString Tab::getPlainTextData(Tab *tab){
    QString text = tab->ui->plainTextEdit->toPlainText();
    return text;
}

// Function to set a plain text inside a plainTextEdit widget
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
        qDebug()<< "User Set Font" << font.family();
    }
    // Else --> Do Nothing
    else
    {
        qDebug() << "Nothing was Done";
    }
}







