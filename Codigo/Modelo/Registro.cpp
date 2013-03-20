/*
 * Registro.cpp
 *
 *  Created on: 13/03/2013
 *      Author: pvm22
 */

#include "Registro.h"

Registro::Registro() {
	// TODO Auto-generated constructor stub
	nombre="";
	eMail="";
	poblacion="";
	cPostal="";
	telefono="";
	direccion="";
}

Registro::Registro(string n, string mail, string pob, string cp, string tel, string dir) {
	// TODO Auto-generated constructor stub
	nombre=n;
	eMail=mail;
	poblacion=pob;
	cPostal=cp;
	telefono=tel;
	direccion=dir;
}

Registro::Registro(const Registro& reg)
{
  if (this != &reg) {
	direccion = reg.direccion;
	eMail = reg.eMail;
	nombre = reg.nombre;
	poblacion = reg.poblacion;
	cPostal = reg.cPostal;
	telefono = reg.telefono;
  }
}

Registro::~Registro() {
	// TODO Auto-generated destructor stub
}

Registro& Registro::operator =(const Registro& reg)
{
  if (this != &reg) {
	direccion = reg.direccion;
	eMail = reg.eMail;
	nombre = reg.nombre;
	poblacion = reg.poblacion;
	cPostal = reg.cPostal;
	telefono = reg.telefono;
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



