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

template<class T>
class ListaDobleEnlazada {
public:
    class Nodo {
    public:
        T dato;
        Nodo *siguiente;
        Nodo *anterior;
        Nodo(T& dat): dato(dat), siguiente(0), anterior(0){}
        T& getDato(){return dato;}
    };
    
public:
    class Iterador {
    private:
        Nodo* nodo;
    public:
        Iterador(Nodo *nod): nodo(nod){}
        Nodo* getNodo(){return nodo;}
        bool fin() {return nodo == 0;}
        void siguiente(){nodo = nodo->siguiente;}
        void anterior(){nodo=nodo->anterior;}
        T& dato(){return nodo->dato;}
    };
public:
    ListaDobleEnlazada();
    ListaDobleEnlazada(const ListaDobleEnlazada& orig);
    ListaDobleEnlazada<T>& operator=(const ListaDobleEnlazada<T>& right);
    void EliminarNodos();
    T& inicio();
    T& final();
    void insertaInicio(T& D);
    void insertaFinal(T& D);
    void inserta(Iterador &i, T &dato);
    void borrarinicio();
    void borrarfinal();
    void borra(Iterador &i);
    int returntam();
    ListaDobleEnlazada<T>& concatena(const ListaDobleEnlazada<T> &l);

    virtual ~ListaDobleEnlazada();
private:
    Nodo *cab;
    Nodo *cola;
    int tam;
};

#endif /* LISTADOBLEENLAZADA_H */

