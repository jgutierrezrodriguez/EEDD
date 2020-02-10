/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Moto.h
 * Author: jgr97
 *
 * Created on 25 de octubre de 2019, 13:26
 */

#ifndef MOTO_H
#define MOTO_H
#include <string>
#include "UTM.h"
#include "Cliente.h"


class Cliente;

class Moto {
    enum Estado{bloqueada,activa,sinbateria,rota};
    
    private:
        std::string id;
        UTM posicion;
        Estado estatus;
        Cliente* usadaPor;
        
    public:
    Moto(std::string id, UTM posicion, Estado estatus);
    
    Moto();
    
    Moto(const Moto& other);
    
    virtual ~Moto();
    
    Estado GetEstatus() const;

    std::string GetId() const;

    UTM GetPosicion() const;

    Cliente* GetUsadaPor() const;

    void SetEstatus(Estado estatus);

    void SetId(std::string id);

    void SetPosicion(UTM posicion);

    void SetUsadaPor(Cliente* usadaPor);

    Moto& operator=(const Moto& otro);
    
    bool seActiva(Cliente* cli);
    
    void seDesactiva ();





};

#endif /* MOTO_H */

