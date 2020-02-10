 /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jgr97
 *
 * Created on 30 de noviembre de 2019, 9:25
 */

#include <cstdlib>
#include "EcoCityMoto.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    //PROGRAMA 1
    
    EcoCityMoto empresa1(15269);
    EcoCityMoto empresa2(15269);
    EcoCityMoto empresa3(15269);
    EcoCityMoto empresa4(17123);
    EcoCityMoto empresa5(17123);
    EcoCityMoto empresa6(17123);
    
    //Tamaño 1. Hash doble 1
    empresa1.cargaClientesHashDoble1("clientes_v2.csv");
    //Tamaño 1. Hash doble 2
    empresa2.cargaClientesHashDoble2("clientes_v2.csv");
    //Tamaño 1. Hash cuadratico
    empresa3.cargaClientesHashcuadratica("clientes_v2.csv");
    //Tamaño 2. Hash doble 1
    empresa4.cargaClientesHashDoble1("clientes_v2.csv");
    //Tamaño 2. Hash doble 2
    empresa5.cargaClientesHashDoble2("clientes_v2.csv");
    //Tamaño 2. Hash cuadratico
    empresa6.cargaClientesHashcuadratica("clientes_v2.csv");
    
    //PROGRAMA 2
    empresa1.cargaMotos("motos.txt");
    Cliente nuevo("53597992B", "123", "Javier Gutierrez Rodriguez", "Cerro del Humilladero 3", 37, 3);
    
    empresa1.nuevoCliente(nuevo);

    
    Cliente *p;
    p=empresa1.BuscarCliente("53597992B");
    
    cout<<endl<<"DNI buscado: "<<p->getDni()<<endl;
    cout<<"Nombre buscado: "<<p->getNombre()<<endl;
    
    Moto* mot;
    mot=p->buscarMotoCercana();
    
    cout<<endl<<"Id moto cercana: "<<mot->GetId()<<endl;
    
    p->desbloquearMoto(mot);
    p->terminarTrayecto(mot);
    
    empresa1.eliminarCliente("53597992B");
    
    empresa1.nuevoCliente(nuevo);
    
    Cliente *j;
    j=empresa1.BuscarCliente("53597992B");
    
    cout<<endl<<"DNI buscado 2: "<<j->getDni()<<endl;
    cout<<"Nombre buscado 2: "<<j->getNombre()<<endl;
    
    empresa1.eliminamilclientes();
    
    return 0;
}

