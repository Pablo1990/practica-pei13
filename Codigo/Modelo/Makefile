COMP=g++
OPC=-g -Wall
CARMOD=

.PHONY=clean

all: pei
 
pei: main.cpp modeloRegistro.o modelo.o Registro.o 
	$(COMP) $(OPC) main.cpp modeloRegistro.o modelo.o Registro.o -o pei

modeloRegistro.o: modeloRegistro.cpp modeloRegistro.h Registro.h modelo.h
	$(COMP) $(OPC) -c modeloRegistro.cpp

modelo.o: modelo.cpp modelo.h
	$(COMP) $(OPC) -c modelo.cpp

Registro.o: Registro.cpp Registro.h
	$(COMP) $(OPC) -c Registro.cpp

clean:
	rm pei 
	rm -r *.o
