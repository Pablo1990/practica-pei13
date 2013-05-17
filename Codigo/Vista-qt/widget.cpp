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

}

void Widget::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.*)"));
    ModeloRegistro mr;
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
