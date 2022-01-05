#ifndef TAB_H
#define TAB_H

#include <QWidget>

namespace Ui {
class Tab;
}

class Tab : public QWidget
{
    Q_OBJECT

public:
    explicit Tab(QWidget *parent = nullptr);
    ~Tab();

    // Function to get Text inside Plain Text Widget
    static QString getPlainTextData(Tab*);

    // Function to set Text inside Plain Text Widget
    static void setPlainTextData(Tab*, QString);

    // Function to set a dark theme to plain Text Widget
    void setDarkTheme();

    // Function to set a light theme to plain Text Widget
    void setLightTheme();

    // Function to set a Cobalt Theme
    void setMonokaiTheme();

    // Function to set Font
    void setPlainTextFont();

private:
    Ui::Tab *ui;
};

#endif // TAB_H
