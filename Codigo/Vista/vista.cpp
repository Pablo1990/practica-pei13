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
 * Fecha: Tue Sep 12 16:42:18 CEST 2000
 * Autor: Antonio-M. Corbi Bellot
 * Email: acorbi@dlsi.ua.es
 */

#include "vista.h"
#include "modelo.h"

/*
 * Constructor por defecto
 */
Vista::Vista(Modelo& m)
{
  su_modelo = &m;

  // La vista se anyade automaticamente a su modelo.
  su_modelo -> anyadir_vista(this);
}

/*
 * Constructor de copia
 */
Vista::Vista(const Vista& una_vista)
{
  su_modelo = una_vista.su_modelo;
}


/*
 * Destructor
 */
Vista::~Vista()
{

}

/*
 * Asignacion
 */
Vista & Vista::operator =(const Vista& una_vista)
{
  if (this != &una_vista) {
    su_modelo = una_vista.su_modelo;
  }
  return *this;
}

/**
 * actualizar_modelo()
 * El modelo ha cambiado y se lo dice a las demas vistas sobre el.
 */
void Vista::actualizar_modelo()
{
   su_modelo -> actualizar_vistas(this);
}

void Vista::poner_modelo (Modelo* m) { 
  su_modelo = m;
  // La vista se anyade automaticamente a su modelo.
  su_modelo->anyadir_vista(this);
  actualizar(); 
}
