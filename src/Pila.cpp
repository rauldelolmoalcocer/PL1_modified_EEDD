#include "Pila.h"
#include "Vehiculo.h"
#include "Nodo.h"
#include <iostream>

using namespace std;

Pila::Pila()
{
    //ctor
    Nodo *cima = NULL;
}

Pila::~Pila()
{
    //dtor
}
Nodo* Pila::get_cima(){
    return(cima);
}
bool Pila::cola_vacia()
{
    return(cima == NULL ? true : false);
}
void Pila::desapilar_nodo(){
    Nodo *aux = cima;
    Vehiculo *veh = aux->get_Vehiculo();

    cima = aux->get_Nodo_siguiente();
    delete aux;

    //cout << "Se ha borrado el nodo que contenia el valor..." << veh << endl;
}
void Pila::set_nodo_a_pila(Vehiculo *veh){
    Nodo* nuevo_nodo = new Nodo(veh,NULL);
    //cima->set_nodo_siguiente(nuevo_nodo); ERROR
    nuevo_nodo->set_nodo_siguiente(cima);//con esta instruccion le decimos a un puntero que estamos apunte siempre hacia la cima
    cima = nuevo_nodo;
}

void Pila::get_data_cima(){

    //cout << "Cima de la pila en ese momento" << endl;
    //cout << "Valor de cima: " << endl;
    //((cima->get_Vehiculo()->to_string();
    //cout << endl;

}
