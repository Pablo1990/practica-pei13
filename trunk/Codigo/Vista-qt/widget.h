#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "../Modelo/modeloRegistro.h"
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    ModeloRegistro mr;
    QString fileName;
    bool modificar;
    bool modoBuscar;
    std::vector<Registro*> buscados;
    int contadorBuscados;
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void on_BtNextRegistro_clicked();

    void on_BtPrevRegistro_clicked();

    void on_BtCargaFichero_clicked();

    void on_BtNuevoRegistro_clicked();

    void on_BtGuardarRegistro_clicked();

    void on_BtBorrarRegistro_clicked();

    void on_BtGuardarFichero_clicked();

    void on_commandLinkButton_clicked();

    void on_BtModificar_clicked();

    void on_BtBuscar_clicked();

    void on_checkBox_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
