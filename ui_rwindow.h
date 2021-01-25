/********************************************************************************
** Form generated from reading UI file 'rwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RWINDOW_H
#define UI_RWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RWindow
{
public:
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionNew_Window;
    QAction *actionSave_As;
    QAction *actionAbout;
    QAction *actionSupport;
    QAction *actionSend_Feedback;
    QAction *actionFont;
    QAction *actionTestCode;
    QAction *actionLight;
    QAction *actionDark;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget_Note;
    QWidget *RBaseTab;
    QWidget *RBaseTab2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QMenu *menuTheme;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RWindow)
    {
        if (RWindow->objectName().isEmpty())
            RWindow->setObjectName(QString::fromUtf8("RWindow"));
        RWindow->resize(1380, 700);
        actionNew = new QAction(RWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionSave = new QAction(RWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionOpen = new QAction(RWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionExit = new QAction(RWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionNew_Window = new QAction(RWindow);
        actionNew_Window->setObjectName(QString::fromUtf8("actionNew_Window"));
        actionSave_As = new QAction(RWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionAbout = new QAction(RWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionSupport = new QAction(RWindow);
        actionSupport->setObjectName(QString::fromUtf8("actionSupport"));
        actionSend_Feedback = new QAction(RWindow);
        actionSend_Feedback->setObjectName(QString::fromUtf8("actionSend_Feedback"));
        actionFont = new QAction(RWindow);
        actionFont->setObjectName(QString::fromUtf8("actionFont"));
        actionTestCode = new QAction(RWindow);
        actionTestCode->setObjectName(QString::fromUtf8("actionTestCode"));
        actionLight = new QAction(RWindow);
        actionLight->setObjectName(QString::fromUtf8("actionLight"));
        actionDark = new QAction(RWindow);
        actionDark->setObjectName(QString::fromUtf8("actionDark"));
        centralwidget = new QWidget(RWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget_Note = new QTabWidget(centralwidget);
        tabWidget_Note->setObjectName(QString::fromUtf8("tabWidget_Note"));
        tabWidget_Note->setIconSize(QSize(16, 16));
        tabWidget_Note->setElideMode(Qt::ElideLeft);
        tabWidget_Note->setUsesScrollButtons(true);
        tabWidget_Note->setDocumentMode(false);
        tabWidget_Note->setTabsClosable(true);
        tabWidget_Note->setMovable(true);
        tabWidget_Note->setTabBarAutoHide(false);
        RBaseTab = new QWidget();
        RBaseTab->setObjectName(QString::fromUtf8("RBaseTab"));
        tabWidget_Note->addTab(RBaseTab, QString());
        RBaseTab2 = new QWidget();
        RBaseTab2->setObjectName(QString::fromUtf8("RBaseTab2"));
        tabWidget_Note->addTab(RBaseTab2, QString());

        verticalLayout->addWidget(tabWidget_Note);

        RWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1380, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuTheme = new QMenu(menuEdit);
        menuTheme->setObjectName(QString::fromUtf8("menuTheme"));
        RWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionNew_Window);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionSupport);
        menuHelp->addSeparator();
        menuHelp->addAction(actionSend_Feedback);
        menuEdit->addAction(actionFont);
        menuEdit->addAction(menuTheme->menuAction());
        menuTheme->addAction(actionLight);
        menuTheme->addAction(actionDark);

        retranslateUi(RWindow);

        tabWidget_Note->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RWindow)
    {
        RWindow->setWindowTitle(QApplication::translate("RWindow", "RWindow", nullptr));
        actionNew->setText(QApplication::translate("RWindow", "New", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("RWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("RWindow", "Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("RWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("RWindow", "Open", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("RWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("RWindow", "Exit", nullptr));
        actionNew_Window->setText(QApplication::translate("RWindow", "New Window", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNew_Window->setShortcut(QApplication::translate("RWindow", "Ctrl+Shift+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_As->setText(QApplication::translate("RWindow", "Save As", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_As->setShortcut(QApplication::translate("RWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("RWindow", "About RNote", nullptr));
        actionSupport->setText(QApplication::translate("RWindow", "Help and Support", nullptr));
        actionSend_Feedback->setText(QApplication::translate("RWindow", "Send Feedback", nullptr));
        actionFont->setText(QApplication::translate("RWindow", "Font", nullptr));
        actionTestCode->setText(QApplication::translate("RWindow", "TestCode", nullptr));
        actionLight->setText(QApplication::translate("RWindow", "Light", nullptr));
        actionDark->setText(QApplication::translate("RWindow", "Dark", nullptr));
        tabWidget_Note->setTabText(tabWidget_Note->indexOf(RBaseTab), QApplication::translate("RWindow", "New Page", nullptr));
        tabWidget_Note->setTabText(tabWidget_Note->indexOf(RBaseTab2), QApplication::translate("RWindow", "New Page2", nullptr));
        menuFile->setTitle(QApplication::translate("RWindow", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("RWindow", "Help", nullptr));
        menuEdit->setTitle(QApplication::translate("RWindow", "Edit", nullptr));
        menuTheme->setTitle(QApplication::translate("RWindow", "Theme", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RWindow: public Ui_RWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RWINDOW_H
