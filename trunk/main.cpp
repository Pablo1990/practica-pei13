#include <iostream>

using namespace std;

#include "./Codigo/Modelo/modeloRegistro.h"

int main(int argc, char *argv[])
{
	ModeloRegistro mr;
	
	if(mr.LeerFichero(argv[1]))
	{
		//mr.Buscar(argv[2]);
		mr.Imprimir(0); // 0 = no buscar ; 1 = buscar
		mr.Borrar(10);
		mr.Borrar(0);
		mr.Imprimir(0);
		mr.CrearRegistro("Juan", "culo", "elda", "lsajdflsjdf", "w2334", "serwer");
		mr.Imprimir(0);
		mr.EscribirFichero(argv[1]);
	}
}
