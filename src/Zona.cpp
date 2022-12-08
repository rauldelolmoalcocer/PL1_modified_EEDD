#include "Zona.h"
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


Zona::Zona(string zona){
    this->zona = zona;
    this->almacen = new Cola();
    this->cam1 = new Camion(zona);
    this->cam2 = new Camion(zona);

    //ctor
}

Zona::~Zona()
{
    //dtor
}


string Zona::get_zona(){
    return(zona);
}
Camion* Zona::get_cam1(){
    return(cam1);
}
Camion* Zona::get_cam2(){
    return(cam2);
}
Cola* Zona::get_almacen(){
    return(almacen);
}

//Posible punto de conflicto
bool Zona::set_veh_almacen(Vehiculo *veh){
    //Testing
    //cout << "Camion semaforo" << turno_cam<< endl;
    if(turno_cam == true){
            cout << "ESTOY EN CAMION" << endl;
            if(cam1->get_num_nodos() < cam1->get_capacidad() && (cam1->get_capacidad() - cam1->get_num_nodos()) != 1){
                //cout << "Aun no me falta un espacion para estar lleno" << endl;
                cam1->get_stack()->set_nodo_a_pila(veh);
                /////////////////////
                cam1->get_stack()->get_data_cima();

                cam1->incremetar_capacidad();
                /////////////////////////////////////////////
                cout <<"ES "<< cam1->get_num_nodos() << endl;
                cout << endl;
                //return("camA no lleno");
                return(false);
            }else if (cam1->get_num_nodos() < cam1->get_capacidad() && (cam1->get_capacidad() - cam1->get_num_nodos()) == 1){
                cam1->get_stack()->set_nodo_a_pila(veh);
                cam1->incremetar_capacidad();
                turno_cam = false;
               // return("camA si lleno");
                return(true);

            }

    }else{
            if(cam2->get_num_nodos() < cam2->get_capacidad() && cam2->get_capacidad() - cam2->get_num_nodos() != 1){
                cam2->get_stack()->set_nodo_a_pila(veh);
                cam2->incremetar_capacidad();
                //return("camB si lleno");
                return(false);

            }else if(cam2->get_num_nodos() < cam2->get_capacidad() && cam2->get_capacidad() - cam2->get_num_nodos() == 1){
                cam2->get_stack()->set_nodo_a_pila(veh);
                cam2->incremetar_capacidad();
                turno_cam = true;
                //return("camB no lleno");
                return(true);

            }
    }
}

//posible punto de conflicto

void Zona::llevar_veh_almacen(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    string num_conc[4] = {"1", "2", "3" , "4"};
    int cont = 0;
    string concen = "";
    Camion *cam;

    if(cam1->get_num_nodos() == 10){
        cam = cam1;
    }else if(cam2->get_num_nodos() == 10){
        cam = cam2;
    }else{
        SetConsoleTextAttribute(h, 4);
        cout << "ERROR: No hay ningun camion lleno, por lo que no vamos a llevar nada al almacen" << endl;
        SetConsoleTextAttribute(h, 7);}


    if(cam->get_num_nodos() == 10){
        while(cont < 10){
            concen = num_conc[FabricaService::GernerateRandomNumber(0,4)] + zona;
            cam->get_stack()->get_cima()->get_Vehiculo()->set_concesionario(concen);

            almacen->set_nodo_cola(cam->get_stack()->get_cima()->get_Vehiculo());
            cam->get_stack()->desapilar_nodo();
            cam->decrementar_capacidad();
            cout << "CAPACIDAD DE " << cam->get_num_nodos() << endl;
            cont += 1;
            cout << "APILANDO EN EL COCHE " << cont << endl;
        }
    }

}

void Zona::set_almacen(Cola *almacen){
    this->almacen = almacen;
}

void Zona::to_string(){

    cout << " La zona tiene asignada la siguiente letra " << zona << " posee el almacen "  << almacen<< endl;

}
/*

    //TESTING
    cout << "He entrado en llevar almacen" << endl;
     Vehiculo *veh;
     HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
     string num_conc[4] = {"1", "2", "3" , "4"};
        int cont = 0;
     if(cam1->get_num_nodos() == 10){
        cout << "Estoy en este if de cam1->get_num_nodos() == 10" << endl;

        while(cam1->get_stack()->get_cima() != NULL){

                cout << "Entre al bucle" << endl;
                //pillamos el vehiculo
                veh = cam1->get_stack()->get_cima()->get_Vehiculo();
                //le asignamos concesionario
                veh->set_concesionario(num_conc[FabricaService::GernerateRandomNumber(0,4)] + zona);

                //desapilamos de camion
                cam1->get_stack()->desapilar_nodo();

                //insertamos en almacen
                almacen->set_nodo_cola(veh);

                //decrementamos la capacidad
                cam1->decrementar_capacidad();

                //liberamos
                delete veh;
                veh = NULL;

                cont += 1;
                cout << "El contador es el siguiente" << cont << endl;
        }

     }else if(cam2->get_num_nodos() == 10){
         while(cam1->get_stack()->get_cima() != NULL){
                veh = cam2->get_stack()->get_cima()->get_Vehiculo();
                 veh->set_concesionario(num_conc[FabricaService::GernerateRandomNumber(0,4)] + zona);
                cam2->get_stack()->desapilar_nodo();
                almacen->set_nodo_cola(veh);
                cam2->decrementar_capacidad();
                delete veh;
          }
     }else{
        SetConsoleTextAttribute(h, 4);
        cout << "ERROR: No hay ningun camion lleno, por lo que no vamos a llevar nada al almacen" << endl;
        SetConsoleTextAttribute(h, 7);
     }

*/
