/* 
 * File:   UTM.h
 * Author: javie
 *
 * Created on 16 de octubre de 2019, 19:15
 */

#ifndef UTM_H
#define UTM_H

class UTM {
private:
    double latitud;
    double longitud;

public:

    UTM(double _lat, double _long);
    UTM(const UTM& orig);
    UTM();
    double GetLatitud() const;

    double GetLongitud() const;

};

#endif /* UTM_H */

