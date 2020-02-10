/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EcoCityMoto.cpp
 * Author: jgr97
 * 
 * Created on 25 de octubre de 2019, 18:43
 */

#include "EcoCityMoto.h"

EcoCityMoto::EcoCityMoto(int tama) : idUltimo(0), arbolCliente(tama) {
}

EcoCityMoto::EcoCityMoto(vector<Moto> &vectorMotos, TablaHashCliente &arbolCliente) :
vectorMotos(vectorMotos), arbolCliente(arbolCliente) {
}

EcoCityMoto::EcoCityMoto(const EcoCityMoto& orig) : idUltimo(orig.idUltimo), vectorMotos(orig.vectorMotos), arbolCliente(orig.arbolCliente) {
}

EcoCityMoto::~EcoCityMoto() {
    //GuardarClientes("pruebanum1.csv");
}

unsigned long EcoCityMoto::djb2(char* str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}


Cliente* EcoCityMoto::BuscarCliente(string DNI) {
    char c[DNI.size() + 1];
    strcpy(c, DNI.c_str());
    
    Cliente *cli;
    cli=arbolCliente.buscar(djb2(c),DNI,*cli);
    
    return cli;
}

void EcoCityMoto::DesbloqueaMoto(Moto* Mo) {
    if (Mo->GetPorcentajeBateria() < 15 || Mo->GetPorcentajeBateria() > 100) {
        throw std::out_of_range("Ecocitymoto::DesbloquearMoto: No es posible desbloquear la moto ya que la bateria esta rota");
    }
    vector<Moto>::iterator it;
    it = find(vectorMotos.begin(), vectorMotos.end(), *Mo);
    it->seActiva();
}

Moto* EcoCityMoto::MotoCercana(UTM ubicacion) {
    double distancia = 0;
    double minimadistancia = 9999;
    Moto *motodef;
    int i = 0;

    for (; i < vectorMotos.size(); i++) {

        UTM aux = vectorMotos[i].GetPosicion();

        double distancia = ubicacion.distacia(aux);

        if (distancia < minimadistancia && vectorMotos[i].GetEstatus()==Estado::bloqueada) {
            minimadistancia = distancia;
            motodef = &(vectorMotos[i]);
        }
    }
    return motodef;
}

bool EcoCityMoto::encuentracliente(string dni) {
//    bool resultado = false;
//    if (arbolCliente.count(dni)>0) {
//        resultado = true;
//    }
//    return resultado;
}


void EcoCityMoto::cargaClientesHashDoble1(string fileNameClientes) {
    ifstream fe; //Flujo de entrada
    string linea; //Cada línea tiene un clienete
    int total = 0; //Contador de líneas o clientes

    //Variables auxiliares para almacenar los valores leídos
    string dni, nombre, pass, direccion, latitud, longitud;
    double dlat, dlon;



    //Asociamos el flujo al fichero 
    fe.open(fileNameClientes);

    if (fe.good()) {
        int primera = 0;
        //Mientras no se haya llegado al final del fichero
        while (!fe.eof()) {
            getline(fe, linea); //Toma una línea del fichero
            stringstream ss; //Stream que trabaja sobre buffer interno         

            if (linea != "") {
                ++total;
            }

            if (total > 1) {
                //Inicializamos el contenido de ss
                ss << linea;

                //Leemos el NIF
                getline(ss, dni, ';'); //El carácter ; se lee y se elimina de ss

                //Leemos el pass
                getline(ss, pass, ';'); //El caráter ; se lee y se elimina de ss

                //Leemos el nombre
                getline(ss, nombre, ';'); //El caráter ; se lee y se elimina de ss

                //Leemos la dirección
                getline(ss, direccion, ';'); //El caráter ; se lee y se elimina de ss

                //Leemos la latitud y longitud
                getline(ss, latitud, ';'); //El caráter ; se lee y se elimina de ss
                getline(ss, longitud, ';'); //El caráter ; se lee y se elimina de ss

                dlat = stod(latitud);
                dlon = stod(longitud);

                //con todos los atributos leídos, se crea el cliente
                Cliente client(dni, pass, nombre, direccion, dlat, dlon);
                client.setAcceso(this);
                
                char c[client.getDni().size() + 1];
                strcpy(c, client.getDni().c_str());
                
                
                arbolCliente.insertarDoble1(djb2(c),dni,client);
            }
        }
        arbolCliente.mostrarInfo();
        cout << "Total de clientes en el fichero: " << total << endl;
        fe.close(); //Cerramos el flujo de entrada
    } else {
        cerr << "No se puede abrir el fichero" << endl;
    }
}

