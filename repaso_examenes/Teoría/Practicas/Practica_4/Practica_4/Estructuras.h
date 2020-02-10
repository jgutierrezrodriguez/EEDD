/*
 * File:   Estructuras.h
 * Author: Miguel Angel
 *
 * Created on 14 de octubre de 2013, 16:15
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

template<class T>
class Nodo{
public:
    T dato;
    Nodo<T> *ant,*sig;
    Nodo(T &_dato,Nodo<T>* _ant,Nodo<T>* _sig):dato(_dato),ant(_ant),sig(_sig){};
    Nodo(const Nodo<T>& orig):dato(orig.dato),ant(orig.ant),sig(orig.sig){};
    virtual ~Nodo(){};
};

template<class T>
class ListaDEnlazada;

template<class T>
class Iterador{
private:
    Nodo<T> *nodo;
    friend class ListaDEnlazada<T>;
public:
    Iterador(Nodo<T>* _nodo):nodo(_nodo){};
    Iterador(const Iterador<T> &orig):nodo(orig.nodo){};
    virtual ~Iterador(){};
  
    bool hayAnterior(){return nodo!=0;};
    bool haySiguiente(){return nodo!=0;};
    void anterior(){nodo=nodo->ant;};
    void siguiente(){nodo=nodo->sig;};
    T& dato(){return nodo->dato;};
    bool operator==(const Iterador<T> &ite);
    bool operator!=(const Iterador<T> &ite);
};

template<class T>
bool Iterador<T>::operator==(const Iterador<T> &ite){
    if(nodo==ite.nodo) return true;
    else return false;
}

template<class T>
bool Iterador<T>::operator!=(const Iterador<T> &ite){
    if(nodo!=ite.nodo) return true;
    else return false;
}

template<class T>
class ListaDEnlazada {
private:
    Nodo<T> *cabecera,*cola;
public:
    ListaDEnlazada():cabecera(0),cola(0){};
    ListaDEnlazada(const ListaDEnlazada<T>& orig):cabecera(orig.cabecera),cola(orig.cola){};
    ListaDEnlazada<T>& operator=(const ListaDEnlazada &lista);//Tenemos que hacerlo
    virtual ~ListaDEnlazada(){};
    
    int tam();
    Iterador<T> iteradorIni(){return Iterador<T>(cabecera);};
    Iterador<T> iteradorFin(){return Iterador<T>(cola);};
    void insertar(Iterador<T>& it,T &dato);
    void borrar(Iterador<T>& it);
    void insertarFin(T &dato);
    void borrarFin();
};

template<class T>
int ListaDEnlazada<T>::tam(){
    if(cabecera==0) return 0;
    Iterador<T> it(cabecera);
    int i=0;
    while(it.haySiguiente()){
        i++;
        it.siguiente();
    }
    return i;
}

template<class T>
ListaDEnlazada<T>& ListaDEnlazada<T>::operator =(const ListaDEnlazada& lista){
}

template<class T>
void ListaDEnlazada<T>::insertar(Iterador<T> &it,T &dato){
    
    if(it.nodo==cabecera){//inicio
        Nodo<T> *inicio=new Nodo<T>(dato,0,it.nodo);
        
        if(cola == 0) cola=inicio;
        
        if(cabecera!=0) cabecera->ant=inicio;
        cabecera=inicio;
    }else{
        Nodo<T> *medio=new Nodo<T>(dato,it.nodo->ant,it.nodo);//aqui
        it.nodo->ant->sig=medio;
        it.nodo->ant=medio;
    }
    
};

template<class T>
void ListaDEnlazada<T>::borrar(Iterador<T> &it){//Solucionar
    Nodo<T> *borrado=it.nodo;
    
    if(it.nodo==cabecera){
       cabecera=cabecera->sig;
       it.siguiente();
       delete borrado;
       if(cabecera != 0) cabecera->ant = 0;
       else cola=0;
    }else if(it.nodo==cola) borrarFin();
    else{
        it.nodo->ant->sig=it.nodo->sig;
        it.nodo->sig->ant=it.nodo->ant;
        it.siguiente();
        delete borrado;
    }
       
};

template<class T>
void ListaDEnlazada<T>::insertarFin(T &dato){
    Nodo<T> *nuevo=new Nodo<T>(dato,cola,0);
    
    if(cabecera==0) cabecera = nuevo;
    if(cola!=0) cola->sig=nuevo;
    cola = nuevo;
};

template<class T>
void ListaDEnlazada<T>::borrarFin(){
    Nodo<T> *borrado = cola;
    
    cola=cola->ant;
    delete borrado;
    
    if(cola !=0) cola->sig=0;
    else cabecera=0;
};

#endif  /* ESTRUCTURAS_H */