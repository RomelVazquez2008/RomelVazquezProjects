#ifndef EQUIPO_H_INCLUDED
#define EQUIPO_H_INCLUDED

#include<iostream>
#include"Recurso.h"
using namespace std;

//Clase hija que hereda de la clase Recurso

class Equipo: public Recurso{
private:
    //ATRIBUTOS
    float metros_barrenados,precio, horas_trabajadas;
public:
    //METODOS
    float obtiene_ingreso();
    float obtiene_metros_barrenados_por_horas_trabajadas();

    //CONSTRUCTORES
    Equipo();
    Equipo(string nuevo_concepto,float nuevo_rendimiento,float nuevo_metros_barrenados,float nuevo_precio, float nuevo_horas_trabajadas);
    //DESTRUCTORS
    ~Equipo();

    //SETTERS
    void set_metros_barrenados(float nuevo_metros_barrenados);
    void set_precio(float nuevo_precio);
    void set_horas_trabajadas(float nuevo_horas_trabajadas);
    //GETTERS
    float get_metros_barrenados();
    float get_precio();
    float get_horas_trabajadas();
};

//Constructores
Equipo::Equipo(){
    metros_barrenados=0;
    precio=0;
    horas_trabajadas=0;
}

Equipo::Equipo(string nuevo_concepto,float nuevo_rendimiento,float nuevo_metros_barrenados,float nuevo_precio,float nuevo_horas_trabajadas){
    concepto=nuevo_concepto;
    metros_barrenados=nuevo_metros_barrenados;
    precio=nuevo_precio;
    horas_trabajadas=nuevo_horas_trabajadas;
    rendimiento=nuevo_rendimiento;
}

//Destructores
Equipo::~Equipo(){
}

//Todos los setters
void Equipo::set_metros_barrenados(float nuevo_metros_barrenados){
    metros_barrenados=nuevo_metros_barrenados;
}

void Equipo::set_precio(float nuevo_precio){
    precio=nuevo_precio;
}

void Equipo::set_horas_trabajadas(float nuevo_horas_trabajadas){
    horas_trabajadas=nuevo_horas_trabajadas;
}

//Todos los getters
float Equipo::get_metros_barrenados(){
    return metros_barrenados;
}

float Equipo::get_precio(){
    return precio;
}

float Equipo::get_horas_trabajadas(){
    return horas_trabajadas;
}

//METODOS
//Esta funcion devuelve los ingresos por su trabajo realizado
float Equipo::obtiene_ingreso(){
    float ingreso=0;
    ingreso=rendimiento*(metros_barrenados/horas_trabajadas);
    return ingreso;
}

//Esta función devuelve los metros barrenados por horas trabajadas
float Equipo::obtiene_metros_barrenados_por_horas_trabajadas(){
    float metros_barrenados_por_horas_trabajadas=0;
    metros_barrenados_por_horas_trabajadas=metros_barrenados/horas_trabajadas;
    return metros_barrenados_por_horas_trabajadas;
}

#endif // EQUIPO_H_INCLUDED
