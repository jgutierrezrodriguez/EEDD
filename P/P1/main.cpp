/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lidia
 *
 */

#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "VDinamico.h"


using namespace std;

/*
 coordenadas UTM formadas por latitud y longitud 
*/

    struct UTM{
      double latitud;
      double longitud;
      UTM (double _lat, double _long): latitud(_lat), longitud (_long){}
    };
    
    
 /**
 Clase Cliente
 **/   
class Cliente {

    string dni;
    string pass;
    string nombre;
    string direccion;
    UTM posicion;

    
public:
    //Constructor
    Cliente(string _dni, string _pass, string _nombre, string _direccion, double _latitud, double _longitud):
    dni(_dni), pass(_pass), nombre(_nombre), direccion (_direccion), posicion (_latitud, _longitud){}
    
    Cliente():dni(""),pass(""),nombre(""),direccion(""),posicion(0,0){}
    
    Cliente& operator=(const Cliente &otro){
        dni=otro.dni;
        pass=otro.pass;
        nombre=otro.nombre;
        direccion=otro.direccion;
        posicion.latitud=otro.posicion.latitud;
        posicion.longitud=otro.posicion.longitud;
        
        return *this;
    }
    
    bool operator<(const Cliente& otro) const{
        return nombre<otro.nombre;
    }
    
    bool operator==(const Cliente &otro){
        bool resultado;
        if(nombre==otro.nombre)
            resultado= true;
        
        else
            resultado =  false;
        
        return resultado;
    }
    
    double getlatitud(){
        return posicion.latitud;
    }
    
    double getlongitud(){
        return posicion.longitud;
    }
    
    double distancia(Cliente &c){
        
        double distancia = sqrt((posicion.latitud - posicion.longitud)*(posicion.latitud - posicion.longitud ) 
        + (c.getlatitud() - c.getlongitud())*(c.getlatitud() - c.getlongitud()));
        
        return distancia;
    }
};



void leeClientes(string fileNameClientes,VDinamico<Cliente> &v ){
    ifstream fe;                    //Flujo de entrada
    string linea;                   //Cada línea tiene un clienete
    int total = 0;                  //Contador de líneas o clientes
    
    //Variables auxiliares para almacenar los valores leídos
    string dni, nombre, pass, direccion, latitud, longitud;
    double dlat, dlon; 


    
    //Asociamos el flujo al fichero 
    fe.open(fileNameClientes);
    
    if(fe.good()){
        //Mientras no se haya llegado al final del fichero
        while(!fe.eof()){
            getline(fe, linea);     //Toma una línea del fichero
            stringstream ss;        //Stream que trabaja sobre buffer interno         

            if(linea!=""){
                ++total;
            }

            if(total>1){                
                //Inicializamos el contenido de ss
                ss << linea;
                
                //Leemos el NIF
                getline(ss,dni,';');            //El carácter ; se lee y se elimina de ss
                
                //Leemos el pass
                getline(ss,pass,';');           //El caráter ; se lee y se elimina de ss

                //Leemos el nombre
                getline(ss,nombre,';');         //El caráter ; se lee y se elimina de ss
                
                //Leemos la dirección
                getline(ss,direccion,';');      //El caráter ; se lee y se elimina de ss
                
                //Leemos la latitud y longitud
                getline(ss,latitud,';');        //El caráter ; se lee y se elimina de ss
                getline(ss,longitud,';');       //El caráter ; se lee y se elimina de ss

                dlat = stod(latitud);
                dlon = stod(longitud);
                
                //con todos los atributos leídos, se crea el cliente
                Cliente client (dni, pass, nombre, direccion,dlat, dlon);
                v.insertar(client);
            }        
        }
            
        cout<<"Total de clientes en el fichero: " << total <<endl;
        fe.close(); //Cerramos el flujo de entrada
    }else{
        cerr<<"No se puede abrir el fichero"<<endl;
    }    
}

	

int main(int argc, char** argv) {
    try{
    cout << "Comienzo de lectura de un fichero " << endl;
    
    VDinamico <Cliente> v;
    leeClientes ("clientes_v2.csv", v);
    
    v.ordenar();
    
    VDinamico <Cliente> v2(v);
    
    cout<<"\n\nQueremos borrar los clientes cuyo nombre sea Marlie Klassmann.";
    Cliente c("","","Marlie Klassmann","",0,0);
    
    int posicion=0;
    
    cout <<"\nTamanio logico previo: "<<v2.tam()<<"\n";
    
    while(posicion>-1){
        posicion = v2.busquedaBin(c);
        
       
        if(posicion!=-1){
            v2.borrar(posicion);
            cout<<"\nPosicion encontrada y borrada: "<<posicion;
        }
     }
    
    cout <<"\n\nTamanio logico posterior: "<<v2.tam();
    
    
    double distancia;
    double maxDistancia=0;
    for (int i = 0; i < v.tam(); i++) {
        for (int j = 0; j < v.tam(); j++) {
            
            distancia=v[i].distancia(v[j]);
            if(distancia>maxDistancia){
                maxDistancia=distancia;
            }
            
        }
    }
    
    
    
    cout<<"\n\nDistancia mayor entre dos clientes del vector: "<<maxDistancia;
    return 0;
    }catch(std::exception& e){
        cout<<"errores: "<<e.what();
    }
}

