/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Cliente.h"



Cliente::Cliente(string _dni, string _pass, string _nombre, string _direccion, double _latitud, double _longitud) :
dni(_dni), pass(_pass), nombre(_nombre), direccion(_direccion), posicion(_latitud, _longitud),listaItinerarios(){
}

Cliente::Cliente() : dni(""), pass(""), nombre(""), direccion(""), posicion(0, 0) {
}

Cliente::Cliente(const Cliente& other) :
dni(other.dni), pass(other.pass), nombre(other.nombre), direccion(other.direccion), posicion(other.posicion), listaItinerarios(other.listaItinerarios){
}

void Cliente::creaitinerarios(int num, int& idUltimo, UTM min, UTM max) {
    srand(1);

    for (int i = 0; i < num; i++) {
        idUltimo = idUltimo + 1;

        int mes = (rand() % 11) + 1;
        int dia = (rand() % 29) + 1;
        int anio = rand() + 2019;
        int hora = (rand() % 23);
        int minutos = (rand() % 59);

        Fecha fecha(dia, mes, anio, hora, minutos);

        double longitudInicio = ((double) rand() * (max.longitud - min.longitud)) / ((double) RAND_MAX - min.longitud);
        double latitudInicio = ((double) rand() * (max.latitud - min.latitud)) / ((double) RAND_MAX - min.latitud);

        double longitudFinal = ((double) rand() * (max.longitud - min.longitud)) / ((double) RAND_MAX - min.longitud);
        double latitudFinal = ((double) rand() * (max.latitud - min.latitud)) / ((double) RAND_MAX - min.latitud);

        UTM inicio(latitudInicio, longitudInicio);
        UTM fin(latitudFinal, longitudFinal);

        int minutosItinerario = rand();

        Itinerario itinera(idUltimo, inicio, fin, fecha, minutosItinerario);
        listaItinerarios.insertaFinal(itinera);

    }
}

double Cliente::distancia(Cliente& c) {

    double distancia = sqrt((posicion.latitud - posicion.longitud)*(posicion.latitud - posicion.longitud)
            + (c.getlatitud() - c.getlongitud())*(c.getlatitud() - c.getlongitud()));

    return distancia;
}

ListaDobleEnlazada<Itinerario> Cliente::getListaItinerarios() {
    return listaItinerarios;
}

void Cliente::mostrarItinerarios() {
    Iterador<Itinerario> it = listaItinerarios.IteradorIterador();
    
    while(!it.fin()){
        it.dato().mostrar();
        it.siguiente();
    }
}


double Cliente::getlatitud() {
    return posicion.latitud;
}

double Cliente::getlongitud() {
    return posicion.longitud;
}

bool Cliente::operator<(const Cliente& otro) const {
    return nombre < otro.nombre;
}

Cliente& Cliente::operator=(const Cliente& otro) {
    dni = otro.dni;
    pass = otro.pass;
    nombre = otro.nombre;
    direccion = otro.direccion;
    posicion.latitud = otro.posicion.latitud;
    posicion.longitud = otro.posicion.longitud;

    return *this;
}

bool Cliente::operator==(const Cliente& otro) {
    bool resultado;
    if (nombre == otro.nombre)
        resultado = true;

    else
        resultado = false;

    return resultado;
}

Cliente::~Cliente() {
}

