/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EcoCityMoto.cpp
 * Author: jgr97
 * 
 * Created on 25 de octubre de 2019, 18:43
 */

#include "EcoCityMoto.h"

EcoCityMoto::EcoCityMoto() : idUltimo(0) {
}

EcoCityMoto::EcoCityMoto(vector<Moto> &vectorMotos, map<string, Cliente> &arbolCliente) :
vectorMotos(vectorMotos), arbolCliente(arbolCliente) {
}

EcoCityMoto::EcoCityMoto(const EcoCityMoto& orig) : idUltimo(orig.idUltimo), vectorMotos(orig.vectorMotos), arbolCliente(orig.arbolCliente) {
}

EcoCityMoto::~EcoCityMoto() {
    GuardarClientes("pruebanum1.csv");
}

Cliente* EcoCityMoto::BuscarCliente(string DNI) {
    if(DNI==""){
        throw std::invalid_argument("Ecocitymoto::BuscarCliente: No es posible asignar cadena vacia a un dni");
    }
    map<string, Cliente>::iterator it;

    it = arbolCliente.find(DNI);
    return &(arbolCliente.at(DNI));
}

void EcoCityMoto::DesbloqueaMoto(Moto* Mo) {
    if (Mo->GetPorcentajeBateria() < 15 || Mo->GetPorcentajeBateria() > 100) {
        throw std::out_of_range("Ecocitymoto::DesbloquearMoto: No es posible desbloquear la moto ya que la bateria esta rota");
    }
    vector<Moto>::iterator it;
    it = find(vectorMotos.begin(), vectorMotos.end(), *Mo);
    it->seActiva();
}

Moto* EcoCityMoto::MotoCercana(UTM ubicacion) {
    double distancia = 0;
    double minimadistancia = 9999;
    Moto *motodef;
    int i = 0;

    for (; i < vectorMotos.size(); i++) {

        UTM aux = vectorMotos[i].GetPosicion();

        double distancia = ubicacion.distacia(aux);

        if (distancia < minimadistancia) {
            minimadistancia = distancia;
            motodef = &(vectorMotos[i]);
        }
    }
    return motodef;
}

void EcoCityMoto::SetVectorMotos(vector<Moto> vectorMotos) {
    this->vectorMotos = vectorMotos;
}

void EcoCityMoto::SetArbolCliente(map<string, Cliente> arbolCliente) {
    this->arbolCliente = arbolCliente;
}

bool EcoCityMoto::encuentracliente(string dni) {
    bool resultado = false;
    if (arbolCliente.count(dni)>0) {
        resultado = true;
    }
    return resultado;
}


//void EcoCityMoto::cargaClientes(string fileNameClientes) {
//    ifstream fe; //Flujo de entrada
//    string linea; //Cada línea tiene un clienete
//    int total = 0; //Contador de líneas o clientes
//
//    //Variables auxiliares para almacenar los valores leídos
//    string dni, nombre, pass, direccion, latitud, longitud;
//    double dlat, dlon;
//
//
//
//    //Asociamos el flujo al fichero 
//    fe.open(fileNameClientes);
//
//    if (fe.good()) {
//        int primera = 0;
//        //Mientras no se haya llegado al final del fichero
//        while (!fe.eof()) {
//            getline(fe, linea); //Toma una línea del fichero
//            stringstream ss; //Stream que trabaja sobre buffer interno         
//
//            if (linea != "") {
//                ++total;
//            }
//
//            if (total > 1) {
//                //Inicializamos el contenido de ss
//                ss << linea;
//
//                //Leemos el NIF
//                getline(ss, dni, ';'); //El carácter ; se lee y se elimina de ss
//
//                //Leemos el pass
//                getline(ss, pass, ';'); //El caráter ; se lee y se elimina de ss
//
//                //Leemos el nombre
//                getline(ss, nombre, ';'); //El caráter ; se lee y se elimina de ss
//
//                //Leemos la dirección
//                getline(ss, direccion, ';'); //El caráter ; se lee y se elimina de ss
//
//                //Leemos la latitud y longitud
//                getline(ss, latitud, ';'); //El caráter ; se lee y se elimina de ss
//                getline(ss, longitud, ';'); //El caráter ; se lee y se elimina de ss
//
//                dlat = stod(latitud);
//                dlon = stod(longitud);
//
//                //con todos los atributos leídos, se crea el cliente
//                Cliente client(dni, pass, nombre, direccion, dlat, dlon);
//                client.setAcceso(this);
//
//                arbolCliente.insert(std::pair<string, Cliente>(dni, client));
//            }
//        }
//
//        cout << "Total de clientes en el fichero: " << total << endl;
//        fe.close(); //Cerramos el flujo de entrada
//    } else {
//        cerr << "No se puede abrir el fichero" << endl;
//    }
//}

