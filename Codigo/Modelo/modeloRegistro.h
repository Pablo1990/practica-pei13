#ifndef _MODELOREGISTRO_H_
#define _MODELOREGISTRO_H_

#include <string>
#include <vector>
#include <cstdlib>
#include <list>
#include <stddef.h>
#include "Registro.h"

class Registro;
using namespace std;

/*!
 * \class ModeloRegistro
 * \brief Es el modelo de una persona en este ejemplo.
 */
class ModeloRegistro
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
  void CrearRegistro(string , string , string , string, string , string );
  bool EscribirFichero(const char * );
  bool LeerFichero(char*);
  bool Modificar(int, string, string, string, string, string, string);
  void Imprimir(int);
  void ImprimirRegistro(Registro*);
  void Buscar(const string);
  bool Borrar(int);
  void ActualizarIds();
  std::vector<string> GetRegistro(int);
  int GetNumRegistros();
  std::vector<Registro*> GetRegistrosBuscados();

  // Parte protegida
protected:
 list<Registro*> lr;
 list<Registro*> busqueda;
 //void anyadirRegistro(Registro r) {lr.push_back(r); }
  // Parte privada
private:

};

#endif
