/* 
 * File:   Itinerario.h
 * Author: javie
 *
 * Created on 16 de octubre de 2019, 17:28
 */

#ifndef ITINERARIO_H
#define	ITINERARIO_H
#include "UTM.h"
#include "fecha.h"
#include <iostream>
class Itinerario {
public:
    Itinerario();
    Itinerario(int id, UTM inicio, UTM fin, Fecha fecha, int minutos);
    Itinerario(const Itinerario& orig);
    virtual ~Itinerario();
    void setId(int id);
    void setInicio(UTM inicio);
    void setFin(UTM fin);
    void setMinutos(int minutos);
    int getId();
    UTM getInicio();
    UTM getFin();
    Fecha getFecha();
    int getMinutos();
    void toString();

private:
    int id;
    UTM inicio;
    UTM fin;
    Fecha fecha;
    int minutos;
};

#endif	/* ITINERARIO_H */

