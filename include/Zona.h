#ifndef ZONA_H
#define ZONA_H

#include <string>
#include "Vehiculo.h"
#include "Camion.h"
#include "Cola.h"
class Zona
{
    public:
        Zona(string zona);
        virtual ~Zona();

        //toString

        void to_string();

        //Getters y Setters

        string get_zona();
        Camion* get_cam1();
        Camion* get_cam2();
        Cola* get_almacen();
        void llevar_veh_almacen();

        bool set_veh_almacen(Vehiculo *veh);//meter vehiculos al almacen teniendo en cuenta la limitacion de 10 vehiculos

        void set_almacen(Cola *almacen);
    protected:

    private:
        bool turno_cam = 1;
        string zona;
        Cola* almacen;
        Camion* cam1;
        Camion* cam2;

        string concesionarios[4]={zona + "1", zona + "2" , zona + "3" , zona + "4"};



};

#endif // ZONA_H
