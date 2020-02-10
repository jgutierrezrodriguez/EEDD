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
#include "UTM.h"

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

    std::string darAviso(){
        std::string resultado;
        
        if(estatus==Estado::activa)
            resultado="La moto esta activa";
        else if(estatus==Estado::bloqueada)
            resultado="La moto esta bloqueada";
        else if(estatus==Estado::rota)
            resultado="La moto esta rota";
        else if(estatus==Estado::sinbateria)
            resultado="La moto esta sin bateria";
        
        return resultado;
    }
    




};

#endif /* MOTO_H */

