#ifndef DIESEL_H_INCLUDED
#define DIESEL_H_INCLUDED

#include<iostream>
using namespace std;
#include"Recurso.h"

//Clase hija que hereda de la clase Recurso

class Diesel: public Recurso{
private:
    //ATRIBUTOS
    float cantidad,metro_lineal,precio;
public:
    //METODOS
    float obtiene_ingreso();
    float obtiene_diesel_por_metro_lineal();

    //CONSTRUCTORES
    Diesel();
    Diesel(string nuevo_concepto,float nuevo_rendimiento,float nuevo_cantidad,float nuevo_metro_lineal,float nuevo_precio);
    //DESTRUCTORS
    ~Diesel();
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
Diesel::Diesel(){
    cantidad=0;
    metro_lineal=0;
    precio=0;
}

Diesel::Diesel(string nuevo_concepto,float nuevo_rendimiento,float nuevo_cantidad,float nuevo_metro_lineal,float nuevo_precio){
    concepto=nuevo_concepto;
    rendimiento=nuevo_rendimiento;
    cantidad=nuevo_cantidad;
    metro_lineal=nuevo_metro_lineal;
    precio=nuevo_precio;
}

//Destructores
Diesel::~Diesel(){
}

//Todos los setters
void Diesel::set_cantidad(float nuevo_cantidad){
    cantidad=nuevo_cantidad;
}

void Diesel::set_metro_lineal(float nuevo_metro_lineal){
    metro_lineal=nuevo_metro_lineal;
}

void Diesel::set_precio(float nuevo_precio){
    precio=nuevo_precio;
}

//Todos los getters
float Diesel::get_precio(){
    return precio;
}

float Diesel::get_metro_lineal(){
    return metro_lineal;
}

float Diesel::get_cantidad(){
    return cantidad;
}

//METODOS
//Esta funcion devuelve los ingresos por su trabajo realizado
float Diesel::obtiene_ingreso(){
    float ingreso=0;
    ingreso=rendimiento*(metro_lineal/cantidad);
    return ingreso;
}

//Esta función devuelve el diesel por los metros lineales
float Diesel::obtiene_diesel_por_metro_lineal(){
    float diesel_por_metro_lineal=0;
    diesel_por_metro_lineal=cantidad/metro_lineal;
    return diesel_por_metro_lineal;
}

#endif // DIESEL_H_INCLUDED
