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

enum EstadoEntrada {vacio,ocupado,borrado};

class TablaHashCliente {
    
    private:
        
        class Entrada{
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
                
            
                Entrada():cliente(),dni(""),claveEntrada(0),estado(vacio){
                    
                };
                
                virtual ~Entrada()  {
                }
                
        };
        //Argumentos
        vector<Entrada> entradas;
        int tam=0;
        float numTerminos=0.0;
        float numColisiones=0.0;
        float maxColisiones=0.0;
        
        //Funciones Privadas 
        unsigned hashDoble1(unsigned long clave, int intento);;
        
        unsigned hashDoble2(unsigned long clave, int intento);;
        
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
        
        bool insertarDoble1(unsigned long clave,string &dni,Cliente &cli);
        
        bool insertarDoble2(unsigned long clave,string &dni,Cliente &cli);
        
        bool insertarcuadratica(unsigned long clave,string &dni,Cliente &cli);
        
        void mostrarInfo();;
        
        bool borrar(unsigned long clave,string& dni);
        
        Cliente* buscar(unsigned long clave,string& dni,Cliente & cli);
        
        float getNumColisiones() const;       
        
        void redispersar(int tama);
        
        void eliminarMILclientes(){
            int cont=0;
            int i=0;
            while(cont<1000){
                if(entradas[i].estado==ocupado){
                    entradas[i].estado=borrado;
                    numTerminos--;
                    
                    if(factorCarga()<0.6){
                        cout<<"Se va a redispersar."<<endl;
                        int taman=tam-tam/3;
                        redispersar(taman);
                        cout<<"Se ha redispersado."<<endl;
                    }
                    
                    cont++;
                }
                i++;
            }
                
        }
};

#endif /* TABLAHASHCLIENTE_H */

