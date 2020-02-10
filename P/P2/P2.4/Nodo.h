/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: jgr97
 *
 * Created on 17 de octubre de 2019, 19:00
 */

#ifndef NODO_H
#define NODO_H

template <class T>
class Nodo{
    public:
        T dato;
        Nodo* anterior;
        Nodo* siguiente;
        
        Nodo (T ddato, Nodo *panterior=0, Nodo *psiguiente = 0): dato(ddato), anterior(panterior), siguiente(psiguiente){}
        
    virtual ~Nodo() {

    }

};

#endif /* NODO_H */

