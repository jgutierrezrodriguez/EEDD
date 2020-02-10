/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/* 
 * File:   main.cpp
 * Author: jgr97
 *
 * Created on 7 de octubre de 2019, 12:38
 */

#include <cstdlib>
#include "Cliente.h"
#include "VDinamico.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <exception>

using namespace std;

void leeClientes(string fileNameClientes,VDinamico<Cliente> &v,double & latMax,double & latMin, double & lonMax, double & lonMin  ){
    ifstream fe;                    //Flujo de entrada
    string linea;                   //Cada línea tiene un clienete
    int total = 0;                  //Contador de líneas o clientes
    
    //Variables auxiliares para almacenar los valores leídos
    string dni, nombre, pass, direccion, latitud, longitud;
    double dlat, dlon; 


    
    //Asociamos el flujo al fichero 
    fe.open(fileNameClientes);
    
    if(fe.good()){
        int primera=0;
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
                
                if(primera==0){
                    latMax=dlat;
                    latMin=dlat;
                    lonMax=dlon;
                    lonMin=dlon;
                    
                    primera++;
                }
                
                else{
                    if(dlat>latMax)
                        latMax=dlat;
                    else if (dlat<latMin)
                        latMin=dlat;
                    
                    if(dlon>lonMax)
                        lonMax=dlon;
                    else if(dlon<lonMin)
                        lonMin=dlon;
                }
                
                v.insertar(client);
            }        
        }
            
        cout<<"Total de clientes en el fichero: " << total <<endl;
        fe.close(); //Cerramos el flujo de entrada
    }else{
        cerr<<"No se puede abrir el fichero"<<endl;
    }    
}
/*
 * 
 */
int main(int argc, char** argv) {

    try{
       srand(time(nullptr));
    
    cout << "Comienzo de lectura de un fichero " << endl;
    
    VDinamico <Cliente> vectorClientes;
    double latMax,latMin,LonMax,LonMin;
    leeClientes ("clientes_v2.csv", vectorClientes,latMax,latMin,LonMax,LonMin);
    
    vectorClientes.ordenar();
  
    UTM min (latMin,LonMin);
    UTM max (latMax,LonMax);
    int idUlt=0;
    int nRand = rand();
    
    cout<<"\nCreamos Itinerarios";
    
    Cliente c("","","Marlie Klassmann","",0,0);
    int posicion=vectorClientes.busquedaBin(c);
    
    cout<<"\nItinerario de Marlie Klassmann:";
    vectorClientes[posicion].creaitinerarios(nRand%10, idUlt, min,max);
    vectorClientes[posicion].mostrarItinerarios();
    
    
    /*
    vectorClientes[1].creaitinerarios(nRand%10, idUlt, min,max);
    vectorClientes[10].creaitinerarios(nRand%7, idUlt, min,max);
    
    cout<<"\nItinerarios vector[1]:";
    vectorClientes[1].mostrarItinerarios();
    cout<<"\n\nItinerarios vector[10]:";
    vectorClientes[10].mostrarItinerarios();
     */
    
    
    
    }catch(std::out_of_range& e){
        cout << e.what() << endl;
    }
    
    
    
}

