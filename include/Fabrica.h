#ifndef FABRICA_H
#define FABRICA_H

#include "Cola.h"
#include <iostream>
#include <string>

using namespace std;

class Fabrica
{
    public:
        Fabrica(string nombre_fabrica);
        virtual ~Fabrica();

        //Getters y Setters

        string get_nombre_fabrica();
        Cola* get_cola_fabricacion();

        void set_nombre_fabrica(string nombre_fabrica);

        void set_cola_fabricacion(Cola *cola);



    protected:

    private:

        string nombre_fabrica;
        Cola *cola_fabricacion;
};

#endif // FABRICA_H
