#include <iostream>
#include <string>
#include "Cliente.h"

using namespace std;

//Romel Aldair Vázquez Molina
//A01700519
//14/11/2019
//Proyecto software Mineria

//OBJETIVO DEL PROGRAMA: Este programa tiene la intención de mejorar la administración en diferente proyectos mineros, ya que se pueden notificar
//los avances en la operacion (por medio de la clase Operacion Minera), así como obtener los rendimientos económicos (por medio de la clase Cliente).
//Por otra parte habrá un encargo de capturar los datos (clase Control Operativo), para notificar a las demás clases.

//ENTREGA FINAL

//Esta función valida que los numeros que ingrese el usuario sean mayot o igguales a 0, de otra forma
//regresa mensaje de error
float validador_positivos(float numero){
    while (numero<0){
        cout<<"Error, ingrese un numero mayor o igual a 0"<<endl;
        cin>>numero;
    }
    return (numero);
}

//Esta función valida que el usuarios ingrese 1 o 0, de otra forma regresa mensaje de error
bool validar_estado(int numero){
    while (true){
        if (numero==1){
            break;
            }
        if (numero==0){
            break;
            }
        cout<<"Error, ingrese una opcion valida (1=En curso, 0=Terminada/Cancelada)"<<endl;
        cin>>numero;
        }
    if (numero==1){
        return true;
        }
    else{
        return false;
        }
}

//Esta función imprime el primer menú
void cargar_menu_de_datos(){
    cout<<"Seleccione una opcion"<<endl;
    cout<<"1. Cargar ejemplo"<<endl;
    cout<<"2. Crear nuevo"<<endl;
    cout<<"3. Salir"<<endl;
}

//Esta función imprime el sub menú
void cargar_menu_de_crear_operacion(){
    cout<<endl;
    cout<<"Seleccione una opcion"<<endl;
    cout<<"1. Crear nuevo plan minero"<<endl;
    cout<<"2. Crear nuevo control operativo"<<endl;
    cout<<"3. Agregar diesel"<<endl;
    cout<<"4. Agregar acero"<<endl;
    cout<<"5. Agregar equipo"<<endl;
    cout<<"6. Agregar personal"<<endl;
    cout<<"7. Consultar total de acero por metro lineal"<<endl;
    cout<<"8. Consultar total de diesel por metro lineal"<<endl;
    cout<<"9. Consultar total horas hombre por metro lineal"<<endl;
    cout<<"10. Consultar total metros barrenados por horas trabajadas"<<endl;
    cout<<"11. Consultar ingresos totales"<<endl;
    cout<<"12. Consultar egresos totales"<<endl;
    cout<<"13. Consultar balance total"<<endl;
    cout<<"14. Consultar informe de balance"<<endl;
    cout<<"15. Consultar estado de plan minero"<<endl;
    cout<<"16. Regresar"<<endl;
}



