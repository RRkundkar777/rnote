// The main window class of our notepad

#ifndef RWINDOW_H
#define RWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class RWindow; }
QT_END_NAMESPACE

// Class Declaration
class RWindow : public QMainWindow
{
    Q_OBJECT

public:
    RWindow(QWidget *parent = nullptr);
    QAction* getExitAction();
    ~RWindow();

    // Event Handling Mechanism
private slots:
    // Basic notepad events
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();

    // Additional Notepad Events
    void on_actionSupport_triggered();
    void on_actionAbout_triggered();
    void on_actionSend_Feedback_triggered();

    // Tab Events
    void on_tabWidget_Note_tabCloseRequested(int index);
    void on_tabWidget_Note_tabBarClicked(int index);

    // Basic editor design events
    void on_actionFont_triggered();
    void on_actionLight_triggered();
    void on_actionPeach_triggered();
    void on_actionMonokai_triggered();

private:
    Ui::RWindow *ui;

    // For tracking no. of tabs
    int TabCount = 0;
    // for storing file paths
    QString tabStack[20];
    // File Operations
    bool findFilePath(QString*);
    void WriteFile(QString);
    void SaveAs();
    // Theme Operations
    void setTheme(QString);
};

#endif // RWINDOW_H
