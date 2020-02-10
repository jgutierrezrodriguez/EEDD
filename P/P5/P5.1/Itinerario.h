

/* 
 * File:   Itinerario.h
 * Author: jgr97 jonathan
 *
 * Created on 16 de octubre de 2019, 19:31
 */



#ifndef ITINERARIO_H
#define ITINERARIO_H
#include "UTM.h"
#include "fecha.h"
#include <iostream>
#include "Moto.h"



class Moto;
using namespace std;
class Itinerario {
    
    private:
        int id;
        UTM inicio, fin;
        Fecha fecha;
        int minutos;
        Moto *vehiculo;
        
        
    public:
        Itinerario();

        Itinerario(int id, UTM inicio, UTM fin, Fecha fecha, int minutos);
        
        Itinerario(const Itinerario& other);

        Itinerario& operator=(const Itinerario& right);

        
        
        void setInicio(UTM inicio);
        void setFin(UTM fin);
        void setFecha(Fecha fecha);
        void setMinutos(int minutos);
        void setId(int id);

        void setVehiculo(Moto* vehiculo);

        
        int getId();
        UTM getInicio();
        UTM getFin();
        Fecha getFecha();
        int getMinutos();
        Moto* getVehiculo();;
        
        virtual ~Itinerario();

        void mostrar();
};

#endif /* ITINERARIO_H */

