COMP=g++
OPC=-g -Wall
CARMOD=../Modelo

main: main.o Form.o
	g++ -o main main.o Form.o modeloRegistro.o Registro.o `pkg-config gtkmm-3.0 --cflags --libs`

main.o: main.cpp  Form.h
	g++ -c main.cpp `pkg-config gtkmm-3.0 --cflags --libs`
	
Form.o: Form.h Form.cpp modeloRegistro.o Registro.o
	g++ -c Form.cpp `pkg-config gtkmm-3.0 --cflags --libs`
	
modeloRegistro.o: $(CARMOD)/modeloRegistro.cpp $(CARMOD)/modeloRegistro.h $(CARMOD)/Registro.h
	$(COMP) $(OPC) -c $(CARMOD)/modeloRegistro.cpp -I $(CARMOD)

Registro.o: $(CARMOD)/Registro.cpp $(CARMOD)/Registro.h
	$(COMP) $(OPC) -c $(CARMOD)/Registro.cpp -I $(CARMOD)/
	
clean:
	rm main
	rm -r *.o
