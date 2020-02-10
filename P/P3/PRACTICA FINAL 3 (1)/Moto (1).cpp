/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Moto.cpp
 * Author: jgr97
 * 
 * Created on 25 de octubre de 2019, 13:26
 */

#include "Moto.h"

Moto::Moto(std::string id, UTM posicion, Estado estatus) :
id(id), posicion(posicion), estatus(estatus) {
}

Moto::Moto() {
}

Moto::Moto(const Moto& other) :
id(other.id), posicion(other.posicion), estatus(other.estatus){
}

Moto::~Moto() {
}

Estado Moto::GetEstatus() const {
    return estatus;
}

std::string Moto::GetId() const {
    return id;
}

UTM Moto::GetPosicion() const {
    return posicion;
}

void Moto::SetEstatus(Estado estatus) {
    this->estatus = estatus;
}

void Moto::SetId(std::string id) {
    this->id = id;
}

void Moto::SetPosicion(UTM posicion) {
    this->posicion = posicion;
}


Moto& Moto::operator=(const Moto& otro) {

    if (this != &otro) {
        estatus = otro.estatus;
        id = otro.id;
        posicion = otro.posicion;
    }

    return *this;
}

bool Moto::seActiva() {
    bool resultado = false;

    if (estatus == bloqueada) {
        estatus = activa;
        resultado = true;
    }

    return resultado;
}

void Moto::seDesactiva() {
    if (estatus == activa) {
        estatus = bloqueada;
    }
}

bool Moto::operator<(const Moto& right) const {
    return right.id > id; // Reuse greater than operator
}

bool Moto::operator==(const Moto& right) const {
    bool result = false;
    if (right.id == id)
        result = true;

    return result;
}

bool Moto::operator>(const Moto& right) const {
    return right.id < id;
}

