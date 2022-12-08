#include "Gestor.h"
#include <iostream>
#include "Fabrica.h"

#include <string>
#include <InteractionUIUtils.h>
#include <Cola.h>
#include <stdlib.h>
#include <windows.h>
#include <Camion.h>
#include "Vehiculo.h"

#include "FabricaService.h"
#include <time.h>
#include "Pila.h"
#include "Zona.h"
using namespace std;


void Gestor::paso_simulacion(Zona* zonaA,Zona* zonaB,Zona* zonaC,Zona* zonaD, Fabrica* fab, int NUM_NS){

    /*
    se sacan NS automóviles de la cola (almacen de la fabrica) y se llevan a uno de los camiones (pila),
    en funcion de la zona de destino (elegida aleatoriamente).

    */
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    //int num_coches_salen;
    int contador = 0;
    int camlleno;
    string zonas[4] = {"A", "B", "C", "D"};

    //cout << "Vamos a avanzar en un paso de la emulacion" << endl;
    //cout << "Dime el numero de coches que quieres que salgan de la fabrica" << endl;
    //cin >> num_coches_salen;
    Vehiculo *veh;

    while(NUM_NS > contador){
        cout << endl;
        cout << "COCHE DESENCOLADO." << endl;
        fab->get_cola_fabricacion()->get_datos_nodo_frente();

        //recogemos el vehiculo con un puntero
        veh = fab->get_cola_fabricacion()->get_frente_cola()->get_Vehiculo();

        //TESTING

        //Desencolamos el coche de la fabrica.
        fab->get_cola_fabricacion()->desencolar();


        //Le asignamos ZonaAleatoriamente
        int zone = FabricaService::GernerateRandomNumber(0,3);

        SetConsoleTextAttribute(h, 5);
        //cout << "Zona caida ..." << zonas[zone] << endl;
        SetConsoleTextAttribute(h, 7);

        switch(zone){//Tocado

        case 0:
            //cout << "Estoy aqui dentro"<< endl;
            camlleno = zonaA->set_veh_almacen(veh);
            //cout << "El camion esta lleno?" << camlleno << endl;
           if(camlleno) {
                //lo llevamos al almacen
                SetConsoleTextAttribute(h, 11);
                //cout << "Vamos a borrar EL CAMION" << endl;
                SetConsoleTextAttribute(h, 7);
                zonaA->llevar_veh_almacen();
                //cout << "He salido!!!" << endl;
           }
            break;

        case 1:
            camlleno = zonaB->set_veh_almacen(veh);

            if(camlleno) {
                //lo llevamos al almacen
                SetConsoleTextAttribute(h, 11);
                cout << "MOVIENDO EL CAMION" << endl;
                SetConsoleTextAttribute(h, 7);
                zonaB->llevar_veh_almacen();
                SetConsoleTextAttribute(h, 11);
                cout << "SALIMOS!!!" << endl;
                SetConsoleTextAttribute(h, 7);
           }
            break;

        case 2:
            camlleno = zonaC->set_veh_almacen(veh);
            if(camlleno) {
                //lo llevamos al almacen
                SetConsoleTextAttribute(h, 11);
                cout << "MOVIENDO EL CAMION" << endl;
                SetConsoleTextAttribute(h, 7);
                zonaC->llevar_veh_almacen();
                SetConsoleTextAttribute(h, 11);
                cout << "SALIMOS!!!" << endl;
                SetConsoleTextAttribute(h, 7);
           }

            break;
        case 3:
            camlleno = zonaD->set_veh_almacen(veh);

            if(camlleno) {
                //lo llevamos al almacen
                SetConsoleTextAttribute(h, 11);
                cout << "MOVIENDO EL CAMION" << endl;
                SetConsoleTextAttribute(h, 7);
                zonaD->llevar_veh_almacen();
                SetConsoleTextAttribute(h, 11);
                cout << "SALIMOS!!!" << endl;
                SetConsoleTextAttribute(h, 7);
           }
            break;

        default:
            cout << "ERROR: Algo ha pasado con la generacion aleatoria de numeros" << endl;
        }
        contador += 1;
    }


}

void Gestor::ver_almacenes(Zona *zonaA,Zona *zonaB,Zona *zonaC,Zona *zonaD){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << endl;
    cout << "IMPRIMIENDO DATOS DE ALMACEN POR PANTALLA: " << endl;
    cout << endl;

    SetConsoleTextAttribute(h, 13);
    cout << "ZONA A" << endl;
    //ver_cola_almacen(zonaA);
    SetConsoleTextAttribute(h, 12);
    cout << "CAMIONES A1" << endl;
    cout << endl;
    ver_camion(zonaA->get_cam1());
    cout << endl;
    SetConsoleTextAttribute(h, 12);
    cout << "CAMIONES A2" << endl;
    cout << endl;
    ver_camion(zonaA->get_cam2());
    cout << endl;

    //------------------------------------------------------------------------------
    SetConsoleTextAttribute(h, 13);
     cout << "ZONA B" << endl;
    //ver_cola_almacen(zonaB);
    SetConsoleTextAttribute(h, 12);
    cout << "CAMIONES B3" << endl;
    cout << endl;
    ver_camion(zonaB->get_cam1());
    cout << endl;
    SetConsoleTextAttribute(h, 12);
    cout << "CAMIONES B4" << endl;
    cout << endl;
    ver_camion(zonaB->get_cam2());
    cout << endl;

    //------------------------------------------------------------------------------

    SetConsoleTextAttribute(h, 13);
    cout << "ZONA C" << endl;
    //ver_cola_almacen(zonaC);
    SetConsoleTextAttribute(h, 12);
    cout << "CAMIONES C5" << endl;
    cout << endl;
    ver_camion(zonaC->get_cam1());
    cout << endl;
    SetConsoleTextAttribute(h, 12);
    cout << "CAMIONES C6" << endl;
    cout << endl;
    ver_camion(zonaC->get_cam2());
    cout << endl;

    //------------------------------------------------------------------------------

    SetConsoleTextAttribute(h, 13);
     cout << "ZONA D" << endl;
    //ver_cola_almacen(zonaD);
    SetConsoleTextAttribute(h, 12);
    cout << "CAMIONES D7" << endl;
    cout << endl;
    ver_camion(zonaD->get_cam1());
    cout << endl;
    SetConsoleTextAttribute(h, 12);
    cout << "CAMIONES D8" << endl;
    cout << endl;
    ver_camion(zonaD->get_cam2());
    cout << endl;

    //------------------------------------------------------------------------------

}

