/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jonathan
 *
 * Created on 15 de noviembre de 2019, 11:54
 */

#include <cstdlib>
#include "EcoCityMoto.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    vector<Moto> motos;
//    EcoCityMoto empresa1(15000);
//    EcoCityMoto empresa2(15000);
    EcoCityMoto empresa3(15000);
//    EcoCityMoto empresa4(20000);
//    EcoCityMoto empresa5(20000);
//    EcoCityMoto empresa6(20000);
//    empresa1.cargaClientes("clientes_v2.csv",1);
//    empresa2.cargaClientes("clientes_v2.csv",2);
    empresa3.cargaClientes("clientes_v2.csv",3);
//    empresa4.cargaClientes("clientes_v2.csv",1);
//    empresa5.cargaClientes("clientes_v2.csv",2);
//    empresa6.cargaClientes("clientes_v2.csv",3);
    
    
    
    Cliente aux("javivi", "", "", "", 37, 3);
    cout<<"\n";
    empresa3.nuevoCliente(aux);
    
    Cliente *cli;
    cli=empresa3.BuscarCliente(aux.getDni());
    
    cout <<cli;
//    
    
    
    
}

