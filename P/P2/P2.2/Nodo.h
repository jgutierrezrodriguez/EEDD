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
        
        Nodo (T ddato, Nodo *panterior=0, Nodo *psiguiente = 0): dato(ddato), anterior(panterior), siguiente(psiguiente){}
};

#endif /* NODO_H */

