/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: jgr97
 *
 * Created on 7 de octubre de 2019, 12:47
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include <list>
#include <cmath>
#include <string>
#include "UTM.h"
#include <ctime>
#include "Itinerario.h"
using namespace std;

class EcoCityMoto;

    class Cliente {

    string dni;
    string pass;
    string nombre;
    string direccion;
    UTM posicion;
    int puntos;
    EcoCityMoto *acceso;
    list<Itinerario> rutas;

    
public:
    Cliente(string _dni, string _pass, string _nombre, string _direccion, double _latitud, double _longitud);
    
    Cliente();
    
    Cliente(const Cliente& other);
    
    Cliente& operator=( const Cliente &otro);
    
    bool operator<(const Cliente& otro) const;
    
    bool operator==(const Cliente &otro);
    
    bool operator>(const Cliente& otro) const;
    
    friend ostream&  operator<<(ostream& os, const Cliente& obj);
    
    double getlatitud();
    
    double getlongitud();
    
    double distancia(Cliente &c);
    
    void creaitinerarios(int num, int idUltimo, UTM min, UTM max);
    
    list<Itinerario> getListaItinerarios();
    
    void mostrarItinerarios();

    virtual ~Cliente();
    
    string& getDni();
    
    void setDNI(string _dni);

    Moto* buscarMotoCercana();
    
    void desbloquearMoto(Moto *m);
    
    void terminarTrayecto(Moto *m);
    
    void setAcceso(EcoCityMoto* acceso);

    string getDireccion() const;

    string getNombre() const;

    string getPass() const;
    
    void setDireccion(string direccion);

    void setDni(string dni);

    void setNombre(string nombre);

    void setPass(string pass);
   
    void fromCSV(const std::string ventrada);
    
    UTM getPosicion() const;

    EcoCityMoto* getAcceso() const;

    list<Itinerario> getRutas() const;

    void insertarItinerario(Itinerario ite);
    
    void mostrarMensaje(string texto);
    
    void decrementarPunto();
    
    void incrementarPunto();
    
    PuntoRecarga* puntoRecargaCercano();
    
    void recargarMoto(Moto* m, PuntoRecarga* p);
    
    int getPuntos() const {
        return puntos;
    }

    void setPuntos(int puntos) {
        if(puntos<10)
            this->puntos = puntos;
        else
            cout<<"No se puede aumentar mas la puntuacion."<<endl;
    }

    
};

#endif /* CLIENTE_H */

