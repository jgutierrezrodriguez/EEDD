/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PuntoRecarga.cpp
 * Author: jgr97
 * 
 * Created on 10 de diciembre de 2019, 18:55
 */

#include "PuntoRecarga.h"

PuntoRecarga::PuntoRecarga() {
}

PuntoRecarga::PuntoRecarga(string _id, UTM _posicion) : id(_id), posicion(_posicion) {
}

PuntoRecarga::PuntoRecarga(const PuntoRecarga& orig) : id(orig.id), posicion(orig.posicion){
}

PuntoRecarga::~PuntoRecarga() {
}

string PuntoRecarga::GetId() const {
    return id;
}

UTM PuntoRecarga::GetPosicion() const {
    return posicion;
}

void PuntoRecarga::SetId(string id) {
    this->id = id;
}

void PuntoRecarga::SetPosicion(UTM posicion) {
    this->posicion = posicion;
}

float PuntoRecarga::getX() {
    return posicion.latitud;
}

float PuntoRecarga::getY() {
    return posicion.longitud;
}
