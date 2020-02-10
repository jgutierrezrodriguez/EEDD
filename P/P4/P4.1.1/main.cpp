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
    empresa.cargaClientes("clientes_v2.csv");
    Cliente aux("53597992b", "", "", "", 37, 3);
    empresa.nuevoCliente(aux);
    
    //Ejercicio 2
    
    Cliente busqueda;
    busqueda=empresa.BuscarCliente("53597992b");
    
    
    Moto mot = busqueda.buscarMotoCercana();
    
    cout<<"Moto id: "<<mot.GetId();
    cout<<"\nMoto pb: "<<mot.GetPorcentajeBateria();
    //Ejercicio 3
    
    busqueda.desbloquearMoto(mot);
    busqueda.terminarTrayecto(mot);
    
    busqueda.mostrarItinerarios();
    
    //Ejercicio 4
    
    vector<Moto> sinbateria = empresa.localizaMotosSinBateria();
    cout<<"\nTamaño sin bateria: "<<sinbateria.size();
    vector<Moto>::iterator it;
    
    bool encontrado=false;
    
    for(int i =0; i<sinbateria.size();i++){
        if(sinbateria[i].GetId()==mot.GetId())
            encontrado=true;
    }
    
    if(encontrado)
        cout<<"\nMoto encontrada sin bateria.";
    else
        cout<<"\nno encontrada.";
            

    
}

