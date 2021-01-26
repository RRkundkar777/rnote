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
void Tab::setDarkTheme(){
    // Getting the Colors
    QColor backgroundColor = Qt::black;
    QColor textColor = Qt::white;

    // Creating a pallette
    QPalette palette;
    palette.setColor(QPalette::Base,backgroundColor);
    palette.setColor(QPalette::Text,textColor);

    // Setting the colors
    if(backgroundColor.isValid() && textColor.isValid())
        this->ui->plainTextEdit->setPalette(palette);
}

// Function to set light theme on Plain Text Edit
void Tab::setLightTheme(){
    // Getting the Colors
    QColor backgroundColor = Qt::white;
    QColor textColor = Qt::black;

    // Creating a color palette
    QPalette palette;
    palette.setColor(QPalette::Base,backgroundColor);
    palette.setColor(QPalette::Text,textColor);

    // Setting the colors
    if(backgroundColor.isValid() && textColor.isValid())
        this->ui->plainTextEdit->setPalette(palette);
}

// Function to set light theme on Plain Text Edit
void Tab::setCobaltTheme(){
    // Getting the Colors
    QColor backgroundColor = QColor::fromHsv(215, 100, 67);
    QColor textColor = QColor::fromRgb(255,255,0);

    // Creating a color palette
    QPalette palette;
    palette.setColor(QPalette::Base,backgroundColor);
    palette.setColor(QPalette::Text,textColor);

    // Setting the colors
    if(backgroundColor.isValid() && textColor.isValid())
        this->ui->plainTextEdit->setPalette(palette);
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









