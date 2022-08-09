#include<QColorDialog>
#include<QFontDialog>
#include "tab.h"
#include "ui_tab.h"
#include "keydown.h"

// editor themes
QString Tab::MonokaiBg = "#555555";
QString Tab::LightBg = "#ffffff";
QString Tab::PeachBg = "#ffdaB9";
QString Tab::Monokai = "background-color: #555555;color: #ffff00;border-color:#555555";
QString Tab::Light = "background-color: #ffffff;color: black;";
QString Tab::Peach=  "background-color: #ffdaB9;color: black;";

// constructor of tab
Tab::Tab(QWidget *parent) : QWidget(parent), ui(new Ui::Tab)
{
    ui->setupUi(this);

    // adding a default font type to plaintextedit
    QFont defaultFont("Helvetica [Cronyx]", 12);
    ui->plainTextEdit->setFont(defaultFont);
}

// destructor of tab
Tab::~Tab()
{
    delete ui;
}

// get plaintext data
QString Tab::getPlainTextData(Tab *tab){
    QString text = tab->ui->plainTextEdit->toPlainText();
    return text;
}

// set plaintext data
void Tab::setPlainTextData(Tab *tab,QString plainText){
    tab->ui->plainTextEdit->setPlainText(plainText);
    return;
}

// set editor theme
void Tab::setEditorTheme(QString Theme)
{
    ui->plainTextEdit->setStyleSheet(Theme);
}

// set plaintext font
void Tab::setPlainTextFont()
{
    bool Ok;
    QFont font = QFontDialog::getFont(&Ok, QFont("Helvetica [Cronyx]", 10), this);

    if(Ok)
    {
        this->ui->plainTextEdit->setFont(font);
    }
}
