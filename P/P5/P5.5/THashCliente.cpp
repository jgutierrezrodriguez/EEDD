/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   THashCliente.cpp
 * Author: jonathan
 * 
 * Created on 15 de noviembre de 2019, 11:59
 */

#include "THashCliente.h"

THashCliente::THashCliente(int tamtabla) : tamhash(tamtabla), numclientes(0), nColisiones(0), nInserciones(0), totalColisiones(0) {
    for(int i =0; i<tamtabla; i++){
        Entrada estandar_vacio;
        hashmap.push_back(estandar_vacio);
    }
}

THashCliente::THashCliente(const THashCliente& orig) : tamhash(orig.tamhash), hashmap(orig.hashmap), numclientes(orig.numclientes),
factordecarga(orig.factordecarga), maxColisiones(orig.maxColisiones), nColisiones(orig.nColisiones), nInserciones(orig.nInserciones),
totalColisiones(orig.totalColisiones) {
}

THashCliente::~THashCliente() {
}

float THashCliente::getFactordecarga() const {
    return factordecarga;
}

unsigned int THashCliente::getTamhash() const {
    return tamhash;
}

unsigned int THashCliente::numClientes() {
    return numclientes;
}

unsigned int THashCliente::promedioColisiones() {
    return nInserciones / totalColisiones;
}

unsigned int THashCliente::MaxColisiones() {
    return maxColisiones;
}

//bool THashCliente::insertar(unsigned long clave, string& dni, Cliente& cli) {
//
//    if (calculoFactorCarga() > 0.7) {
//        redispersar(tamhash * 2);
//    }
//
//    bool insertado = false;
//    int intentos = 0;
//    int limite = 23;
//    bool encontrado = false;
//    Cliente client;
//
//
//    encontrado = buscar(clave, dni, client);
//
//    while (!encontrado && intentos < limite) {
//        int posicion = hash(clave, intentos);
//
//        if (hashmap[posicion].GetMarca() == Entrada::vacio) {
//            hashmap[posicion].SetClientes(cli);
//            hashmap[posicion].SetDni(dni);
//            hashmap[posicion].SetClave(clave);
//            hashmap[posicion].SetMarca(Entrada::ocupado);
//            insertado = true;
//            encontrado = true;
//            numclientes++;
//            nInserciones++;
//        } else {
//            intentos++;
//        }
//    }
//
//    if (intentos > maxColisiones) {
//        maxColisiones = intentos;
//    }
//
//    totalColisiones = totalColisiones + intentos;
//
//    return insertado;
//}

bool THashCliente::borrar(unsigned long clave, string& dni) {
    bool encontrado = false;
    Cliente cli;

    encontrado = buscar(clave, dni, cli,1);
    int posicion = buscarEntrada(clave, dni);

    if (encontrado) {
        hashmap[posicion].borrar();
        numclientes--;
    }

    return encontrado; // Borramos la entrada, pero el dni sigue asociado a la entrada 
}

unsigned int THashCliente::hash(unsigned long clave, int intento) {

    //Funcion hash cuadratica
    //    unsigned long posicion;
    //    posicion = (clave + (intento * intento)) % tamhash;
    //    return posicion;

    //Funcion hash doble dispersion
    //    unsigned long posicion, posicion_final;
    //    posicion = clave % tamhash;
    //    posicion_final = (posicion + (intento * (proRelat - (clave % (proRelat))))) % tamhash; //proRelat es el numero primo menor al tamhash
    //    return posicion_final;

}

unsigned int THashCliente::funcionhasdispersion(unsigned long clave, int intento) {
    int proRelat=primMenor(tamhash);
    unsigned long posicion, posicion_final;
    posicion = clave % tamhash;
    posicion_final = (posicion + (intento * (proRelat - (clave % (proRelat))))) % tamhash; //proRelat es el numero primo menor al tamhash
    return posicion_final;
}


unsigned int THashCliente::funcionhascuadratica(unsigned long clave, int intento) {
        unsigned long posicion;
        posicion = (clave + (intento * intento)) % tamhash;
        return posicion;
}


unsigned int THashCliente::funcionHashDoble(unsigned long clave, int intento) {
    unsigned int posicion, porcentaje;
    porcentaje = clave % hashmap.size() + (intento * clave % hashmap.size());
            posicion = porcentaje % hashmap.size();
    return posicion;
}

bool THashCliente::buscar(unsigned long clave, string& dni, Cliente& cli,int i) {
    bool encontrado = false;
    int intentos = 0;

    while (!encontrado && intentos < 100) {
        int posicion;
        if(i==1)
            posicion = funcionhasdispersion(clave, intentos);
        else if(i==2)
            posicion = funcionHashDoble(clave, intentos);
        else if(i==3)
            posicion = funcionhascuadratica(clave, intentos);

        if (hashmap[posicion].GetMarca() == Entrada::ocupado && hashmap[posicion].GetDni() == dni) {
            cli = hashmap[posicion].clientes;
            encontrado = true;
        } else {
            intentos++;
        }
    }
    return encontrado;
}

