/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jgr97
 *
 * Created on 30 de octubre de 2019, 9:10
 */

#include <cstdlib>
#include "AVL.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int v[6]={2,34,1,5,6,8};
    AVL<int> arbol;
    
   
    for(int i =0; i<6;i++){
        arbol.inserta(v[i]);
    }
    
    arbol.recorreInorden(arbol.GetRaiz());
    
    int j;
    int busqueda=34;
    arbol.busquedaRecursiva(busqueda,j);
    
    cout << "Buscado encontrado: "<<j;
}

