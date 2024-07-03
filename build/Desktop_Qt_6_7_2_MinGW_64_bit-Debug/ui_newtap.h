/********************************************************************************
** Form generated from reading UI file 'newtap.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWTAP_H
#define UI_NEWTAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newTap
{
public:
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;

    void setupUi(QWidget *newTap)
    {
        if (newTap->objectName().isEmpty())
            newTap->setObjectName("newTap");
        newTap->resize(768, 554);
        horizontalLayout = new QHBoxLayout(newTap);
        horizontalLayout->setObjectName("horizontalLayout");
        textEdit = new QTextEdit(newTap);
        textEdit->setObjectName("textEdit");
        textEdit->setStyleSheet(QString::fromUtf8("font-size:16px;"));

        horizontalLayout->addWidget(textEdit);


        retranslateUi(newTap);

        QMetaObject::connectSlotsByName(newTap);
    } // setupUi

    void retranslateUi(QWidget *newTap)
    {
        newTap->setWindowTitle(QCoreApplication::translate("newTap", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newTap: public Ui_newTap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWTAP_H
