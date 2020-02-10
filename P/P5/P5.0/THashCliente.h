/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   THashCliente.h
 * Author: jonathan
 *
 * Created on 15 de noviembre de 2019, 11:59
 */

#ifndef THASHCLIENTE_H
#define THASHCLIENTE_H

#include <string>
#include <iostream>
#include "Cliente.h"
#include "Entrada.h"
#include <strstream>

using namespace std;

class THashCliente {
public:
    THashCliente(int tamtabla);
    THashCliente(const THashCliente& orig);
    virtual ~THashCliente();

    //funciones.
    unsigned long djb2(unsigned char *str);
    unsigned int numClientes();
    float getFactordecarga() const;
    void setFactordecarga(float factordecarga);
    unsigned int getTamhash() const;
    void setTamhash(unsigned int tamhash);
    unsigned int promedioColisiones();
    unsigned int MaxColisiones();
   
    bool insertar(unsigned long clave, string &dni,Cliente &cli);
    //bool buscar(unsigned long clave, string &dni, Cliente &*cli);
    bool borrar(unsigned long clave, string &dni);
    void redispersar(unsigned tama);

private:
    unsigned int tamhash;
    unsigned int numclientes;
    float factordecarga;
    unsigned int nColisiones;
    unsigned int nInserciones;
    unsigned int totalColisiones;
    unsigned int maxColisiones;
    vector<Entrada> hashmap;


};

#endif /* THASHCLIENTE_H */

