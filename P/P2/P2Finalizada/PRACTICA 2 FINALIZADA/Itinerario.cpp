/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Itinerario.cpp
 * Author: jgr97
 * 
 * Created on 16 de octubre de 2019, 19:31
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
    
    if (this != &right) {
        fecha=right.fecha;
        fin=right.fin;
        id=right.id;
        inicio=right.inicio;
        minutos=right.minutos;
    }
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
    cout<<"\n\tInicio: "<<inicio.latitud<<" "<<inicio.longitud<<"\n\tFin: "<<fin.latitud<<" "<<fin.longitud;
    cout<<"\n\tFecha: "<<fecha.verDia()<<"/"<<fecha.verMes()<<"/"<<fecha.verAnio()<<" Hora:"<<fecha.verHora()<<":"<<fecha.verMin();
    cout<<"\n\tMinutos: "<<minutos;
}