void EcoCityMoto::cargaClientesHashDoble2(string fileNameClientes) {
    ifstream fe; //Flujo de entrada
    string linea; //Cada línea tiene un clienete
    int total = 0; //Contador de líneas o clientes

    //Variables auxiliares para almacenar los valores leídos
    string dni, nombre, pass, direccion, latitud, longitud;
    double dlat, dlon;



    //Asociamos el flujo al fichero 
    fe.open(fileNameClientes);

    if (fe.good()) {
        int primera = 0;
        //Mientras no se haya llegado al final del fichero
        while (!fe.eof()) {
            getline(fe, linea); //Toma una línea del fichero
            stringstream ss; //Stream que trabaja sobre buffer interno         

            if (linea != "") {
                ++total;
            }

            if (total > 1) {
                //Inicializamos el contenido de ss
                ss << linea;

                //Leemos el NIF
                getline(ss, dni, ';'); //El carácter ; se lee y se elimina de ss

                //Leemos el pass
                getline(ss, pass, ';'); //El caráter ; se lee y se elimina de ss

                //Leemos el nombre
                getline(ss, nombre, ';'); //El caráter ; se lee y se elimina de ss

                //Leemos la dirección
                getline(ss, direccion, ';'); //El caráter ; se lee y se elimina de ss

                //Leemos la latitud y longitud
                getline(ss, latitud, ';'); //El caráter ; se lee y se elimina de ss
                getline(ss, longitud, ';'); //El caráter ; se lee y se elimina de ss

                dlat = stod(latitud);
                dlon = stod(longitud);

                //con todos los atributos leídos, se crea el cliente
                Cliente client(dni, pass, nombre, direccion, dlat, dlon);
                client.setAcceso(this);
                
                char c[client.getDni().size() + 1];
                strcpy(c, client.getDni().c_str());
                
                
                arbolCliente.insertarDoble2(djb2(c),dni,client);
            }
        }
        arbolCliente.mostrarInfo();
        cout << "Total de clientes en el fichero: " << total << endl;
        fe.close(); //Cerramos el flujo de entrada
    } else {
        cerr << "No se puede abrir el fichero" << endl;
    }
}

void EcoCityMoto::cargaClientesHashcuadratica(string fileNameClientes) {
    ifstream fe; //Flujo de entrada
    string linea; //Cada línea tiene un clienete
    int total = 0; //Contador de líneas o clientes

    //Variables auxiliares para almacenar los valores leídos
    string dni, nombre, pass, direccion, latitud, longitud;
    double dlat, dlon;



    //Asociamos el flujo al fichero 
    fe.open(fileNameClientes);

    if (fe.good()) {
        int primera = 0;
        //Mientras no se haya llegado al final del fichero
        while (!fe.eof()) {
            getline(fe, linea); //Toma una línea del fichero
            stringstream ss; //Stream que trabaja sobre buffer interno         

            if (linea != "") {
                ++total;
            }

            if (total > 1) {
                //Inicializamos el contenido de ss
                ss << linea;

                //Leemos el NIF
                getline(ss, dni, ';'); //El carácter ; se lee y se elimina de ss

                //Leemos el pass
                getline(ss, pass, ';'); //El caráter ; se lee y se elimina de ss

                //Leemos el nombre
                getline(ss, nombre, ';'); //El caráter ; se lee y se elimina de ss

                //Leemos la dirección
                getline(ss, direccion, ';'); //El caráter ; se lee y se elimina de ss

                //Leemos la latitud y longitud
                getline(ss, latitud, ';'); //El caráter ; se lee y se elimina de ss
                getline(ss, longitud, ';'); //El caráter ; se lee y se elimina de ss

                dlat = stod(latitud);
                dlon = stod(longitud);

                //con todos los atributos leídos, se crea el cliente
                Cliente client(dni, pass, nombre, direccion, dlat, dlon);
                client.setAcceso(this);
                
                char c[client.getDni().size() + 1];
                strcpy(c, client.getDni().c_str());
                
                
                arbolCliente.insertarcuadratica(djb2(c),dni,client);
            }
        }
        arbolCliente.mostrarInfo();
        cout << "Total de clientes en el fichero: " << total << endl;
        fe.close(); //Cerramos el flujo de entrada
    } else {
        cerr << "No se puede abrir el fichero" << endl;
    }
}



