// The tab class of our notepad

#ifndef TAB_H
#define TAB_H

#include <QWidget>

namespace Ui {
    class Tab;
}

// class declaration
class Tab : public QWidget
{
    Q_OBJECT

public:
    explicit Tab(QWidget *parent = nullptr);
    ~Tab();

    // plain text
    static QString getPlainTextData(Tab*);
    static void setPlainTextData(Tab*, QString);

    // setting editor theme and font
    void setEditorTheme(QString);
    void setPlainTextFont();

    // editor themes
    static QString Monokai, MonokaiBg;
    static QString Light, LightBg;
    static QString Peach, PeachBg;

private:
    Ui::Tab *ui;
};

#endif // TAB_H
