#include "widget.h"
#include "../Modelo/modeloRegistro.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_BtNextRegistro_clicked()
{
    std::vector<std::string> ar=mr.GetRegistro(ui->LbId->text().toInt()+1);
    if(ar.size()==6)
    {
        ui->INombre->setPlainText(QString::fromUtf8( ar[0].c_str() ));
        ui->IDireccion->setPlainText(QString::fromUtf8( ar[1].c_str() ));
        ui->IPoblacion->setPlainText(QString::fromUtf8( ar[2].c_str() ));
        ui->ICPostal->setPlainText(QString::fromUtf8( ar[3].c_str() ));
        ui->ITelefono->setPlainText(QString::fromUtf8( ar[4].c_str() ));
        ui->IMail->setPlainText(QString::fromUtf8( ar[5].c_str() ));
        QString str;
        str.append(QString("%1").arg((ui->LbId->text().toInt()+1)));
        ui->LbId->setText(str);
    }
}

void Widget::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.*)"));
    std::vector<std::string> ar;
    if(mr.LeerFichero(fileName.toAscii().data()))
    {
        ar=mr.GetRegistro(0);
        ui->INombre->setPlainText(QString::fromUtf8( ar[0].c_str() ));
        ui->IDireccion->setPlainText(QString::fromUtf8( ar[1].c_str() ));
        ui->IPoblacion->setPlainText(QString::fromUtf8( ar[2].c_str() ));
        ui->ICPostal->setPlainText(QString::fromUtf8( ar[3].c_str() ));
        ui->ITelefono->setPlainText(QString::fromUtf8( ar[4].c_str() ));
        ui->IMail->setPlainText(QString::fromUtf8( ar[5].c_str() ));
        ui->LbId->setText("0");
    }
}

void Widget::on_BtPrevRegistro_clicked()
{
    std::vector<std::string> ar=mr.GetRegistro(ui->LbId->text().toInt()-1);
    if(ar.size()==6)
    {
        ui->INombre->setPlainText(QString::fromUtf8( ar[0].c_str() ));
        ui->IDireccion->setPlainText(QString::fromUtf8( ar[1].c_str() ));
        ui->IPoblacion->setPlainText(QString::fromUtf8( ar[2].c_str() ));
        ui->ICPostal->setPlainText(QString::fromUtf8( ar[3].c_str() ));
        ui->ITelefono->setPlainText(QString::fromUtf8( ar[4].c_str() ));
        ui->IMail->setPlainText(QString::fromUtf8( ar[5].c_str() ));
        QString str;
        str.append(QString("%1").arg((ui->LbId->text().toInt()-1)));
        ui->LbId->setText(str);
    }
}
