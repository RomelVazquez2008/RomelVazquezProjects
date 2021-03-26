#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include"operacion_minera.h"
#include<iostream>
using namespace std;
//Esta clase se encarga de crear un nuevo plan minero y consulta los ingresos que ha tenido hasta el momento

//Esta clase incluye AGREGACIÓN

//Declaracion de la clase cliente
class Cliente{
public:
    //MÉTODOS
    float consultar_balance();
    void informe_balance();
    //CONSTRUCTOR
    Cliente();
    Cliente(string nuevo_nombre, string nuevo_rfc,float nuevo_presupuesto);
    //DESTRUCTOR
    ~Cliente();
    //SETTERS
    void set_nombre(string nuevo_nombre);
    void set_rfc(string nuevo_rfc);
    void set_presupuesto(float nuevo_presupuesto);
    void set_ingresos(Operacion_Minera llamada_operacion); //AGREGACIÓN
    void set_egresos(Operacion_Minera llamada_operacion); //AGREGACIÓN
    //GETTERS
    string get_nombre();
    string get_rfc();
    float get_presupuesto();
    float get_ingresos();
    float get_egresos();

private:
    //VARIABLES DE INSTANCIA
    string nombre, rfc;
    float presupuesto, ingresos, egresos;
};

//Constructor default que instancia un objeto genérico
Cliente::Cliente(){
    nombre="";
    rfc="";
    presupuesto=0;
    ingresos=0;
    egresos=0;
}

Cliente::Cliente(string nuevo_nombre, string nuevo_rfc,float nuevo_presupuesto){
    nombre=nuevo_nombre;
    rfc=nuevo_rfc;
    presupuesto=nuevo_presupuesto;
    ingresos=0;
    egresos=0;
}

//Destructor del objeto
Cliente::~Cliente(){
}

//TODOS LOS SETTERS
void Cliente::set_nombre(string nuevo_nombre){
    nombre=nuevo_nombre;
}

void Cliente::set_rfc(string nuevo_rfc){
    rfc=nuevo_rfc;
}

void Cliente::set_presupuesto(float nuevo_presupuesto){
    presupuesto=nuevo_presupuesto;
}

void Cliente::set_ingresos(Operacion_Minera llamada_operacion){
    ingresos=llamada_operacion.obtener_total_de_ingresos();
}

void Cliente::set_egresos(Operacion_Minera llamada_operacion){
    egresos=llamada_operacion.obtener_total_de_egresos();
}

//TODOS LOS GETTERS
string Cliente::get_nombre(){
    return nombre;
}

string Cliente::get_rfc(){
    return rfc;
}

float Cliente::get_presupuesto(){
    return presupuesto;
}

float Cliente::get_ingresos(){
    return ingresos;
}

float Cliente::get_egresos(){
    return egresos;
}

//esta función devuelve cuanto dinero se tiene despues de ingresos y egresos
float Cliente::consultar_balance(){
    float balance;
    balance=presupuesto+ingresos-egresos;
    return balance;
}

//esta funcion notifica al usuario si hay perdidas, ganancias o estados de cuenta neutro
void Cliente::informe_balance(){
    if (ingresos>egresos){
        cout<<nombre<<" tiene ganancias de $"<<(ingresos-egresos)<<endl;
    }
    else if (egresos>ingresos){
        cout<<nombre<<" tiene perdidas de $"<<(ingresos-egresos)<<endl;
    }
    else{
        cout<<nombre<<" tiene un estado de resultados neutro $0"<<endl;
    }
}

#endif // CLIENTE_H_INCLUDED
