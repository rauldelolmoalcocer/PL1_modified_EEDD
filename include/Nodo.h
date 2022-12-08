#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>
#include "Vehiculo.h"

class Nodo
{
    public:
        //contructores de objeto Nodo
        Nodo(Vehiculo *veh, Nodo *siguiente);
        virtual ~Nodo();


        //getters y setters
        Vehiculo* get_Vehiculo();
        void set_vehiculo_nodo(Vehiculo *veh);

        Nodo* get_Nodo_siguiente();
        void set_nodo_siguiente(Nodo *nod);

        //toString() para mostrar datos por pantalla
        void to_string();



    protected:

    private:
        Vehiculo *veh;
        Nodo *siguiente;

        //hay que hacer un toString() para leer los datos del nodo.

};

#endif // NODO_H