void EcoCityMoto::cargaMotos(string fileNameMotos) {
    ifstream fe; //Flujo de entrada
    string linea; //Cada línea tiene un clienete
    int total = 0; //Contador de líneas o clientes

    //Variables auxiliares para almacenar los valores leídos
    string id, latitud, longitud;
    double dlat, dlon;
    string est;
    int estado;

    //Asociamos el flujo al fichero 
    fe.open(fileNameMotos);

    if (fe.good()) {
        int primera = 0;
        //Mientras no se haya llegado al final del fichero
        while (!fe.eof()) {
            getline(fe, linea); //Toma una línea del fichero
            stringstream ss; //Stream que trabaja sobre buffer interno         

            if (linea != "") {
                ++total;
            }

            if (total > 1) {
                //Inicializamos el contenido de ss
                ss << linea;

                //Leemos el NIF
                getline(ss, id, ';'); //El carácter ; se lee y se elimina de ss

                //Leemos el pass
                getline(ss, est, ';'); //El caráter ; se lee y se elimina de ss

                //Leemos la latitud y longitud
                getline(ss, latitud, ';'); //El caráter ; se lee y se elimina de ss
                getline(ss, longitud, ';'); //El caráter ; se lee y se elimina de ss

                estado = stod(est);
                dlat = stod(latitud);
                dlon = stod(longitud);

                UTM pos(dlat, dlon);

                Estado esta;
                if (estado == 0)
                    esta = bloqueada;
                else if (estado == 1)
                    esta = activa;
                else if (estado == 2)
                    esta = sinbateria;
                else
                    esta = rota;
                //con todos los atributos leídos, se crea el cliente
                Moto mot(id, pos, esta);

                vectorMotos.push_back(mot);
            }
        }

        cout << "Total de motos en el fichero: " << total << endl;
        fe.close(); //Cerramos el flujo de entrada
    } else {
        cerr << "No se puede abrir el fichero" << endl;
    }
}

vector<Moto*> EcoCityMoto::localizaMotosSinBateria() {
    vector<Moto*> motossinbateria;

    for (int i = 0; i < vectorMotos.size(); i++) {
        if (vectorMotos[i].GetEstatus() == sinbateria) {
            motossinbateria.push_back(&vectorMotos[i]);
        }
    }


    return motossinbateria;
}

void EcoCityMoto::nuevoCliente(Cliente &cli) {
    
    float numcolisionesantes=arbolCliente.getNumColisiones();
    
    char c[cli.getDni().size() + 1];
    strcpy(c, cli.getDni().c_str());

    cli.setAcceso(this);
    arbolCliente.insertarDoble1(djb2(c),cli.getDni(),cli);
    
    float numcolisionesdespues=arbolCliente.getNumColisiones();
    
    cout<<endl<<"Numero de colisiones producidas en la insercion del nuevo cliente: "<<
            numcolisionesdespues-numcolisionesantes<<endl;
}

void EcoCityMoto::eliminarCliente(string id) {
    char c[id.size() + 1];
    strcpy(c,id.c_str());


    arbolCliente.borrar(djb2(c),id);
}

void EcoCityMoto::GuardarClientes(string nombreArchivo) {
//    //Crea un fichero de salida
//    ofstream fs(nombreArchivo, std::ofstream::out);
//    //Enviamos una cadena al fichero de salida :
//    map<string, Cliente>::iterator ite;
//    for (ite = arbolCliente.begin(); ite != arbolCliente.end(); ite++) {
//        fs << arbolCliente[(*ite).first].getDni() << ";";
//        fs << arbolCliente[(*ite).first].getPass() << ";";
//        fs << arbolCliente[(*ite).first].getNombre() << ";";
//        fs << arbolCliente[(*ite).first].getDireccion() << ";";
//        fs << arbolCliente[(*ite).first].getlatitud() << ";";
//        fs << arbolCliente[(*ite).first].getlongitud() << ";";
//
//        list<Itinerario> aux = arbolCliente[(*ite).first].getRutas();
//
//        fs << aux.size() << ";";
//
//        list<Itinerario>::iterator it = aux.begin();
//
//        for (int i = 0; i < aux.size(); i++) {
//            fs << (*it).getId() << ";";
//            fs << (*it).getInicio().latitud << ";";
//            fs << (*it).getInicio().longitud << ";";
//            fs << (*it).getFin().latitud << ";";
//            fs << (*it).getFin().latitud << ";";
//            fs << (*it).getFecha().verDia() << ";";
//            fs << (*it).getFecha().verMes() << ";";
//            fs << (*it).getFecha().verAnio() << ";";
//            fs << (*it).getFecha().verHora() << ";";
//            fs << (*it).getFecha().verMin() << ";";
//            fs << (*it).getMinutos() << ";";
//
//            it++;
//        }
//
//        fs << endl;
//
//    }
//    fs.close();
}








