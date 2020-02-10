/* 
 * File:   Pila.h
 * Author: Miguel Angel
 *
 * Created on 9 de noviembre de 2013, 14:13
 */

#ifndef PILA_H
#define PILA_H

#include "Estructuras.h"

template<class U>
class Pila: private ListaDEnlazada<U> {
private:
    int numElementos;
public:
    Pila();
    ~Pila();
    void push(U &datos);
    void pop();
    U top();
    bool empty();
};

template<class U>
Pila<U>::Pila():numElementos(0){}

template<class U>
Pila<U>::~Pila(){}

template<class U>
void Pila<U>::push(U &datos){
    Iterador<U> it=this->iteradorIni();
    insertar(it,datos);
    numElementos++;
}

template<class U>
void Pila<U>::pop(){
    Iterador<U> it=this->iteradorIni();
    borrar(it);
    numElementos--;
}

template<class U>
U Pila<U>::top(){
    Iterador<U> it=this->iteradorIni();
    return it.dato();
}

template<class U>
bool Pila<U>::empty(){
    if(this->tam()==0) return true;
    else return false;
}

#endif /* PILA_H */