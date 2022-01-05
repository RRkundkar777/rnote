#ifndef RWINDOW_H
#define RWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class RWindow; }
QT_END_NAMESPACE

// Class Definition
// Derived from QMainWindow Class

class RWindow : public QMainWindow
{
    Q_OBJECT

public:
    RWindow(QWidget *parent = nullptr);
    ~RWindow();

private slots:
    void on_actionNew_triggered();

    void on_tabWidget_Note_tabCloseRequested(int index);

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_tabWidget_Note_tabBarClicked(int index);

    void on_actionExit_triggered();

    void on_actionSave_As_triggered();

    void on_actionSupport_triggered();

    void on_actionDark_triggered();

    void on_actionFont_triggered();

    void on_actionLight_triggered();

    void on_actionMonokai_triggered();

private:
    Ui::RWindow *ui;

    // For tracking no. of tabs
    int TabCount = 0;
    // for storing file paths
    QString tabStack[20];
};

#endif // RWINDOW_H
