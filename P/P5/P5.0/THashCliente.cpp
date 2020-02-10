/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   THashCliente.cpp
 * Author: jonathan
 * 
 * Created on 15 de noviembre de 2019, 11:59
 */

#include "THashCliente.h"

THashCliente::THashCliente(int tamtabla) : tamhash(tamtabla), numclientes(0), nColisiones(0), nInserciones(0), totalColisiones(0) {
}

THashCliente::THashCliente(const THashCliente& orig) : tamhash(orig.tamhash), hashmap(orig.hashmap), numclientes(orig.numclientes),
factordecarga(orig.factordecarga), maxColisiones(orig.maxColisiones), nColisiones(orig.nColisiones), nInserciones(orig.nInserciones),
totalColisiones(orig.totalColisiones) {
}

THashCliente::~THashCliente() {
}

unsigned long THashCliente::djb2(unsigned char* str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

float THashCliente::getFactordecarga() const {
    return factordecarga;
}

unsigned int THashCliente::getTamhash() const {
    return tamhash;
}

unsigned int THashCliente::numClientes() {
    return numclientes;
}

void THashCliente::setFactordecarga(float factordecarga) {
    this->factordecarga = factordecarga;
}

void THashCliente::setTamhash(unsigned int tamhash) {
    this->tamhash = tamhash;
}

unsigned int THashCliente::promedioColisiones() {
    return nInserciones / nColisiones;
}

unsigned int THashCliente::MaxColisiones() {
    return maxColisiones;
}

bool THashCliente::insertar(unsigned long clave, string& dni, Cliente& cli) {
    bool insertado = false;
    int intentos = 0;
}

bool THashCliente::borrar(unsigned long clave, string& dni) {

}

//bool THashCliente::buscar(unsigned long clave, string& dni, Cliente*& cli) { //da error en el (&*) mirar que es.
//    bool encontrado=false;
//    int intentos=0;
//    unsigned int pos= djb2(dni);
//        if(hashmap[pos].getTermino() == term){
//            aux = *(vec[pos].getDatos());
//            encontrado = true;
//            return aux;
//        }
//}

void THashCliente::redispersar(unsigned tama) {

}
