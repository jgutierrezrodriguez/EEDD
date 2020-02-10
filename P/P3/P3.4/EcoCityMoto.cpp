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

EcoCityMoto::EcoCityMoto(const EcoCityMoto& orig) : idUltimo(orig.idUltimo), vectorMotos(orig.vectorMotos), arbolCliente(orig.arbolCliente){
}

EcoCityMoto::~EcoCityMoto() {
}

Cliente EcoCityMoto::BuscarCliente(string DNI) {

}

void EcoCityMoto::DesbloqueaMoto(Moto Mo, Cliente* cli) {
    int posicion;
    posicion=vectorMotos.busquedaBin(Mo);
    vectorMotos[posicion].seActiva(cli);
}

Moto EcoCityMoto::MotoCercana(UTM ubicacion) {
    double distancia = 0;
    double minimadistancia = 9999999;
    Moto motodef;

    for (int i = 0; i < vectorMotos.tam(); i++) {
        UTM aux = vectorMotos[i].GetPosicion();

        distancia = sqrt((ubicacion.latitud - ubicacion.longitud)*(ubicacion.latitud - ubicacion.longitud)
                + (aux.latitud - aux.longitud)*(aux.latitud - aux.longitud));

        if (distancia < minimadistancia) {
            minimadistancia = distancia;
            motodef=vectorMotos[i];
        }

    }  
        return motodef;
}