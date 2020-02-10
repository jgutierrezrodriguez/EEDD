/* 
 * File:   main.cpp
 * Author: Danymad92
 *
 * Created on 6 de noviembre de 2013, 18:06
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <ostream>
#include "CodigoPost.h"
#include "Avl.h"

using namespace std;

struct StructPost{
    string ciudad;
    ListaDEnlazada<CodigoPost> codigos;
    bool operator<(const StructPost &cp) const {
        return (ciudad < cp.ciudad);
    }
    friend ostream& operator <<(ostream& salida, StructPost &a) {
        cout << a.ciudad;
        return salida;
    }
};

void cargarCsv(string cadena,int &Zipcode,string &ZipCodeType,string &City,string &State,string &LocationType,float &Lat,float &Long,string &Location,bool &Decommisioned,int &TaxReturnsFiled,int &EstimatedPopulation,int &TotalWages){
    stringstream ss;
    ss<<cadena;
    //string palabra;
    ss.ignore(1);
    ss>>Zipcode;
    ss.ignore(1);
    ss.ignore(1);
    ss.ignore(1);
    getline(ss>>ws,ZipCodeType,'"');
    ss.ignore(1);
    ss.ignore(1);
    getline(ss>>ws,City,'"');
    ss.ignore(1);
    ss.ignore(1);
    getline(ss>>ws,State,'"');
    ss.ignore(1);
    ss.ignore(1);
    getline(ss>>ws,LocationType,'"');
    ss.ignore(1);
    ss>>Lat;
    ss.ignore(1);
    ss>>Long;
    ss.ignore(1);
    ss.ignore(1);
    getline(ss>>ws,Location,'"');
    ss.ignore(1);
    ss.ignore(1);
    ss>>Decommisioned;
    ss.ignore(1);
    ss.ignore(1);
    ss.ignore(1);
    ss>>TaxReturnsFiled;
    ss.ignore(1);
    ss>>EstimatedPopulation;
    ss.ignore(1);
    ss>>TotalWages;
}

int main(int argc, char** argv) {
     Avl<StructPost> arbol;
    StructPost *encontrado=NULL;
    int Zipcode,TaxReturnsFiled,EstimatedPopulation,TotalWages;
    float Lat,Long;
    string cadena,ZipCodeType,City,State,LocationType,Location,basura,leida;
    bool Decommisioned;
    
    ifstream fichero("free-zipcode-database-Primary.csv");
    if(fichero){
        cout<<"Leyendo el fichero..."<<endl;
        getline(fichero>>ws,basura);
        while(getline(fichero>>ws,cadena)){  
            StructPost s;
            cargarCsv(cadena,Zipcode,ZipCodeType,City,State,LocationType,Lat,Long,Location,Decommisioned,TaxReturnsFiled,EstimatedPopulation,TotalWages);
            s.ciudad=City;
            CodigoPost c(Zipcode,ZipCodeType,State,LocationType,Lat,Long,Location,Decommisioned,TaxReturnsFiled,EstimatedPopulation,TotalWages);
            encontrado=arbol.busquedaNR(s);
            if(encontrado){
                encontrado->codigos.insertarFin(c);
            }else{
                s.codigos.insertarFin(c);
                arbol.insertarNR(s); 
            }            
        }
        
        cout<<"Fichero leido"<<endl;
        
        
        cout<<"Introduzca una ciudad: " <<endl;
        getline(cin>>ws,leida);
        StructPost o;
        o.ciudad=leida;
        encontrado=arbol.busquedaNR(o);
        if(encontrado){
            Iterador<CodigoPost> it=encontrado->codigos.iteradorIni();
            while(it.haySiguiente()){
                cout<<it.dato().GetZipcode()<<endl;
                it.siguiente();
            }
            
        }
    }
    
    return 0;
}