void EcoCityMoto::cargaClientes(string fileNameClientes) {
    ifstream fe; //Flujo de entrada
    string linea; //Cada línea tiene un clienete
    int total = 0; //Contador de líneas o clientes
    double latMax, latMin, lonMax, lonMin;
    //Variables auxiliares para almacenar los valores leídos
    string dni, nombre, pass, direccion, latitud, longitud;
    double dlat, dlon;
    int itama, iid;
    string id, latfin, lonfin, latinicio, loninicio, dia, hora, mes, anio, min, minutos, tama;
    double dlatfin, dlonfin, dlatinicio, dloninicio;
    unsigned udia, uhora, umes, uanio, umin, uminutos;



    //Asociamos el flujo al fichero 
    fe.open(fileNameClientes);

    if (fe.good()) {
        int primera = 0;
        //Mientras no se haya llegado al final del fichero
        while (!fe.eof()) {
            getline(fe, linea); //Toma una línea del fichero
            stringstream ss; //Stream que trabaja sobre buffer interno         

            if (linea != "") {
                ++total;
            }

            if (total > 1) {
                //Inicializamos el contenido de ss
                ss << linea;

                //Leemos el NIF
                getline(ss, dni, ';'); //El carácter ; se lee y se elimina de ss

                //Leemos el pass
                getline(ss, pass, ';'); //El caráter ; se lee y se elimina de ss

                //Leemos el nombre
                getline(ss, nombre, ';'); //El caráter ; se lee y se elimina de ss

                //Leemos la dirección
                getline(ss, direccion, ';'); //El caráter ; se lee y se elimina de ss

                //Leemos la latitud y longitud
                getline(ss, latitud, ';'); //El caráter ; se lee y se elimina de ss
                getline(ss, longitud, ';'); //El caráter ; se lee y se elimina de ss

                dlat = stod(latitud);
                dlon = stod(longitud);

                getline(ss, tama, ';'); //El caráter ; se lee y se elimina de ss
                itama = stoi(tama);

                //                if (primera == 0) {
                //                    latMax = dlat;
                //                    latMin = dlat;
                //                    lonMax = dlon;
                //                    lonMin = dlon;
                //
                //                    primera++;
                //                } else {
                //                    if (dlat > latMax)
                //                        latMax = dlat;
                //                    else if (dlat < latMin)
                //                        latMin = dlat;
                //
                //                    if (dlon > lonMax)
                //                        lonMax = dlon;
                //                    else if (dlon < lonMin)
                //                        lonMin = dlon;
                //                }






                //                //con todos los atributos leídos, se crea el cliente
                Cliente client(dni, pass, nombre, direccion, dlat, dlon);
                client.setAcceso(this);

                for (int i = 0; i < itama; i++) {
                    getline(ss, id, ';');
                    id = stoi(id);

                    getline(ss, latinicio, ';');
                    getline(ss, loninicio, ';');
                    dlatinicio = stod(latinicio);
                    dloninicio = stod(loninicio);
                    UTM inicio(dlatinicio, dloninicio);


                    getline(ss, latfin, ';');
                    getline(ss, lonfin, ';');
                    dlatfin = stod(latfin);
                    dlonfin = stod(lonfin);
                    UTM fin(dlatfin, dlonfin);

                    getline(ss, dia, ';');
                    getline(ss, mes, ';');
                    getline(ss, anio, ';');
                    getline(ss, hora, ';');
                    getline(ss, min, ';');
                    getline(ss, minutos, ';');

                    udia = stoi(dia);
                    umes = stoi(mes);
                    uanio = stoi(anio);
                    uhora = stoi(hora);
                    umin = stoi(min);
                    uminutos = stoi(minutos);
                    //Itinerario(int id, UTM inicio, UTM fin, Fecha fecha, int minutos);
                    Fecha fe(udia, umes, uanio, uhora, umin);
                    Itinerario ite(iid, inicio, fin, fe, uminutos);
                    client.insertarItinerario(ite);
                }

                arbolCliente.insert(std::pair<string, Cliente>(dni, client));
            }


        }

        //        UTM max (latMax,lonMax);
        //        UTM min (latMin,lonMin);
        //        map<string,Cliente>::iterator it;
        //        srand(time(nullptr));
        //        
        //        for(it=arbolCliente.begin();it!=arbolCliente.end();it++){
        //            idUltimo++;
        //            int num=rand()%4;
        //            int ider=1;
        //            arbolCliente[(*it).first].creaitinerarios(num,ider,min,max);
        //                    
        //        }

        cout << "Total de clientes en el fichero: " << total << endl;
        fe.close(); //Cerramos el flujo de entrada
    } else {
        cerr << "No se puede abrir el fichero" << endl;
    }
}

