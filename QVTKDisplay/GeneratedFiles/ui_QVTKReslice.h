/********************************************************************************
** Form generated from reading UI file 'QVTKReslice.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QVTKRESLICE_H
#define UI_QVTKRESLICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "QVTKLine.h"

QT_BEGIN_NAMESPACE

class Ui_QVTKReslice
{
public:
    QPushButton *pushButton;
    QWidget *widget;
    QLabel *XY;
    QLabel *XZ;
    QLabel *YZ;
    QVTKLine *selectX;
    QVTKLine *selectXZ;
    QVTKLine *selectY;
    QVTKLine *selectYZ;

    void setupUi(QWidget *QVTKReslice)
    {
        if (QVTKReslice->objectName().isEmpty())
            QVTKReslice->setObjectName(QStringLiteral("QVTKReslice"));
        QVTKReslice->resize(800, 600);
        pushButton = new QPushButton(QVTKReslice);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(730, 20, 60, 23));
        widget = new QWidget(QVTKReslice);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 720, 600));
        XY = new QLabel(widget);
        XY->setObjectName(QStringLiteral("XY"));
        XY->setGeometry(QRect(0, 0, 0, 0));
        XZ = new QLabel(widget);
        XZ->setObjectName(QStringLiteral("XZ"));
        XZ->setGeometry(QRect(0, 0, 0, 0));
        YZ = new QLabel(widget);
        YZ->setObjectName(QStringLiteral("YZ"));
        YZ->setGeometry(QRect(0, 0, 0, 0));
        selectX = new QVTKLine(widget);
        selectX->setObjectName(QStringLiteral("selectX"));
        selectX->setGeometry(QRect(0, 0, 0, 0));
        selectXZ = new QVTKLine(widget);
        selectXZ->setObjectName(QStringLiteral("selectXZ"));
        selectXZ->setGeometry(QRect(0, 0, 0, 0));
        selectY = new QVTKLine(widget);
        selectY->setObjectName(QStringLiteral("selectY"));
        selectY->setGeometry(QRect(0, 0, 0, 0));
        selectYZ = new QVTKLine(widget);
        selectYZ->setObjectName(QStringLiteral("selectYZ"));
        selectYZ->setGeometry(QRect(0, 0, 0, 0));

        retranslateUi(QVTKReslice);

        QMetaObject::connectSlotsByName(QVTKReslice);
    } // setupUi

    void retranslateUi(QWidget *QVTKReslice)
    {
        QVTKReslice->setWindowTitle(QApplication::translate("QVTKReslice", "QVTKReslice", 0));
        pushButton->setText(QApplication::translate("QVTKReslice", "PushButton", 0));
        XY->setText(QString());
        XZ->setText(QString());
        YZ->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QVTKReslice: public Ui_QVTKReslice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QVTKRESLICE_H
