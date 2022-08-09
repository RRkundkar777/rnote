// The main window class of our notepad

#ifndef RWINDOW_H
#define RWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class RWindow; }
QT_END_NAMESPACE

// Class declaration
class RWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::RWindow *ui;

    // for storing file paths
    int pathCount = -1;
    QString fileLocations[25];

    // file operations
    bool findFilePath(QString*);
    void writeFile(QString);
    void saveAs();

    // theme operations
    void setTheme(QString);
    void setEditorTheme(QString theme);

public:
    RWindow(QWidget *parent = nullptr);
    ~RWindow();
    QAction* getExitAction();

    // event handling mechanism
private slots:
    // basic notepad events
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();

    // additional notepad events
    void on_actionSupport_triggered();
    void on_actionAbout_triggered();
    void on_actionSend_Feedback_triggered();

    // tab_menu events
    void on_tab_menu_tabCloseRequested(int index);
    void on_tab_menu_tabBarClicked(int index);

    // editor design events
    void on_actionFont_triggered();
    void on_actionLight_triggered();
    void on_actionPeach_triggered();
    void on_actionMonokai_triggered();
    void on_actionLight_2_triggered();
    void on_actionPeach_2_triggered();
    void on_actionMonokai_2_triggered();
};

#endif // RWINDOW_H
