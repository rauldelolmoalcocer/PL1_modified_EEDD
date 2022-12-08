#include "Nodo.h"
#include <string>
#include <iostream>
#include "Vehiculo.h"

using namespace std;

Nodo::Nodo(Vehiculo *veh, Nodo *siguiente)
{
    this->veh = veh;
    this->siguiente = siguiente;
}
Nodo::~Nodo()
{
    //dtor
}

Vehiculo* Nodo::get_Vehiculo(){
    return(veh);
}
void Nodo::set_vehiculo_nodo(Vehiculo *veh){
    this->veh = veh;
}
Nodo* Nodo::get_Nodo_siguiente(){
    return(siguiente);
}
void Nodo::set_nodo_siguiente(Nodo *nod){
    this->siguiente = nod;
}

void Nodo::to_string(){
    //cout << "Puntero a Nodo:" << siguiente << "vehiculo" << veh << endl;
}
