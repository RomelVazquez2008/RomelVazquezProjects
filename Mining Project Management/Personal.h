#ifndef PERSONAL_H_INCLUDED
#define PERSONAL_H_INCLUDED
#include<iostream>
#include"Recurso.h"
using namespace std;

//Clase hija que hereda de la clase Recurso

class Personal: public Recurso{
private:
    //ATRIBUTOS
    float horas_hombre, horas_trabajadas, metro_lineal, pago_dia;
public:
    //METODOS
    float obtiene_ingreso();
    float obtiene_horas_hombre_por_metro_lineal();

    //CONSTRUCTOR
    Personal();
    ~Personal();
    //DESTRUCTOR
    Personal(string nuevo_concepto,float nuevo_rendimiento,float nuevo_horas_hombre,float nuevo_horas_trabajadas,float nuevo_metro_lineal,float nuevo_pago_dia);

    //SETTERS
    void set_horas_hombre(float nuevo_horas_hombre);
    void set_horas_trabajadas(float nuevo_horas_trabajadas);
    void set_metro_lineal(float nuevo_metro_lineal);
    void set_pago_dia(float nuevo_pago_dia);
    //GETTERS
    float get_horas_hombre();
    float get_horas_trabajadas();
    float get_metro_lineal();
    float get_pago_dia();
};

//Constructores
Personal::Personal(){
    horas_hombre=0;
    horas_trabajadas=0;
    metro_lineal=0;
    pago_dia=0;
}

Personal::Personal(string nuevo_concepto,float nuevo_rendimiento,float nuevo_horas_hombre,float nuevo_horas_trabajadas,float nuevo_metro_lineal,float nuevo_pago_dia){
    concepto=nuevo_concepto;
    rendimiento=nuevo_rendimiento;
    horas_hombre=nuevo_horas_hombre;
    horas_trabajadas=nuevo_horas_trabajadas;
    metro_lineal=nuevo_metro_lineal;
    pago_dia=nuevo_pago_dia;
}

//Destructores
Personal::~Personal(){
}

//Todos los setters
void Personal::set_horas_hombre(float nuevo_horas_hombre){
    horas_hombre=nuevo_horas_hombre;
}

void Personal::set_horas_trabajadas(float nuevo_horas_trabajadas){
    horas_trabajadas=nuevo_horas_trabajadas;
}

void Personal::set_metro_lineal(float nuevo_metro_lineal){
    metro_lineal=nuevo_metro_lineal;
}

void Personal::set_pago_dia(float nuevo_pago_dia){
    pago_dia=nuevo_pago_dia;
}

//Todos los getters
float Personal::get_horas_hombre(){
    return horas_hombre;
}

float Personal::get_horas_trabajadas(){
    return horas_trabajadas;
}

float Personal::get_metro_lineal(){
    return metro_lineal;
}

float Personal::get_pago_dia(){
    return pago_dia;
}

//METODOS
//Esta funcion devuelve los ingresos por su trabajo realizado
float Personal::obtiene_ingreso(){
    float ingreso=0;
    ingreso=rendimiento*(metro_lineal/horas_trabajadas);
    return ingreso;
}

//Esta función devuelve las horas hombre por metro lineal
float Personal::obtiene_horas_hombre_por_metro_lineal(){
    float horas_hombre_por_metro_lineal=0;
    horas_hombre_por_metro_lineal=horas_hombre/metro_lineal;
    return horas_hombre_por_metro_lineal;
}

#endif // PERSONAL_H_INCLUDED
