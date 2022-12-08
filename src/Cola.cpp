#include "Cola.h"
#include "Nodo.h"
#include "Vehiculo.h"
#include <iostream>
#include <windows.h>
#include "InteractionUIUtils.h"

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
Cola::Cola()
{
    this->frente = NULL;
    this->fin = NULL;
}

Cola::~Cola()
{
    //dtor
}

bool Cola::cola_vacia()
{
    return(frente == NULL ? true : false);
}

void Cola::set_nodo_cola(Vehiculo *veh)
{
    /*
    Metodo encargada de pasarle un nodo yu asignarselo de nuevo a nodo cola.
    */

    //pasamos los datos.
    Nodo *nuevo = new Nodo(veh, NULL);
    if(cola_vacia())
    {
        frente = nuevo;
    }
    else
    {
        fin->set_nodo_siguiente(nuevo);
        fin->get_Nodo_siguiente()->get_Vehiculo();
    }
    fin = nuevo;


}
Nodo* Cola::get_frente_cola()
{
    /*
    Metodo encargada de pasar el primer elemento de la cola.
    */
    return(frente);

}

Nodo* Cola::get_nodo_cola_fin()
{
    return(fin);
}


void Cola::desencolar()
{
    /*
    Metodo encargado de eliminar nodo de frente de cola.

    */
    //HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    if(!cola_vacia()){
         //nos quedamos con el numero


        Nodo *aux = frente;
        if(frente == fin)
        {

            frente = NULL;
            fin = NULL;

        }
        else
        {
            frente = aux->get_Nodo_siguiente();

        }
        delete aux;

        //Corregimos capturamos el error de si encuetra la cola vacia.

        if(frente == NULL && fin == NULL)
        {

            //pintado las letras.
            SetConsoleTextAttribute(h, 2);
            cout << endl;
            cout << "------------------------------------" << endl;
            cout << "  NO HAY MAS ELEMENTOS EN LA COLA." << endl;
            cout << "------------------------------------" << endl;
            cout << endl;
            SetConsoleTextAttribute(h, 7);

        }
        else
        {
            //cout << "------------------------------------" << endl;
            //cout << aux << endl;
            //cout << frente->get_Nodo_siguiente()<< endl;
            //cout << "------------------------------------" << endl;
        }
    }else{
        SetConsoleTextAttribute(h, 2);
        cout << "------------------------------------" << endl;
        cout << "        LA COLA ESTA VACIA." << endl;
        cout << "------------------------------------" << endl;
        SetConsoleTextAttribute(h, 7);

    }

}
void Cola::get_datos_nodo_frente()
{

    /*
    Metodo encargado de mostrar los elementos de un nodo.
    */

    if(frente != NULL && fin != NULL)
    {
        cout << endl;
        SetConsoleTextAttribute(h,1);
        cout << "------------------------------------"<< endl;
        cout << endl;
        cout << "Numero bastidor: " << frente->get_Vehiculo()->get_numero_bastidor() << endl;
        cout << "Modelo: " << frente->get_Vehiculo()->get_modelo() << endl;
        cout << "Color: " << frente->get_Vehiculo()->get_color() << endl;
        cout << "Concesionario: " << frente->get_Vehiculo()->get_concesionario() << endl;
        cout << endl;
        cout << "------------------------------------" << endl;
        cout << endl;
        //cout << "Puntero a siguiente: " << &fin << endl;

    }
    else
    {

        SetConsoleTextAttribute(h, 4);
        cout << "------------------------------------" << endl;
        cout << "ERROR: La pila esta vacia." << endl;
        cout << "------------------------------------" << endl;
        SetConsoleTextAttribute(h, 7);
    }
}

