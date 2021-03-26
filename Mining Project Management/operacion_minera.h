#ifndef OPERACION_MINERA_H_INCLUDED
#define OPERACION_MINERA_H_INCLUDED

#include"control_operativo.h"

#include<iostream>
using namespace std;

//Esta clase esta clase pone un nuevo control operativo y además consulta el avance del proyecto

//Esta clase incluye COMPOSICIÓN

//Declaracion de la clase Operacion Minera
class Operacion_Minera{
public:
    //MÉTODOS
    void estatus_operacion();
    float obtener_total_acero_por_metro_lineal();
    float obtener_total_diesel_por_metro_lineal();
    float obtener_total_horas_hombre_por_metro_lineal();
    float obtener_total_metros_barrenados_por_horas_trabajadas();
    float obtener_total_de_egresos();
    float obtener_total_de_ingresos();
    void agregar_acero(string nuevo_concepto,float nuevo_rendimiento,float nuevo_cantidad,float nuevo_metro_lineal,float nuevo_precio);
    void agregar_diesel(string nuevo_concepto,float nuevo_rendimiento,float nuevo_cantidad,float nuevo_metro_lineal,float nuevo_precio);
    void agregar_equipo(string nuevo_concepto,float nuevo_rendimiento,float nuevo_metros_barrenados,float nuevo_precio, float nuevo_horas_trabajadas);
    void agregar_personal(string nuevo_concepto,float nuevo_rendimiento,float nuevo_horas_hombre,float nuevo_horas_trabajadas,float nuevo_metro_lineal,float nuevo_pago_dia);
    //CONSTRUCTOR
    Operacion_Minera();
    Operacion_Minera(string nuevo_nombre, bool nuevo_estatus);
    //DESTRUCTOR
    ~Operacion_Minera();
    //SETTERS
    void set_nombre(string nuevo_nombre);
    void set_estatus(bool nuevo_estatus);
    void set_control_operativ(string nuevo_nombre);
    //GETTERS
    string get_nombre();
    bool get_estatus();
    Control_Operativo get_control_operativ();

//Declaracion de las variables de instancia
private:
    string nombre;
    bool estatus;
    Control_Operativo control_operativ; //COMPOSICIÓN
};

//Constructor default de los objetoscout<<luis.get_ingresos()<<endl;
Operacion_Minera::Operacion_Minera(){
    nombre="";
    estatus=false;
    control_operativ;
}

Operacion_Minera::Operacion_Minera(string nuevo_nombre, bool nuevo_estatus){
    nombre=nuevo_nombre;
    estatus=nuevo_estatus;
    control_operativ;
}

//destructor de los objetos
Operacion_Minera::~Operacion_Minera(){
}

//TODOS LOS SETTERS
void Operacion_Minera::set_nombre(string nuevo_nombre){
    nombre=nuevo_nombre;
}

void Operacion_Minera::set_estatus(bool nuevo_estatus){
    estatus=nuevo_estatus;
}

void Operacion_Minera::set_control_operativ(string nuevo_nombre){
    Control_Operativo nuevo_control_operativo(nuevo_nombre);
    control_operativ=nuevo_control_operativo;
}

//TODOS LOS GETTERS
string Operacion_Minera::get_nombre(){
    return nombre;
}

bool Operacion_Minera::get_estatus(){
    return estatus;
}


Control_Operativo Operacion_Minera::get_control_operativ(){
    return control_operativ;
}

//Esta funcion devuelve el estado del proyecto, ya sea si se está ejecutando o no
void Operacion_Minera::estatus_operacion(){
    if (estatus==true){
        cout<<"operacion en proceso"<<endl;
    }
    else {
        cout<<"operacion terminada"<<endl;
    }
}

//Las siguientes 4 funciones devulven los totales de los recursos implementados
float Operacion_Minera::obtener_total_acero_por_metro_lineal(){
    float total=0;
    total=control_operativ.total_acero_por_metro_lineal();
    return total;
}

float Operacion_Minera::obtener_total_diesel_por_metro_lineal(){
    float total=0;
    total=control_operativ.total_diesel_por_metro_lineal();
    return total;
}

float Operacion_Minera::obtener_total_horas_hombre_por_metro_lineal(){
    float total=0;
    total=control_operativ.total_horas_hombre_por_metro_lineal();
    return total;
}

float Operacion_Minera::obtener_total_metros_barrenados_por_horas_trabajadas(){
    float total=0;
    total=control_operativ.total_metros_barrenados_por_horas_trabajadas();
    return total;
}

//Las siguientes 2 funciones son de utilidad para que pasen a la clase cliente los datos
float Operacion_Minera::obtener_total_de_egresos(){
    float total=0;
    total=control_operativ.total_de_egresos();
    return total;
}

float Operacion_Minera::obtener_total_de_ingresos(){
    float total=0;
    total=control_operativ.total_de_ingresos();
    return total;
}

//Estas 4 funciones interactuan con la composición de control operativo, para agregar nuevos recursos
void Operacion_Minera::agregar_acero(string nuevo_concepto,float nuevo_rendimiento,float nuevo_cantidad,float nuevo_metro_lineal,float nuevo_precio){
     control_operativ.set_acer(nuevo_concepto,nuevo_rendimiento,nuevo_cantidad,nuevo_metro_lineal,nuevo_precio);
}

void Operacion_Minera::agregar_diesel(string nuevo_concepto,float nuevo_rendimiento,float nuevo_cantidad,float nuevo_metro_lineal,float nuevo_precio){
    control_operativ.set_diese(nuevo_concepto,nuevo_rendimiento,nuevo_cantidad,nuevo_metro_lineal,nuevo_precio);
}

void Operacion_Minera::agregar_equipo(string nuevo_concepto,float nuevo_rendimiento,float nuevo_metros_barrenados,float nuevo_precio, float nuevo_horas_trabajadas){
    control_operativ.set_equip(nuevo_concepto,nuevo_rendimiento,nuevo_metros_barrenados,nuevo_precio,nuevo_horas_trabajadas);
}

void Operacion_Minera::agregar_personal(string nuevo_concepto,float nuevo_rendimiento,float nuevo_horas_hombre,float nuevo_horas_trabajadas,float nuevo_metro_lineal,float nuevo_pago_dia){
    control_operativ.set_persona(nuevo_concepto,nuevo_rendimiento,nuevo_horas_hombre,nuevo_horas_trabajadas,nuevo_metro_lineal,nuevo_pago_dia);
}

#endif // OPERACION_MINERA_H_INCLUDED
