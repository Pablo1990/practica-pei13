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
	return (c==' ' || c=='\t');
}

void ModeloRegistro::CrearRegistro(string nombre, string mail, string pobl, string cp, string tele, string dir){

	Registro* reg = new Registro(lr.size(), nombre, mail, pobl, cp, tele, dir);
	lr.push_back(reg);
}

void ModeloRegistro::procesarRegistro(string *lineas)
{
	string resul;
	Registro* reg = new Registro(lr.size());
	
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

bool ModeloRegistro::EscribirFichero(char* nombreFichero)
{
	ofstream fo;
	fo.open(nombreFichero, ios::out);
	list<Registro*>::iterator t;
  	for(t = lr.begin(); t != lr.end(); t++){
		fo<<"NOMBRE: "<<(*t)->getNombre()<<endl;
		fo<<"DIRECCION: "<<(*t)->getDireccion()<<endl;
      		fo<<"POBLACION: "<<(*t)->getPoblacion()<<endl;
      		fo<<"CPOSTAL: "<<(*t)->getPostal()<<endl;
      		fo<<"TELEFONO: "<<(*t)->getTelefono()<<endl;
      		fo<<"EMAIL: "<<(*t)->getMail()<<endl;
		fo<<endl;
	}

	fo.close();

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
			if(linea.length() > 3) //en futuras ampliaciones habría que cambiarlo. Hace mierdas
			{
				lineas[cont]=linea;	
			
				if(cont == 5)
				{	
					procesarRegistro(lineas);
					cont = -1;
				}
				cont++;
			}			
				linea="";
				getline(fi,linea);
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

void ModeloRegistro::ActualizarIds(){

  list<Registro*>::iterator t;
  int cont=0;
  for(t = lr.begin(); t != lr.end(); t++){
	(*t)->setId(cont);
	cont++;
  }
}

void ModeloRegistro::Buscar(string filtro) //, int campo
{
	
  	list<Registro*>::iterator t;
	bool find = false;
	//if(campo==1)
	
  	for(t = lr.begin(); t != lr.end(); t++)
	{
	//switch(campo){
	      	if((*t)->getNombre() == filtro)
		{
			(*t)->setBuscado(true);
		}
		else if((*t)->getDireccion() == filtro) 
		{
			(*t)->setBuscado(true);
		}
		else if((*t)->getPoblacion() == filtro) 
		{
			(*t)->setBuscado(true);

		}
		else if((*t)->getPostal() == filtro) 
		{
			(*t)->setBuscado(true);
		}
		else if((*t)->getTelefono() == filtro) 
		{
			(*t)->setBuscado(true);
		}
		else if((*t)->getMail() == filtro) 
		{
			(*t)->setBuscado(true);
		}
  	}

}

bool ModeloRegistro::Borrar(int id2)
{
	int cont=0;
	list<Registro*>::iterator t = lr.begin();
	while(cont<id2 && t!=lr.end())
	{
		t++;
		cont++;
	}

	if(id2==cont)
	{
		lr.erase(t);
		ActualizarIds();
		return true;
	}	
	
	return false;	
}

bool ModeloRegistro::Modificar(int id2, string n, string mail, string pob, string cp, string tel, string dir)
{
	int cont=0;
	list<Registro*>::iterator t = lr.begin();
	while(cont<id2)
	{
		t++;
		cont++;
	}

	(*t)->setNombre(n);
	(*t)->setDireccion(mail);
	(*t)->setPoblacion(pob);
	(*t)->setPostal(cp);
	(*t)->setTelefono(tel);
	(*t)->setMail(dir);

	return true;
}

void ModeloRegistro::Imprimir(int tipo)
{
  list<Registro*>::iterator t;
  for(t = lr.begin(); t != lr.end(); t++){
	if(tipo == 1 && (*t)->getBuscado())//buscar
	{
		ImprimirRegistro(*t);
	}
	else if(tipo == 0)
	{
		ImprimirRegistro(*t);
	}
  }
	cout<<endl;
}

void ModeloRegistro::ImprimirRegistro(Registro* t)
{	
	cout<<"----------------REGISTRO-----------------"<<endl;
	cout<<"Nombre: "<<(t)->getNombre()<<endl;
	cout<<"Direccion: "<<(t)->getDireccion()<<endl;
      cout<<"Poblacion: "<<(t)->getPoblacion()<<endl;
      cout<<"CPostal: "<<(t)->getPostal()<<endl;
      cout<<"Telefono: "<<(t)->getTelefono()<<endl;
      cout<<"Email: "<<(t)->getMail()<<endl;
}

Registro* ModeloRegistro::GetRegistro(int id)
{
	list<Registro*>::iterator t;
  for(t = lr.begin(); t != lr.end(); t++){
	if((*t)->getId()==id)
	{
		return (t);
	}
  }

return NULL;
}