void Gestor::ver_cola_almacen(Zona *zone){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    if(zone->get_almacen()->get_frente_cola() != NULL){
        Cola *aux = new Cola();
        int cont = 0;


        while(zone->get_almacen()->get_frente_cola() != NULL){

            //Mientas las cola este vacia.
            zone->get_almacen()->get_datos_nodo_frente();
            aux->set_nodo_cola(zone->get_almacen()->get_frente_cola()->get_Vehiculo());
            aux->get_datos_nodo_frente();
            zone->get_almacen()->desencolar();

            cont+=1;
           // cout << "Desapilando" << cont << endl;

        }
    cont = 0;

       while(aux->get_frente_cola() != NULL){

            zone->get_almacen()->set_nodo_cola(aux->get_frente_cola()->get_Vehiculo());
            zone->get_almacen()->get_frente_cola()->get_Vehiculo()->to_string();
            aux->desencolar();
            cont+=1;
           // cout << "Apilado" << cont << endl;

       }
        delete aux;

    }else{

        SetConsoleTextAttribute(h, 1);
        cout << "ERROR:La cola esta vacia." << endl;
        SetConsoleTextAttribute(h, 7);

    }


}

void Gestor::ver_camion(Camion *cam){

    //MAL
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    Pila *final_stack = new Pila();
    Pila *aux = new Pila();

    int cont = 0;
        // cout << "########################################################" << endl;
        //   cout << "########################################################" << endl;
        //   cout << "########################################################" << endl;

    if(true){
        while(cont < cam->get_num_nodos()){

            SetConsoleTextAttribute(h, 2);
            cout << endl;
            cam->get_stack()->get_cima()->get_Vehiculo()->to_string();
            cout << endl;
            SetConsoleTextAttribute(h, 7);

            aux->set_nodo_a_pila(cam->get_stack()->get_cima()->get_Vehiculo());
            cam->get_stack()->desapilar_nodo();

            cont+= 1;

        }
       // cout << "########################################################" << endl;
       // cout << "########################################################" << endl;
       // cout << "########################################################" << endl;

        cont = 0;
        while(cont < cam->get_num_nodos()){

         //   SetConsoleTextAttribute(h, 2);
         //   aux->get_cima()->get_Vehiculo()->to_string();
         //   SetConsoleTextAttribute(h, 7);

            final_stack->set_nodo_a_pila(aux->get_cima()->get_Vehiculo());
            aux->desapilar_nodo();

            cont+= 1;

        }

        delete aux;
       // cout << "########################################################" << endl;
      //  cout << "########################################################" << endl;
      //  cout << "########################################################" << endl;


        cont = 0;
        while(cont < cam->get_num_nodos()){

           // SetConsoleTextAttribute(h, 2);
         //   final_stack->get_cima()->get_Vehiculo()->to_string();
         //   SetConsoleTextAttribute(h, 7);

            cam->get_stack()->set_nodo_a_pila(final_stack->get_cima()->get_Vehiculo());
            final_stack->desapilar_nodo();

            cont+= 1;

        }

        delete final_stack;


    }
    else{
        SetConsoleTextAttribute(h, 4);
        cout << "ERROR:Camion vacio" << endl;
        SetConsoleTextAttribute(h, 7);

    }
}

void Gestor::borrar_registros(Zona *zonaA,Zona *zonaB,Zona *zonaC,Zona *zonaD, Fabrica *fab){

    borrar_zona(zonaA);
    borrar_zona(zonaB);
    borrar_zona(zonaC);
    borrar_zona(zonaD);

    while(fab->get_cola_fabricacion()->get_frente_cola() != NULL){

        fab->get_cola_fabricacion()->desencolar();
    }




}

void Gestor::borrar_zona(Zona *zona){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    //cout << "He entrado" << endl;
    int cont = 0;

    while(zona->get_almacen()->get_frente_cola() != NULL){
      zona->get_almacen()->desencolar();
      //cout << "Desencolado" << endl;
    }



    //cout << "pila vacia " << zona->get_cam1()->get_num_nodos() << endl;
    //zona->get_cam1()->get_stack()->desapilar_nodo();
    for(int i=0;i<=4;i++){
        while(cont < zona->get_cam1()->get_num_nodos()){
            zona->get_cam1()->get_stack()->desapilar_nodo();
            zona->get_cam1()->decrementar_capacidad();
            //cout << "Desapilado" << endl;
            cont+= 1;
        }

        cont = 0;
        while(cont < zona->get_cam2()->get_num_nodos()){
            zona->get_cam2()->get_stack()->desapilar_nodo();
            zona->get_cam2()->decrementar_capacidad();
            //cout << "Desapilado" << endl;
            cont+= 1;
        }
    }


}


