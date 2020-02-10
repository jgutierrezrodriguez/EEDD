/* 
 * File:   Avl.h
 * Author: Danymad92
 *
 * Created on 6 de noviembre de 2013, 18:06
 */

#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <stack>
#include "Pila.h"

using namespace std;

template<class T> class NodoAvl {
public:
    NodoAvl<T> *izq, *der;
    T dato;
    char bal; // -1,0,1 para un arbol avl

    NodoAvl(const T &ele=T()) : izq(0), der(0), bal(0), dato(ele) {
    }

    NodoAvl(const NodoAvl<T> &orig) : izq(orig.izq), der(orig.der), dato(orig.dato), bal(orig.bal) {
    }

    ~NodoAvl() {
    }
};

template<typename T> class Avl {
    NodoAvl<T> *raiz;
    int insertar(NodoAvl<T>* &c,const T &dato);
//    bool insertar(const T &dato);
    void rotDecha(NodoAvl<T>* &p);
    void rotIzqda(NodoAvl<T>* &p);
    void inorden(NodoAvl<T>* p, int nivel);
public:

    Avl(void) {
        raiz = 0;
    };

    virtual ~Avl() {
    }; //Recorrerlo en postorden y eliminar todos los NodoAvls,como un erase
    bool insertarNR(const T &dato);
    T *busquedaNR(const T &dato);

    void recorreInorden() {
        inorden(raiz, 0);
    };
    int factorEquilibrio(NodoAvl<T>* p);
};

template<class T>
void Avl<T>::rotDecha(NodoAvl<T>* &p) {
    NodoAvl<T> *q = p, *l;
    p = l = q->izq;
    q->izq = l->der;
    l->der = q;
    q->bal--;
    if (l->bal > 0) q->bal -= l->bal;
    l->bal--;
    if (q->bal < 0) l->bal -= -q->bal;
};

template<class T>
void Avl<T>::rotIzqda(NodoAvl<T>* &p) {
    NodoAvl<T> *q = p, *r;
    p = r = q->der;
    q->der = r->izq;
    r->izq = q;
    q->bal++;
    if (r->bal < 0) q->bal += -r->bal;
    r->bal++;
    if (q->bal > 0) r->bal += q->bal;
};

//template<class T>
//bool Avl<T>::insertar(const T &dato) {
//    NodoAvl<T>* nuevo=new NodoAvl<T> (dato);
//    NodoAvl<T>* &c=raiz;
//    NodoAvl<T>* p=c;
//    
//    Pila<NodoAvl<T>* > pila;
//    int deltaH=0;
//    
//    if (!p) {
//        p = nuevo;
//        //c=p;
//        return true;
//    }else{
//        NodoAvl<T>* hoja=0;
//        //Buscar hoja
//        while (p){
//            pila.push(p);
//            hoja = p;
//            if (p->dato < dato) {
//                p=p->der;
//            } else if (dato < p->dato) {
//                p=p->izq;
//            }
//        }
//
//        
//        if (hoja->dato < dato){
//            hoja->der = nuevo;
//        }else if(dato < hoja->dato){
//            hoja->izq = nuevo;
//        }
//        
//        
//        while(!pila.empty()){
//            p=pila.top();
//            pila.pop();
//            c=p;
//            if (p->dato < dato){
//                p->bal--;
//                if (p->bal == -2) {
//                    if (p->der->bal == 1) rotDecha(p->der);
//                    rotIzqda(c);
//                    
//                    if(!pila.empty()){
//                        pila.top()->der=c;   
//                    }
//                    while(!pila.empty()){
//                        c=pila.top();
//                        pila.pop();
//                    }
//                }
//            }else if(dato < p->dato){
//                p->bal++;
//                if (p->bal == 2) {
//                    if (p->izq->bal == -1) rotIzqda(p->izq);
//                    rotDecha(c);
//                    
//                    if(!pila.empty()){
//                        pila.top()->izq=c;
//                    }
//                    while(!pila.empty()){
//                        c=pila.top();
//                        pila.pop();
//                    }
//                }
//            }
//        }
//        return true;
//    }
//    return false;
//};

template<typename T>
int Avl<T>::insertar(NodoAvl<T>* &c,const T &dato) {
    NodoAvl<T> *p = c;
    int deltaH = 0;
    if (!p) {
        p = new NodoAvl<T> (dato);
        c = p;
        deltaH = 1;
    }else if (p->dato < dato) {
        if (insertar(p->der, dato)) {
            p->bal--;
            if (p->bal == -1) deltaH = 1;
            else if (p->bal == -2) {
                if (p->der->bal == 1) rotDecha(p->der);
                rotIzqda(c);
            }
        }
    } else if (dato < p->dato) {
        if (insertar(p->izq, dato)) {
            p->bal++;
            if (p->bal == 1) deltaH = 1;
            else if (p->bal == 2) {
                if (p->izq->bal == -1) rotIzqda(p->izq);
                rotDecha(c);
            }
        }
    }
    return deltaH;
}

template <class T>
void Avl<T>::inorden(NodoAvl<T>* p, int nivel) {
    if (p) {
        inorden(p->izq, nivel + 1);
        // Sustituir por procesamiento ----
        cout << "Procesando NodoAvl " << p->dato;
        cout << " en el nivel " << nivel << endl;
        // -----------
        inorden(p->der, nivel + 1);
    }
};

template <class T>
T* Avl<T>::busquedaNR(const T &dato) {
    NodoAvl<T> *p = raiz;
    while (p) {
        if (p->dato < dato) {
            p = p->der;
        } else if (dato < p->dato) {
            p = p->izq;
        } else {
            T* dat = &p->dato;
            return dat;
        }
    }
    return NULL;
};

template <class T>
bool Avl<T>::insertarNR(const T &ele) {
    T* encontrado = busquedaNR(ele);
    if (!encontrado) {
        insertar(raiz,ele);
        return true;
    }
    return false;
};

template <class T>
int Avl<T>::factorEquilibrio(NodoAvl<T>* p){
    int izq=0,decha=0;
    if(p->izq){
        izq=factorEquilibrio(p->izq);
        izq++;
    }
    if(p->der){
        decha=factorEquilibrio(p->izq);
        decha++;
    }
    return izq-decha;
}



#endif /* AVL_H */