/* 
 * File:   CodigoPost.cpp
 * Author: Miguel Angel
 * 
 * Created on 10 de noviembre de 2013, 18:22
 */

#include "CodigoPost.h"

CodigoPost::CodigoPost(int a,string b,string c,string d,float e,float f,string g,bool h,int i,int j,int k):Zipcode(a),ZipCodeType(b),State(c),LocationType(d),Lat(e),Long(f),Location(g),Decommisioned(h),TaxReturnsFiled(i),EstimatedPopulation(j),TotalWages(k) {
}

CodigoPost::CodigoPost(const CodigoPost& orig):Zipcode(orig.Zipcode),ZipCodeType(orig.ZipCodeType),State(orig.State),LocationType(orig.LocationType),Lat(orig.Lat),Long(orig.Long),Location(orig.Location),Decommisioned(orig.Decommisioned),TaxReturnsFiled(orig.TaxReturnsFiled),EstimatedPopulation(orig.EstimatedPopulation),TotalWages(orig.TotalWages)  {
}

CodigoPost::~CodigoPost() {
}

void CodigoPost::SetTotalWages(int TotalWages) {
    this->TotalWages = TotalWages;
}

int CodigoPost::GetTotalWages() const {
    return TotalWages;
}

void CodigoPost::SetEstimatedPopulation(int EstimatedPopulation) {
    this->EstimatedPopulation = EstimatedPopulation;
}

int CodigoPost::GetEstimatedPopulation() const {
    return EstimatedPopulation;
}

void CodigoPost::SetTaxReturnsFiled(int TaxReturnsFiled) {
    this->TaxReturnsFiled = TaxReturnsFiled;
}

int CodigoPost::GetTaxReturnsFiled() const {
    return TaxReturnsFiled;
}

void CodigoPost::SetDecommisioned(bool Decommisioned) {
    this->Decommisioned = Decommisioned;
}

bool CodigoPost::IsDecommisioned() const {
    return Decommisioned;
}

void CodigoPost::SetLocation(string Location) {
    this->Location = Location;
}

string CodigoPost::GetLocation() const {
    return Location;
}

void CodigoPost::SetLong(float Long) {
    this->Long = Long;
}

float CodigoPost::GetLong() const {
    return Long;
}

void CodigoPost::SetLat(float Lat) {
    this->Lat = Lat;
}

float CodigoPost::GetLat() const {
    return Lat;
}

void CodigoPost::SetLocationType(string LocationType) {
    this->LocationType = LocationType;
}

string CodigoPost::GetLocationType() const {
    return LocationType;
}

void CodigoPost::SetState(string State) {
    this->State = State;
}

string CodigoPost::GetState() const {
    return State;
}

void CodigoPost::SetZipCodeType(string ZipCodeType) {
    this->ZipCodeType = ZipCodeType;
}

string CodigoPost::GetZipCodeType() const {
    return ZipCodeType;
}

void CodigoPost::SetZipcode(int Zipcode) {
    this->Zipcode = Zipcode;
}

int CodigoPost::GetZipcode() const {
    return Zipcode;
}

