/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jgr97
 *
 * Created on 5 de noviembre de 2019, 19:15
 */

#include <cstdlib>
#include "EcoCityMoto.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    //Ejercicio 1
    EcoCityMoto empresa;
    empresa.cargaMotos("motos.txt");
    empresa.cargaClientes("pruebanum1.csv");
    Cliente aux("javivi", "", "", "", 37, 3);
    empresa.nuevoCliente(aux);
    
    //Ejercicio 2
    Cliente *busqueda;
    busqueda=empresa.BuscarCliente("javivi");
    
    busqueda->setAcceso(&empresa);
  
    Moto *mot = busqueda->buscarMotoCercana();
    
    cout<<"Moto id: "<<mot->GetId();
    cout<<"\nMoto pb: "<<mot->GetPorcentajeBateria();
    //Ejercicio 3
    
    busqueda->desbloquearMoto(mot);
    busqueda->terminarTrayecto(mot);
    //Ejercicio 4
    
    busqueda->mostrarItinerarios();
    vector<Moto> sinbateria = empresa.localizaMotosSinBateria();
    
    bool encontrado=false;
    
    for(int i =0; i<sinbateria.size();i++){
        if(sinbateria[i].GetId()==mot->GetId())
            encontrado=true;
    }
    
    if(encontrado)
        cout<<"\nMoto encontrada en la lista de motos sin bateria.";
    else
        cout<<"\nNo encontrada en la lista de motos sin bateria.";
            
    //Ejercicio 5
    
    empresa.eliminarCliente(busqueda->getDni());
    
}

