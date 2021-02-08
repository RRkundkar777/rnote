/********************************************************************************
** Form generated from reading UI file 'tab.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_H
#define UI_TAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab
{
public:
    QGridLayout *gridLayout;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *Tab)
    {
        if (Tab->objectName().isEmpty())
            Tab->setObjectName(QStringLiteral("Tab"));
        Tab->resize(899, 582);
        gridLayout = new QGridLayout(Tab);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new QPlainTextEdit(Tab);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(32);
        plainTextEdit->setFont(font);
        plainTextEdit->setStyleSheet(QLatin1String("QPlainTextEdit\n"
"{\n"
"    border: 0;\n"
"}"));
        plainTextEdit->setLineWidth(0);
        plainTextEdit->setPlaceholderText(QStringLiteral(""));

        gridLayout->addWidget(plainTextEdit, 0, 0, 1, 1);


        retranslateUi(Tab);

        QMetaObject::connectSlotsByName(Tab);
    } // setupUi

    void retranslateUi(QWidget *Tab)
    {
        Tab->setWindowTitle(QApplication::translate("Tab", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Tab: public Ui_Tab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_H
