/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entrada.cpp
 * Author: jonathan
 * 
 * Created on 19 de noviembre de 2019, 12:43
 */

#include "Entrada.h"

Entrada::Entrada() {
}

Entrada::Entrada(const Entrada& orig) {
}

Entrada::~Entrada() {
}

long int Entrada::GetClave() {
    return clave;
}


Entrada::EnumMarcar Entrada::GetMarca() {
    return Marca;
}

void Entrada::SetClave(long int clave) {
    this->clave = clave;
}

void Entrada::SetMarca(EnumMarcar Marca) {
    this->Marca = Marca;
}

string& Entrada::GetDni() {
    return dni;
}

void Entrada::SetClientes(Cliente& clientes) {
    this->clientes = clientes;
}

Cliente& Entrada::GetClientes() {
    return clientes;
}

void Entrada::SetDni(string dni) {
    this->dni = dni;
}

void Entrada::borrar() {
    Marca=Entrada::vacio;
    clave=0;
    dni="";
}

