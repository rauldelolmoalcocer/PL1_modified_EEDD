#include "FabricaService.h"
#include <iostream>
#include "Vehiculo.h"
#include <string>
#include "Cola.h"
#include <Fabrica.h>
#include <stdlib.h>
#include <ctime>
#include<stdio.h>
#include <windows.h>


using namespace std;

int FabricaService::GernerateRandomNumber(int A, int B){
    /*
    Funcion que se encarga de generar aleatoriamente numeros.
    */

    return((rand() % (B - A + 1)) + A);
}

string FabricaService::GenerateNumeroBastidor(){
    // ADA-12345

    char random_char;
    string tmp_var = "";

    for(int i = 0; i < 8; i++){
        if(i < 3){
            random_char = GernerateRandomNumber(65, 90);
            tmp_var.push_back(random_char);
        }else{

            tmp_var += to_string(rand()%9);
        }

    }
    //cout << "numero de bastidor " << tmp_var << endl;

    return(tmp_var);

}

void FabricaService::GenerateRandomVehiculos(Fabrica *fab, int NUM){
    /*
        Funcion encargada de la generacion aleatoria de coches y su insercion en la cola de
        vehiculos fabricados.
    */

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(NULL));

    string modelos[4] = {"Deportio", "Todoterreno", "Mini", "Lujoso"};
    string colores[6] = {"Rojo" , "Verde", "Azul" , "Negro", "Blanco", "Gris"};

    string concesionario = "0";
    string num_bastidor;
    string modelo;
    string color;

    for(int i= 0; i < NUM; i++){

        num_bastidor = GenerateNumeroBastidor();
        modelo = modelos[GernerateRandomNumber(0,3)];
        color = colores[GernerateRandomNumber(0,5)];

        fab->get_cola_fabricacion()->set_nodo_cola( new Vehiculo(num_bastidor, modelo,color, concesionario));

        cout <<"Creado el vehiculo con numero de bastidor: " << num_bastidor << endl;
        cout <<"Modelo: " << modelo << endl;
        cout <<"Color: " << color << endl;
        cout <<"Concesionario: " << concesionario << endl;
        cout <<endl;
    }
}

//TESTEAR ESTA FUNCION.

void FabricaService::MostrarDatosPorPantalla(Fabrica *fab){
    /*
    Funcion encargada de mostrar datos por pantalla.

    cima(fabrica)--> datos
    desapilar(nodo)
*/

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    Cola *aux = new Cola();
    Fabrica *aux_fab = fab;
    if(!aux_fab->get_cola_fabricacion()->cola_vacia()){


       while(!aux_fab->get_cola_fabricacion()->cola_vacia()){

            //pintamos los datos del frente de la cola.
            aux_fab->get_cola_fabricacion()->get_datos_nodo_frente();
            //hazme una cima de cola y insertamela en la cola auxiliar
            aux->set_nodo_cola( aux_fab->get_cola_fabricacion()->get_frente_cola()->get_Vehiculo());
            //desapilamos
            aux_fab->get_cola_fabricacion()->desencolar();

        }

        fab->set_cola_fabricacion(aux);
        delete aux;
    }
    else{

        SetConsoleTextAttribute(h, 2);
        cout << "LA COLA ESTA VACIA." << endl;
        SetConsoleTextAttribute(h, 7);

    }
}

