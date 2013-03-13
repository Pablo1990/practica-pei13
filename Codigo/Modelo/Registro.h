/*
 * Registro.h
 *
 *  Created on: 13/03/2013
 *      Author: pvm22
 */
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

#ifndef REGISTRO_H_
#define REGISTRO_H_

using namespace std;

class Registro {
public:
	Registro();
	virtual ~Registro();
    string getDireccion() const;
    string getMail() const;
    string getNombre() const;
    string getPoblacion() const;
    string getPostal() const;
    string getTelefono() const;
    void setDireccion(string direccion);
    void setMail(string eMail);
    void setNombre(string nombre);
    void setPoblacion(string poblacion);
    void setPostal(string cPostal);
    void setTelefono(string telefono);
	
private:
	string nombre;
	string direccion;
	string poblacion;
	string cPostal;
	string telefono;
	string eMail;
};

#endif /* REGISTRO_H_ */
