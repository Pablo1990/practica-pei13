/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created: Fri May 17 10:10:01 2013
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
#include <QtGui/QMenu>
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
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
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
    QLabel *label_7;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuAcerca_de;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(723, 588);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 40, 161, 311));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
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

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(210, 40, 181, 311));
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
        horizontalLayoutWidget->setGeometry(QRect(110, 370, 201, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        BtPrevRegistro = new QPushButton(horizontalLayoutWidget);
        BtPrevRegistro->setObjectName(QString::fromUtf8("BtPrevRegistro"));

        horizontalLayout->addWidget(BtPrevRegistro);

        label_7 = new QLabel(horizontalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(20, 30));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_7);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 723, 25));
        menuAcerca_de = new QMenu(menubar);
        menuAcerca_de->setObjectName(QString::fromUtf8("menuAcerca_de"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuAcerca_de->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Nombre", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Direccion", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Poblacion", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "C\303\263digo Postal", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Tel\303\251fono", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "E-mail", 0, QApplication::UnicodeUTF8));
        BtPrevRegistro->setText(QApplication::translate("MainWindow", "<", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", ">", 0, QApplication::UnicodeUTF8));
        menuAcerca_de->setTitle(QApplication::translate("MainWindow", "Acerca de", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
