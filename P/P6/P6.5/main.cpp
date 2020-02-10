/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jgr97
 *
 * Created on 3 de diciembre de 2019, 17:49
 */

#include <cstdlib>
#include <iostream>
#include <valarray>
#include "MallaRegular.h"
#include "EcoCityMoto.h"

using namespace std;

void GuardarPuntosRecarga(string nombreArchivo, float latitud, float longitud, float latitud2, float longitud2) {

    float Rlat = latitud2 - latitud;
    float Rlon = longitud2 - longitud;
    //generamos el archivo
    ofstream fs(nombreArchivo, std::ofstream::out);

    for (int i = 0; i < 300; i++) {
        fs << i << ";";
        float r = static_cast<float> (rand()) / static_cast<float> (RAND_MAX);

        //        float lat //= latitud + (float)rand()%Rlat;
        //        float lon //= longitud + (float)rand()%Rlon;
        fs << latitud + r << ";";
        fs << longitud + r << ";" << endl;
    }

    fs << endl;

    fs.close();
}

/*
 * 
 */
int main(int argc, char** argv) {

    EcoCityMoto empresa(15269,36,2,39,5,50,50);
    EcoCityMoto empresa2(15269,34,1,40,6,10,10);
    
    cout<<"Carga puntos de recarga en las empresas."<<endl;
    empresa.CargarPuntosRecarga("prueba");
    empresa2.CargarPuntosRecarga("prueba");
    
    cout<<endl<<"Datos empresa 1: ";
    empresa.mostrarInfoMalla();
    
    cout<<endl<<"Datos empresa 2: ";
    empresa2.mostrarInfoMalla();
    
    cout<<endl<<"Carga clientes."<<endl;
    empresa.cargaClientesHashDoble1("clientes_v2.csv");
    
    cout<<endl<<"Carga motos."<<endl;
    empresa.cargaMotos("motos.txt");
    
    
    //ejercicio 4
    Cliente jon("58978549A", "123", "Jonathan", "Granada", 37.090, 3.091);
    cout<<endl<<"Inserta un nuevo cliente.";
    empresa.nuevoCliente(jon);

    //ejercicio 5
    Cliente* puntero = empresa.BuscarCliente("58978549A");
    cout<<endl<<"Informacion cliente insertado y buscado:"<<endl;
    cout <<"\t- Nombre: " <<puntero->getNombre() << endl;
    cout <<"\t- DNI: "<< puntero->getDni() << endl;
    cout << "\t- Direccion: "<< puntero->getDireccion() << endl;
    cout << "\t- Puntos: "<< puntero->getPuntos() << endl;
    //ejercicio 6
    Moto* M = puntero->buscarMotoCercana();
    cout << endl<<"Se busca una moto cerca del cliente: "<< M->GetId()<< endl;
    
    vector<Moto*> vecMotos;
    vecMotos=empresa.localizaMotosSinBateria();
    cout<<endl<<"Se localizan las motos sin bateria y que estan fuera de ambito:"<<endl;
    cout<<"\t -Tamaño vector motos sin bateria: "<<vecMotos.size()<<endl;
    
    cout<<endl<<"El cliente desbloquea la moto buscada y realiza un trayecto:"<<endl;
    puntero->desbloquearMoto(M);
    puntero->terminarTrayecto(M);
    
    cout<<"Porcentaje de bateria tras el recorrido: "<<M->GetPorcentajeBateria()<<endl;
    
    if(M->GetPorcentajeBateria()<=15){
        
        cout<<endl<<"Se busca un punto de recarga cercano: "<<endl;
        PuntoRecarga* precarga;
        precarga=empresa.puntoRecargaCercano(puntero);
        
        cout<<"\t- Id Punto de recarga cercano: "<<precarga->GetId()<<endl;
        
        cout<<endl<<"Se recarga la moto en el punto de recarga:"<<endl;
        puntero->recargarMoto(M,precarga);

        cout<<"Puntos despues: "<<puntero->getPuntos()<<endl;
    }

}

