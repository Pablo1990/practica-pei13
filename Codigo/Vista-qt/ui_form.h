/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created: Wed May 15 16:05:03 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *INombre;
    QPlainTextEdit *IDireccion;
    QPlainTextEdit *IPoblacion;
    QPlainTextEdit *ICPostal;
    QPlainTextEdit *ITelefono;
    QPlainTextEdit *IMail;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *BtPrevRegistro;
    QLabel *LbIdRegistro;
    QPushButton *BtNextRegistro;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(818, 733);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(130, 30, 221, 271));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        INombre = new QPlainTextEdit(verticalLayoutWidget_2);
        INombre->setObjectName(QString::fromUtf8("INombre"));

        verticalLayout_2->addWidget(INombre);

        IDireccion = new QPlainTextEdit(verticalLayoutWidget_2);
        IDireccion->setObjectName(QString::fromUtf8("IDireccion"));

        verticalLayout_2->addWidget(IDireccion);

        IPoblacion = new QPlainTextEdit(verticalLayoutWidget_2);
        IPoblacion->setObjectName(QString::fromUtf8("IPoblacion"));

        verticalLayout_2->addWidget(IPoblacion);

        ICPostal = new QPlainTextEdit(verticalLayoutWidget_2);
        ICPostal->setObjectName(QString::fromUtf8("ICPostal"));

        verticalLayout_2->addWidget(ICPostal);

        ITelefono = new QPlainTextEdit(verticalLayoutWidget_2);
        ITelefono->setObjectName(QString::fromUtf8("ITelefono"));

        verticalLayout_2->addWidget(ITelefono);

        IMail = new QPlainTextEdit(verticalLayoutWidget_2);
        IMail->setObjectName(QString::fromUtf8("IMail"));

        verticalLayout_2->addWidget(IMail);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(80, 320, 211, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        BtPrevRegistro = new QPushButton(horizontalLayoutWidget);
        BtPrevRegistro->setObjectName(QString::fromUtf8("BtPrevRegistro"));

        horizontalLayout->addWidget(BtPrevRegistro);

        LbIdRegistro = new QLabel(horizontalLayoutWidget);
        LbIdRegistro->setObjectName(QString::fromUtf8("LbIdRegistro"));
        LbIdRegistro->setMaximumSize(QSize(30, 30));
        LbIdRegistro->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(LbIdRegistro);

        BtNextRegistro = new QPushButton(horizontalLayoutWidget);
        BtNextRegistro->setObjectName(QString::fromUtf8("BtNextRegistro"));

        horizontalLayout->addWidget(BtNextRegistro);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 30, 101, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 818, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        BtPrevRegistro->setText(QApplication::translate("MainWindow", "<", 0, QApplication::UnicodeUTF8));
        LbIdRegistro->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        BtNextRegistro->setText(QApplication::translate("MainWindow", ">", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "NOMBRE", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "DIRECCION", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "POBLACION", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "CPOSTAL", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "TELEFONO", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "EMAIL", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
