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
    THashCliente prueba(13337);
    vector<Moto> prueba2;
    EcoCityMoto empresa(prueba2,prueba);
    empresa.cargaClientes("clientes_v2.csv");
}

