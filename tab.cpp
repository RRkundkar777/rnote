#include "tab.h"
#include "ui_tab.h"

// For changing theme
#include<QColorDialog>

// For Debugging
#include<QDebug>

// Member Functions

// Constructor of Tab Widget Class
Tab::Tab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab)
{
    ui->setupUi(this);
    qDebug() << "Plain Text Constructor Called";

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
void Tab::setDarkTheme(Tab *tab){
    // Getting the Colors
    QColor backgroundColor = Qt::black;
    QColor textColor = Qt::white;

    // Creating a pallette
    QPalette palette;
    palette.setColor(QPalette::Base,backgroundColor);
    palette.setColor(QPalette::Text,textColor);

    // Setting the colors
    if(backgroundColor.isValid() && textColor.isValid())
        tab->ui->plainTextEdit->setPalette(palette);
}
