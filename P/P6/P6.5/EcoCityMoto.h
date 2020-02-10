/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EcoCityMoto.h
 * Author: jgr97
 *
 * Created on 25 de octubre de 2019, 18:43
 */

#ifndef ECOCITYMOTO_H
#define ECOCITYMOTO_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include "Moto.h"
#include "TablaHashCliente.h"
#include <string>
#include "UTM.h"
#include <cstring>
#include "MallaRegular.h"
using namespace std;

class Cliente;

class EcoCityMoto {
private:
    unsigned idUltimo;
    vector<Moto> vectorMotos;
    TablaHashCliente arbolCliente;
    vector<string> dniClientes;
    
    MallaRegular<PuntoRecarga> mallaPRecargas;
    unsigned long djb2(char* str);



public:
    
    EcoCityMoto(int tama, float aXMin, float aYMin, float aXMax, float aYMax, int nDivX, int nDivY);
    EcoCityMoto(vector<Moto> &vectorMotos, TablaHashCliente &arbolCliente);
    EcoCityMoto(const EcoCityMoto& orig);
    virtual ~EcoCityMoto();
    Moto* MotoCercana(UTM ubicacion);
    void DesbloqueaMoto(Moto* M);
    Cliente* BuscarCliente(string DNI);

    void cargaClientesHashDoble1(string fileNameClientes);
    void cargaClientesHashDoble2(string fileNameClientes);
    void cargaClientesHashcuadratica(string fileNameClientes);
    void cargaMotos(string fileNameMotos);

    vector<Moto*> localizaMotosSinBateria();
    void nuevoCliente(Cliente &cli);

    vector<string> getDniClientes() const;
    
    void mostrarInfoMalla(){
        cout<<endl<<"Maximo de puntos de recarga por celda: "<<mallaPRecargas.maxElementosPorCelda()<<endl;
        cout<<"Media de puntos de recarga por celda: "<<mallaPRecargas.mediaElementosPorCelda()<<endl;
    }



    void eliminarCliente(string id);

    void cargarclientes(string nombreArchivo);
    void GuardarClientes(string nombreArchivo);

    void eliminamilclientes();;

    PuntoRecarga* puntoRecargaCercano(Cliente* cli);
    void CargarPuntosRecarga(string file);
};

#endif /* ECOCITYMOTO_H */

