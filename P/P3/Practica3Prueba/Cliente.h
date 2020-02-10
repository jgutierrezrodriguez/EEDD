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
/*
#ifndef CLIENTE_H
#define CLIENTE_H
#include "ListaDobleEnlazada.h"
#include <cmath>
#include <string>
//#include "EcoCityMoto.h"
#include "UTM.h"
#include <ctime>
//#include "Itinerario.h"
//#include "EcoCityMoto.h"


using namespace std;

//class Itinerario;
//class EcoCityMoto;

class Cliente {

    string dni;
    string pass;
    string nombre;
    string direccion;
    UTM posicion;
  //  EcoCityMoto* empresaMotos;
    //Moto* motousada;
    
    //ListaDobleEnlazada<Itinerario> rutas;

    
public:
    Cliente(string _dni, string _pass, string _nombre, string _direccion, double _latitud, double _longitud);
    
    Cliente();
    
    Cliente(const Cliente& other);
    
    Cliente& operator=( const Cliente &otro);
    
    bool operator<(const Cliente& otro) const;
    
    bool operator==(const Cliente &otro);
    
    double getlatitud();
    
    double getlongitud();
    
    UTM getPosicion(){
        return posicion;
    }
    
    
    //void setEmpresaMoto(EcoCityMoto *otro);
    
    double distancia(Cliente &c);
    
    void creaitinerarios(int num, int &idUltimo, UTM min, UTM max);
    
    //ListaDobleEnlazada<Itinerario> getListaItinerarios();
    
    void mostrarItinerarios();

    virtual ~Cliente();
    
    string getDni() const;

    //Moto buscarMotoCercana();
    
    /*void desbloquearMoto(Moto vehi){
        empresaMotos->DesbloqueaMoto(vehi,*this);
    }
    
    void terminarTrayecto(){
        empresaMotos->terminarTrayectoCliente(*this);
    }

};

#endif CLIENTE_H */

