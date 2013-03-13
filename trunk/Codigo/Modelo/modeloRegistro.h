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

#ifndef _MODELOREGISTRO_H_
#define _MODELOREGISTRO_H_

#include <string>
#include "modelo.h"

class Registro;
using namespace std;

/*
 * Clase:     ModeloRegistro
 * Fecha:     Tue Sep 12 16:36:32 CEST 2000
 * Autor:     Antonio-M. Corbi Bellot
 * Email:     acorbi@dlsi.ua.es
 * Proposito: Representa el modelo de una persona.
 */

/*!
 * \class ModeloRegistro
 * \brief Es el modelo de una persona en este ejemplo.
 */
class ModeloRegistro : public Modelo
{
  friend class Registro;
  // Parte publica
public:

  /*!
   * \brief Constructor por defecto. Necesita nombre y edad.
   * \param n El nombre de la persona.
   * \param e La edad de la persona.
   */
  ModeloRegistro();
  //! Constructor de copia
  ModeloRegistro(const ModeloRegistro &un_modeloRegistro);

  //! Destructor
  ~ModeloRegistro();

  //! Asignacion
  ModeloRegistro & operator =(const ModeloRegistro &un_modeloRegistro);

  void procesarRegistro(string[]);

  bool LeerFichero(char*);

  void Imprimir();

  // Parte protegida
protected:
  //! Nombre de la persona.
 list<Registro*> lr;
 void anyadirRegistro(Registro* r) { lr.push_back(r); }
  // Parte privada
private:

};

#endif
