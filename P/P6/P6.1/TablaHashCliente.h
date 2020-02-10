/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TablaHashCliente.h
 * Author: jgr97
 *
 * Created on 30 de noviembre de 2019, 9:32
 */

#ifndef TABLAHASHCLIENTE_H
#define TABLAHASHCLIENTE_H
#include "Cliente.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

enum EstadoEntrada {
    vacio, ocupado, borrado
};

class TablaHashCliente {
private:

    class Entrada {
    public:
        Cliente cliente;
        unsigned long claveEntrada;
        string dni;
        EstadoEntrada estado;

        void SetClave(unsigned long clave) {
            this->claveEntrada = clave;
        }

        void SetCliente(Cliente cliente) {
            this->cliente = cliente;
        }

        void SetDni(string dni) {
            this->dni = dni;
        }

        void SetEstatus(EstadoEntrada estado) {
            this->estado = estado;
        }

        unsigned long GetClave() const {
            return claveEntrada;
        }

        Cliente GetCliente() const {
            return cliente;
        }

        string GetDni() const {
            return dni;
        }

        EstadoEntrada GetEstatus() const {
            return estado;
        }

        Entrada() : cliente(), dni(""), claveEntrada(0), estado(vacio) {

        };

        virtual ~Entrada() {
        }

    };
    //Argumentos
    vector<Entrada> entradas;
    int tam = 0;
    float numTerminos = 0.0;
    float numColisiones = 0.0;
    float maxColisiones = 0.0;

    //Funciones Privadas 
    unsigned hashDoble1(unsigned long clave, int intento);
    ;

    unsigned hashDoble2(unsigned long clave, int intento);
    ;

    unsigned hashCuadratica(unsigned long clave, int intento);

    bool coprimo(unsigned num);

    int primoMenor(unsigned num);

public:
    TablaHashCliente(int tamF);

    virtual ~TablaHashCliente();

    float maxCol();

    float proCol();

    float factorCarga();

    float tama();

    float numClientes();

    bool insertarDoble1(unsigned long clave, string &dni, Cliente &cli);

    bool insertarDoble2(unsigned long clave, string &dni, Cliente &cli);

    bool insertarcuadratica(unsigned long clave, string &dni, Cliente &cli);

    void mostrarInfo();

    vector<Entrada> getEntradas() const {
        return entradas;
    }

    void setEntradas(vector<Entrada> entradas) {
        this->entradas = entradas;
    }

    float getMaxColisiones() const {
        return maxColisiones;
    }

    void setMaxColisiones(float maxColisiones) {
        this->maxColisiones = maxColisiones;
    }

    float getNumTerminos() const {
        return numTerminos;
    }

    void setNumTerminos(float numTerminos) {
        this->numTerminos = numTerminos;
    }

    int getTam() const {
        return tam;
    }

    void setTam(int tam) {
        this->tam = tam;
    }

    void GuardarThash(string nombreArchivo);


    bool borrar(unsigned long clave, string& dni);

    Cliente* buscar(unsigned long clave, string& dni, Cliente & cli);

    float getNumColisiones() const;

    void redispersar(int tama);

    void eliminarMILclientes();
};

#endif /* TABLAHASHCLIENTE_H */

