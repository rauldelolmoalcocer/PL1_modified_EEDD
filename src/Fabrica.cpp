#include "Fabrica.h"
#include "Cola.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>

using namespace std;


Fabrica::Fabrica(string nombre_fabrica)
{
    //ctor
    this->nombre_fabrica = nombre_fabrica;
    this->cola_fabricacion = new Cola();
}

Fabrica::~Fabrica()
{
    //dtor
}

string Fabrica::get_nombre_fabrica(){
    return(nombre_fabrica);
}
Cola* Fabrica::get_cola_fabricacion(){
    return(cola_fabricacion);
}
void Fabrica::set_nombre_fabrica(string nombre_fabrica){
    this->nombre_fabrica = nombre_fabrica;
}


void Fabrica::set_cola_fabricacion(Cola *cola){
    if(cola_fabricacion->cola_vacia()){

    this->cola_fabricacion = cola;
    }
    else{
        cout << "PELIGRO DE CREAR MEMORIA RESIDUAL."<<endl;
    }

}

