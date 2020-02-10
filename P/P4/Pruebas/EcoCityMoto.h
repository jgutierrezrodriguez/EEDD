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
#include "Cliente.h"
#include <string>
#include "UTM.h"
using namespace std;

class Cliente;

class EcoCityMoto {
private:
    unsigned idUltimo;
    vector<Moto> vectorMotos;
    map<string, Cliente> arbolCliente;

public:
    EcoCityMoto();
    EcoCityMoto(vector<Moto> &vectorMotos, map<string, Cliente> &arbolCliente);
    EcoCityMoto(const EcoCityMoto& orig);
    virtual ~EcoCityMoto();
    Moto* MotoCercana(UTM ubicacion);
    void DesbloqueaMoto(Moto* M);
    Cliente* BuscarCliente(string DNI);

    void SetArbolCliente(map<string, Cliente> arbolCliente);
    void SetVectorMotos(vector<Moto> vectorMotos);

    void cargaClientes(string fileNameClientes); //HAY QUE MODIFICARLO PARA CARGAR TMB ITINERARIOS
    void cargaMotos(string fileNameMotos);

    vector<Moto> localizaMotosSinBateria();
    void nuevoCliente(Cliente cli);
    

    void eliminarCliente(string id);

    void cargarclientes(string nombreArchivo);
    void GuardarClientes(string nombreArchivo);

};

#endif /* ECOCITYMOTO_H */

