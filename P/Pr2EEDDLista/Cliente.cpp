
#include "Cliente.h"

Cliente::Cliente() {
}

Cliente::Cliente(string _dni, string _pass, string _nombre, string _direccion, double _latitud, double _longitud) :
dni(_dni), pass(_pass), nombre(_nombre), direccion(_direccion), posicion(_latitud, _longitud), itinerarios() {
}

Cliente::Cliente(const Cliente& orig) {
    dni = orig.dni;
    nombre = orig.nombre;
    direccion = orig.direccion;
    posicion = orig.posicion;
    itinerarios = orig.itinerarios;
}

Cliente::~Cliente() {
}

bool Cliente::operator<(Cliente& right) {
    if (nombre < right.nombre) {
        return true;
    }
    return false;

}

bool Cliente::operator==(const Cliente& right) {
    if (right.nombre == this->nombre) {
        return true;
    }
    return false;
}

void Cliente::SetPosicion(UTM posicion) {
    this->posicion = posicion;
}

UTM Cliente::GetPosicion() const {
    return posicion;
}

void Cliente::SetDireccion(string direccion) {
    this->direccion = direccion;
}

string Cliente::GetDireccion() const {
    return direccion;
}

void Cliente::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Cliente::GetNombre() const {
    return nombre;
}

void Cliente::SetPass(string pass) {
    this->pass = pass;
}

string Cliente::GetPass() const {
    return pass;
}

void Cliente::SetDni(string dni) {
    this->dni = dni;
}

string Cliente::GetDni() const {
    return dni;
}

ListaEnlazada<Itinerario> Cliente::GetItinerarios() const {
    return itinerarios;
}

void Cliente::creaIntinerarios() {

    int tamRandom = 11;
    int numItinerarios = rand() % tamRandom;
    int idanterior = rand() % tamRandom;
    double maxLong = 14.4;
    double maxLat = 14.4;
    //ListaEnlazada<itinerarios> itns();
    for (int i = 0; i < numItinerarios; i++) {
        int id = idanterior + rand() % (idanterior + tamRandom - idanterior);
        idanterior = id;
        double latitud = rand() % (int) maxLong;
        double longitud = rand() % (int) maxLong;
        double latitud2 = latitud + rand() % (int) (maxLat + 1 - latitud);
        double longitud2 = longitud + rand() % (int) (maxLong + 1 - longitud);

        int annio = 2019 + rand() % (2021 - 2019);
        int mes = 1 + rand() % (13 - 1);
        int dia;
        switch (mes) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                dia = 1 + rand() % (32 - 1);
                break;
            case 4: case 6: case 9: case 11:
                dia = 1 + rand() % (31 - 1);
                break;
            case 2:if (annio % 4 == 0)
                    dia = 1 + rand() % (29 - 1);
                else
                    dia = 1 + rand() % (30 - 1);

                break;
        }
        int hora = rand() % 24;
        int min = rand() % 60;
        Fecha fecha(dia, mes, annio, hora, min);

        UTM utmI(latitud, longitud);
        UTM utmF(latitud2, longitud2);
        Itinerario it(id, utmI, utmF, fecha, min);
        itinerarios.insertaFin(it);

    }
        Iterador<Itinerario> it = itinerarios.iterador();
        std::cout<<"Cliente: "<<this->nombre<<std::endl;
    for (int i = 0; i < itinerarios.getTama(); i++) {
        it.dato().toString();
        it.siguiente();
    }
}
