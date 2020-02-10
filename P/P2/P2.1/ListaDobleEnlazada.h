/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaDobleEnlazada.h
 * Author: jonathan
 *
 * Created on 18 de octubre de 2019, 13:06
 */

#ifndef LISTADOBLEENLAZADA_H
#define LISTADOBLEENLAZADA_H

#include "Iterador.h"

template<class T>
class ListaDobleEnlazada {
    private:
    Nodo<T> *cab;
    Nodo<T> *cola;
    int tam;
    
    public:
        
        ListaDobleEnlazada();
        ListaDobleEnlazada( const ListaDobleEnlazada& orig);
        ListaDobleEnlazada<T>& operator=(const ListaDobleEnlazada<T>& right);
        T& inicio();
        T& fin();
        void insertaInicio(T& D);
        void insertaFinal(T& D);
        void inserta(Iterador<T> &i, T &dato);
        void borrarinicio();
        void borrarfinal();
        void borra(Iterador<T> &i);
        int returntam();
        ListaDobleEnlazada<T>& concatena(const ListaDobleEnlazada<T> &l);
        
        Iterador<T> IteradorIterador () const{
            return Iterador<T>(cab);
        };

        virtual ~ListaDobleEnlazada();
    
    

};

template<class T>
ListaDobleEnlazada<T>::ListaDobleEnlazada() : cab(0), cola(0), tam(0) {
}

template<class T>
ListaDobleEnlazada<T>::ListaDobleEnlazada(const ListaDobleEnlazada<T>& orig) {

    Iterador<T> it = orig.IteradorIterador();
    
    cab=0;
    cola=0;
    Nodo<T>* nodo=orig.cab;
    
    while (!it.fin()) {
        insertaFinal(it.dato());
        it.siguiente();
    }
    tam = orig.tam;
}

template<class T>
int ListaDobleEnlazada<T>::returntam() {
    return tam;
}

template<class T>
ListaDobleEnlazada<T>& ListaDobleEnlazada<T>::operator=(const ListaDobleEnlazada<T>& orig) {
    if (this != &orig) {
        
        Iterador<T> it = orig.IteradorIterador();
        
        if(cola!=0){
            Iterador<T> it2 = IteradorIterador();
            
            while(!it2.fin()){
                it2.siguiente();
                borrarinicio();
            }
        }

        cola = 0;
        cab = 0;
       
        while (!it.fin()) {
            insertaFinal(it.dato());
            it.siguiente();
        }
    }
    return *this;
}

template<class T>
T& ListaDobleEnlazada<T>::inicio() {
    return cab->dato;
}

template<class T>
T& ListaDobleEnlazada<T>::fin() {
    cola->dato;
}

template<class T>
void ListaDobleEnlazada<T>::insertaInicio(T& D) {

    Nodo<T> *nuevo = new Nodo<T>(D,0,cab);

    if (cab != 0)
        cab->anterior = nuevo;

    if (cola == 0)
        cola = nuevo;

    cab = nuevo;
    tam++;
}

template<class T>
void ListaDobleEnlazada<T>::insertaFinal(T& D) {
    Nodo<T> *nuevo = new Nodo<T>(D,cola,0);

    if (cab == 0)
        cab = nuevo;

    if (cola != 0)
        cola->siguiente = nuevo;

    cola = nuevo;
    tam++;
}

template<class T>
void ListaDobleEnlazada<T>::inserta(Iterador<T>& i, T& dato) {

    if (i.nodo->siguiente == 0) {
        insertaFinal(dato);
    } else {
        if (i.nodo->anterior == 0) {
            insertaInicio(dato);
        }
        else{
            Nodo<T> *nuevo = new Nodo<T>(dato,i.nodo->anterior,i.nodo);
            i.nodo->siguiente=nuevo;
            i.nodo->anterior=nuevo;
            tam++;
        }
    }
}

template<class T>
void ListaDobleEnlazada<T>::borrarinicio() {
    Nodo <T>*borrado;
    borrado = cab;
    cab = cab->siguiente;
    delete borrado;
    if(cab!=0)
        cab->anterior = 0;
    else
        cola=0;
    tam--;

}

template<class T>
void ListaDobleEnlazada<T>::borrarfinal() {
    Nodo <T>*borrado;
    borrado = cola;
    cola = cola->anterior;
    
    delete borrado;
    
    if(cola!=0)
        cola->siguiente = 0;
    else
        cab=0;
    
    tam--;
}

template<class T>
void ListaDobleEnlazada<T>::borra(Iterador<T>& i) {
    i.nodo->anterior->siguiente=i.nodo->siguiente;
    i.nodo->siguiente->anterior=i.nodo->anterior;
    delete i.nodo;
    
    tam--;
}

template<class T>
ListaDobleEnlazada<T>& ListaDobleEnlazada<T>::concatena(const ListaDobleEnlazada<T>& l) {
    ListaDobleEnlazada<T> nuevaL(this);
    Nodo <T>*nuevoP=l.cab;
    while(nuevoP!=0){
        Nodo <T>nuevo= new Nodo<T>(nuevoP->dato);
        nuevaL.cola->siguiente=nuevo;
        nuevo.anterior=nuevaL.cola;
        nuevaL.cola=nuevo;
        nuevoP=nuevoP->siguiente;         
    }
    nuevaL.tam += l.tam;
    return nuevaL;
}

template<class T>
ListaDobleEnlazada<T>::~ListaDobleEnlazada() {
    while(tam!=0){
        borrarfinal();
    }
}

#endif /* LISTADOBLEENLAZADA_H */

