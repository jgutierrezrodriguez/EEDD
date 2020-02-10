/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Iterador.h
 * Author: jgr97
 *
 * Created on 8 de octubre de 2019, 20:44
 */


#ifndef ITERADOR_H
#define ITERADOR_H

#include "Nodo.h"

template <class T>
class ListaDobleEnlazada;

template<class T>
class  Iterador{
        friend class ListaDobleEnlazada<T>;
        Nodo<T> *nodo;
    
    
    public:
        
        Iterador(Nodo<T> *aNodo) : nodo(aNodo) {}
        
        Iterador():nodo(0) {}
        
        Iterador(const Iterador& orig) {
            nodo = orig.nodo;
        }

        
        virtual ~Iterador() {
        }
        
        bool fin() { return nodo == 0; }
        
        void siguiente() {
            nodo = nodo->siguiente;
        }
        
        void anterior(){
            nodo=nodo->anterior;
        }
        
        bool haySiguiente(){
            return nodo->siguiente != 0;
        }
        
        bool hayAnterior(){
            return nodo->anterior !=0;
        }
        
        T &dato() { return nodo->dato; }
};

#endif /* ITERADOR_H */

