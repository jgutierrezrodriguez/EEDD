/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UTM.cpp
 * Author: jonathan
 * 
 * Created on 18 de octubre de 2019, 13:57
 */

#include "UTM.h"

UTM::UTM(): latitud(0), longitud(0) {
}

UTM::UTM(double la, double lon): latitud(la), longitud(lon)
{

}


UTM::UTM(const UTM& orig): latitud(orig.latitud), longitud(orig.longitud) {
}

UTM::~UTM() {
}

double UTM::GetLatitud() const {
    return latitud;
}

double UTM::GetLongitud() const {
    return longitud;
}

void UTM::SetLatitud(double latitud) {
    this->latitud = latitud;
}

void UTM::SetLongitud(double longuitud) {
    this->longitud = longuitud;
}


