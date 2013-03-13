#include <iostream>

using namespace std;

#include "./Codigo/Modelo/modeloRegistro.h"

int main(int argc, char *argv[])
{
	ModeloRegistro mr = ModeloRegistro();
	
	if(mr.LeerFichero(argv[1]))
		mr.Imprimir();

}
