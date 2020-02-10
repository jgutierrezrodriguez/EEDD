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
        Nodo(T& dat):dato(dat){};
        T& getDato(){return dato;};
        Nodo& operator=(const Nodo &otro){
            dato=otro.dato;
            siguiente=otro.siguiente;
            anterior=otro.anterior;
        }
    };
    
public:
    class Iterador {
    private:
        Nodo* nodo;
    public:
        Iterador();
        Iterador(Nodo *nod){nodo=nod;};
        Nodo* getNodo(){return nodo;};
        bool fin(){
            if(nodo->siguiente==0)
                return true;
        };
        void siguiente(){
            nodo=nodo->siguiente;
        };
        void anterior(){
            nodo=nodo->anterior;
        };
        T& dato(){
            return nodo->dato;
        };
        
        Iterador& operator=(const Iterador &otro){
            nodo=otro.nodo;
        };
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
    Iterador & IteradorIterador (){
        ListaDobleEnlazada<T>::Iterador it (cab);
        
        return it;
    };

    virtual ~ListaDobleEnlazada();
private:
    Nodo *cab;
    Nodo *cola;
    int tam;
};

template<class T>
ListaDobleEnlazada<T>::ListaDobleEnlazada() : cab(0), cola(0), tam(0) {
}

template<class T>
ListaDobleEnlazada<T>::ListaDobleEnlazada(const ListaDobleEnlazada& orig) {

    Nodo *inicial = new Nodo(orig.cab->getDato());
    Nodo *atras = inicial;
    Nodo *antiguo = orig.cab;

    while (antiguo->siguiente != 0) {
        antiguo = antiguo->siguiente;
        Nodo *nuevo = new Nodo(antiguo->getDato());
        atras->siguiente = nuevo;
        nuevo->anterior = atras;
        atras = atras->siguiente;
    }

    cola = atras;
    cab = inicial;
    tam = orig.tam;
}

template<class T>
int ListaDobleEnlazada<T>::returntam() {
    return tam;
}

template<class T>
ListaDobleEnlazada<T>& ListaDobleEnlazada<T>::operator=(const ListaDobleEnlazada<T>& right) {
    if (this != &right) {
        EliminarNodos();
        this(right); // intento llamar al contructor copia, sino sacar lo del constructor copia a un metodo externo y ponerlo aqui.
    }
    return *this;
}

template<class T>
void ListaDobleEnlazada<T>::EliminarNodos() {
    Nodo *actual = cab;
    Nodo *borrado;
    while (actual != nullptr) {
        borrado = actual;
        actual = actual->siguiente;
        delete borrado;
    }
    cab = cola = nullptr;
    tam = 0;
}

template<class T>
T& ListaDobleEnlazada<T>::inicio() {
    return cab->dato;
}

template<class T>
T& ListaDobleEnlazada<T>::final() {
    cola->dato;
}

template<class T>
void ListaDobleEnlazada<T>::insertaInicio(T& D) {

    Nodo *nuevo = new Nodo(D);

    if (cab != 0)
        cab->anterior = nuevo;

    if (cola == 0)
        cola = nuevo;

    cab = nuevo;
    tam++;
}

template<class T>
void ListaDobleEnlazada<T>::insertaFinal(T& D) {
    Nodo *nuevo = new Nodo(D);

    if (cab == 0)
        cab = nuevo;

    if (cola == 0)
        cola->siguiente = nuevo;

    cola = nuevo;
    tam++;
}

template<class T>
void ListaDobleEnlazada<T>::inserta(Iterador& i, T& dato) {

    if (i.getNodo()->siguiente == 0) {
        insertaFinal(dato);
    } else {
        if (i.getNodo()->anterior == 0) {
            insertaInicio(dato);
        }
        Nodo *nuevo = new Nodo(dato);
        i.getNodo()->anterior->siguiente = nuevo;
        nuevo->siguiente = i;
        nuevo->anterior = i.getNodo()->anterior;
        i.getNodo()->anterior = nuevo;
    }
}

template<class T>
void ListaDobleEnlazada<T>::borrarinicio() {
    Nodo *borrado;
    borrado = cab;
    cab = cab->siguiente;
    cab->anterior = 0;
    delete borrado;

}

template<class T>
void ListaDobleEnlazada<T>::borrarfinal() {
    Nodo *borrado;
    borrado = cola;
    cola = cola->anterior;
    cola->siguiente = 0;
    delete borrado;
}

template<class T>
void ListaDobleEnlazada<T>::borra(Iterador& i) {
    i.getNodo()->anterior->siguiente=i.getNodo()->siguiente;
    i.getNodo()->siguiente->anterior=i.getNodo()->anterior;
    delete i.getNodo();
}

template<class T>
ListaDobleEnlazada<T>& ListaDobleEnlazada<T>::concatena(const ListaDobleEnlazada<T>& l) {
    ListaDobleEnlazada<T> nuevaL(this);
    Nodo *nuevoP=l.cab;
    while(nuevoP!=0){
        Nodo nuevo= new Nodo(nuevoP->dato);
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
    EliminarNodos();
    cab=cola=0;
}

#endif /* LISTADOBLEENLAZADA_H */

