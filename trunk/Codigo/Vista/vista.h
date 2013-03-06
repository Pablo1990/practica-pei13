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

#ifndef _VISTA_H_
#define _VISTA_H_

/*
 * Clase:     Vista
 * Fecha:     Tue Sep 12 16:42:18 CEST 2000
 * Autor:     Antonio-M. Corbi Bellot
 * Email:     acorbi@dlsi.ua.es
 * Proposito: La clase base de las vistas.
 */

class Modelo;

/*!
 * \class Vista
 * \brief Es la clase base de las vistas en este ejemplo.
 */
class Vista
{
  // Parte publica
public:

  /*! 
   * \brief Constructor por defecto.
   *
   * El modelo sera nulo
   */
  Vista() { su_modelo = 0; }

  /*! 
   * \brief Constructor por defecto.
   *
   * \param m El modelo con el que se asocia esta vista.
   */
  Vista(Modelo& m);
  //! Constructor de copia
  Vista(const Vista& una_vista);

  //! Destructor
  ~Vista();

  //! Asignacion
  Vista & operator =(const Vista& una_vista);
  
  //! Cambiamos el modelo asociado.
  void poner_modelo (Modelo* m);

  /*! 
   * \brief Actualización de la vista ordenada por el modelo.
   *
   * Es virtual pura ya que son las vistas derivadas de esta clase las
   * que deben saber cómo actualizarse.
   */
  virtual void actualizar() = 0;

  /*!
   * \brief Actualizacion del modelo ordenada por la vista.
   *
   * Tiene sentido cuando el usuario actuando sobre la vista modifica
   * datos que han de reflejarse posteriormente en el modelo.
   *
   * Por defecto le dice al modelo que actualice sus otras posibles
   * vistas sobre el. Tiene sentido que se llame en ultimo lugar
   * dentro del propio metodo redefinido en una clase derivada.
   */
  virtual void actualizar_modelo();

  // Parte protegida
protected:
  //! El modelo al que se asocia esta vista.
  Modelo* su_modelo;

  // Parte privada
private:

};

#endif
