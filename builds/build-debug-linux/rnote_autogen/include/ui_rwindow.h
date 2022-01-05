/********************************************************************************
** Form generated from reading UI file 'rwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RWINDOW_H
#define UI_RWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
    QAction *actionTestCode;
    QAction *actionLight;
    QAction *actionDark;
    QAction *actionFont;
    QAction *actionMonokai;
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
            RWindow->setObjectName(QStringLiteral("RWindow"));
        RWindow->resize(1380, 700);
        actionNew = new QAction(RWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionSave = new QAction(RWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionOpen = new QAction(RWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExit = new QAction(RWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionNew_Window = new QAction(RWindow);
        actionNew_Window->setObjectName(QStringLiteral("actionNew_Window"));
        actionSave_As = new QAction(RWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionAbout = new QAction(RWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionSupport = new QAction(RWindow);
        actionSupport->setObjectName(QStringLiteral("actionSupport"));
        actionSend_Feedback = new QAction(RWindow);
        actionSend_Feedback->setObjectName(QStringLiteral("actionSend_Feedback"));
        actionTestCode = new QAction(RWindow);
        actionTestCode->setObjectName(QStringLiteral("actionTestCode"));
        actionLight = new QAction(RWindow);
        actionLight->setObjectName(QStringLiteral("actionLight"));
        actionDark = new QAction(RWindow);
        actionDark->setObjectName(QStringLiteral("actionDark"));
        actionFont = new QAction(RWindow);
        actionFont->setObjectName(QStringLiteral("actionFont"));
        actionMonokai = new QAction(RWindow);
        actionMonokai->setObjectName(QStringLiteral("actionMonokai"));
        centralwidget = new QWidget(RWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget_Note = new QTabWidget(centralwidget);
        tabWidget_Note->setObjectName(QStringLiteral("tabWidget_Note"));
        tabWidget_Note->setIconSize(QSize(16, 16));
        tabWidget_Note->setElideMode(Qt::ElideLeft);
        tabWidget_Note->setUsesScrollButtons(true);
        tabWidget_Note->setDocumentMode(false);
        tabWidget_Note->setTabsClosable(true);
        tabWidget_Note->setMovable(true);
        tabWidget_Note->setTabBarAutoHide(false);
        RBaseTab = new QWidget();
        RBaseTab->setObjectName(QStringLiteral("RBaseTab"));
        tabWidget_Note->addTab(RBaseTab, QString());
        RBaseTab2 = new QWidget();
        RBaseTab2->setObjectName(QStringLiteral("RBaseTab2"));
        tabWidget_Note->addTab(RBaseTab2, QString());

        verticalLayout->addWidget(tabWidget_Note);

        RWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1380, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTheme = new QMenu(menuEdit);
        menuTheme->setObjectName(QStringLiteral("menuTheme"));
        RWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        RWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
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
        menuTheme->addAction(actionMonokai);

        retranslateUi(RWindow);

        tabWidget_Note->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RWindow)
    {
        RWindow->setWindowTitle(QApplication::translate("RWindow", "RWindow", Q_NULLPTR));
        actionNew->setText(QApplication::translate("RWindow", "New Tab", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("RWindow", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("RWindow", "Save", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("RWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("RWindow", "Open", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("RWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("RWindow", "Exit", Q_NULLPTR));
        actionNew_Window->setText(QApplication::translate("RWindow", "New Window", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionNew_Window->setShortcut(QApplication::translate("RWindow", "Ctrl+Shift+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave_As->setText(QApplication::translate("RWindow", "Save As", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSave_As->setShortcut(QApplication::translate("RWindow", "Ctrl+Shift+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("RWindow", "About RNote", Q_NULLPTR));
        actionSupport->setText(QApplication::translate("RWindow", "Help and Support", Q_NULLPTR));
        actionSend_Feedback->setText(QApplication::translate("RWindow", "Send Feedback", Q_NULLPTR));
        actionTestCode->setText(QApplication::translate("RWindow", "TestCode", Q_NULLPTR));
        actionLight->setText(QApplication::translate("RWindow", "Theme Light", Q_NULLPTR));
        actionDark->setText(QApplication::translate("RWindow", "Absolute Dark", Q_NULLPTR));
        actionFont->setText(QApplication::translate("RWindow", "Font ...", Q_NULLPTR));
        actionMonokai->setText(QApplication::translate("RWindow", "Monokai", Q_NULLPTR));
        tabWidget_Note->setTabText(tabWidget_Note->indexOf(RBaseTab), QApplication::translate("RWindow", "New Page", Q_NULLPTR));
        tabWidget_Note->setTabText(tabWidget_Note->indexOf(RBaseTab2), QApplication::translate("RWindow", "New Page2", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("RWindow", "File", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("RWindow", "Help", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("RWindow", "Edit", Q_NULLPTR));
        menuTheme->setTitle(QApplication::translate("RWindow", "Editor Theme", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RWindow: public Ui_RWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RWINDOW_H
