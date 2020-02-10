/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   THashCliente.h
 * Author: jonathan
 *
 * Created on 15 de noviembre de 2019, 11:59
 */

#ifndef THASHCLIENTE_H
#define THASHCLIENTE_H

#include <string>
#include <iostream>
#include <vector>
#include "Cliente.h"

using namespace std;

class THashCliente {
private:

    class Entrada {
    public:

        enum EnumMarcar {
            vacio, borrado, ocupado
        };

        long int clave=0;
        EnumMarcar Marca=vacio;
        string dni="";
        Cliente clientes;

        Entrada() {
        };

        virtual ~Entrada() {
        };

        EnumMarcar GetMarca() {
            return Marca;
        };

        void SetMarca(EnumMarcar Marca) {
            this->Marca = Marca;
        };

        long int GetClave() {
            return clave;
        };

        void SetClave(long int clave) {
            this->clave = clave;
        };

        Cliente& GetClientes() {
            return clientes;
        };

        void SetClientes(Cliente& clientes) {
            this->clientes = clientes;
            Marca=ocupado;
        };

        string& GetDni() {
            return dni;
        };

        void SetDni(string dni) {
            this->dni = dni;
        };

        void borrar() {
            Marca = vacio;
            clave = 0;
            dni = "";
        };
        Entrada(const Entrada& other) :
        clave(other.clave), Marca(other.Marca), dni(other.dni), clientes(other.clientes) {
        }
        
        
        


    };

    unsigned int tamhash;
     float numclientes;
    float factordecarga;
     float nColisiones;
     float nInserciones;
     float totalColisiones;
     float maxColisiones;
    vector<Entrada> hashmap;
    float ultimos_intentos=0;
    int buscarEntrada(unsigned long clave, string& dni);
    
    

    unsigned int hash(unsigned long clave, int intento);
    unsigned int funcionHashDoble(unsigned long clave, int intento);
    unsigned int funcionhascuadratica(unsigned long clave, int intento);
    unsigned int funcionhasdispersion(unsigned long clave, int intento);

public:

    THashCliente() { };

    THashCliente(int tamtabla);
    THashCliente(const THashCliente& orig);
    virtual ~THashCliente();

    //funciones.
    unsigned int numClientes();
    float getFactordecarga() const;
    unsigned int getTamhash() const;
    unsigned int promedioColisiones();
    unsigned int MaxColisiones();
    float calculoFactorCarga();

    bool insertar(unsigned long clave, string &dni, Cliente &cli);
    bool buscar(unsigned long clave, string& dni, Cliente& cli,int i);
    bool borrar(unsigned long clave, string &dni);
    void redispersar(unsigned tama);
    THashCliente& operator=(const THashCliente& right);

    bool insertarcuadratica(unsigned long clave, string& dni, Cliente& cli);
    bool insertarDobledis(unsigned long int clave, string& dni, Cliente& cli);
    bool insertardispersion(unsigned long int clave, string& dni, Cliente& cli);
    
    float getUltimos_intentos() const {
        return ultimos_intentos;
    }

    

    bool coprimo(unsigned num);

    int primMenor(unsigned num);

    void mostrarInfo(){
        cout<<"Tamanio tabla: "<<tamhash<<endl;
        cout<<"Numero de Clientes: "<< numclientes<<endl;
        cout<<"Factor de Carga: "<< calculoFactorCarga()<<endl;
        cout<<"Promedio de colisiones: "<<promedioColisiones()<<endl;
        cout<<"Max Colisiones: "<<maxColisiones<<endl;
        cout<<"TOTAL COLISIONES: "<<totalColisiones;
                
    }
};

#endif /* THASHCLIENTE_H */

