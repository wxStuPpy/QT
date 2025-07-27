/********************************************************************************
** Form generated from reading UI file 'statewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATEWIDGET_H
#define UI_STATEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StateWidgetClass
{
public:

    void setupUi(QWidget *StateWidgetClass)
    {
        if (StateWidgetClass->objectName().isEmpty())
            StateWidgetClass->setObjectName("StateWidgetClass");
        StateWidgetClass->resize(600, 400);

        retranslateUi(StateWidgetClass);

        QMetaObject::connectSlotsByName(StateWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *StateWidgetClass)
    {
        StateWidgetClass->setWindowTitle(QCoreApplication::translate("StateWidgetClass", "StateWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StateWidgetClass: public Ui_StateWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATEWIDGET_H
