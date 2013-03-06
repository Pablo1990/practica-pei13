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
 * Fecha: Tue Sep 12 18:30:54 CEST 2000
 * Autor: Antonio-M. Corbi Bellot
 * Email: acorbi@dlsi.ua.es
 */

#include <iostream>
#include "modelo.h"
#include "vista.h"

using namespace std;

/*
 * Constructor por defecto
 */
Modelo::Modelo()
{

}

/*
 * Constructor de copia
 */
Modelo::Modelo(const Modelo& un_modelo)
{

}


/*
 * Destructor
 */
Modelo::~Modelo()
{

}

/*
 * Asignacion
 */
Modelo & Modelo::operator =(const Modelo& un_modelo)
{
  if (this != &un_modelo) {
    lv.erase(lv.begin(), lv.end());
    lv = un_modelo.lv;
  }
}

/*
 * actualizar_vistas
 */
void Modelo::actualizar_vistas(Vista* v)
{
  list<Vista*>::iterator t;

  for(t = lv.begin(); t != lv.end(); t++)
    if ((*t) != v) {
      (*t)->actualizar();
      cout << "Actualizo " << *t << endl;
    } else cout << "No actualizo " << *t << endl;
}
