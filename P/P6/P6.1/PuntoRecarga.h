/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PuntoRecarga.h
 * Author: jgr97
 *
 * Created on 10 de diciembre de 2019, 18:55
 */

#ifndef PUNTORECARGA_H
#define PUNTORECARGA_H
#include <string>
#include "UTM.h"

using namespace std;
class PuntoRecarga {
    private:
        string id;
        UTM posicion;

    public:
        PuntoRecarga();
        PuntoRecarga(string _id, UTM _posicion);
        PuntoRecarga(const PuntoRecarga& orig);
        virtual ~PuntoRecarga();
    
        string GetId() const;

        UTM GetPosicion() const;
        
        void SetId(string id);

        void SetPosicion(UTM posicion);
        
        float getX();
        
        float getY();    
};

#endif /* PUNTORECARGA_H */

