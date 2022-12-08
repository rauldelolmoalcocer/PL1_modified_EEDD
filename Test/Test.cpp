    int cont = 0;

    while(fab->get_cola_fabricacion()->get_frente_cola() != NULL){

        fab->get_cola_fabricacion()->get_datos_nodo_frente();
        col->set_nodo_cola(fab->get_cola_fabricacion()->get_frente_cola()->get_Vehiculo());
        fab->get_cola_fabricacion()->desencolar();
        cont += 1;
        cout << "Desapilado" << cont << endl;



    }

    fab->set_cola_fabricacion(col);



    cout << "##############################################" << endl;
    fab->get_cola_fabricacion()->get_frente_cola()->get_Vehiculo()->to_string();

    int cont1 = 0;

    while(fab->get_cola_fabricacion()->get_frente_cola() != NULL){
        fab->get_cola_fabricacion()->desencolar();

        cont1 += 1;
        cout << "Vamos por la iteracion" << cont1 << endl;


    }


    cout << "##############################################" << endl;
    fab->get_cola_fabricacion()->get_frente_cola()->get_Vehiculo()->to_string();

/*--------------------------------------------------------------*/


    Fabrica *fab = new Fabrica("Fabrica manolo");

    FabricaService::GenerateRandomVehiculos(fab, 20);


    cout << "##############################################" << endl;
    cout << fab->get_cola_fabricacion()->get_frente_cola() << endl;

    Cola *col = fab->get_cola_fabricacion();

    Zona *zone = new Zona("zona inventada");

    zone->set_almacen(col);
    Gestor::ver_cola_almacen(zone);

    cout << "##############################################" << endl;
    fab->get_cola_fabricacion()->get_frente_cola()->get_Vehiculo()->to_string();

/*______________________________________*/


    Vehiculo *Veh = new Vehiculo("asdsd", "asdd", "sasd", "asdd");
    Vehiculo *Veh1 = new Vehiculo("Manolo", "Pepe", "sasd", "asdd");
    Vehiculo *Veh2 = new Vehiculo("Ejerc", "Juancho", "sasd", "asdd");
    Vehiculo *Veh3 = new Vehiculo("W2ewwqe", "Lucia", "sasd", "asdd");
    Vehiculo *Veh4 = new Vehiculo("weqwec", "Isabel", "sasd", "asdd");
    Vehiculo *Veh5 = new Vehiculo("asdsd", "asdd", "sasd", "asdd");
    Vehiculo *Veh6 = new Vehiculo("Manolo", "Pepe", "sasd", "asdd");
    Vehiculo *Veh7 = new Vehiculo("Ejerc", "Juancho", "sasd", "asdd");
    Vehiculo *Veh8 = new Vehiculo("W2ewwqe", "Lucia", "sasd", "asdd");
    Vehiculo *Veh9 = new Vehiculo("weqwec", "Isabel", "sasd", "asdd");



    Camion *cam = new Camion("adasd");

    cam->get_stack()->set_nodo_a_pila(Veh);
    cam->get_stack()->set_nodo_a_pila(Veh1);
    cam->get_stack()->set_nodo_a_pila(Veh2);
    cam->get_stack()->set_nodo_a_pila(Veh3);
    cam->get_stack()->set_nodo_a_pila(Veh4);
    cam->get_stack()->set_nodo_a_pila(Veh5);
    cam->get_stack()->set_nodo_a_pila(Veh6);
    cam->get_stack()->set_nodo_a_pila(Veh7);
    cam->get_stack()->set_nodo_a_pila(Veh8);
    cam->get_stack()->set_nodo_a_pila(Veh9);


    cam->incrementar(10);
    Gestor::ver_camion(cam);