#include "ui_form.h"
#include "../Modelo/modeloRegistro.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     QMainWindow *window = new QMainWindow;
     Ui::MainWindow ui;
     ui.setupUi(window);

     window->show();

	ModeloRegistro mr;
    std::vector<std::string> ar;
	if(mr.LeerFichero(argv[1]))
	{
        ar=mr.GetRegistro(0);
        ui.INombre->setPlainText(QString::fromUtf8( ar[0].c_str() ));
        ui.IDireccion->setPlainText(QString::fromUtf8( ar[1].c_str() ));
        ui.IPoblacion->setPlainText(QString::fromUtf8( ar[2].c_str() ));
        ui.ICPostal->setPlainText(QString::fromUtf8( ar[3].c_str() ));
        ui.ITelefono->setPlainText(QString::fromUtf8( ar[4].c_str() ));
        ui.IMail->setPlainText(QString::fromUtf8( ar[5].c_str() ));
	}
     return app.exec();
 }
