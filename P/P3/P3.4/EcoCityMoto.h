/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EcoCityMoto.h
 * Author: jgr97
 *
 * Created on 25 de octubre de 2019, 18:43
 */

#ifndef ECOCITYMOTO_H
#define ECOCITYMOTO_H
#include "AVL.h"
#include "VDinamico.h"
#include "Moto.h"
#include "Cliente.h"
#include <string>

class Moto;
class Cliente;

class EcoCityMoto {
    private:
        unsigned idUltimo;
        VDinamico<Moto> vectorMotos;
        AVL<Cliente> arbolCliente;
        
    public:
        EcoCityMoto();
        EcoCityMoto(const EcoCityMoto& orig);
        virtual ~EcoCityMoto();
        Moto MotoCercana(UTM ubicacion);
        void DesbloqueaMoto(Moto M, Cliente* cli);
        Cliente BuscarCliente(string DNI);
        void terminarTrayectoCliente(Cliente* cli){
            int tam=vectorMotos.tam();
            bool encontrado=false;
            int i =0;
            while(encontrado==false){
                if(vectorMotos[i].GetUsadaPor()==cli){
                    encontrado=true;
                    vectorMotos[i].SetPosicion(cli->getPosicion());
                    vectorMotos[i].SetEstatus(bloqueada);
                }
                else
                    i++;
            }
            
        }
};

#endif /* ECOCITYMOTO_H */

