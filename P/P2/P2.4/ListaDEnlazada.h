/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaDEnlazada.h
 * Author: jgr97
 *
 * Created on 17 de octubre de 2019, 18:59
 */

#ifndef LISTADENLAZADA_H
#define LISTADENLAZADA_H

#include "Nodo.h"
#include "Iterador.h"

template <class T>
class ListaDEnlazada{
    private:
        Nodo<T> *inicio;
        Nodo<T> *fin;
        
        int tam=0;
    public:
        
        // CONSTRUCTORES:
        ListaDEnlazada<T>();                               // Por defecto
        ListaDEnlazada<T>(const ListaDEnlazada<T>& origen); // De copia
        
        
        
        // OPERADORES: 
        ListaDEnlazada<T>& operator=(const ListaDEnlazada<T> &otro); // Asignacion
        
        // FUNCIONES        
        T Inicial();                                 //Devuelve el primer elemento
        T Fin();                                    //Devuelve el ultimo elemento
        Iterador<T> & IteradorIterador ();     //Devuelve un iterador
        void insertaInicio( T&dato);                //Inserta al inicio
        void insertaFin(T& dato);                   //Inserta al final
        void inserta(Iterador<T> &it, T &dato);
        void borraInicio();                         //Borra primer elemento
        void borraFinal();                          //Borra ultimo elemento
        void borra(Iterador<T> &i);                    //Borra el elemento referenciado por un iterador
        int retTam();                                  //Devuelve el numero de elementos de la lista
        void concatena(const ListaDEnlazada<T> &l); //devuelve una nueva lista con la concatenación de la lista actual y la proporcionada por parámetro.
        
        
        
        //DESTRUCTOR
        virtual ~ListaDEnlazada();
};

#endif /* LISTADENLAZADA_H */

