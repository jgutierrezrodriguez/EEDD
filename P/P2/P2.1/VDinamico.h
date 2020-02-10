/* 
 * File:   VDinamico.h
 * Author: Javier Gutierrez Rodriguez y Jonathan Martin Jimenez
 *
 * Created on 18 de septiembre de 2019, 9:45
 */

#ifndef VDINAMICO_H
#define VDINAMICO_H

#include <algorithm>
#include <math.h>
#include <climits>
#include <exception>


using namespace std;
template <class T>
class VDinamico{
    
    // Variables:
    unsigned taml, tamf;    // Tamaño logico y tamaño fisico del vector.
    T* vector;              // Vector dinamico de tipo T.
        
    public:
        // Constructores:
        VDinamico<T>();     // Por defecto.
        VDinamico<T>(unsigned int taml);    // Dado un  tamaño logico
        VDinamico<T>(const VDinamico<T>& origen);   // De copia.
        VDinamico<T>(const VDinamico<T>& origen, 
                unsigned int inicio, unsigned int num); // De copia parcial.
        
        // Operadores:
        
        VDinamico<T> &operator=(const VDinamico<T> &otro); // De asignacion.
        T& operator[](const unsigned int num);      // Lectura/Escritura.
        
        // Funciones:
        void insertar(const T& dato, unsigned int pos = UINT_MAX);
        T borrar (unsigned int pos = UINT_MAX);
        void ordenar();
        int busquedaBin(T& dato);   //Busqueda binaria o dicotomica.
        int tam();      // Devuelve el tamaño logico.
        unsigned calcularTamF(unsigned int tam); //Calcula el tamaño fisico dado un tamaño logico
        void aumenta();
        void disminuye();
        
        // Destructor:
        virtual ~VDinamico<T>();
};


/******************************** CONSTRUCTORES ********************************/
template <class T>
VDinamico<T>::VDinamico(): taml(0),tamf(1) {
    vector = new T[tamf];
}

template <class T>
VDinamico<T>::VDinamico(unsigned int taml){
    this->taml=taml;
    tamf=calcularTamF(taml); 
    
    vector = new T [tamf];
}

template <class T>
VDinamico<T>::VDinamico(const VDinamico<T>& origen): taml(origen.taml),tamf(origen.tamf) {
    vector = new T[tamf];
    
    for(int i = 0; i<taml; i++){
        vector[i]=origen.vector[i];
    }
}

template <class T>
VDinamico<T>::VDinamico(const VDinamico<T>& origen, 
        unsigned int inicio, unsigned int num){
    
    taml= num - inicio + 1;
    tamf=calcularTamF(taml); 
    
    vector = new T [tamf];
    
    for(int i = 0; i<taml; i++){
        vector[i]=origen.vector[inicio+i];
    }
    
    
}


/********************************* OPERADORES *********************************/
template <class T>
VDinamico<T>& VDinamico<T>::operator =(const VDinamico<T>& otro){
    
    if(otro==*this){
        //throw std::invalid_argument("no se puede contruir el vector ya que es el mismo.");
    }
    
    taml=otro.taml;
    tamf=otro.tamf;
    
    delete vector;
    vector=new T[tamf];
    
    for(int i = 0; i<taml;i++){
        vector[i]=otro.vector[i];
    }
    
    return *this;
}

template <class T>
T &VDinamico<T>::operator [](const unsigned int num) {
    
    if(num>taml){
        //throw std::invalid_argument("num es mayor que el tamaño logico.");
    }
    return vector[num]; //HACE FALTA PONER UNA EXCEPCION SI NUM ESTA  FUERA DE RANGO
}

/********************************** FUNCIONES **********************************/

template <class T>
void VDinamico<T>::insertar(const T& dato, unsigned int pos){
    
   if(pos != UINT_MAX || pos <0){
        //throw std::invalid_argument("insertar:: posicion esta fuera de rango.");
    } 
    
    if(tamf==taml){
        aumenta();
    }
    
    if(pos==UINT_MAX){
         
        vector[taml]=dato;
        taml++;
    }
    else {
        for(int i=taml-1;i>=pos;i--){
            vector[i+1]=vector[i];
        }
            
        vector[pos]=dato;
        taml++;
    }  
}


template <class T>
T VDinamico<T>::borrar(unsigned int pos){
    
    if (pos <0 || pos> taml){
        //throw std::invalid_argument("borrar:: posicion esta fuera de rango.");
    }
    
    
    T dato;
    
    dato=vector[pos];
    
    if(pos==UINT_MAX){
        taml--;
    }
    
    else{
        for(int i=pos;i<taml;i++){
            vector[i]=vector[i+1];
        }
        
        taml--;
    }
    
    if(taml*3<tamf){
        disminuye();
    }
    
    return dato;
}

template <class T>
void VDinamico<T>::ordenar(){
    std::sort(vector,vector+taml);
}

template<class T>
int VDinamico<T>::busquedaBin(T& dato){
    
    
    int primero = 0;
    int ultimo = taml-1;
    int medio;
    
    while(primero<=ultimo){
        medio = (primero + ultimo)/2;
        
        if(dato==vector[medio]){
            return medio;
        }
        else{
            if(dato<vector[medio])
                ultimo=medio-1;
            else
                primero=medio+1;
        }
    }
    
    return -1;
}

template <class T>
int VDinamico<T>::tam(){
    return taml;
}

template <class T>
unsigned VDinamico<T>::calcularTamF(unsigned int tam){
    int exp = ceil(log2(tam));
    return pow (2, exp);
}

template <class T>
void VDinamico<T>::aumenta(){
    if(taml==tamf){
        T* aux;
        aux=new T [tamf=tamf*2];
        
        for(int i=0; i<taml; i++){
            aux[i]=vector[i];
        }
        
        delete []vector;
        vector=aux;
    }
}

template <class T>
void VDinamico<T>::disminuye(){
    if(taml*3<tamf){
        
        tamf=tamf/2;
        T *aux = new T[tamf];
        
        for(int i=0;i<taml;i++){
            aux[i]=vector[i];
        }
        
        delete []vector;
        vector=aux;
    }
}


/******************************** DESTRUCTORES *********************************/
template <class T>
VDinamico<T>::~VDinamico(){
    if(vector)
        delete []vector ;
}

#endif /* VDINAMICO_H */
