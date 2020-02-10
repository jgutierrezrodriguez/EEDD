#ifndef CLIENTE_H
#define CLIENTE_H

#include <cmath>
#include "UTM.h"
#include "Itinerario.h"
#include "ListaDobleEnlazada.h"


class Cliente {

private:
    string dni;
    string pass;
    string nombre;
    string direccion;
    UTM posicion;
    
    ListaDobleEnlazada<Itinerario> it;
public:
    //Constructor
    Cliente(string _dni, string _pass, string _nombre, string _direccion, double _latitud, double _longitud);
    
    Cliente();
    
    Cliente& operator=(const Cliente &otro);
    
    bool operator<(const Cliente& otro) const;
    
    bool operator==(const Cliente &otro);
    
    double getlatitud();
    
    double getlongitud();
    
    double distancia(Cliente &c);
    
    void creaitinerarios(int num, int& idUltimo, UTM min, UTM max);
    
    ListaDobleEnlazada<Itinerario> getListaItinerario();
    
    virtual ~Cliente();

};

Cliente::~Cliente() {}

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

            double longitudInicio = ((double) rand() * (max.GetLongitud() - min.GetLongitud())) / ((double) RAND_MAX - min.GetLongitud());
            double latitudInicio = ((double) rand() * (max.GetLatitud() - min.GetLatitud())) / ((double) RAND_MAX - min.GetLatitud());

            double longitudFinal = ((double) rand() * (max.GetLongitud() - min.GetLongitud())) / ((double) RAND_MAX - min.GetLongitud());
            double latitudFinal = ((double) rand() * (max.GetLatitud() - min.GetLatitud())) / ((double) RAND_MAX - min.GetLatitud());

            UTM inicio(latitudInicio, longitudInicio);
            UTM fin(latitudFinal, longitudFinal);

            int minutosItinerario = rand();

            Itinerario itinera(idUltimo, inicio, fin, fecha, minutosItinerario);
            it.insertaInicio(itinera);
        }
    }

ListaDobleEnlazada<Itinerario> Cliente::getListaItinerario(){
        return it;
    }

double Cliente::distancia(Cliente &c){
        
        double distancia = sqrt((posicion.GetLatitud() - posicion.GetLongitud())*(posicion.GetLatitud() - posicion.GetLongitud() ) 
        + (c.getlatitud() - c.getlongitud())*(c.getlatitud() - c.getlongitud()));
        
        return distancia;
    }

double Cliente::getlongitud(){
        return posicion.GetLongitud();
    }


double Cliente::getlatitud(){
        return posicion.GetLatitud();
    }


bool Cliente::operator==(const Cliente &otro){
        bool resultado;
        if(nombre==otro.nombre)
            resultado= true;
        
        else
            resultado =  false;
        
        return resultado;
    }

bool Cliente::operator<(const Cliente& otro) const{
        return nombre<otro.nombre;
    }

Cliente& Cliente::operator=(const Cliente &otro){
        dni=otro.dni;
        pass=otro.pass;
        nombre=otro.nombre;
        direccion=otro.direccion;
        posicion.SetLatitud(otro.posicion.GetLatitud());
        posicion.SetLongitud(otro.posicion.GetLongitud());

        return *this;
    }

Cliente::Cliente():dni(""),pass(""),nombre(""),direccion(""),posicion(0,0){}

Cliente::Cliente(string _dni, string _pass, string _nombre, string _direccion, double _latitud, double _longitud):
    dni(_dni), pass(_pass), nombre(_nombre), direccion (_direccion){
        posicion.SetLatitud(_latitud);
        posicion.SetLongitud(_longitud);
    }
#endif /* CLIENTE_H */

