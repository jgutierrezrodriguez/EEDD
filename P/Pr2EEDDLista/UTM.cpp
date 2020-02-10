/* 
 * File:   UTM.cpp
 * Author: javie
 * 
 * Created on 16 de octubre de 2019, 19:15
 */

#include "UTM.h"

UTM::UTM() : latitud(0), longitud(0) {
}

UTM::UTM(double _lat, double _long) : latitud(_lat), longitud(_long) {
}

UTM::UTM(const UTM& orig) {
    latitud = orig.latitud;
    longitud = orig.longitud;
}

double UTM::GetLongitud() const {
    return longitud;
}

double UTM::GetLatitud() const {
    return latitud;
}


