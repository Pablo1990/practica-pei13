COMP=g++
OPC=-g -Wall
CARMOD=./Codigo/Modelo

.PHONY=clean

all: pei
 
pei: main.cpp modeloRegistro.o modelo.o Registro.o 
	$(COMP) $(OPC) main.cpp modeloRegistro.o modelo.o Registro.o -o pei

modeloRegistro.o: $(CARMOD)/modeloRegistro.cpp $(CARMOD)/modeloRegistro.h $(CARMOD)/Registro.h $(CARMOD)/modelo.h
	$(COMP) $(OPC) -c $(CARMOD)/modeloRegistro.cpp -I $(CARMOD)

modelo.o: $(CARMOD)/modelo.cpp $(CARMOD)/modelo.h
	$(COMP) $(OPC) -c $(CARMOD)/modelo.cpp -I $(CARMOD)/

Registro.o: $(CARMOD)/Registro.cpp $(CARMOD)/Registro.h
	$(COMP) $(OPC) -c $(CARMOD)/Registro.cpp -I $(CARMOD)/

clean:
	rm main 
	rm -r *.o
