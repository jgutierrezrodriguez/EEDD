/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVL.h
 * Author: jonathan
 *
 * Created on 19 de octubre de 2019, 17:34
 */

#ifndef AVL_H
#define AVL_H

template <class T>
class AVL {
public:

    template<class U>
    class Nodo {
    public:
        Nodo<U> *izq, *der; //punteros para moverse
        U dato; //dato a insertar
        char bal; //valor de equilibrio

        Nodo(T& elemento) : izq(0), der(0), bal(0), dato(elemento) {
        }

        T& getDato() {
            return dato;
        }
    };
    
private:
    Nodo<T> *raiz;
    Nodo<T> *actual;
    int contador=0;
    int altura;

    void Preordencopia(Nodo<T> *P, Nodo<T> *original) {
        if (original) {
            P = new Nodo<T>(original->dato);

            Preordencopia(P->izq, original->izq);
            Preordencopia(P->der, original->der);
        }
    }
    
    void borrarNodosPosorden(Nodo<T> *P){
        
        borrarNodosPosorden(P->izq);
        borrarNodosPosorden(P->der);
        
        contador=0;
        altura=0;
        delete P;
        
    }
    
    int inserta(Nodo<T>* &c, T &dato){
        Nodo<T> *p = c;
        int deltaH = 0;
        
        if (!p){
            p = new Nodo<T>(dato);
            c = p; deltaH=1;
        }
        
        else if (dato > p->dato){
            if (inserta(p->der, dato)){
                p->bal--;
                
                if (p->bal == -1) deltaH=1;
                else if (p->bal == -2) {
                    if (p->der->bal == 1) rotDecha(p->der);
                    rotIzqda(c);
                }
            }
        }
        
        else if (dato < p->dato){
            if (inserta(p->izq, dato)){
                p->bal++;
                if (p->bal==1) deltaH = 1;
                else if (p->bal == 2){
                    if (p->izq->bal == -1) rotIzqda(p->izq);
                    rotDecha(c);
                }
            } 
        }
        contador++;
        return deltaH;
    }
    
    Nodo<T> buscaClave (T &ele, Nodo<T> *p){
        if (!p)
            return 0;
        else if (ele < p->dato)
            return buscaClave (ele, p->izq);
        else if (ele > p-> dato)
            return buscaClave (ele, p->der);
        else 
            return p;
    }
    

public:

    AVL() :raiz(0), altura(0), contador(0), actual(0){
    }

    AVL(const AVL<T>& orig) {
        altura = orig.altura;
        contador = orig.contador;
        Preordencopia(raiz, orig.raiz);
    }
    
    AVL<T>& operator=(const AVL<T>& right) {
        if (this != &right){
            
            borrarNodos(raiz);
            contador = right.contador;
            Preordencopia(raiz,right.raiz);
            
        }
        return *this;
    }
    
    void rotDer(Nodo<T>* &nodo){
        Nodo<T> *q = nodo, *l;
        
        nodo = l = q->izq;
        q->izq = l->der;
        l->der = q;
        q->bal--;
        if (l->bal > 0) q->bal -= l->bal;
        l->bal--;
        if(q->bal < 0) l->bal -= -q->bal;
    }
    
    void rotIzq(Nodo<T>* &nodo){
        Nodo<T> *q = nodo, *r;
        nodo = r = q->der;
        q->der = r->izq;
        r->izq = q;
        q->bal++;
        if (r->bal < 0) q->bal += -r->bal;
        r->bal++;
        if(q->bal > 0) r->bal += q->bal;
    }

    virtual ~AVL(){
    borrarNodosPosorden(raiz);
    }
    
    
    bool inserta(T& dato){
        return  inserta(raiz,dato);
    }
    
    void recorreInorden(Nodo<T> *P){
        if(P){
            recorreInorden(P->izq);
            recorreInorden(P->der);
        }
    }
    
    unsigned int numElementos(){
        return contador;
    }
    
    unsigned int retAltura(){
        return altura;
    }
    
    
    bool busquedaRecursiva (T &ele, T &result){
        Nodo<T> *p = buscaClave (ele, raiz);
        if (p) {
            result = p->dato;
            return true;
        }
        return false;
    }
    
    bool buscaIt(T& dato, T& result) {
    Nodo<T>* nod1 = raiz;
    while (nod1) {
        if (dato < nod1->dato)
            nod1 = nod1->izq;
        else
            if (dato > nod1->dato)
            nod1 = nod1->der;

        else {
            result = nod1->dato;
            return true;
        }
    }
    return false;
}
    
};

#endif /* AVL_H */

