#include "widget.h"
#include "../Modelo/modeloRegistro.h"
#include "ui_widget.h"
#include "acercade.h"
#include "ui_acercade.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    modoBuscar=false;
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_BtNextRegistro_clicked()
{
    if(!modoBuscar)
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
            ui->BtModificar->setEnabled(true);
            ui->BtGuardarRegistro->setEnabled(false);
        }
    }
    else
    {
        if(contadorBuscados+1<buscados.size())
        {
            ui->INombre->setPlainText( QString::fromStdString(buscados[contadorBuscados+1]->getNombre()));
            ui->IDireccion->setPlainText(QString::fromStdString(buscados[contadorBuscados+1]->getDireccion()));
            ui->IPoblacion->setPlainText(QString::fromStdString(buscados[contadorBuscados+1]->getPoblacion()));
            ui->ICPostal->setPlainText(QString::fromStdString(buscados[contadorBuscados+1]->getPostal()));
            ui->ITelefono->setPlainText(QString::fromStdString(buscados[contadorBuscados+1]->getTelefono()));
            ui->IMail->setPlainText(QString::fromStdString(buscados[contadorBuscados+1]->getMail()));
            QString str;
            str.append(QString("%1").arg((contadorBuscados+1)));
            ui->LbId->setText(str);
            contadorBuscados++;
        }
    }
}

void Widget::on_BtPrevRegistro_clicked()
{
    if(!modoBuscar)
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
            ui->BtModificar->setEnabled(true);
        }
    }
    else
    {
        if(contadorBuscados>0)
        {
            ui->INombre->setPlainText( QString::fromStdString(buscados[contadorBuscados-1]->getNombre()));
            ui->IDireccion->setPlainText(QString::fromStdString(buscados[contadorBuscados-1]->getDireccion()));
            ui->IPoblacion->setPlainText(QString::fromStdString(buscados[contadorBuscados-1]->getPoblacion()));
            ui->ICPostal->setPlainText(QString::fromStdString(buscados[contadorBuscados-1]->getPostal()));
            ui->ITelefono->setPlainText(QString::fromStdString(buscados[contadorBuscados-1]->getTelefono()));
            ui->IMail->setPlainText(QString::fromStdString(buscados[contadorBuscados-1]->getMail()));
            QString str;
            str.append(QString("%1").arg((contadorBuscados-1)));
            ui->LbId->setText(str);
            contadorBuscados--;
        }
    }
}

void Widget::on_BtCargaFichero_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.*)"));
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
        ui->BtGuardarRegistro->setEnabled(true);
        ui->BtModificar->setEnabled(true);
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
    modificar=false;
    ui->BtModificar->setEnabled(false);
}

void Widget::on_BtGuardarRegistro_clicked()
{
    if(!modificar)
    {
        mr.CrearRegistro(ui->INombre->toPlainText().toStdString(), ui->IMail->toPlainText().toStdString(), ui->IPoblacion->toPlainText().toStdString(), ui->ICPostal->toPlainText().toStdString(), ui->ITelefono->toPlainText().toStdString(), ui->IDireccion->toPlainText().toStdString());
        ui->BtGuardarRegistro->setEnabled(false);
        modificar=true;
        ui->BtModificar->setEnabled(true);
    }
    else
    {
        if(!modoBuscar)
        {
            mr.Modificar(ui->LbId->text().toInt(), ui->INombre->toPlainText().toStdString(), ui->IMail->toPlainText().toStdString(), ui->IPoblacion->toPlainText().toStdString(), ui->ICPostal->toPlainText().toStdString(), ui->ITelefono->toPlainText().toStdString(), ui->IDireccion->toPlainText().toStdString());
            ui->BtGuardarRegistro->setEnabled(false);
            ui->BtModificar->setEnabled(true);
        }
        else
        {
            mr.Modificar(buscados[ui->LbId->text().toInt()]->getId(), ui->INombre->toPlainText().toStdString(), ui->IMail->toPlainText().toStdString(), ui->IPoblacion->toPlainText().toStdString(), ui->ICPostal->toPlainText().toStdString(), ui->ITelefono->toPlainText().toStdString(), ui->IDireccion->toPlainText().toStdString());
            ui->BtGuardarRegistro->setEnabled(false);
            buscados = mr.GetRegistrosBuscados();
            ui->BtModificar->setEnabled(true);
        }
    }
}

