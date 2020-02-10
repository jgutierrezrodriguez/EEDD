/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EcoCityMoto.cpp
 * Author: jgr97
 * 
 * Created on 25 de octubre de 2019, 18:43
 */

#include "EcoCityMoto.h"

EcoCityMoto::EcoCityMoto() : idUltimo(0) {
}

EcoCityMoto::EcoCityMoto(VDinamico<Moto> &vectorMotos, AVL<Cliente> &arbolCliente) :
vectorMotos(vectorMotos), arbolCliente(arbolCliente) {
}


EcoCityMoto::EcoCityMoto(const EcoCityMoto& orig) : idUltimo(orig.idUltimo) {
}

EcoCityMoto::~EcoCityMoto() {
}


Cliente* EcoCityMoto::BuscarCliente(string DNI) {

    Cliente aux;
    aux.setDNI(DNI);
    Cliente *devolver;
    
    devolver=arbolCliente.busquedaRecursiva(aux);
    
    
    
    return devolver;
    
}

void EcoCityMoto::DesbloqueaMoto(Moto* Mo) {
    int i;
    i=vectorMotos.busquedaBin(*Mo);
    vectorMotos[i].seActiva();
}

Moto* EcoCityMoto::MotoCercana(UTM ubicacion) {
    double distancia = 0;
    double minimadistancia = 9999;
    Moto *motodef;
    int i=0;
  
    for (i; i < vectorMotos.tam(); i++) {
        
        UTM aux = vectorMotos[i].GetPosicion();
        
        double distancia = ubicacion.distacia(aux);

        if (distancia < minimadistancia) {
            minimadistancia = distancia;
            motodef=&(vectorMotos[i]);
        }
    }  
        return motodef;
}

void EcoCityMoto::SetVectorMotos(VDinamico<Moto> vectorMotos) {
    this->vectorMotos = vectorMotos;
}


void EcoCityMoto::SetArbolCliente(AVL<Cliente> arbolCliente) {
    this->arbolCliente = arbolCliente;
}




