/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UTM.h
 * Author: jonathan
 *
 * Created on 18 de octubre de 2019, 13:57
 */

#ifndef UTM_H
#define UTM_H

class UTM {
public:
    UTM();
    UTM(double la, double lon);
    UTM(const UTM& orig);
    virtual ~UTM();
    
    double GetLatitud() const;
    double GetLongitud() const;
    void SetLatitud(double latitud);
    void SetLongitud(double longitud);


private:
    double latitud;
    double longitud;
};

#endif /* UTM_H */