void EcoCityMoto::cargaMotos(string fileNameMotos) {
    ifstream fe; //Flujo de entrada
    string linea; //Cada línea tiene un clienete
    int total = 0; //Contador de líneas o clientes

    //Variables auxiliares para almacenar los valores leídos
    string id, latitud, longitud;
    double dlat, dlon;
    string est;
    int estado;

    //Asociamos el flujo al fichero 
    fe.open(fileNameMotos);

    if (fe.good()) {
        int primera = 0;
        //Mientras no se haya llegado al final del fichero
        while (!fe.eof()) {
            getline(fe, linea); //Toma una línea del fichero
            stringstream ss; //Stream que trabaja sobre buffer interno         

            if (linea != "") {
                ++total;
            }

            if (total > 1) {
                //Inicializamos el contenido de ss
                ss << linea;

                //Leemos el NIF
                getline(ss, id, ';'); //El carácter ; se lee y se elimina de ss

                //Leemos el pass
                getline(ss, est, ';'); //El caráter ; se lee y se elimina de ss

                //Leemos la latitud y longitud
                getline(ss, latitud, ';'); //El caráter ; se lee y se elimina de ss
                getline(ss, longitud, ';'); //El caráter ; se lee y se elimina de ss

                estado = stod(est);
                dlat = stod(latitud);
                dlon = stod(longitud);

                UTM pos(dlat, dlon);

                Estado esta;
                if (estado == 0)
                    esta = bloqueada;
                else if (estado == 1)
                    esta = activa;
                else if (estado == 2)
                    esta = sinbateria;
                else
                    esta = rota;
                //con todos los atributos leídos, se crea el cliente
                Moto mot(id, pos, esta);

                vectorMotos.push_back(mot);
            }
        }

        cout << "Total de motos en el fichero: " << total << endl;
        fe.close(); //Cerramos el flujo de entrada
    } else {
        cerr << "No se puede abrir el fichero" << endl;
    }
}

vector<Moto*> EcoCityMoto::localizaMotosSinBateria() {
    vector<Moto*> motossinbateria;

    for (int i = 0; i < vectorMotos.size(); i++) {
        if (vectorMotos[i].GetEstatus() == sinbateria) {
            motossinbateria.push_back(&vectorMotos[i]);
        }
    }


    return motossinbateria;
}

void EcoCityMoto::nuevoCliente(Cliente cli) {
    cli.setAcceso(this);
    arbolCliente.insert(std::pair<string, Cliente>(cli.getDni(), cli));
}

void EcoCityMoto::eliminarCliente(string id) {
    map<string, Cliente>::iterator it;
    it = arbolCliente.find(id);
    arbolCliente.erase(it);
}

void EcoCityMoto::cargarclientes(string nombreArchivo) {
    std::ifstream fe;
    string linea;
    Cliente aux;
    fe.open(nombreArchivo);
    if (fe.good()) {
        while (!fe.eof()) {
            getline(fe, linea);
            if (linea != "") {
                aux.fromCSV(linea);
                arbolCliente[aux.getDni()] = aux;
            }
        }
        fe.close();
    } else {
        std::cerr << "No se pudo abrir el archivo" << std::endl;
    }
}

void EcoCityMoto::GuardarClientes(string nombreArchivo) {
    //Crea un fichero de salida
    ofstream fs(nombreArchivo, std::ofstream::out);
    //Enviamos una cadena al fichero de salida :
    map<string, Cliente>::iterator ite;
    for (ite = arbolCliente.begin(); ite != arbolCliente.end(); ite++) {
        fs << arbolCliente[(*ite).first].getDni() << ";";
        fs << arbolCliente[(*ite).first].getPass() << ";";
        fs << arbolCliente[(*ite).first].getNombre() << ";";
        fs << arbolCliente[(*ite).first].getDireccion() << ";";
        fs << arbolCliente[(*ite).first].getlatitud() << ";";
        fs << arbolCliente[(*ite).first].getlongitud() << ";";

        list<Itinerario> aux = arbolCliente[(*ite).first].getRutas();

        fs << aux.size() << ";";

        list<Itinerario>::iterator it = aux.begin();

        for (int i = 0; i < aux.size(); i++) {
            fs << (*it).getId() << ";";
            fs << (*it).getInicio().latitud << ";";
            fs << (*it).getInicio().longitud << ";";
            fs << (*it).getFin().latitud << ";";
            fs << (*it).getFin().latitud << ";";
            fs << (*it).getFecha().verDia() << ";";
            fs << (*it).getFecha().verMes() << ";";
            fs << (*it).getFecha().verAnio() << ";";
            fs << (*it).getFecha().verHora() << ";";
            fs << (*it).getFecha().verMin() << ";";
            fs << (*it).getMinutos() << ";";

            it++;
        }

        fs << endl;

    }
    fs.close();
}








