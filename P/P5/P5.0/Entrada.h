/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entrada.h
 * Author: jonathan
 *
 * Created on 19 de noviembre de 2019, 12:43
 */

#ifndef ENTRADA_H
#define ENTRADA_H

#include <vector>
#include "Cliente.h"

class Entrada {
public:
    Entrada();
    Entrada(const Entrada& orig);
    virtual ~Entrada();
    enum EnumMarcar{vacio,borrado,ocupado};
    
    EnumMarcar GetMarca() const;

    void SetMarca(EnumMarcar Marca);

    long int GetClave() const;

    void SetClave(long int clave);

    vector<Cliente*> GetClientes() const;

    void SetClientes(vector<Cliente*> clientes);

private:
    long int clave;
    EnumMarcar Marca;
    vector<Cliente*> clientes;
};

#endif /* ENTRADA_H */

