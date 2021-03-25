#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include <iostream>
using namespace std;

/*
* Proyecto: Simulaci�n rappy
* Romel Aldair V�zquez Molina
* A01700519
* 11/06/2020
* versi�n : Final
*/

// Clase Empleado
//CLASE PADRE Y ABSTRACTA, QUE HEREDAN CHEF Y MESERO
class Empleado{
  protected:
    //ATRIBUTOS
    string nombre;
  public:
    //CONSTRUCTORES
    Empleado();
    Empleado(string nuevo_nombre);
    //DESTRUCTOR
    ~Empleado();
    //METODOS
    virtual void atender_orden(int indice)=0;   //Definici�n de clase abstracta
    virtual void descripcion()=0; //Definici�n de clase abstracta
    //GETTER
    string get_nombre();
};
/**
 * Constructor defalut de la clase Empleado que permite crear un objeto vac�o.
 *
 * Crea un objeto vac�o en parametros, para despu�s ser llenado con setters.
 *
 * @param
 * @return
 */
Empleado::Empleado(){
  nombre="";
}

/**
 * Constructor con atributos predefinidos de la clase Empleado.
 *
 * Crea un objeto con los par�metros que manda el usuario (nombre),
 *
 * @param  string nuevo_nombre del empleado
 * @return
 */
Empleado::Empleado(string nuevo_nombre){
  nombre=nuevo_nombre;
}

/**
 * Destructor de la clase Empleado
 *
 * Permite destruir el objeto existente, para ahorrar recursos de memoria
 *
 * @param
 * @return
 */
Empleado::~Empleado(){
}

/**
 * get_nombre retorna el valor del nombre de esta clase
 *
 * Devuelve el valor actual del atributo de nombre de la clase Empleado
 *
 * @param
 * @return string nombre
 */
string Empleado::get_nombre(){
    return nombre;
}

#endif
