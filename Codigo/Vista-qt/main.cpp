#include "ui_form.h"
#include "../Modelo/modeloRegistro.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     QMainWindow *window = new QMainWindow;
     Ui::MainWindow ui;
     ui.setupUi(window);

     window->show();

	ModeloRegistro mr;
	string *ar;
	if(mr.LeerFichero(argv[1]))
	{
		ar=mr.GetRegistro(1);
		ui.INombre->setPlainText(&ar[0]);
	}
     return app.exec();
 }
