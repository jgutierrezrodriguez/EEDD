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
id(other.id), posicion(other.posicion), estatus(other.estatus), usadaPor(other.usadaPor) {
}

Moto::~Moto() {

}

Moto::Estado Moto::GetEstatus() const {
    return estatus;
}

std::string Moto::GetId() const {
    return id;
}

UTM Moto::GetPosicion() const {
    return posicion;
}

Cliente* Moto::GetUsadaPor() const {
    return usadaPor;
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

void Moto::SetUsadaPor(Cliente* usadaPor) {
    this->usadaPor = usadaPor;
}

Moto& Moto::operator=(const Moto& otro) {

    if (this != &otro) {
        estatus = otro.estatus;
        id = otro.id;
        posicion = otro.posicion;
        usadaPor = otro.usadaPor;
    }

    return *this;
}

bool Moto::seActiva(Cliente* cli) {
    bool resultado = false;

    if (estatus == bloqueada) {
        usadaPor = cli;
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