void Widget::on_BtBorrarRegistro_clicked()
{
    if(!modoBuscar)
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
    else
    {
        mr.Borrar(buscados[ui->LbId->text().toInt()]->getId());
        buscados = mr.GetRegistrosBuscados();
        if(contadorBuscados>=buscados.size())
        {
            contadorBuscados--;
        }
        if(contadorBuscados<0)
        {
            contadorBuscados=0;
        }
        if(buscados.size()!=0)
        {
            ui->INombre->setPlainText( QString::fromStdString(buscados[contadorBuscados]->getNombre()));
            ui->IDireccion->setPlainText(QString::fromStdString(buscados[contadorBuscados]->getDireccion()));
            ui->IPoblacion->setPlainText(QString::fromStdString(buscados[contadorBuscados]->getPoblacion()));
            ui->ICPostal->setPlainText(QString::fromStdString(buscados[contadorBuscados]->getPostal()));
            ui->ITelefono->setPlainText(QString::fromStdString(buscados[contadorBuscados]->getTelefono()));
            ui->IMail->setPlainText(QString::fromStdString(buscados[contadorBuscados]->getMail()));
            QString str;
            str.append(QString("%1").arg(contadorBuscados));
            ui->LbId->setText(str);
        }
        else
        {
            QString str;
            str.append(QString("%1").arg(0));
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

void Widget::on_BtGuardarFichero_clicked()
{
    mr.EscribirFichero(fileName.toAscii().data());
    QMessageBox msgBox;
    msgBox.setText("Se ha guardado el fichero correctamente");
    msgBox.exec();
}

void Widget::on_commandLinkButton_clicked()
{
    acercade a;
    a.exec();
}

void Widget::on_BtModificar_clicked()
{
    modificar=true;
    ui->BtGuardarRegistro->setEnabled(true);
    ui->BtModificar->setEnabled(false);
}

void Widget::on_BtBuscar_clicked()
{
    mr.Buscar(ui->IBuscar->toPlainText().toStdString());
    buscados = mr.GetRegistrosBuscados();
    if(buscados.size()>0)
    {
        contadorBuscados=0;
        ui->INombre->setPlainText( QString::fromStdString(buscados[contadorBuscados]->getNombre()));
        ui->IDireccion->setPlainText(QString::fromStdString(buscados[contadorBuscados]->getDireccion()));
        ui->IPoblacion->setPlainText(QString::fromStdString(buscados[contadorBuscados]->getPoblacion()));
        ui->ICPostal->setPlainText(QString::fromStdString(buscados[contadorBuscados]->getPostal()));
        ui->ITelefono->setPlainText(QString::fromStdString(buscados[contadorBuscados]->getTelefono()));
        ui->IMail->setPlainText(QString::fromStdString(buscados[contadorBuscados]->getMail()));
        QString str;
        str.append(QString("%1").arg((contadorBuscados)));
        ui->LbId->setText(str);
        modoBuscar=true;
        ui->checkBox->setChecked(true);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("No se han encontrado resultados");
        msgBox.exec();
    }
}

void Widget::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked())
    {
        contadorBuscados=0;
        buscados = mr.GetRegistrosBuscados();
        if(buscados.size()==0)
        {
            QMessageBox msgBox;
            msgBox.setText("No se han encontrado resultados");
            msgBox.exec();
            ui->BtNuevoRegistro->setEnabled(false);
        }
        else
        {
            QString str;
            str.append(QString("%1").arg(contadorBuscados));
            ui->LbId->setText(str);
            ui->INombre->setPlainText( QString::fromStdString(buscados[contadorBuscados]->getNombre()));
            ui->IDireccion->setPlainText(QString::fromStdString(buscados[contadorBuscados]->getDireccion()));
            ui->IPoblacion->setPlainText(QString::fromStdString(buscados[contadorBuscados]->getPoblacion()));
            ui->ICPostal->setPlainText(QString::fromStdString(buscados[contadorBuscados]->getPostal()));
            ui->ITelefono->setPlainText(QString::fromStdString(buscados[contadorBuscados]->getTelefono()));
            ui->IMail->setPlainText(QString::fromStdString(buscados[contadorBuscados]->getMail()));
            modoBuscar=true;
            ui->checkBox->setChecked(true);
            ui->BtNuevoRegistro->setEnabled(false);
        }
    }
    else
    {
        ui->checkBox->setChecked(false);
        contadorBuscados=0;
        modoBuscar=false;
        std::vector<std::string> ar=mr.GetRegistro(0);
        ui->INombre->setPlainText(QString::fromUtf8( ar[0].c_str() ));
        ui->IDireccion->setPlainText(QString::fromUtf8( ar[1].c_str() ));
        ui->IPoblacion->setPlainText(QString::fromUtf8( ar[2].c_str() ));
        ui->ICPostal->setPlainText(QString::fromUtf8( ar[3].c_str() ));
        ui->ITelefono->setPlainText(QString::fromUtf8( ar[4].c_str() ));
        ui->IMail->setPlainText(QString::fromUtf8( ar[5].c_str() ));
        ui->LbId->setText("0");
        ui->BtModificar->setEnabled(true);
        ui->BtNuevoRegistro->setEnabled(false);
    }
}
