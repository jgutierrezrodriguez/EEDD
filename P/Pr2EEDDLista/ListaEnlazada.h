#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

template<class T>
class ListaEnlazada;

template <class T>
class Nodo {
public:
    T dato;
    Nodo* ant, *sig;

    Nodo() : dato(dato), ant(0), sig(0) {

    }

    Nodo(T& dato, Nodo*ant, Nodo* sig) : dato(dato), ant(ant), sig(sig) {
    }

    Nodo(const Nodo& orig) {
        dato = orig.dato;
        ant = orig.ant;
        sig = orig.sig;
    }

    ~Nodo() {
        std::runtime_error("Destructor de nodo no implementado");
    }

};

template <class T>
class Iterador {
private:
    Nodo<T>* nodo;
    friend class ListaEnlazada<T>;
public:

    Iterador() : nodo(0) {
    }

    Iterador(Nodo<T>* nodo) : nodo(nodo) {
    }

    Iterador(const Iterador& orig) {
        nodo = orig.nodo;
    }
    Iterador& operator*(const Iterador& right);

    ~Iterador() {
    }

    void siguiente() {
        nodo = nodo->sig;
    }

    void anterior() {
        nodo = nodo->ant;
    }

    T& dato() {
        return nodo->dato;
    }

    bool hayAnterior() {
        return nodo->ant != 0;
    }

    bool haySiguiente() {
        return nodo->sig != 0;
    }

    bool fin() {
        return nodo == 0;
    }
};

template<class T>
class ListaEnlazada {
private:
    Nodo<T>* cabecera;
    Nodo<T>* cola;
    int tama;
public:
    ListaEnlazada();
    ListaEnlazada(const ListaEnlazada& orig);
    virtual ~ListaEnlazada();
    ListaEnlazada& operator=(const ListaEnlazada<T>& orig);

    Iterador<T> iterador() const {
        return Iterador<T>(cabecera);
    }
    T& Inicio();
    T& Fin();
    void insertaInicio(T& dato);
    void insertaFin(T& dato);
    void inserta(Iterador<T>& i, T& dato);
    void borraInicio();
    void borraFinal();
    void borra(Iterador <T>& i);
    // int tam();
    ListaEnlazada<T> concatena(ListaEnlazada<T>& l);
    void borra2(Iterador<T>& i, int numElementos);
    int getTama();
    // unsigned tam() const{return tama;};
};

template<class T>
ListaEnlazada<T>::ListaEnlazada() : cabecera(0), cola(0), tama(0) {
}

template<class T>
ListaEnlazada<T>::ListaEnlazada(const ListaEnlazada& orig) {
    Iterador<T> i = orig.iterador();
    cabecera = 0;
    cola = 0;
    tama = orig.tama;
    Nodo<T>* nodo = orig.cabecera;
    while (!i.fin()) {
        this->insertaFin(nodo->dato);
        i.siguiente();
    }
}

template<class T>
ListaEnlazada<T>& ListaEnlazada<T>::operator=(const ListaEnlazada<T>& right) {
    
    if (this != &right) {


        Iterador<T> i = right.iterador();
        if (cabecera != 0) {
            Iterador<T> j = ListaEnlazada::iterador();
            while (!j.fin()) {
                j.siguiente();
                borraInicio();
            }
        }
        cabecera = 0;
        cola = 0;
        while (!i.fin()) {
            insertaFin(i.dato());
            i.siguiente();
        
        }

    }
    return *this;
}

template<class T>
ListaEnlazada<T>::~ListaEnlazada() {

    while (tama != 0) {
        borraInicio();
        // cout << tama<<endl;
    }
}

template<class T>
T& ListaEnlazada<T>::Inicio() {
    Nodo<T>* nodo = cabecera;
    if (nodo == NULL) {
        throw std::runtime_error("La lista esta vacia");
    }
    return cabecera->dato;
}

