#ifndef ACERO_H_INCLUDED
#define ACERO_H_INCLUDED

#include<iostream>
using namespace std;
#include"Recurso.h"

//Clase hija que hereda de la clase Recurso

class Acero: public Recurso{
private:
    //ATRIBUTOS
    float cantidad;
    float metro_lineal;
    float precio;
public:
    //METODOS
    float obtiene_ingreso();
    float obtiene_acero_por_metro_lineal();

    //CONSTRUCTORES
    Acero();
    Acero(string nuevo_concepto,float nuevo_rendimiento,float nuevo_cantidad,float nuevo_metro_lineal,float nuevo_precio);
    //DESTRUCTOR
    ~Acero();
    //SETTERS
    void set_cantidad(float nuevo_cantidad);
    void set_metro_lineal(float nuevo_metro_lineal);
    void set_precio(float nuevo_precio);
    //GETTERS
    float get_cantidad();
    float get_metro_lineal();
    float get_precio();
};

//Constructores
Acero::Acero(){
    cantidad=0;
    metro_lineal=0;
    precio=0;
}

Acero::Acero(string nuevo_concepto,float nuevo_rendimiento,float nuevo_cantidad,float nuevo_metro_lineal,float nuevo_precio):Recurso(nuevo_concepto,nuevo_rendimiento){
    cantidad=nuevo_cantidad;
    metro_lineal=nuevo_metro_lineal;
    precio=nuevo_precio;
}

//Destructores
Acero::~Acero(){
}

//Todos los setters
void Acero::set_cantidad(float nuevo_cantidad){
    cantidad=nuevo_cantidad;
}

void Acero::set_metro_lineal(float nuevo_metro_lineal){
    metro_lineal=nuevo_metro_lineal;
}

void Acero::set_precio(float nuevo_precio){
    precio=nuevo_precio;
}

//Todos los getters
float Acero::get_cantidad(){
    return cantidad;
}

float Acero::get_metro_lineal(){
    return metro_lineal;
}

float Acero::get_precio(){
    return precio;
}

//METODOS
//Esta funcion devuelve los ingresos por su trabajo realizado
float Acero::obtiene_ingreso(){
    float ingreso=0;
    ingreso=rendimiento*(metro_lineal/cantidad);
    return ingreso;
}

//Esta función devuelve el acero por los metros lineales
float Acero::obtiene_acero_por_metro_lineal(){
    float acero_por_metro_lineal=0;
    acero_por_metro_lineal=cantidad/metro_lineal;
    return acero_por_metro_lineal;
}


#endif // ACERO_H_INCLUDED