int THashCliente::buscarEntrada(unsigned long clave, string& dni) {
    bool encontrado = false;
    int intentos = 0;
    int posicion;

    while (!encontrado && intentos < tamhash) {
        posicion = hash(clave, intentos);

        if (hashmap[posicion].GetMarca() == Entrada::ocupado && hashmap[posicion].GetDni() == dni) {
            encontrado = true;
        } else {
            intentos++;
        }
    }

    return posicion;
}

void THashCliente::redispersar(unsigned tama) {

    THashCliente nueva(tama);

    for (int i = 0; i < hashmap.size(); i++) {
        if (hashmap[i].GetMarca() == Entrada::ocupado) {
            nueva.insertardispersion(hashmap[i].GetClave(), hashmap[i].GetDni(), hashmap[i].GetClientes());
        }
    }

    *this = nueva;

}

float THashCliente::calculoFactorCarga() {
    float fc;
    
    fc = numclientes / tamhash;

    return fc;
}

THashCliente& THashCliente::operator=(const THashCliente& right) {
    if (this != &right) {
        this->tamhash = right.tamhash;
        this->nColisiones = right.nColisiones;
        this->numclientes = right.numclientes;
        this->factordecarga = right.factordecarga;
        this->nInserciones = right.nInserciones;
        this->maxColisiones = right.maxColisiones;
        this->totalColisiones = right.totalColisiones;
        this->hashmap = right.hashmap;
    }

    return *this;
}

bool THashCliente::insertarDobledis(unsigned long int clave, string& dni, Cliente& cli) {
    if (calculoFactorCarga() > 0.7) {
        redispersar(tamhash * 2);
    }

    bool insertado = false;
    int intentos = 0;
    int limite = 50;
    bool encontrado = false;
    Cliente client;


    encontrado = buscar(clave, dni, client,2);

    while (!encontrado && intentos < limite) {
        int posicion = funcionHashDoble(clave, intentos);

        if (hashmap[posicion].GetMarca() == Entrada::vacio) {
            hashmap[posicion].SetClientes(cli);
            hashmap[posicion].SetDni(dni);
            hashmap[posicion].SetClave(clave);
            hashmap[posicion].SetMarca(Entrada::ocupado);
            insertado = true;
            encontrado = true;
            numclientes++;
            nInserciones++;
        } else {
            intentos++;
        }
    }

    if (intentos > maxColisiones) {
        maxColisiones = intentos;
    }
    ultimos_intentos=intentos;
    totalColisiones = totalColisiones + intentos;

    return insertado;
}

bool THashCliente::insertarcuadratica(unsigned long clave, string& dni, Cliente& cli) {

    if (calculoFactorCarga() > 0.7) {
        redispersar(tamhash * 2);
    }

    bool insertado = false;
    int intentos = 0;
    int limite = 23;
    bool encontrado = false;
    Cliente client;


    encontrado = buscar(clave, dni, client,3);

    while (!encontrado && intentos < limite) {
        int posicion = funcionhascuadratica(clave, intentos);

        if (hashmap[posicion].GetMarca() == Entrada::vacio) {
            hashmap[posicion].SetClientes(cli);
            hashmap[posicion].SetDni(dni);
            hashmap[posicion].SetClave(clave);
            hashmap[posicion].SetMarca(Entrada::ocupado);
            insertado = true;
            encontrado = true;
            numclientes++;
            nInserciones++;
        } else {
            intentos++;
        }
    }

    if (intentos > maxColisiones) {
        maxColisiones = intentos;
    }

    totalColisiones = totalColisiones + intentos;

    return insertado;
}

bool THashCliente::insertardispersion(unsigned long int clave, string& dni, Cliente& cli) {
    if (calculoFactorCarga() > 0.7) {
        redispersar(tamhash * 2);
    }

    bool insertado = false;
    int intentos = 0;
    int limite = 50;
    bool encontrado = false;
    Cliente client;


    encontrado = buscar(clave, dni, client,1);

    while (!encontrado && intentos < limite) {
        int posicion = funcionhasdispersion(clave, intentos);

        if (hashmap[posicion].GetMarca() == Entrada::vacio) {
            hashmap[posicion].SetClientes(cli);
            hashmap[posicion].SetDni(dni);
            hashmap[posicion].SetClave(clave);
            hashmap[posicion].SetMarca(Entrada::ocupado);
            insertado = true;
            encontrado = true;
            numclientes++;
            nInserciones++;
        } else {
            intentos++;
        }
    }
    
    if (intentos > maxColisiones) {
        maxColisiones = intentos;
    }
    
    ultimos_intentos=intentos;
    totalColisiones = totalColisiones + intentos;

    return insertado;
}

bool THashCliente::coprimo(unsigned num) {
    for (unsigned i = 2; i < num / 2; ++i)
        if (num % i == 0)
            return false;
    return true;
}

int THashCliente::primMenor(unsigned num) {
    int numi = num - 1;
    while (!coprimo(numi)) {
        --numi;
    }
    return numi;
}



