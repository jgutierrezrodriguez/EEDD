/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: jgr97
 *
 * Created on 7 de octubre de 2019, 13:13
 */

#ifndef NODO_H
#define NODO_H

template <class T>
class Nodo{
    public:
        T dato;
        Nodo* anterior;
        Nodo* siguiente;
        
        Nodo():anterior(0), siguiente(0) {}

        Nodo (T ddato, Nodo *panterior, Nodo *psiguiente): dato(ddato), anterior(panterior), siguiente(psiguiente){}
        
        Nodo( Nodo& orig) {
            dato = orig.dato;
            anterior = orig.anterior;
            siguiente = orig.siguiente;
        }
        
        virtual ~Nodo() { }

};

#endif /* NODO_H */

