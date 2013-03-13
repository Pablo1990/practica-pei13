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

#ifndef _MODELO_H_
#define _MODELO_H_

#include <cstdlib>
#include <list>
#include <stddef.h>

/*
 * Clase:     Modelo
 * Fecha:     Tue Sep 12 18:30:54 CEST 2000
 * Autor:     Antonio-M. Corbi Bellot
 * Email:     acorbi@dlsi.ua.es
 * Proposito: La clase base de los modelos.
 */

//class Vista;
using namespace std;

/*!
 * \class Modelo
 * \brief Es la clase base de los modelos en este ejemplo.
 */
class Modelo
{
  //friend class Vista;
  // Parte publica
public:

  //! Constructor por defecto
  Modelo();
  //! Constructor de copia
  Modelo(const Modelo& un_modelo);

  //! Destructor
  ~Modelo();

  //! Asignacion
  Modelo & operator =(const Modelo& un_modelo);

  /*!
   * \brief Actualiza las vistas sobre este modelo.
   *
   * Excepto la que se pasa como parametro, por defecto el par�metro es
   * NULL y en ese caso se actualizan todas.
   *
   * Es �til cuando una vista actualiza el modelo y solicita a este
   * que actualice todas sus vistas asociadas, en este caso puede
   * indicar que actualice a todas menos a ella que ya muestra el
   * estado en el que quedara el modelo.
   */
  //void actualizar_vistas(Vista* v = NULL);


  // Parte protegida
protected:
  //! La lista de vistas asociadas con este modelo.
  //list<Vista*> lv;

  /*! 
   * \brief A�ade una nueva vista para este modelo.
   *
   * \param v La vista a a�adir al modelo.
   */
  //void anyadir_vista(Vista* v) { lv.push_back(v); }

  // Parte privada
private:

};

#endif