template<class T>
T& ListaEnlazada<T>::Fin() {
    Nodo<T>* nodo = cabecera;
    if (nodo == NULL) {
        throw std::runtime_error("La lista esta vacia");
    }
    return cola->dato;
}

template<class T>
void ListaEnlazada<T>::insertaInicio(T& dato) {
    Nodo<T>* nuevo;
    nuevo = new Nodo<T>(dato, 0, cabecera);
    if (cola == 0) {
        cola = nuevo;
    }
    if (cabecera != 0)
        cabecera->ant = nuevo;
    cabecera = nuevo;

    tama++;
}

template<class T>
void ListaEnlazada<T>::insertaFin(T& dato) {
    Nodo<T>* nuevo;
    nuevo = new Nodo<T>(dato, cola, 0);
    if (cabecera == 0) {
        cabecera = nuevo;
    }
    if (cola != 0) {
        cola->sig = nuevo;
    }

    cola = nuevo;
    tama++;
}

template<class T>
void ListaEnlazada<T>::inserta(Iterador<T>& i, T& dato) {
    if (i.nodo == cabecera || cabecera == cola) {
        insertaInicio(dato);
        return;
    }
    Nodo<T>* nuevo;
    nuevo = new Nodo<T>(dato, i->nodo->ant, i->nodo);
    i->nodo->sig = nuevo;
    i->nodo->ant = nuevo;
    tama++;
}

template<class T>
void ListaEnlazada<T>::borraInicio() {
    Nodo<T> *borrado = cabecera;
    cabecera = cabecera->sig;
    delete borrado;
    if (cabecera != 0) {
        cabecera->ant = 0;
    } else {
        cola = 0;
    }
    tama--;
}

template<class T>
void ListaEnlazada<T>::borraFinal() {
    Nodo<T> *borrado = cola;
    cola = cola->ant;
    delete borrado;
    if (cola != 0) {
        cola->sig = 0;
    } else {
        cabecera = 0;
    }
    tama--;
}

template<class T>
void ListaEnlazada<T>::borra(Iterador<T>& i) {
    if (cabecera == 0) throw std::runtime_error("La lista está vacía");
    if (i.nodo == cabecera) {
        borraInicio();
        return;
    }
    if (i.nodo == cola) {
        borraFinal();
        return;
    }
    i.nodo->ant->sig=i.nodo->sig;
    i.nodo->ant=0;
    i.nodo->sig=0;
    delete i.nodo;
    tama--;
}

//template<class T>
//int ListaEnlazada<T>::tam() {
//    int tam = 0;
//    Nodo<T> *nuevo = 0;
//    if (cabecera != cola) {
//        nuevo = cabecera;
//        while (nuevo != cola->sig) {
//            nuevo = nuevo->sig;
//            tam++;
//        }
//    } else {
//        return 0;
//    }
//    return tam;
//}

template<class T>
ListaEnlazada<T> ListaEnlazada<T>::concatena(ListaEnlazada<T>& l) {
    Nodo<T>* nuevo = 0;
    ListaEnlazada<T> lista;
    lista = *this;
    if (l.cabecera != 0) {
        nuevo = l.cabecera;
        lista.insertaFin(nuevo->dato);
    }
    if (l.cabecera != l.cola) {
        nuevo = nuevo->sig;
        lista.insertaFin(nuevo->dato);
        while (nuevo != l.cola) {
            nuevo = nuevo->sig;
            lista.insertaFin(nuevo->dato);
        }
    }

    return lista;

}

template<class T>
void ListaEnlazada<T>::borra2(Iterador<T>& i, int numElementos) {
    Nodo<T>* borra;

    while (numElementos > 0) {
        borra = i.nodo;
        delete borra;
        i.siguiente();
        numElementos--;
    }

}

template<class T>
int ListaEnlazada<T>::getTama() {
    return tama;
}
#endif /* LISTAENLAZADA_H */

