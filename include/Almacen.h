#ifndef ALMACEN_H
#define ALMACEN_H

#include "Cola.h"


class Almacen
{
    public:
        Almacen();
        virtual ~Almacen();





    protected:

    private:
        Cola *cola;
        string zona;



};

#endif // ALMACEN_H
