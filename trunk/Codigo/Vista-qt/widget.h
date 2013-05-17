#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "../Modelo/modeloRegistro.h"
#include <QFileDialog>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    ModeloRegistro mr;
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void on_BtNextRegistro_clicked();

    void on_pushButton_clicked();

    void on_BtPrevRegistro_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
