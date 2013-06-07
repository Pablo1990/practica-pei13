COMP=g++
OPC=-g -Wall
CARMOD=

.PHONY=clean

all: pei
 
pei: main.cpp modeloRegistro.o Registro.o 
	$(COMP) $(OPC) main.cpp modeloRegistro.o Registro.o -o pei

modeloRegistro.o: modeloRegistro.cpp modeloRegistro.h Registro.h
	$(COMP) $(OPC) -c modeloRegistro.cpp

Registro.o: Registro.cpp Registro.h
	$(COMP) $(OPC) -c Registro.cpp

clean:
	rm pei 
	rm -r *.o
