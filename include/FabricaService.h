#ifndef FABRICASERVICE_H
#define FABRICASERVICE_H

#include <iostream>
#include "Vehiculo.h"
#include <string>
#include "Cola.h"
#include <Fabrica.h>
using namespace std;

class FabricaService
{
    public:
        static void GenerateRandomVehiculos(Fabrica *fab, int NUM);
        static int GernerateRandomNumber(int A, int B);
        static string GenerateNumeroBastidor();
        static void MostrarDatosPorPantalla(Fabrica *fab);
       // static void SimulacionFabrica()


    protected:

    private:
};

#endif // FABRICASERVICE_H
