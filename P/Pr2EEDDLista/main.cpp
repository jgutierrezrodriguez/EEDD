/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: macosx
 *
 * Created on 26 de septiembre de 2019, 10:52
 */

#include <cstdlib>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Cliente.h"
#include "VDinamico.h"
#include "UTM.h"
using namespace std;

/*
 *
 */

float distanciaUTM(UTM u1, UTM u2) {

    return sqrt(pow((u2.GetLatitud() - u1.GetLatitud()), 2) + pow((u2.GetLongitud() - u1.GetLongitud()), 2));
}

void leeClientes(string fileNameClientes) {
    ifstream fe; //Flujo de entrada
    string linea; //Cada línea tiene un clienete
    int total = 0; //Contador de líneas o clientes

    //Variables auxiliares para almacenar los valores leídos
    string dni, nombre, pass, direccion, latitud, longitud;
    double dlat, dlon;



    //Asociamos el flujo al fichero 
    fe.open(fileNameClientes);

    if (fe.good()) {
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
                cout << "leido cliente " << total << "  " << endl;
            }
        }

        cout << "Total de clientes en el fichero: " << total << endl;
        fe.close(); //Cerramos el flujo de entrada
    } else {
        cerr << "No se puede abrir el fichero" << endl;
    }
}

int main(int argc, char** argv) {
    VDinamico<Cliente> clientes;
    cout << "Comienzo de lectura de un fichero " << endl;
    ifstream fe; //Flujo de entrada
    string linea; //Cada línea tiene un clienete
    int total = 0; //Contador de líneas o clientes

    //Variables auxiliares para almacenar los valores leídos
    string dni, nombre, pass, direccion, latitud, longitud;
    double dlat, dlon;



    //Asociamos el flujo al fichero 
    fe.open("clientes_v2.csv");

    if (fe.good()) {
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
                client.creaIntinerarios();
                clientes.insertar(client);
                //cout << "leido cliente " << total << "  " <<client.GetDni()<< endl;
                total++;
            }
        }

        cout << "Total de clientes en el fichero: " << total << endl;
        fe.close(); //Cerramos el flujo de entrada
    } else {
        cerr << "No se puede abrir el fichero" << endl;
    }
    //for (int i = 0; i < clientes.tam(); i++)
    //{
    //	std::cout<<"Cliente: "<<clientes[i].GetDni() << std::endl;;
    //}

    VDinamico<Cliente> clientes2;
    clientes2 = clientes;
    clientes2.ordenar();
    for (int i = 0; i < clientes.tam(); i++) {
        std::cout << "Cliente: " << clientes2[i].GetNombre() << std::endl;
    }
    Cliente cl;
    bool eliminar = true;
    string nombreEliminar = "Abby";
//    int pos = clientes2.busquedaBin(nombreEliminar);
//    ListaEnlazada<Itinerario> lista = clientes2[pos].GetItinerarios();
//    Iterador<Itinerario> it = lista.iterador();
//    for (int i = 0; i < lista.getTama(); i++) {
//        it.dato().toString();
//        it.siguiente();
//    }



    //    if (pos != -1) {
    //        std::cout << "Cliente Encontrado pos: " << pos << " nombre: " << clientes2[pos].GetNombre() << std::endl;
    //        for (int i = pos; i < clientes2.tam() || eliminar; i++) {
    //            if (clientes2[i].GetNombre().find(nombreEliminar) != std::string::npos) {
    //                std::cout << "Cliente borrado: " << clientes2[i].GetNombre() << std::endl;
    //                clientes2.eliminar(i);
    //            } else {
    //                eliminar = false;
    //            }
    //        }
    //    } else {
    //        std::cout << " Cliente NO encontrado: " << std::endl;
    //    }
    //
    //
    //
    //
    //    int menor = 0;
    //    int mayor = 0;
    //
    //    float distancia = 0, distanciamayor = 0;
    //
    //    for (int i = 0; i < clientes2.tam(); i++) {
    //        for (int j = 0; j < clientes2.tam(); j++) {
    //            if (j > i) {
    //                distancia = distanciaUTM(clientes2[i].GetPosicion(), clientes2[j].GetPosicion());
    //                if (distancia > distanciamayor) {
    //                    distanciamayor = distancia;
    //                    mayor = i;
    //                    menor = j;
    //                    std::cout << "La distancia maxima temporal es: " << distanciamayor << " Entre Los clientes : " << clientes2[mayor].GetNombre() << " y " << clientes2[menor].GetNombre() << std::endl;
    //                }
    //            }
    //        }
    //
    //    }
    //    std::cout << "La distancia maxima es: " << distanciamayor;
    return 0;
}



