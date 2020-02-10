/* 
 * File:   CodigoPost.h
 * Author: Miguel Angel
 *
 * Created on 10 de noviembre de 2013, 18:22
 */

#ifndef CODIGOPOST_H
#define CODIGOPOST_H

#include <string>

using namespace std;

class CodigoPost {
private:
    int Zipcode;
    string ZipCodeType;
    string State;
    string LocationType;
    float Lat;
    float Long;
    string Location;
    bool Decommisioned;
    int TaxReturnsFiled;
    int EstimatedPopulation;
    int TotalWages;
public:
    CodigoPost(int a,string b,string c,string d,float e,float f,string g,bool h,int i,int j,int k);
    CodigoPost(const CodigoPost& orig);
    virtual ~CodigoPost();
    void SetTotalWages(int TotalWages);
    int GetTotalWages() const;
    void SetEstimatedPopulation(int EstimatedPopulation);
    int GetEstimatedPopulation() const;
    void SetTaxReturnsFiled(int TaxReturnsFiled);
    int GetTaxReturnsFiled() const;
    void SetDecommisioned(bool Decommisioned);
    bool IsDecommisioned() const;
    void SetLocation(string Location);
    string GetLocation() const;
    void SetLong(float Long);
    float GetLong() const;
    void SetLat(float Lat);
    float GetLat() const;
    void SetLocationType(string LocationType);
    string GetLocationType() const;
    void SetState(string State);
    string GetState() const;
    void SetZipCodeType(string ZipCodeType);
    string GetZipCodeType() const;
    void SetZipcode(int Zipcode);
    int GetZipcode() const;
};

#endif /* CODIGOPOST_H */