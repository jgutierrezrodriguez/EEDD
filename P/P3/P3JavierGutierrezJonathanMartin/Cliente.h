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
#include "EcoCityMoto.h"
#include "UTM.h"
#include <ctime>
#include "Itinerario.h"


using namespace std;

class EcoCityMoto;

class Cliente {

    string dni;
    string pass;
    string nombre;
    string direccion;
    UTM posicion;
    EcoCityMoto *acceso;
    
    ListaDobleEnlazada<Itinerario> rutas;

    
public:
    Cliente(string _dni, string _pass, string _nombre, string _direccion, double _latitud, double _longitud);
    
    Cliente();
    
    Cliente(const Cliente& other);
    
    Cliente& operator=( const Cliente &otro);
    
    bool operator<(const Cliente& otro) const;
    
    bool operator==(const Cliente &otro);
    
    bool operator>(const Cliente& otro) const;
    
    friend ostream&  operator<<(ostream& os, const Cliente& obj);
    
    double getlatitud();
    
    double getlongitud();
    
    double distancia(Cliente &c);
    
    void creaitinerarios(int num, int &idUltimo, UTM min, UTM max);
    
    ListaDobleEnlazada<Itinerario> getListaItinerarios();
    
    void mostrarItinerarios();

    virtual ~Cliente();
    
    string getDni() const;
    
    void setDNI(string _dni);

    Moto* buscarMotoCercana();
    
    void desbloquearMoto(Moto* m);
    
    void terminarTrayecto(Moto *m);
    
    void setAcceso(EcoCityMoto* acceso);

};

#endif /* CLIENTE_H */

