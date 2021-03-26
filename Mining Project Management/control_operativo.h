#ifndef CONTROL_OPERATIVO_H_INCLUDED
#define CONTROL_OPERATIVO_H_INCLUDED

#include "Equipo.h"
#include "Personal.h"
#include "Acero.h"
#include "Diesel.h"
#include<iostream>
using namespace std;

//Esta clase añade nuevos recursos y además instancia sus valores inciales

//Esta clase incluye COMPOSICIÓN

//Declaración de la clase Control Operativo
class Control_Operativo{
public:
    //MÉTODOS
    void persona_en_cargo();
    float total_de_egresos();
    float total_de_ingresos();
    float total_acero_por_metro_lineal();
    float total_diesel_por_metro_lineal();
    float total_horas_hombre_por_metro_lineal();
    float total_metros_barrenados_por_horas_trabajadas();
    //CONSTRUCTOR
    Control_Operativo();
    Control_Operativo(string nuevo_nombre);
    //DESTRUCTOR
    ~Control_Operativo();
    //SETTERS
    void set_nombre(string nuevo_nombre);
    void set_indice_diese(int nuevo_indice_diese);
    void set_indice_equip(int nuevo_indice_equip);
    void set_indice_persona(int nuevo_indice_persona);
    void set_indice_acer(int nuevo_indice_acer);
    void set_ingresos(float nuevo_ingresos);
    void set_egresos(float nuevo_egresos);
    void set_diese(string nuevo_concepto,float nuevo_rendimiento,float nuevo_cantidad,float nuevo_metro_lineal,float nuevo_precio);
    void set_acer(string nuevo_concepto,float nuevo_rendimiento,float nuevo_cantidad,float nuevo_metro_lineal,float nuevo_precio);
    void set_persona(string nuevo_concepto,float nuevo_rendimiento,float nuevo_horas_hombre,float nuevo_horas_trabajadas,float nuevo_metro_lineal,float nuevo_pago_dia);
    void set_equip(string nuevo_concepto,float nuevo_rendimiento,float nuevo_metros_barrenados,float nuevo_precio, float nuevo_horas_trabajadas);
    //GETTERS
    string get_nombre();
    int get_indice_diese();
    int get_indice_equip();
    int get_indice_persona();
    int get_indice_acer();
    float get_ingresos();
    float get_egresos();
    Diesel get_diese(int main_indice);
    Acero get_acer(int main_indice);
    Personal get_persona(int main_indice);
    Equipo get_equip(int main_indice);
//Variables de instancia
private:
    string nombre;
    int indice_diese, indice_equip, indice_persona, indice_acer;
    float ingresos, egresos;
    //COMPOSICIÓN
    Equipo equip[50];
    Personal persona[50];
    Acero acer[50];
    Diesel diese[50];
};

//Constructor default de la clase
Control_Operativo::Control_Operativo(){
    nombre="";
    indice_diese=0;
    indice_equip=0;
    indice_persona=0;
    indice_acer=0;
    ingresos=0;
    egresos=0;
    equip[0];
    persona[0];
    acer[0];
    diese[0];
}

Control_Operativo::Control_Operativo(string nuevo_nombre){
    nombre=nuevo_nombre;
    indice_diese=0;
    indice_equip=0;
    indice_persona=0;
    indice_acer=0;
    ingresos=0;
    egresos=0;
    equip[0];
    persona[0];
    acer[0];
    diese[0];
}

//destructor default
Control_Operativo::~Control_Operativo(){
}

//TODOS LOS SETTERS
void Control_Operativo::set_nombre(string nuevo_nombre){
    nombre=nuevo_nombre;
}

void Control_Operativo::set_indice_diese(int nuevo_indice_diese){
    indice_diese=nuevo_indice_diese;
}

void Control_Operativo::set_indice_equip(int nuevo_indice_equip){
    indice_equip=nuevo_indice_equip;
}

void Control_Operativo::set_indice_persona(int nuevo_indice_persona){
    indice_persona=nuevo_indice_persona;
}

void Control_Operativo::set_indice_acer(int nuevo_indice_acer){
    indice_acer=nuevo_indice_acer;
}

void Control_Operativo::set_ingresos(float nuevo_ingresos){
    ingresos=nuevo_ingresos;
}

void Control_Operativo::set_egresos(float nuevo_egresos){
    egresos=nuevo_egresos;
}

void Control_Operativo::set_diese(string nuevo_concepto,float nuevo_rendimiento,float nuevo_cantidad,float nuevo_metro_lineal,float nuevo_precio){
    Diesel nuevo_diesel(nuevo_concepto,nuevo_rendimiento,nuevo_cantidad,nuevo_metro_lineal,nuevo_precio);
    diese[indice_diese]=nuevo_diesel;
    indice_diese++;
}

