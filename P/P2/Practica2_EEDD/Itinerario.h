/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Itinerario.h
 * Author: jgr97
 *
 * Created on 18 de octubre de 2019, 20:15
 */

#ifndef ITINERARIO_H
#define ITINERARIO_H
#include "UTM.h"
#include "fecha.h"
#include <iostream>
using namespace std;

class Itinerario {
    
    private:
        int id;
        UTM inicio, fin;
        Fecha fecha;
        int minutos;
        
    public:
        Itinerario(int id, UTM inicio, UTM fin, Fecha fecha, int minutos);
        Itinerario(const Itinerario& other);

    Itinerario& operator=(const Itinerario& right);

        
        
        void setInicio(UTM inicio);
        void setFin(UTM fin);
        void setFecha(Fecha fecha);
        void setMinutos(int minutos);
        
        int getId();
        UTM getInicio();
        UTM getFin();
        Fecha getFecha();
        int getMinutos();
        void mostrar();
        
        virtual ~Itinerario();
};
#endif /* ITINERARIO_H */

