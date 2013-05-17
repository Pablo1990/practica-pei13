#include <iostream>

using namespace std;

#include "./Codigo/Modelo/modeloRegistro.h"

int main(int argc, char *argv[])
{
	ModeloRegistro mr;
	
	if(mr.LeerFichero(argv[1]))
	{
		//mr.Buscar(argv[2]);
		mr.CrearRegistro("Pablo", "culo", "elda", "lsajdflsjdf", "w2334", "serwer");
		mr.Imprimir(0);
	}
}
