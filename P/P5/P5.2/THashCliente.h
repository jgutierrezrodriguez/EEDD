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
        enum EnumMarcar{vacio,borrado,ocupado};
       
            long int clave;
            EnumMarcar Marca;
            string dni;
            Cliente clientes;
        
            Entrada() {};
            
            
            virtual ~Entrada(){};


            EnumMarcar GetMarca(){
                return Marca;
            };

            void SetMarca(EnumMarcar Marca){
                this->Marca = Marca;
            };

            long int GetClave() {
                return clave;
            };


            void SetClave(long int clave){
                this->clave = clave;
            };

            Cliente& GetClientes(){
                return clientes;
            };

            void SetClientes(Cliente& clientes){
                this->clientes=clientes;
            };

            string& GetDni(){
                return dni;
            };

            void SetDni(string dni){
                this->dni = dni;
            };

            void borrar(){
                Marca=Entrada::vacio;
                clave=0;
                dni="";
            };



    };
    
    unsigned int tamhash;
    unsigned int numclientes;
    float factordecarga;
    unsigned int nColisiones;
    unsigned int nInserciones;
    unsigned int totalColisiones;
    unsigned int maxColisiones;
    vector<Entrada> hashmap;
    int buscarEntrada(unsigned long clave, string& dni);
    
    unsigned int hash(unsigned long clave, int intento);
    
    public:
        THashCliente() {};

        THashCliente(int tamtabla);
        THashCliente(const THashCliente& orig);
        virtual ~THashCliente();

        //funciones.
        unsigned int numClientes();
        float getFactordecarga() const;
        unsigned int getTamhash() const;
        unsigned int promedioColisiones();
        unsigned int MaxColisiones();
        double calculoFactorCarga();

        bool insertar( unsigned long clave,  string &dni,Cliente &cli);
        bool buscar(unsigned long clave, string& dni, Cliente& cli);
        bool borrar(unsigned long clave, string &dni);
        void redispersar(unsigned tama);
        THashCliente& operator=(const THashCliente& right);



    


};

#endif /* THASHCLIENTE_H */

