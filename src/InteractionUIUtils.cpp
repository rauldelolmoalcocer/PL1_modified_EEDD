#include "InteractionUIUtils.h"


#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void InteractionUIUtils::printMenu(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    /*
        OBJ:Imprimir el menu interaccion con el usuario y elegir la operacion que se desea realizar
        PRE: NULL
        printMenu--> secuencia de Strings por pantalla
    */
    SetConsoleTextAttribute(h, 6);
    cout << "|------------------------------------------------------------------------------------------------------------------|"<<endl;
    cout << "|                                       MENU DE INTERACION                                                         |"<< endl;
    cout << "|------------------------------------------------------------------------------------------------------------------|"<< endl;
    cout << "|0.- SALIR                                                                                                         |"<< endl;
    cout << "|1.- GENERAR ALEATORIAMENTE NV AUTOMOVILES EN LA FABRICA                                                           |"<< endl;
    cout << "|2.- GENERAR ALEATORIAMENTE AUTOMOVILES EN LA FABRICA SOLICITANDO NV POR PANTALLA                                  |"<< endl;
    cout << "|3.- MOSTRAR LOS DATOS DE LA COLA DE AUTOMOVILES EN LA FABRICA                                                     |"<< endl;
    cout << "|4.- AVANZAR UN PASO SALEN NS AUTOMOVILES Y LLEGADA UN ALMACEN DE ZONA (ELEGIDA ALEATORIAMENTE)                    |"<< endl;
    cout << "|5.- AVANZAR UN PASO EN LA SIMULACION SOLICITANDO NS                                                               |"<< endl;
    cout << "|6.- MOSTRAR EN PANTALLA LOS DATOS DE LOS ALMACENES DE ZONA (CAMIONES Y REGISTRO)                                  |"<< endl;
    cout << "|7.- BORRAR AUTOMOVILES DISPONIBLES DE LA FABRICA, DE LOS CAMIONES Y/O DE LOS REGISTROS DE ZONA                    |"<< endl;
    cout << "|8.- REALIZAR LA SIMULACION HASTA FINALIZAR LOS AUTOMOVILES DISPONIBLES                                            |"<< endl;
    cout << "|9.- LIMPIAR                                                                                                       |"<< endl;
    cout << "|------------------------------------------------------------------------------------------------------------------|"<< endl;


}
