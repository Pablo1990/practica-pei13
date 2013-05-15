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
	
	if(mr.LeerFichero(argv[1]))
	{
		ui.INombre->setPlainText(QApplication::translate("MainWindow", "Pepe", 0, QApplication::UnicodeUTF8));
	}
     return app.exec();
 }
