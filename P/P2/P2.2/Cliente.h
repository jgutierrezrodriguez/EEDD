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

#include <cmath>
#include "ListaEnlazada.h"
#include "Itinerario.h"
#include <string>

using namespace std;



class Cliente {

private:
    string dni;
    string pass;
    string nombre;
    string direccion;
    UTM posicion;
   
    ListaDEnlazada<Itinerario> listaIti;
    
public:
    //Constructor
    Cliente(string _dni, string _pass, string _nombre, string _direccion, double _latitud, double _longitud):
    dni(_dni), pass(_pass), nombre(_nombre), direccion (_direccion), posicion (_latitud, _longitud){
        
    }
    
    Cliente():dni(""),pass(""),nombre(""),direccion(""),posicion(0,0){}
    
    Cliente& operator=(const Cliente &otro){
        dni=otro.dni;
        pass=otro.pass;
        nombre=otro.nombre;
        direccion=otro.direccion;
        posicion.latitud=otro.posicion.latitud;
        posicion.longitud=otro.posicion.longitud;
        
        return *this;
    }
    
    bool operator<(const Cliente& otro) const{
        return nombre<otro.nombre;
    }
    
    bool operator==(const Cliente &otro){
        bool resultado;
        if(nombre==otro.nombre)
            resultado= true;
        
        else
            resultado =  false;
        
        return resultado;
    }
    
    double getlatitud(){
        return posicion.latitud;
    }
    
    double getlongitud(){
        return posicion.longitud;
    }
    
    double distancia(Cliente &c){
        
        double distancia = sqrt((posicion.latitud - posicion.longitud)*(posicion.latitud - posicion.longitud ) 
        + (c.getlatitud() - c.getlongitud())*(c.getlatitud() - c.getlongitud()));
        
        return distancia;
    }
};

#endif /* CLIENTE_H */

