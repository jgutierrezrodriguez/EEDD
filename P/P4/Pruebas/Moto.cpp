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
#include <iostream>

Moto::Moto(std::string id, UTM posicion, Estado estatus) :
id(id), posicion(posicion), estatus(estatus){
    
    srand(time(nullptr));
    if(estatus==sinbateria){
        porcentajeBateria=(rand()%15);
    }
    else{
        porcentajeBateria=( rand()%74)+16;
    }
}

Moto::Moto() {
}

Moto::Moto(const Moto& other) :
id(other.id), posicion(other.posicion), estatus(other.estatus), porcentajeBateria(other.porcentajeBateria){
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

float Moto::GetPorcentajeBateria(){
    return porcentajeBateria;
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

void Moto::SetPorcentajeBateria(float porcentajeBateria) {
    this->porcentajeBateria = porcentajeBateria;
    
    if( porcentajeBateria <= 15.0){
        estatus=sinbateria;
        std::cout<<"\nEstatus cambiado a sin bateria.";
    }
        
}



Moto& Moto::operator=(const Moto& otro) {

    if (this != &otro) {
        estatus = otro.estatus;
        id = otro.id;
        posicion = otro.posicion;
        porcentajeBateria=porcentajeBateria;
    }

    return *this;
}

bool Moto::seActiva() {
    bool resultado = false;

    if (estatus == bloqueada) {
        std::cout<<"Se ha activado la moto";
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
    return id<right.id; // Reuse greater than operator
}

bool Moto::operator==(const Moto& right) const {
    return id==right.id;
}

bool Moto::operator>(const Moto& right) const {
    return id>right.id;
}

