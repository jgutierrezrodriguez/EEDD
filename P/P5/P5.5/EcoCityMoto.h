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
#include "THashCliente.h"
#include <vector>
#include "Moto.h"
#include <string>
#include <cstring>
using namespace std;

class EcoCityMoto {
private:
    unsigned idUltimo;
    vector<Moto> vectorMotos;
    THashCliente arbolCliente;

public:
    EcoCityMoto();
    EcoCityMoto(int tama);
    EcoCityMoto(const EcoCityMoto& orig);
    EcoCityMoto(vector<Moto> &vectorMotos, THashCliente &arbolCliente);
    virtual ~EcoCityMoto();
    Moto* MotoCercana(UTM ubicacion);
    void DesbloqueaMoto(Moto* M);
    Cliente* BuscarCliente(string DNI);

    void cargaClientes(string fileNameClientes,int opcion); //HAY QUE MODIFICARLO PARA CARGAR TMB ITINERARIOS
    void cargaMotos(string fileNameMotos);

    vector<Moto*> localizaMotosSinBateria();
    void nuevoCliente(Cliente &cli);

    unsigned long djb2(char* str);


    void eliminarCliente(string id);

    void cargarclientes(string nombreArchivo);
    void GuardarClientes(string nombreArchivo);

    bool encuentracliente(string dni);
    

};

#endif /* ECOCITYMOTO_H */