void Control_Operativo::set_acer(string nuevo_concepto,float nuevo_rendimiento,float nuevo_cantidad,float nuevo_metro_lineal,float nuevo_precio){
    Acero nuevo_acero(nuevo_concepto,nuevo_rendimiento,nuevo_cantidad,nuevo_metro_lineal,nuevo_precio);
    acer[indice_acer]=nuevo_acero;
    indice_acer++;
}

void Control_Operativo::set_persona(string nuevo_concepto,float nuevo_rendimiento,float nuevo_horas_hombre,float nuevo_horas_trabajadas,float nuevo_metro_lineal,float nuevo_pago_dia){
    Personal nuevo_personal(nuevo_concepto,nuevo_rendimiento,nuevo_horas_hombre,nuevo_horas_trabajadas,nuevo_metro_lineal,nuevo_pago_dia);
    persona[indice_persona]=nuevo_personal;
    indice_persona++;
}
void Control_Operativo::set_equip(string nuevo_concepto,float nuevo_rendimiento,float nuevo_metros_barrenados,float nuevo_precio, float nuevo_horas_trabajadas){
    Equipo nuevo_equipo(nuevo_concepto,nuevo_rendimiento,nuevo_metros_barrenados,nuevo_precio,nuevo_horas_trabajadas);
    equip[indice_equip]=nuevo_equipo;
    indice_equip++;
}

//TODOS LOS GETTERS
string Control_Operativo::get_nombre(){
    return nombre;
}

int Control_Operativo::get_indice_diese(){
    return indice_diese;
}

int Control_Operativo::get_indice_equip(){
    return indice_equip;
}

int Control_Operativo::get_indice_persona(){
    return indice_persona;
}

int Control_Operativo::get_indice_acer(){
    return indice_acer;
}

float Control_Operativo::get_ingresos(){
    return ingresos;
}

float Control_Operativo::get_egresos(){
    return egresos;
}

Diesel Control_Operativo::get_diese(int main_indice){
    return diese[main_indice];
}

Acero Control_Operativo::get_acer(int main_indice){
    return acer[main_indice];
}

Personal Control_Operativo::get_persona(int main_indice){
    return persona[main_indice];
}

Equipo Control_Operativo::get_equip(int main_indice){
    return equip[main_indice];
}

//Esta función devuelve la persona que está en cargo, con su debido identificador
void Control_Operativo::persona_en_cargo(){
    cout<<"La persona en cargo es: "<<nombre<<endl;
}

//Esta función itera en cada uno de los recursos, para obtener los egresos
float Control_Operativo::total_de_egresos(){
    int indice;
    float total=0;
    for (indice=0; indice<indice_acer; indice++){
        total=total+acer[indice].get_precio();
    }
    indice=0;
    for (indice=0; indice<indice_diese; indice++){
        total=total+diese[indice].get_precio();
    }
    indice=0;
    for (indice=0; indice<indice_equip; indice++){
        total=total+equip[indice].get_precio();
    }
    indice=0;
    for (indice=0; indice<indice_persona; indice++){
        total=total+persona[indice].get_pago_dia();
    }
    return total;
}

//Esta función itera en cada uno de los recursos, para obtener los ingresos
float Control_Operativo::total_de_ingresos(){
    int indice;
    float total=0;
    for (indice=0; indice<indice_acer; indice++){
        total=total+acer[indice].obtiene_ingreso();
    }
    indice=0;
    for (indice=0; indice<indice_diese; indice++){
        total=total+diese[indice].obtiene_ingreso();
    }
    indice=0;
    for (indice=0; indice<indice_equip; indice++){
        total=total+equip[indice].obtiene_ingreso();
    }
    indice=0;
    for (indice=0; indice<indice_persona; indice++){
        total=total+persona[indice].obtiene_ingreso();
    }
    return total;
}

//Las siguiente 4 funciones son para pasar el total de los indicadores de cada recurso
float Control_Operativo::total_acero_por_metro_lineal(){
    float total=0;
    int indice;
        for (indice=0; indice<indice_acer; indice++){
        total=total+acer[indice].obtiene_acero_por_metro_lineal();
    }
    return total;
}

float Control_Operativo::total_diesel_por_metro_lineal(){
    float total=0;
    int indice;
    for (indice=0; indice<indice_diese; indice++){
        total=total+diese[indice].obtiene_diesel_por_metro_lineal();
    }
    return total;
}

float Control_Operativo::total_horas_hombre_por_metro_lineal(){
    float total=0;
    int indice;
    for (indice=0; indice<indice_persona; indice++){
        total=total+persona[indice].obtiene_horas_hombre_por_metro_lineal();
    }
    return total;
}

float Control_Operativo::total_metros_barrenados_por_horas_trabajadas(){
    float total=0;
    int indice;
        for (indice=0; indice<indice_equip; indice++){
        total=total+equip[indice].obtiene_metros_barrenados_por_horas_trabajadas();
    }
    return total;
}

#endif // CONTROL_OPERATIVO_H_INCLUDED
