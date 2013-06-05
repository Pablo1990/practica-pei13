main: main.o Form.o
	g++ -o main main.o Form.o `pkg-config gtkmm-3.0 --cflags --libs`

main.o: main.cpp  Form.h
	g++ -c main.cpp `pkg-config gtkmm-3.0 --cflags --libs`
	
Form.o: Form.h Form.cpp
	g++ -c Form.cpp `pkg-config gtkmm-3.0 --cflags --libs`
	
clean:
	rm *.o
