/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Cliente.h"

Cliente::Cliente(string _dni, string _pass, string _nombre, string _direccion, double _latitud, double _longitud) :
dni(_dni), pass(_pass), nombre(_nombre), direccion(_direccion), posicion(_latitud, _longitud), rutas() {
}

Cliente::Cliente() : dni(""), pass(""), nombre(""), direccion(""), posicion(0, 0) {
}

Cliente::Cliente(const Cliente& other) :
dni(other.dni), pass(other.pass), nombre(other.nombre), direccion(other.direccion), posicion(other.posicion), rutas(other.rutas) {
}

void Cliente::creaitinerarios(int num, int& idUltimo, UTM min, UTM max) {
    srand(time(nullptr));
    for (int i = 0; i < num; i++) {
        idUltimo = idUltimo + 1;

        int mes = (rand() % 11) + 1;
        int dia = (rand() % 29) + 1;
        int anio = rand() % 10 + 2019;
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
        
        rutas.push_back(itinera);

    }
}

double Cliente::distancia(Cliente& c) {

    double distancia = posicion.distacia(c.posicion);
      

    return distancia;
}

list<Itinerario> Cliente::getListaItinerarios() {
    return rutas;
}

void Cliente::mostrarItinerarios() {
     list<Itinerario>::iterator it=rutas.begin();
     for(int i=0; i<rutas.size();i++){
         it->mostrar();
         it++;
     }
}

double Cliente::getlatitud() {
    return posicion.latitud;
}

double Cliente::getlongitud() {
    return posicion.longitud;
}

string Cliente::getDni() const {
    return dni;
}


EcoCityMoto* Cliente::getAcceso() const {
    return acceso;
}




bool Cliente::operator<(const Cliente& otro) const {
    return dni < otro.dni;
}

bool Cliente::operator>(const Cliente& otro) const {
    return dni > otro.dni;
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
    if (dni == otro.dni)
        resultado = true;

    else
        resultado = false;

    return resultado;
}

void Cliente::setDNI(string _dni) {
    dni = _dni;
}

Moto& Cliente::buscarMotoCercana() {
    return acceso->MotoCercana(posicion);
    
}

void Cliente::setAcceso(EcoCityMoto* acceso) {
    this->acceso = acceso;
}



 void Cliente::desbloquearMoto(Moto& m) {
    acceso->DesbloqueaMoto(m);
}
 
 ostream& operator<<(ostream& os, const Cliente& obj) {
    os << obj.dni;
    return os;
}
 
 void Cliente::terminarTrayecto(Moto& m) {
    Itinerario it;
    it.setVehiculo(&m);
    srand(time(nullptr));
    it.setId(rand()%5);
    int mes = (rand() % 11) + 1;
    int dia = (rand() % 29) + 1;
    int anio = rand() % 10 + 2019;
    int hora = (rand() % 23);
    int minutos = (rand() % 59);

    Fecha fecha(dia, mes, anio, hora, minutos);
    it.setFecha(fecha);

    double laMax = 38.0;
    double laMin = 37.0;
    double loMax = 4.0;
    double loMin = 3.0;

    double longitudFinal = ((double) rand() * (loMax - loMin)) / ((double) RAND_MAX - loMin);
    double latitudFinal = ((double) rand() * (laMax - laMin)) / ((double) RAND_MAX - laMin);

    UTM fin(latitudFinal, longitudFinal);
    it.setInicio(posicion);
    it.setFin(fin);
    it.setMinutos(rand() % (int)m.GetPorcentajeBateria()-1+1);
    
    rutas.push_back(it);
    
    m.SetPorcentajeBateria(m.GetPorcentajeBateria()-minutos);
    m.seDesactiva();
}
 
string Cliente::getDireccion() const {
    return direccion;
}

string Cliente::getNombre() const {
    return nombre;
}

string Cliente::getPass() const {
    return pass;
}

void Cliente::fromCSV(const std::string ventrada) {
    std::stringstream ss;
    std::locale prefs("");
    ss.imbue(prefs);
    std::string dni, pass, nombre, direccion;
    double latitud, longuitud;
    getline(ss, dni, ';');
    getline(ss, pass, ';');
    getline(ss, nombre, ';');
    getline(ss, direccion, ';');
    ss >> latitud;
    ss.ignore(1);
    ss >> longuitud;
    this->setDNI(dni);
    this->setPass(pass);
    this->setNombre(nombre);
    this->setDireccion(direccion);
    this->getPosicion().setLatitud(latitud);
    this->getPosicion().setLongitud(longuitud);
}

void Cliente::setDireccion(string direccion) {
    this->direccion = direccion;
}

void Cliente::setDni(string dni) {
    this->dni = dni;
}

void Cliente::setNombre(string nombre) {
    this->nombre = nombre;
}

void Cliente::setPass(string pass) {
    this->pass = pass;
}

UTM Cliente::getPosicion() const {
    return posicion;
}



Cliente::~Cliente() {
}

