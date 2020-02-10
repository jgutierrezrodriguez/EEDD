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

EcoCityMoto::EcoCityMoto() : idUltimo(0) {
}

EcoCityMoto::EcoCityMoto(vector<Moto> &vectorMotos, map<string,Cliente> &arbolCliente) :
vectorMotos(vectorMotos), arbolCliente(arbolCliente) {
}


EcoCityMoto::EcoCityMoto(const EcoCityMoto& orig) : idUltimo(orig.idUltimo), vectorMotos(orig.vectorMotos), arbolCliente(orig.arbolCliente) {
}

EcoCityMoto::~EcoCityMoto() {
}


Cliente EcoCityMoto::BuscarCliente(string DNI) {
    
    map<string, Cliente>::iterator it;
    
    it=arbolCliente.find(DNI);
    return it;
    
}

void EcoCityMoto::DesbloqueaMoto(Moto& Mo) {
    
  
    
    vector<Moto>::iterator it;
    it=find(vectorMotos.begin(),vectorMotos.end(),Mo);
    it->seActiva();
}

Moto EcoCityMoto::MotoCercana(UTM ubicacion) {
    double distancia = 0;
    double minimadistancia = 9999;
    Moto motodef;
    int i=0;
  
    for (i; i < vectorMotos.size(); i++) {
        
        UTM aux = vectorMotos[i].GetPosicion();
        
        double distancia = ubicacion.distacia(aux);

        if (distancia < minimadistancia) {
            minimadistancia = distancia;
            motodef=vectorMotos[i];
        }
    }  
        return motodef;
}

void EcoCityMoto::SetVectorMotos(vector<Moto> vectorMotos) {
    this->vectorMotos = vectorMotos;
}


void EcoCityMoto::SetArbolCliente(map<string,Cliente> arbolCliente) {
    this->arbolCliente = arbolCliente;
}

void EcoCityMoto::cargaClientes(string fileNameClientes) {
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

                arbolCliente.insert(std::pair<string, Cliente>(dni, client));
            }
        }

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
    vector<Moto>::iterator it = vectorMotos.begin();



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

                vectorMotos.insert(it, mot);
                it++;
            }
        }

        cout << "Total de motos en el fichero: " << total << endl;
        fe.close(); //Cerramos el flujo de entrada
    } else {
        cerr << "No se puede abrir el fichero" << endl;
    }
}

vector<Moto> EcoCityMoto::localizaMotosSinBateria() {
    vector<Moto> motossinbateria;
    vector<Moto>::iterator itsinbateria = motossinbateria.begin();

    for (int i = 0; i < vectorMotos.size(); i++) {
        if (vectorMotos[i].estatus == sinbateria) {
            motossinbateria.insert(itsinbateria, vectorMotos[i]);
            itsinbateria++;
        }
    }

    return motossinbateria;
}

void EcoCityMoto::nuevoCliente(Cliente cli) {
    arbolCliente.insert(std::pair<string, Cliente>(cli.getDni(), cli));
}


void EcoCityMoto::eliminarCliente(string id) {
    map<string, Cliente>::iterator it;
    it = arbolCliente.find(id);
    arbolCliente.erase(it);
}










