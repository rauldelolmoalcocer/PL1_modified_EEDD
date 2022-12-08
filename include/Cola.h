#ifndef COLA_H
#define COLA_H

#include "Nodo.h"
#include "Vehiculo.h"
#include <string>
#include <iostream>

using namespace std;


/* CLASE COLA
Por defecto se generar vacia con el fin de que el usuario instroducca los datos
con los getters y setters correspondientes.
*/
class Cola{

    public:

        //Contructores y destructores.

        Cola();
        virtual ~Cola();

        //geters y setters de cola

        void set_nodo_cola(Vehiculo *veh);//inserta un nodo a la cola
        Nodo* get_frente_cola(); //Devuelve un nodo frente

        Nodo* get_nodo_cola_fin();

        bool cola_vacia();

        void desencolar();//elimina el dato de la cola

        //Datos frente cola
        void get_datos_nodo_frente();



    protected:

    private:
        Nodo *frente;
        Nodo *fin;
};

#endif // COLA_H
