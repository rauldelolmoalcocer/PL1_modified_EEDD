#ifndef PILA_H
#define PILA_H

#include <Nodo.h>
class Pila
{
public:
    Pila();
    virtual ~Pila();

    void set_nodo_a_pila(Vehiculo *veh);
    Nodo* get_cima();
    void desapilar_nodo();

    void get_data_cima();
    bool cola_vacia();
protected:

private:
    Nodo *cima; //puntero a cima cola.

};

#endif // PILA_H
