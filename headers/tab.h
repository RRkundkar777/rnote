// The Tab class of our notepad

#ifndef TAB_H
#define TAB_H

#include <QWidget>

namespace Ui {
class Tab;
}

// Class Declaration
class Tab : public QWidget
{
    Q_OBJECT

public:
    explicit Tab(QWidget *parent = nullptr);
    ~Tab();

    // Getting and Setting Plain text data
    static QString getPlainTextData(Tab*);
    static void setPlainTextData(Tab*, QString);

    // Setting editor themes
    void setDarkTheme();
    void setLightTheme();
    void setMonokaiTheme();

    // Setting fonts
    void setPlainTextFont();

private:
    Ui::Tab *ui;
};

#endif // TAB_H
