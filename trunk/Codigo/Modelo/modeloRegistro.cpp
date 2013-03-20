// -*- C++ -*-

/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/*
 * Fecha: Tue Sep 12 16:36:32 CEST 2000
 * Autor: Antonio-M. Corbi Bellot
 * Email: acorbi@dlsi.ua.es
 */
#include <iostream>
#include <fstream>
#include "modeloRegistro.h"
#include "Registro.h"

using namespace std;

/*
 * Constructor por defecto
 */
ModeloRegistro::ModeloRegistro()
{
  
}

/*
 * Constructor de copia
 */
ModeloRegistro::ModeloRegistro(const ModeloRegistro &un_modeloRegistro)
{
  if (this != &un_modeloRegistro) {
    lr.erase(lr.begin(), lr.end());
    lr = un_modeloRegistro.lr;
  }
}


/*
 * Destructor
 */
ModeloRegistro::~ModeloRegistro()
{
	lr.erase(lr.begin(), lr.end());
}

/*
 * Asignacion
 */
ModeloRegistro & ModeloRegistro::operator =(const ModeloRegistro &un_modeloRegistro)
{
   if (this != &un_modeloRegistro) {
    lr.erase(lr.begin(), lr.end());
    lr = un_modeloRegistro.lr;
  }
  return *this;
}

bool EsEspacio(char c){
	return (c==' ');
}

void ModeloRegistro::procesarRegistro(string *lineas)
{
	string resul;
	Registro* reg=NULL;
	*reg = Registro();
	for(int i=0; i<6; i++)
	{
		string linea=lineas[i];
		bool encon=false;
		resul="";
		for(int j=0; j<linea.length(); j++)
		{
			if(linea[j]=='\n' || linea[j]=='\r')
			{
				break;
			}
			if(!encon && EsEspacio(linea[j]))
			{
				encon=true;
			}
			if(encon && (!EsEspacio(linea[j]) || resul.length()>0))
			{
				resul+=linea[j];
			}
		}
		switch(i){
			case 0: reg->setNombre(resul);
				break;
			case 1: reg->setDireccion(resul);
				break;
			case 2: reg->setPoblacion(resul);
				break;
			case 3: reg->setPostal(resul);
				break;
			case 4: reg->setTelefono(resul);
				break;
			case 5: reg->setMail(resul);
				break;
			default: break;
		}
	}

	lr.push_back(reg);
}

bool ModeloRegistro::LeerFichero(char* nombreFichero)
{
	ifstream fi;
	fi.open(nombreFichero ,ios::in);
	string *lineas = new string[6];
	string linea="";
	int cont = 0;

	if (fi.is_open())
	{
		getline(fi, linea);

		while(!fi.eof())//lee linea a linea
		{	
			lineas[cont]=linea;	
			
			if(cont == 5)
			{	
				procesarRegistro(lineas);
				cont = -1;
			}			
			linea="";
			getline(fi,linea);
			cont++;
		}
		fi.close();
		return true;
	}
	else
	{
		cout<<"Error al abrir el fichero "<<nombreFichero<<endl;
		return false;
	}
	

}

void ModeloRegistro::Imprimir()
{
  list<Registro*>::iterator t;

  for(t = lr.begin(); t != lr.end(); t++){
	cout<<"ccc"<<endl;
      cout<<(*t)->getNombre();
  }

}


