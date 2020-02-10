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


#include <string>
#include "Cliente.h"
using namespace std;
class Cliente;
class Entrada {
    enum EnumMarcar{vacio,borrado,ocupado};
    private:
        friend class THashCliente;
        long int clave;
        EnumMarcar Marca;
        string dni;
        Cliente clientes;
    public:
        Entrada();
        Entrada(const Entrada& orig);
        virtual ~Entrada();
        

        EnumMarcar GetMarca();

        void SetMarca(EnumMarcar Marca);

        long int GetClave();

        void SetClave(long int clave);

        Cliente& GetClientes();

        void SetClientes(Cliente& clientes);

        string& GetDni();

        void SetDni(string dni);

        void borrar();



};

#endif /* ENTRADA_H */

