/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ListaEnlazada.h"

/******************************** CONSTRUCTORES ********************************/

template <class T>
ListaDEnlazada<T>::ListaDEnlazada(){
   inicio = 0;
   fin = 0;
}

template<class T>
ListaDEnlazada<T>::ListaDEnlazada(const ListaDEnlazada<T>& origen) {
    
    inicio = 0;
    fin = 0;
    
    Iterador<T> it = origen.IteradorIterador();
    
    insertaInicio(it.dato());
    it.siguiente();
    
    while(!it.fin()){
        insertaFin(it.dato());
        it.siguiente();
    }
}

/********************************* OPERADORES *********************************/

template<class T>
ListaDEnlazada<T>& ListaDEnlazada<T>::operator=(ListaDEnlazada<T>& otro) {
    
    while(inicio!=fin){
        borraFinal();
    }
    
    inicio = 0;
    fin = 0;
    tam=0;
    
    Iterador<T> it = otro.IteradorIterador();
    
    insertaInicio(it.dato());
    it.siguiente();
    
    while(!it.fin()){
        insertaFin(it.dato());
        it.siguiente();
    }
    
}

/********************************** FUNCIONES **********************************/

template<class T>
T ListaDEnlazada<T>::Inicial() {

    return inicio->dato;
}

template<class T>
T ListaDEnlazada<T>::Fin() {

    return fin->dato;
}

template<class T>
int ListaDEnlazada<T>::retTam() {
    return tam;
}

template<class T>
Iterador<T>& ListaDEnlazada<T>::IteradorIterador() {
    
    Iterador<T> it (inicio);
    
    return it;
    
}

template<class T>
void ListaDEnlazada<T>::insertaInicio(T& dato) {
    Nodo<T> * n;
    n= new Nodo<T>(dato,0,inicio);
    
    if(inicio!=0)
        inicio->anterior=n;
    
    if(fin==0)
        fin=n;
    
    inicio=n;
}

template<class T>
void ListaDEnlazada<T>::insertaFin(T& dato) {

    Nodo<T> * n;
    n= new Nodo<T>(dato,0,inicio);
    
    if(inicio==0)
        inicio=n;
    
    if(fin!=0)
        fin->siguiente=n;
    
    fin=n;
}

template<class T>
void ListaDEnlazada<T>::inserta(Iterador<T>& it, T& dato) {
    Nodo<T> * n;
    
    n= new Nodo<T> (dato,it.anterior(),it.getPNodo());
    
    
    it.nodo->anterior->siguiente=n;
    it.nodo->anterior=n;
    
}

template<class T>
void ListaDEnlazada<T>::borraInicio() {

    Nodo<T> *borrado = inicio;
    inicio=inicio->siguiente;
    
    delete borrado;
    
    if(inicio!=0){
        inicio->anterior=0;
    }
    
    else{
        fin=0;
    }
    
}

template<class T>
void ListaDEnlazada<T>::borraFinal() {

    Nodo<T> * borrado = fin;
    fin=fin->anterior;
    
    delete borrado;
    
    if(fin!=0){
        fin->siguiente=0;
    }
    else{
        inicio=0;
    }
}

template<class T>
void ListaDEnlazada<T>::borra(Iterador<T>& i) {

    if(i.nodo->siguiente==0){
        borraFinal();
    }
    
    else if(i.nodo->anterior==0){
        borraInicio();
    }
    
    else {
        i.nodo->siguiente->anterior=i.nodo->anterior;
        i.nodo->anterior->siguiente=i.nodo->siguiente;
        delete i.nodo;
    }
   
}







/******************************** DESTRUCTORES *********************************/


template<class T>
ListaDEnlazada<T>::~ListaDEnlazada() {
    
    while(inicio!=fin){
        borraFinal();
    }
}





