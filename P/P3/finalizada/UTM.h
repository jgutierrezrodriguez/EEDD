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

    

};

#endif /* UTM_H */

