#pragma once
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Cliente.h
 * Author: macosx
 *
 * Created on 26 de septiembre de 2019, 10:56
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <cstdlib>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "ListaEnlazada.h"
#include "Itinerario.h"
#include <time.h>
#include "UTM.h"
using namespace std;

class Cliente {
private:
    string dni;
    string pass;
    string nombre;
    string direccion;
    UTM posicion;
    ListaEnlazada<Itinerario> itinerarios;
public:
    //Constructor
    Cliente();
    Cliente(string _dni, string _pass, string _nombre, string _direccion, double _latitud, double _longitud);
    Cliente(const Cliente& orig);
    ~Cliente();
    bool operator<(Cliente& right);
    void SetPosicion(UTM posicion);
    UTM GetPosicion() const;
    void SetDireccion(string direccion);
    string GetDireccion() const;
    void SetNombre(string nombre);
    string GetNombre() const;
    void SetPass(string pass);
    string GetPass() const;
    void SetDni(string dni);
    string GetDni() const;
    bool operator==(const Cliente& right);
    void creaIntinerarios();
    ListaEnlazada<Itinerario> GetItinerarios() const;

};

#endif /* CLIENTE_H */


