COMP=g++
OPC=-g -Wall
CARMOD=./Codigo/Modelo
CARQT=./Codigo/Vista-qt
CARGTK=./Codigo/Vista-gtkmm

.PHONY=clean

all:
	$(info --------- COMPILADO: TERMINAL, QT Y GTKMM ---------)
	cd $(CARMOD); make;
	cd $(CARQT); qmake; make;
	cd $(CARGTK); make;

clean:
	$(info --------- LIMPIANDO: TERMINAL, QT Y GTKMM ---------)
	cd $(CARMOD); make clean;
	cd $(CARQT); make clean;
	cd $(CARGTK); make clean;
