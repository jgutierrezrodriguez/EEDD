/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jonathan
 *
 * Created on 19 de octubre de 2019, 17:32
 */

#include <cstdlib>
#include "EcoCityMoto.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <exception>

using namespace std;

void leeClientes(string fileNameClientes, AVL<Cliente> &arbol, double & latMax, double & latMin, double & lonMax, double & lonMin) {
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

                if (primera == 0) {
                    latMax = dlat;
                    latMin = dlat;
                    lonMax = dlon;
                    lonMin = dlon;

                    primera++;
                } else {
                    if (dlat > latMax)
                        latMax = dlat;
                    else if (dlat < latMin)
                        latMin = dlat;

                    if (dlon > lonMax)
                        lonMax = dlon;
                    else if (dlon < lonMin)
                        lonMin = dlon;
                }

                arbol.inserta(client);
            }
        }

        cout << "Total de clientes en el fichero: " << total << endl;
        fe.close(); //Cerramos el flujo de entrada
    } else {
        cerr << "No se puede abrir el fichero" << endl;
    }
}

void leeMotos(string fileNameClientes, VDinamico<Moto> &v) {
    ifstream fe; //Flujo de entrada
    string linea; //Cada línea tiene un clienete
    int total = 0; //Contador de líneas o clientes

    //Variables auxiliares para almacenar los valores leídos
    string id, latitud, longitud;
    double dlat, dlon;
    string est;
    int estado;



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

                v.insertar(mot);
            }
        }

        cout << "Total de motos en el fichero: " << total << endl;
        fe.close(); //Cerramos el flujo de entrada
    } else {
        cerr << "No se puede abrir el fichero" << endl;
    }
}

int main(int argc, char** argv) {

    try {
        AVL<Cliente> arbolcli;
        VDinamico<Moto> vectormot;
        double latMax, latMin, LonMax, LonMin;

        leeClientes("clientes_v2.csv", arbolcli, latMax, latMin, LonMax, LonMin);

        //arbolcli.recorreInorden(arbolcli.GetRaiz());
        cout << "\nAltura del arbol:" << arbolcli.retAltura() << "\n";

        leeMotos("motos.txt", vectormot);

        EcoCityMoto empresa(vectormot, arbolcli);
        
        EcoCityMoto *p=&empresa;

        Cliente *client;
        

        cout << "\n\nEntra en ecocity.";
        

        client = empresa.BuscarCliente("98907675B");
        
        client->setAcceso(p);
        if (client->getDni() == "98907675B") {
            Moto *M;
            cout<<"\nSe busca la moto.";
            M=client->buscarMotoCercana();
            cout<<"\nMoto Cercana: "<<M->GetId()<<"\nSe desbloquea la moto.";
            client->desbloquearMoto(M);
            cout<<"\nSe termina el trayecto.";
            client->terminarTrayecto(M);
            
            cout<<"\nSe ha creado un itinerario y se muestra.";
            client->mostrarItinerarios();

        } else {
            cout << "\nNo se ha encontrado el cliente.";
        }
    } catch (std::out_of_range& e) {
        e.what();
    }

}

