#ifndef GESTOR_H
#define GESTOR_H

#include "Fabrica.h"
#include "Zona.h"
#include "Cola.h"

using namespace std;

class Gestor
{
    public:


        static void paso_simulacion(Zona *zonaA,Zona *zonaB,Zona *zonaC,Zona *zonaD, Fabrica *fab, int NV);
        static void ver_almacenes(Zona *zonaA,Zona *zonaB,Zona *zonaC,Zona *zonaD);
        static void ver_cola_almacen(Zona *zone);
        static void ver_camion(Camion *cam);
        static void borrar_registros(Zona *zonaA,Zona *zonaB,Zona *zonaC,Zona *zonaD, Fabrica *fab);
        static void borrar_zona(Zona *zona);
};

#endif // GESTOR_H
