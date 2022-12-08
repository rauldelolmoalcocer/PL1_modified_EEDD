#include "Camion.h"
#include <string>
#include <iostream>
#include "Pila.h"
using namespace std;

Camion::Camion(string zona_asig)
{
    this->zona_asig;
    this->stack_ = new Pila();
    this->capacidad = (8 + rand() % (8-6));
    this->num_nodos = 0;
}

Camion::~Camion()
{
    //dtor
}
void Camion::decrementar_capacidad(){
    this->num_nodos = num_nodos - 1;
}
string Camion::get_zona_asig(){
    return(zona_asig);

}
Pila* Camion::get_stack(){
    return(stack_);
    }
int Camion::get_capacidad(){
    return(capacidad);

}
void Camion::incrementar(int NUM){
            this->num_nodos = NUM;
        }
int Camion::get_num_nodos(){
    return(num_nodos);
}

void Camion::incremetar_capacidad(){
    this->num_nodos = num_nodos + 1;

}
bool Camion::overflow(){
    return(capacidad == num_nodos ? true : false);
}
void Camion::to_string()
{
    cout << "" << endl;

}
