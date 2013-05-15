/*
 * Registro.cpp
 *
 *  Created on: 13/03/2013
 *      Author: pvm22
 */

#include "Registro.h"

Registro::Registro(int iden) {
	// TODO Auto-generated constructor stub
	id = iden;
	nombre="";
	eMail="";
	poblacion="";
	cPostal="";
	telefono="";
	direccion="";
	buscado = false;
}

Registro::Registro(int id, string n, string mail, string pob, string cp, string tel, string dir) {
	// TODO Auto-generated constructor stub
	id = id;
	nombre=n;
	eMail=mail;
	poblacion=pob;
	cPostal=cp;
	telefono=tel;
	direccion=dir;
	buscado = false;
}

Registro::Registro(const Registro& reg)
{
  if (this != &reg) {
	id = reg.id;
	direccion = reg.direccion;
	eMail = reg.eMail;
	nombre = reg.nombre;
	poblacion = reg.poblacion;
	cPostal = reg.cPostal;
	telefono = reg.telefono;
	buscado = reg.buscado;
  }
}

Registro::~Registro() {
	// TODO Auto-generated destructor stub
}

Registro& Registro::operator =(const Registro& reg)
{
  if (this != &reg) {
	id = reg.id;
	direccion = reg.direccion;
	eMail = reg.eMail;
	nombre = reg.nombre;
	poblacion = reg.poblacion;
	cPostal = reg.cPostal;
	telefono = reg.telefono;
	buscado = reg.buscado;
  }
  return (*this);
}

string Registro::getDireccion() const
{
    return direccion;
}

string Registro::getMail() const
{
    return eMail;
}

string Registro::getNombre() const
{
    return nombre;
}

string Registro::getPoblacion() const
{
    return poblacion;
}

string Registro::getPostal() const
{
    return cPostal;
}

string Registro::getTelefono() const
{
    return telefono;
}

bool Registro::getBuscado() const
{
    return buscado;
}
void Registro::setDireccion(string direccion)
{
    this->direccion = direccion;
}

void Registro::setMail(string eMail)
{
    this->eMail = eMail;
}

void Registro::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Registro::setPoblacion(string poblacion)
{
    this->poblacion = poblacion;
}

void Registro::setPostal(string cPostal)
{
    this->cPostal = cPostal;
}

void Registro::setTelefono(string telefono)
{
    this->telefono = telefono;
}

void Registro::setBuscado(bool buscado)
{
    this->buscado=buscado;
}

void Registro::setId(int i)
{
	this->id = i;
}

int Registro::getId(){

	return this->id;
}


