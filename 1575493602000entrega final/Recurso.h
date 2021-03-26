#ifndef RECURSO_H_INCLUDED
#define RECURSO_H_INCLUDED

#include<iostream>
using namespace std;

//Esta es la clase padre de las clases, Diesel, Equipo, Cliente y Acero

class Recurso{
protected:
    //Atributos que van a heredar las clases hijas
    string concepto;
    float rendimiento;
public:
    //CONSTRUCTORES
    Recurso();
    Recurso(string nuevo_concepto, float nuevo_rendimiento);
    //DESTRUCTORS
    ~Recurso();
    //SETTERS
    void set_concepto(string nuevo_concepto);
    void set_rendimiento(float nuevo_rendimiento);
    //GETTERS
    string get_concepto();
    float get_rendimiento();

};
//Constructores
Recurso::Recurso(){
    concepto="";
    rendimiento=0;
}

Recurso::Recurso(string nuevo_concepto,float nuevo_rendimiento){
    concepto=nuevo_concepto;
    rendimiento=nuevo_rendimiento;
}

//Destructor
Recurso::~Recurso(){
}


//Todos los setters
void Recurso::set_concepto(string nuevo_concepto){
    concepto=nuevo_concepto;
}


void Recurso::set_rendimiento(float nuevo_rendimiento){
    rendimiento=nuevo_rendimiento;
}

//Todos los getters
string Recurso::get_concepto(){
    return concepto;
}


float Recurso::get_rendimiento(){
    return rendimiento;
}

#endif // RECURSO_H_INCLUDED
