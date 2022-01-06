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

    // Setting editor theme
    void setEditorTheme(QString);

    // Setting fonts
    void setPlainTextFont();

    // Editor Themes
    static QString Monokai, MonokaiBg;
    static QString Light, LightBg;
    static QString Peach, PeachBg;

private:
    Ui::Tab *ui;
};

#endif // TAB_H
