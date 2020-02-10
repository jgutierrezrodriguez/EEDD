/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UTM.h
 * Author: jgr97 jonathan
 *
 * Created on 16 de octubre de 2019, 19:53
 */

#ifndef UTM_H
#define UTM_H

struct UTM {
    double latitud = 0;
    double longitud = 0;

    UTM(double _lat, double _long) : latitud(_lat), longitud(_long) {
    }

    UTM(const UTM& otro) {
        latitud = otro.latitud;
        longitud = otro.longitud;
    }

    UTM() {
    }

    UTM& operator=(const UTM& right) {

        if (this != &right) {
            latitud = right.latitud;
            longitud = right.longitud;
        }

        return *this;
    }

    double distacia(const UTM& otro){
        double latitud_=latitud-otro.latitud;
        double longitud_=longitud-otro.longitud;
        double distacia=latitud_+longitud_;

        return distacia;
    }

    double getLatitud() const {
        return latitud;
    }

    void setLatitud(double latitud) {
        this->latitud = latitud;
    }

    double getLongitud() const {
        return longitud;
    }

    void setLongitud(double longitud) {
        this->longitud = longitud;
    }


};

#endif /* UTM_H */

