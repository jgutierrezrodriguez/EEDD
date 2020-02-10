/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: jgr97
 *
 * Created on 7 de octubre de 2019, 12:47
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include "ListaDobleEnlazada.h"
#include <cmath>
#include <string>
#include "Itinerario.h"
#include "time.h"


using namespace std;

class Cliente {

    string dni;
    string pass;
    string nombre;
    string direccion;
    UTM posicion;
    
    ListaDobleEnlazada<Itinerario> listaItinerarios;

    
public:
    Cliente(string _dni, string _pass, string _nombre, string _direccion, double _latitud, double _longitud);
    
    Cliente();
    
    Cliente(const Cliente& other);
    
    Cliente& operator=( const Cliente &otro);
    
    bool operator<(const Cliente& otro) const;
    
    bool operator==(const Cliente &otro);
    
    double getlatitud();
    
    double getlongitud();
    
    double distancia(Cliente &c);
    
    void creaitinerarios(int num, int &idUltimo, UTM min, UTM max);
    
    ListaDobleEnlazada<Itinerario> getListaItinerarios();
    
    void mostrarItinerarios();

    virtual ~Cliente();

};

#endif /* CLIENTE_H */

