/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TablaHashCliente.cpp
 * Author: jgr97
 * 
 * Created on 30 de noviembre de 2019, 9:32
 */

#include "TablaHashCliente.h"

TablaHashCliente::TablaHashCliente(int tamF) : tam(tamF), entradas() {
    Entrada entr;
    for(int i=0;i<tamF;i++){
        entradas.push_back(entr);
    }
}

float TablaHashCliente::factorCarga() {
    return numTerminos / tam;
}

float TablaHashCliente::maxCol() {
    return maxColisiones;
}

float TablaHashCliente::numClientes() {
    return numTerminos;
}

float TablaHashCliente::proCol() {
    return numColisiones / numTerminos;
}

float TablaHashCliente::tama() {
    return tam;
}

bool TablaHashCliente::coprimo(unsigned num) {
    for (unsigned i = 2; i < num / 2; ++i)
        if (num % i == 0)
            return false;
    return true;
}

int TablaHashCliente::primoMenor(unsigned num) {
    int numi = num - 1;
    while (!coprimo(numi)) {
        --numi;
    }
    return numi;
}

unsigned TablaHashCliente::hashDoble1(unsigned long clave, int intento) {
    int posicion, posicion_final;
    int primoMen = primoMenor(tam);
    posicion = clave % tam;
    posicion_final = (posicion + (intento * (primoMen - (clave % (primoMen))))) % tam;
    return posicion_final;
}

unsigned TablaHashCliente::hashDoble2(unsigned long clave, int intento) {
    unsigned int posicion, porcentaje;
    porcentaje = clave % entradas.size() + (intento * clave % entradas.size());
    posicion = porcentaje % entradas.size();
    return posicion;
}

unsigned TablaHashCliente::hashCuadratica(unsigned long clave, int intento) {
    unsigned long pos = (clave + (intento * intento)) % tam;
    return pos;
}

bool TablaHashCliente::insertarDoble1(unsigned long clave, string& dni, Cliente& cli) {

    if (factorCarga() > 0.7)
        redispersar(tam * 2);
    
    int contCol=0;
    unsigned int pos=hashDoble1(clave, contCol);
     
    while(entradas[pos].estado==ocupado && entradas[pos].claveEntrada!=clave){
        pos=hashDoble1(clave, contCol);
        contCol++;
    }
 
    //cout<<max<<endl;
    if(entradas[pos].claveEntrada!=clave){
        entradas[pos].cliente=cli;
        entradas[pos].claveEntrada=clave;
        entradas[pos].estado=ocupado;
        
        numTerminos++;
        
        if(maxColisiones<contCol-1) 
            maxColisiones=contCol-1;
        
        numColisiones+=contCol;
        
        return true;
    }else{
        return false;
    }
    
    
}


bool TablaHashCliente::insertarDoble2(unsigned long clave, string& dni, Cliente& cli) {

    if (factorCarga() > 0.7)
        redispersar(tam * 2);
    
    int contCol=0;
    unsigned int pos=hashDoble2(clave, contCol);
     
    while(entradas[pos].estado==ocupado && entradas[pos].claveEntrada!=clave){
        pos=hashDoble2(clave, contCol);
        contCol++;
    }
 
    //cout<<max<<endl;
    if(entradas[pos].claveEntrada!=clave){
        entradas[pos].cliente=cli;
        entradas[pos].claveEntrada=clave;
        entradas[pos].estado=ocupado;
        
        numTerminos++;
        
        if(maxColisiones<contCol-1) 
            maxColisiones=contCol-1;
        
        numColisiones+=contCol;
        
        return true;
    }else{
        return false;
    }
}

bool TablaHashCliente::insertarcuadratica(unsigned long clave, string& dni, Cliente& cli) {

    if (factorCarga() > 0.7)
        redispersar(tam * 2);
    
    int contCol=0;
    unsigned int pos=hashCuadratica(clave, contCol);
     
    while(entradas[pos].estado==ocupado && entradas[pos].claveEntrada!=clave){
        pos=hashCuadratica(clave, contCol);
        contCol++;
    }
 
    //cout<<max<<endl;
    if(entradas[pos].claveEntrada!=clave){
        entradas[pos].cliente=cli;
        entradas[pos].claveEntrada=clave;
        entradas[pos].estado=ocupado;
        
        numTerminos++;
        
        if(maxColisiones<contCol-1) 
            maxColisiones=contCol-1;
        
        numColisiones+=contCol;
        
        return true;
    }else{
        return false;
    }
}

bool TablaHashCliente::borrar(unsigned long clave, string& dni) {
    bool encontrado = false;
    unsigned cont = 0, posicion = 0;
    unsigned limite = 50;
    
    while (!encontrado && cont < limite) {
        posicion = hashDoble2(clave, cont);
        if (entradas[posicion].estado == ocupado && entradas[posicion].dni==dni) {
            encontrado=true;
            entradas[posicion].estado == borrado;
            numTerminos--;
            
            if(factorCarga()<0.7){
                redispersar(tam*2);
                cout<<"Se ha redispersado. Tama: "<<tam;
            }
        } else {
            cont++;
        }

    }
    
    
    //Si no es encontrado llegamos a este return
    return encontrado;
}

Cliente* TablaHashCliente::buscar(unsigned long clave, string& dni, Cliente & cli){
    int intento=0;
    unsigned int posicion=hashDoble1(clave,intento);
    
    while(entradas[posicion].estado==ocupado || entradas[posicion].estado==borrado){
        if(entradas[posicion].claveEntrada==clave){
            return &entradas[posicion].cliente;
        }else{
            intento++;
            posicion=hashDoble1(clave, intento);  
        }
    }
    return NULL;
}

void TablaHashCliente::redispersar(int tama) {
    
    TablaHashCliente nueva(tama);
    
    for(int i=0; i<entradas.size(); i++){
        if(entradas[i].estado==ocupado)
            nueva.insertarDoble1(entradas[i].claveEntrada,entradas[i].dni,entradas[i].cliente);
    }
    
    *this=nueva;
}

TablaHashCliente::~TablaHashCliente() {
}

float TablaHashCliente::getNumColisiones() const {
    return numColisiones;
}

void TablaHashCliente::mostrarInfo() {
    cout << endl << "Max colisiones: " << maxColisiones << endl;
    cout << "Promedio colisiones: " << proCol() << endl;
    cout << "Factor de carga: " << factorCarga() << endl;
    cout << "Tam tabla: " << tama() << endl;
    cout << "Num terminos: " << numTerminos << endl;
    cout << "Num colisiones: " << numColisiones << endl;
}


