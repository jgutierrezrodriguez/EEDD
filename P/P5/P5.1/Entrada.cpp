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

long int Entrada::GetClave() const {
    return clave;
}

vector<Cliente*> Entrada::GetClientes() const {
    return clientes;
}

Entrada::EnumMarcar Entrada::GetMarca() const {
    return Marca;
}

void Entrada::SetClave(long int clave) {
    this->clave = clave;
}

void Entrada::SetClientes(vector<Cliente*> clientes) {
    this->clientes = clientes;
}

void Entrada::SetMarca(EnumMarcar Marca) {
    this->Marca = Marca;
}
