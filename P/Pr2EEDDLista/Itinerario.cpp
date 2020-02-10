/* 
 * File:   Itinerario.cpp
 * Author: javie
 * 
 * Created on 16 de octubre de 2019, 17:28
 */

#include "Itinerario.h"

Itinerario::Itinerario(int id, UTM inicio, UTM fin, Fecha fecha, int minutos) : id(id), inicio(inicio), fin(fin), fecha(fecha), minutos(minutos) {
}

Itinerario::Itinerario() {

}

Itinerario::Itinerario(const Itinerario& orig) {
    id=orig.id;
    inicio=orig.inicio;
    fin=orig.fin;
    fecha=orig.fecha;
    minutos=orig.minutos;
}

Itinerario::~Itinerario() {
}

void Itinerario::setId(int id) {
    this->id = id;
}

void Itinerario::setFin(UTM fin) {
    this->fin = fin;
}

void Itinerario::setInicio(UTM inicio) {
    this->inicio = inicio;
}

void Itinerario::setMinutos(int minutos) {
    this->minutos = minutos;
}

int Itinerario::getMinutos() {
    return minutos;
}

int Itinerario::getId() {
    return id;
}

Fecha Itinerario::getFecha() {
    return fecha;
}

UTM Itinerario::getInicio() {
    return inicio;
}

UTM Itinerario::getFin() {
    return fin;
}

void Itinerario::toString() {
    std::cout<<"Id: "<<id<<" "<<" Fecha: "<<fecha.verDia()<<"-"<<fecha.verMes()<<"-"<<fecha.verAnio()<<" Hora: "<<fecha.verHora()<<":"<<fecha.verMin()<<std::endl;
    
}
