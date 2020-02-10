/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Itinerario.cpp
 * Author: jgr97
 * 
 * Created on 18 de octubre de 2019, 20:15
 */

#include "Itinerario.h"

Itinerario::Itinerario(int id, UTM inicio, UTM fin, Fecha fecha, int minutos) :
id(id), inicio(inicio), fin(fin), fecha(fecha), minutos(minutos)
{
}

Itinerario::Itinerario(const Itinerario& other) :
id(other.id), inicio(other.inicio), fin(other.fin), fecha(other.fecha), minutos(other.minutos) {
}

Itinerario& Itinerario::operator=(const Itinerario& right) {
    // Check for self-assignment!
    if (this == &right) // Same object?
        return *this; // Yes, so skip assignment, and just return *this.
    // Deallocate, allocate new space, copy values...
    return *this;
}


Fecha Itinerario::getFecha() {
    return fecha;
}

UTM Itinerario::getFin() {
    return fin;
}

int Itinerario::getId() {
    return id;
}

UTM Itinerario::getInicio() {
    return inicio;
}

int Itinerario::getMinutos() {
    return minutos;
}

void Itinerario::setFecha(Fecha fecha) {
    this->fecha=fecha;
}

void Itinerario::setFin(UTM fin) {
    this->fin=fin;
}

void Itinerario::setInicio(UTM inicio) {
    this->inicio=inicio;
}

void Itinerario::setMinutos(int minutos) {
    this->minutos=minutos;
}

Itinerario::~Itinerario() {
}

void Itinerario::mostrar() {
    cout<<"\nid: "<<id;
    cout<<"\n\tInicio: "<<inicio.GetLatitud()<<" "<<inicio.GetLongitud()<<"\n\tFin: "<<fin.GetLatitud()<<" "<<fin.GetLongitud();
    cout<<"\n\tFecha: "<<fecha.verAnio()<<"/"<<fecha.verMes()<<"/"<<fecha.verDia()<<"/"<<fecha.verHora()<<"/"<<fecha.verMin();
    cout<<"\n\tMinutos: "<<minutos;
}

