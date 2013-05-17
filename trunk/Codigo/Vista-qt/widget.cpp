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
        ui->BtGuardarRegistro->setEnabled(false);
    }
}

void Widget::on_BtCargaFichero_clicked()
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

void Widget::on_BtNuevoRegistro_clicked()
{
    QString str;
    str.append(QString("%1").arg(mr.GetNumRegistros()));
    ui->LbId->setText(str);
    ui->INombre->setPlainText(QString::fromUtf8(""));
    ui->IDireccion->setPlainText(QString::fromUtf8( "" ));
    ui->IPoblacion->setPlainText(QString::fromUtf8( "" ));
    ui->ICPostal->setPlainText(QString::fromUtf8( "" ));
    ui->ITelefono->setPlainText(QString::fromUtf8( "" ));
    ui->IMail->setPlainText(QString::fromUtf8( "" ));
    ui->BtGuardarRegistro->setEnabled(true);
}

void Widget::on_BtGuardarRegistro_clicked()
{
    mr.CrearRegistro(ui->INombre->toPlainText().toStdString(), ui->IMail->toPlainText().toStdString(), ui->IPoblacion->toPlainText().toStdString(), ui->ICPostal->toPlainText().toStdString(), ui->ITelefono->toPlainText().toStdString(), ui->IDireccion->toPlainText().toStdString());
    ui->BtGuardarRegistro->setEnabled(false);
}

void Widget::on_BtBorrarRegistro_clicked()
{
    if(mr.GetNumRegistros()>=1)
    {
        mr.Borrar(ui->LbId->text().toInt());
        std::vector<std::string> ar;
        ar=mr.GetRegistro(ui->LbId->text().toInt());
        if(ar[0]=="-1" && mr.GetNumRegistros()!=0)
        {
            ar=mr.GetRegistro(ui->LbId->text().toInt()-1);
            QString str;
            str.append(QString("%1").arg((ui->LbId->text().toInt()-1)));
            ui->LbId->setText(str);
        }

        if(mr.GetNumRegistros()!=0)
        {
            ui->INombre->setPlainText(QString::fromUtf8( ar[0].c_str() ));
            ui->IDireccion->setPlainText(QString::fromUtf8( ar[1].c_str() ));
            ui->IPoblacion->setPlainText(QString::fromUtf8( ar[2].c_str() ));
            ui->ICPostal->setPlainText(QString::fromUtf8( ar[3].c_str() ));
            ui->ITelefono->setPlainText(QString::fromUtf8( ar[4].c_str() ));
            ui->IMail->setPlainText(QString::fromUtf8( ar[5].c_str() ));
        }
        else
        {
            QString str;
            str.append(QString("%1").arg(mr.GetNumRegistros()));
            ui->LbId->setText(str);
            ui->INombre->setPlainText(QString::fromUtf8(""));
            ui->IDireccion->setPlainText(QString::fromUtf8( "" ));
            ui->IPoblacion->setPlainText(QString::fromUtf8( "" ));
            ui->ICPostal->setPlainText(QString::fromUtf8( "" ));
            ui->ITelefono->setPlainText(QString::fromUtf8( "" ));
            ui->IMail->setPlainText(QString::fromUtf8( "" ));
        }
    }
}