int main(){
//Esto es para cargar el ejemplo
Cliente luis("Luis Marquez","VAMR00",10000);
Operacion_Minera tajo("Tajo 5 de mayo",true);
tajo.set_control_operativ("control 1");
tajo.agregar_diesel("Diesel 3 de mayo",105,100,100,1000);
tajo.agregar_diesel("Diesel 4 de mao",105,500,100,1000);
tajo.agregar_acero("Acero 3 de mayo",20,100,50,960);
tajo.agregar_equipo("Barredora 10 GTX 1060",590,530,740,260);
tajo.agregar_personal("Minero Jorge",130,960,530,480,250);

//variables de instancia
int opcion_datos=0, opcion_menu=0;
int nuevo_estado=0;
string nuevo_nombre,nuevo_nombre_operacion,nuevo_rfc, nombre_control, concepto_diesel, concepto_acero, concepto_equipo,concepto_personal;
float nuevo_presupuesto;
bool estado_operacion=false, estado_control=false;
float rendimiento_diesel, cantidad_diesel, metro_lineal_diesel, precio_diesel;
float rendimiento_acero,cantidad_acero,metro_lineal_acero,precio_acero;
float rendimiento_equipo,metros_barrenados_equipo,precio_equipo,horas_trabajadas_equipo;
float rendimiento_personal,horas_hombre_personal,horas_trabajadas_personal,metro_lineal_personal,pago_dia_personal;
Operacion_Minera operacion_usuario;

//Aquí inicia el programa
while (true){
cargar_menu_de_datos();
cin>>opcion_datos;
//Esta opción deja al usuario ver el ejemplo, cargado con 5 objetos de recursos,
//De igual forma puede añadir nuevos y consultar sus estados
if (opcion_datos==1){
    estado_operacion=true;
    estado_control=true;
    while (true){
        cout<<endl;
        cout<<"Bienvenido: "<<luis.get_nombre()<<endl;
        cargar_menu_de_crear_operacion();
        cin>>opcion_menu;
        if (opcion_menu==1){
            if (estado_operacion==true){
                cout<<"Ya se establecio un plan minero previamente"<<endl;
                }
            else{
                cout<<"Introduzca el nombre del plan: "<<endl;
                getline (cin, nuevo_nombre_operacion);
                getline (cin, nuevo_nombre_operacion);
                tajo.set_nombre(nuevo_nombre_operacion);
                cout<<"Introduzca el estado de la operacion(1=En curso, 0=Terminada/Cancelada): "<<endl;
                cin>>nuevo_estado;
                nuevo_estado=validar_estado(nuevo_estado);
                tajo.set_estatus(nuevo_estado);
                cout<<"Operacion Minera agregada con exito"<<endl;
                estado_operacion=true;
                }
            }
        else if (opcion_menu==2){
            if (estado_operacion==false){
                cout<<"Opcion no disponible, primero cree un plan minero"<<endl;
                }
            else if (estado_control==true){
                cout<<"Ya se establecio un plan minero previamente"<<endl;
            }
            else{
                cout<<"Introduzca el nombre del control: "<<endl;
                getline (cin, nombre_control);
                getline (cin, nombre_control);
                tajo.set_control_operativ(nombre_control);
                estado_control=true;
                cout<<"Control Operativo agregado con exito"<<endl;
                }
            }
        else if (opcion_menu==3){
            if (estado_control==false){
                cout<<"Opcion no disponible, primero cree un control operativo"<<endl;
                }
            else{
                cout<<"Introduzca el concepto del diesel: "<<endl;
                getline (cin, concepto_diesel);
                getline (cin, concepto_diesel);
                cout<<"Introduzca el rendimiento del diesel: "<<endl;
                cin>>rendimiento_diesel;
                rendimiento_diesel=validador_positivos(rendimiento_diesel);
                cout<<"Introduzca la cantidad del diesel: "<<endl;
                cin>>cantidad_diesel;
                cantidad_diesel=validador_positivos(cantidad_diesel);
                cout<<"Introduzca el metro lineal del diesel: "<<endl;
                cin>>metro_lineal_diesel;
                metro_lineal_diesel=validador_positivos(metro_lineal_diesel);
                cout<<"Introduzca el precio del diesel: "<<endl;
                cin>>precio_diesel;
                precio_diesel=validador_positivos(precio_diesel);
                tajo.agregar_diesel(concepto_diesel,rendimiento_diesel, cantidad_diesel, metro_lineal_diesel, precio_diesel);
                cout<<"Diesel agregado con exito"<<endl;
                }
            }
        else if (opcion_menu==4){
            if (estado_control==false){
                cout<<"Opcion no disponible, primero cree un control operativo"<<endl;
                }
            else{
                cout<<"Introduzca el concepto del acero: "<<endl;
                getline (cin, concepto_acero);
                getline (cin, concepto_acero);
                cout<<"Introduzca el rendimiento del acero: "<<endl;
                cin>>rendimiento_acero;
                rendimiento_acero=validador_positivos(rendimiento_acero);
                cout<<"Introduzca la cantidad del acero: "<<endl;
                cin>>cantidad_acero;
                cantidad_acero=validador_positivos(cantidad_acero);
                cout<<"Introduzca el metro lineal del acero: "<<endl;
                cin>>metro_lineal_acero;
                metro_lineal_acero=validador_positivos(metro_lineal_acero);
                cout<<"Introduzca el precio del acero: "<<endl;
                cin>>precio_acero;
                precio_acero=validador_positivos(precio_acero);
                tajo.agregar_acero(concepto_acero,rendimiento_acero,cantidad_acero,metro_lineal_acero,precio_acero);
                cout<<"Acero agregado con exito"<<endl;
                }
            }
        else if (opcion_menu==5){
            if (estado_control==false){
                cout<<"Opcion no disponible, primero cree un control operativo"<<endl;
                }
            else{
                cout<<"Introduzca el concepto del equipo: "<<endl;
                getline (cin, concepto_equipo);
                getline (cin, concepto_equipo);
                cout<<"Introduzca el rendimiento del equipo: "<<endl;
                cin>>rendimiento_equipo;
                rendimiento_equipo=validador_positivos(rendimiento_equipo);
                cout<<"Introduzca los metros barrenados del equipo: "<<endl;
                cin>>metros_barrenados_equipo;
                metros_barrenados_equipo=validador_positivos(metros_barrenados_equipo);
                cout<<"Introduzca el precio del equipo: "<<endl;
                cin>>precio_equipo;
                precio_equipo=validador_positivos(precio_equipo);
                cout<<"Introduzca las horas trabajadas del equipo: "<<endl;
                cin>>horas_trabajadas_equipo;
                horas_trabajadas_equipo=validador_positivos(horas_trabajadas_equipo);
                tajo.agregar_equipo(concepto_equipo,rendimiento_equipo,metros_barrenados_equipo,precio_equipo,horas_trabajadas_equipo);
                cout<<"Equipo agregado con exito"<<endl;
                }
            }
        else if (opcion_menu==6){
            if (estado_control==false){
                cout<<"Opcion no disponible, primero cree un control operativo"<<endl;
                }
            else{
                cout<<"Introduzca el concepto del personal: "<<endl;
                getline (cin,concepto_personal);
                getline (cin,concepto_personal);
                cout<<"Introduzca el rendimiento del personal: "<<endl;
                cin>>rendimiento_personal;
                rendimiento_personal=validador_positivos(rendimiento_personal);
                cout<<"Introduzca las horas hombre del personal: "<<endl;
                cin>>horas_hombre_personal;
                horas_hombre_personal=validador_positivos(horas_hombre_personal);
                cout<<"Introduzca horas trabajadas del personal: "<<endl;
                cin>>horas_trabajadas_personal;
                horas_trabajadas_personal=validador_positivos(horas_trabajadas_personal);
                cout<<"Introduzca el metro lineal del personal: "<<endl;
                cin>>metro_lineal_personal;
                metro_lineal_personal=validador_positivos(metro_lineal_personal);
                cout<<"Introduzca pago al dia del personal: "<<endl;
                cin>>pago_dia_personal;
                pago_dia_personal=validador_positivos(pago_dia_personal);
                tajo.agregar_personal(concepto_personal,rendimiento_personal,horas_hombre_personal,horas_trabajadas_personal,metro_lineal_personal,pago_dia_personal);
                cout<<"Personal agregado con exito"<<endl;
                }
            }
        else if (opcion_menu==7){
            if (estado_control==false){
                cout<<"Opcion no disponible, primero cree un control operativo"<<endl;
                }
            else{
                cout<<"El total de acero por metro lineal es: "<<tajo.obtener_total_acero_por_metro_lineal()<<endl;
                }
            }
        else if (opcion_menu==8){
            if (estado_control==false){
                cout<<"Opcion no disponible, primero cree un control operativo"<<endl;
                }
            else{
                cout<<"El total de diesel por metro lineal es: "<<tajo.obtener_total_diesel_por_metro_lineal()<<endl;
                }
            }
        else if (opcion_menu==9){
            if (estado_control==false){
                cout<<"Opcion no disponible, primero cree un control operativo"<<endl;
                }
            else{
                cout<<"El total de horas hombre por metro lineal es: "<<tajo.obtener_total_horas_hombre_por_metro_lineal()<<endl;
                }
            }
        else if (opcion_menu==10){
            if (estado_control==false){
                cout<<"Opcion no disponible, primero cree un control operativo"<<endl;
                }
            else{
                cout<<"El total de metros barrenados por horas trabajadas: "<<tajo.obtener_total_metros_barrenados_por_horas_trabajadas()<<endl;
                }
            }
        else if (opcion_menu==11){
            luis.set_ingresos(tajo);
            cout<<"El total de ingresos son: "<<luis.get_ingresos()<<endl;
            }
        else if (opcion_menu==12){
            luis.set_egresos(tajo);
            cout<<"El total de egresos son: "<<luis.get_egresos()<<endl;
            }
        else if (opcion_menu==13){
            luis.set_ingresos(tajo);
            luis.set_egresos(tajo);
            cout<<"El balance total es: "<<luis.consultar_balance()<<endl;
            }
        else if (opcion_menu==14){
            luis.set_ingresos(tajo);
            luis.set_egresos(tajo);
            luis.informe_balance();
            }
        else if (opcion_menu==15){
            tajo.estatus_operacion();
            }
        else if (opcion_menu==16){
            break;
            }
        else{
            cout<<"Opcion invalida"<<endl;
            }
        }
    }
//Esta opción es para que el usuario pueda iniciar de 0 un nuevo proyecto
else if (opcion_datos==2){
    estado_operacion=false;
    estado_control=false;
    cout<<"Introduzca su nombre: "<<endl;
    getline (cin, nuevo_nombre);
    getline (cin, nuevo_nombre);
    cout<<"Introduzca su RFC: "<<endl;
    getline (cin, nuevo_rfc);
    cout<<"Introduzca su Presupuesto: "<<endl;
    cin>>nuevo_presupuesto;
    nuevo_presupuesto=validador_positivos(nuevo_presupuesto);
    Cliente usuario(nuevo_nombre,nuevo_rfc,nuevo_presupuesto);
    while (true){
        cout<<endl;
        cout<<"Bienvenido: "<<usuario.get_nombre()<<endl;
        cargar_menu_de_crear_operacion();
        cin>>opcion_menu;
        if (opcion_menu==1){
            if (estado_operacion==true){
                cout<<"Ya se establecio un plan minero previamente"<<endl;
                }
            else{
            cout<<"Introduzca el nombre del plan: "<<endl;
            getline (cin, nuevo_nombre_operacion);
            getline (cin, nuevo_nombre_operacion);
            operacion_usuario.set_nombre(nuevo_nombre_operacion);
            cout<<"Introduzca el estado de la operacion(1=En curso, 0=Terminada/Cancelada): "<<endl;
            cin>>nuevo_estado;
            nuevo_estado=validar_estado(nuevo_estado);
            operacion_usuario.set_estatus(nuevo_estado);
            cout<<"Operacion Minera agregada con exito"<<endl;
            estado_operacion=true;
                }
            }
        else if (opcion_menu==2){
            if (estado_operacion==false){
                cout<<"Opcion no disponible, primero cree un plan minero"<<endl;
                }
            else if (estado_control==true){
                cout<<"Ya se establecio un plan minero previamente"<<endl;
            }
            else{
                cout<<"Introduzca el nombre del control: "<<endl;
                getline (cin, nombre_control);
                getline (cin, nombre_control);
                operacion_usuario.set_control_operativ(nombre_control);
                estado_control=true;
                cout<<"Control Operativo agregado con exito"<<endl;
                }
            }
        else if (opcion_menu==3){
            if (estado_control==false){
                cout<<"Opcion no disponible, primero cree un control operativo"<<endl;
                }
            else{
                cout<<"Introduzca el concepto del diesel: "<<endl;
                getline (cin, concepto_diesel);
                getline (cin, concepto_diesel);
                cout<<"Introduzca el rendimiento del diesel: "<<endl;
                cin>>rendimiento_diesel;
                rendimiento_diesel=validador_positivos(rendimiento_diesel);
                cout<<"Introduzca la cantidad del diesel: "<<endl;
                cin>>cantidad_diesel;
                cantidad_diesel=validador_positivos(cantidad_diesel);
                cout<<"Introduzca el metro lineal del diesel: "<<endl;
                cin>>metro_lineal_diesel;
                metro_lineal_diesel=validador_positivos(metro_lineal_diesel);
                cout<<"Introduzca el precio del diesel: "<<endl;
                cin>>precio_diesel;
                precio_diesel=validador_positivos(precio_diesel);
                operacion_usuario.agregar_diesel(concepto_diesel,rendimiento_diesel, cantidad_diesel, metro_lineal_diesel, precio_diesel);
                cout<<"Diesel agregado con exito"<<endl;
                }
            }
        else if (opcion_menu==4){
            if (estado_control==false){
                cout<<"Opcion no disponible, primero cree un control operativo"<<endl;
                }
            else{
                cout<<"Introduzca el concepto del acero: "<<endl;
                getline (cin, concepto_acero);
                getline (cin, concepto_acero);
                cout<<"Introduzca el rendimiento del acero: "<<endl;
                cin>>rendimiento_acero;
                rendimiento_acero=validador_positivos(rendimiento_acero);
                cout<<"Introduzca la cantidad del acero: "<<endl;
                cin>>cantidad_acero;
                cantidad_acero=validador_positivos(cantidad_acero);
                cout<<"Introduzca el metro lineal del acero: "<<endl;
                cin>>metro_lineal_acero;
                metro_lineal_acero=validador_positivos(metro_lineal_acero);
                cout<<"Introduzca el precio del acero: "<<endl;
                cin>>precio_acero;
                precio_acero=validador_positivos(precio_acero);
                operacion_usuario.agregar_acero(concepto_acero,rendimiento_acero,cantidad_acero,metro_lineal_acero,precio_acero);
                cout<<"Acero agregado con exito"<<endl;
                }
            }
        else if (opcion_menu==5){
            if (estado_control==false){
                cout<<"Opcion no disponible, primero cree un control operativo"<<endl;
                }
            else{
                cout<<"Introduzca el concepto del equipo: "<<endl;
                getline (cin, concepto_equipo);
                getline (cin, concepto_equipo);
                cout<<"Introduzca el rendimiento del equipo: "<<endl;
                cin>>rendimiento_equipo;
                rendimiento_equipo=validador_positivos(rendimiento_equipo);
                cout<<"Introduzca los metros barrenados del equipo: "<<endl;
                cin>>metros_barrenados_equipo;
                metros_barrenados_equipo=validador_positivos(metros_barrenados_equipo);
                cout<<"Introduzca el precio del equipo: "<<endl;
                cin>>precio_equipo;
                precio_equipo=validador_positivos(precio_equipo);
                cout<<"Introduzca las horas trabajadas del equipo: "<<endl;
                cin>>horas_trabajadas_equipo;
                horas_trabajadas_equipo=validador_positivos(horas_trabajadas_equipo);
                operacion_usuario.agregar_equipo(concepto_equipo,rendimiento_equipo,metros_barrenados_equipo,precio_equipo,horas_trabajadas_equipo);
                cout<<"Equipo agregado con exito"<<endl;
                }
            }
        else if (opcion_menu==6){
            if (estado_control==false){
                cout<<"Opcion no disponible, primero cree un control operativo"<<endl;
                }
            else{
                cout<<"Introduzca el concepto del personal: "<<endl;
                getline (cin,concepto_personal);
                getline (cin,concepto_personal);
                cout<<"Introduzca el rendimiento del personal: "<<endl;
                cin>>rendimiento_personal;
                rendimiento_personal=validador_positivos(rendimiento_personal);
                cout<<"Introduzca las horas hombre del personal: "<<endl;
                cin>>horas_hombre_personal;
                horas_hombre_personal=validador_positivos(horas_hombre_personal);
                cout<<"Introduzca horas trabajadas del personal: "<<endl;
                cin>>horas_trabajadas_personal;
                horas_trabajadas_personal=validador_positivos(horas_trabajadas_personal);
                cout<<"Introduzca el metro lineal del personal: "<<endl;
                cin>>metro_lineal_personal;
                metro_lineal_personal=validador_positivos(metro_lineal_personal);
                cout<<"Introduzca pago al dia del personal: "<<endl;
                cin>>pago_dia_personal;
                pago_dia_personal=validador_positivos(pago_dia_personal);
                operacion_usuario.agregar_personal(concepto_personal,rendimiento_personal,horas_hombre_personal,horas_trabajadas_personal,metro_lineal_personal,pago_dia_personal);
                cout<<"Personal agregado con exito"<<endl;
                }
            }
        else if (opcion_menu==7){
            if (estado_control==false){
                cout<<"Opcion no disponible, primero cree un control operativo"<<endl;
                }
            else{
                cout<<"El total de acero por metro lineal es: "<<operacion_usuario.obtener_total_acero_por_metro_lineal()<<endl;
                }
            }
        else if (opcion_menu==8){
            if (estado_control==false){
                cout<<"Opcion no disponible, primero cree un control operativo"<<endl;
                }
            else{
                cout<<"El total de diesel por metro lineal es: "<<operacion_usuario.obtener_total_diesel_por_metro_lineal()<<endl;
                }
            }
        else if (opcion_menu==9){
            if (estado_control==false){
                cout<<"Opcion no disponible, primero cree un control operativo"<<endl;
                }
            else{
                cout<<"El total de horas hombre por metro lineal es: "<<operacion_usuario.obtener_total_horas_hombre_por_metro_lineal()<<endl;
                }
            }
        else if (opcion_menu==10){
            if (estado_control==false){
                cout<<"Opcion no disponible, primero cree un control operativo"<<endl;
                }
            else{
                cout<<"El total de metros barrenados por horas trabajadas: "<<operacion_usuario.obtener_total_metros_barrenados_por_horas_trabajadas()<<endl;
                }
            }
        else if (opcion_menu==11){
            usuario.set_ingresos(operacion_usuario);
            cout<<"El total de ingresos son: "<<usuario.get_ingresos()<<endl;
            }
        else if (opcion_menu==12){
            usuario.set_egresos(operacion_usuario);
            cout<<"El total de egresos son: "<<usuario.get_egresos()<<endl;
            }
        else if (opcion_menu==13){
            usuario.set_ingresos(operacion_usuario);
            usuario.set_egresos(operacion_usuario);
            cout<<"El balance total es: "<<usuario.consultar_balance()<<endl;
            }
        else if (opcion_menu==14){
            usuario.set_ingresos(operacion_usuario);
            usuario.set_egresos(operacion_usuario);
            usuario.informe_balance();
            }
        else if (opcion_menu==15){
            operacion_usuario.estatus_operacion();
            }
        else if (opcion_menu==16){
            break;
            }
        else{
            cout<<"Opcion invalida"<<endl;
        }
        }
    }
//Esta Opcion sale del progra
else if (opcion_datos==3){
    cout<<"Hasta luego"<<endl;
    break;
    }
else {
    cout<<"Opcion invalida"<<endl;
    }
}


}
