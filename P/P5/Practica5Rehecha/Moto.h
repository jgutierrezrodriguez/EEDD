/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Moto.h
 * Author: jgr97 jonathan
 *
 * Created on 25 de octubre de 2019, 13:26
 */

#ifndef MOTO_H
#define MOTO_H
#include <string>
#include <iostream>
#include "UTM.h"

using namespace std;

enum Estado{bloqueada,activa,sinbateria,rota};

class Moto {
    
    
    private:
        std::string id;
        UTM posicion;
        Estado estatus;
        float porcentajeBateria;
        
    public:
    Moto(std::string id, UTM posicion, Estado estatus);
    
    Moto();
    
    Moto(const Moto& other);
    
    virtual ~Moto();
    
    Estado GetEstatus() const;

    std::string GetId() const;

    UTM GetPosicion() const;

    void SetEstatus(Estado estatus);

    void SetId(std::string id);

    void SetPosicion(UTM posicion);

    Moto& operator=(const Moto& otro);
    
    bool seActiva();
    
    void seDesactiva ();
    
    
    bool operator<(const Moto& right) const;

    bool operator==(const Moto& right) const;

    bool operator>(const Moto& right) const;
    
    void SetPorcentajeBateria(float porcentajeBateria);
    
    float GetPorcentajeBateria();
    
    void darAviso();

    




};

#endif /* MOTO_H */

