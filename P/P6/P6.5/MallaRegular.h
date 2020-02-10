/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MallaRegular.h
 * Author: jgr97
 *
 * Created on 4 de diciembre de 2019, 10:08
 */

#ifndef MALLAREGULAR_H
#define MALLAREGULAR_H

#include <list>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cmath>

using namespace std;

template <class T>
class MallaRegular {
    private:
        float minX, maxX, minY, maxY;
        float numDiviX, numDiviY;
        float tamaCasillaX, tamaCasillaY;
        int numelementos=0;
        int max_elemento_casilla=0;
        
        
        class Casilla {
            public:
                list<T> listaDatos;
                Casilla (): listaDatos(){};
                
                
                void insertarCasilla(T dato){
                    listaDatos.push_back(dato);
                }
                
                
                T* buscarCasilla(T& dato){                    
                    typename list<T>::iterator it = find(listaDatos.begin(), listaDatos.end(), dato);
                    
                    return it;
                }
                
                
                void borrarCasilla (T& dato){
                    typename list<T>::iterator it = find(listaDatos.begin(), listaDatos.end(), dato);
                    listaDatos.erase(it);
                }
                
                float numElementos(){
                    return listaDatos.size();
                }

                virtual ~Casilla() {

                }

                
            
        };
        
        vector< vector<Casilla>> matrizCasillas;
        
        
        Casilla* obtenerCasilla(float x, float y){
            int i = (x -minX)/tamaCasillaX;
            int j = (y - minY)/tamaCasillaY;
            
            return &matrizCasillas[i][j];
        }
        
        
    public:
        
        MallaRegular() {
        }

        MallaRegular(float aXMin, float aYMin, float aXMax, float aYMax, int nDivX, int nDivY): maxX(aXMax), maxY(aYMax), minY(aYMin), minX(aXMin), 
        numDiviX(nDivX), numDiviY(nDivY), matrizCasillas(nDivX, vector<Casilla >(nDivY)){
            tamaCasillaX= (maxX - minX)/ numDiviX;
            tamaCasillaY= (maxY - minY)/ numDiviY;
            
        }
        
        MallaRegular(const MallaRegular& orig): matrizCasillas(orig.matrizCasillas), maxX(orig.maxX), maxY(orig.maxY), minX(orig.minX), minY(orig.minY)
        , numDiviX(orig.numDiviX), numDiviY(orig.numDiviY), tamaCasillaX(orig.tamaCasillaX), tamaCasillaY(orig.tamaCasillaY){}
        
        float GetMaxX() const {
            return maxX;
        }

        float GetMaxY() const {
            return maxY;
        }

        float GetMinX() const {
            return minX;
        }

        float GetMinY() const {
            return minY;
        }

        float GetNumDiviX() const {
            return numDiviX;
        }

        float GetNumDiviY() const {
            return numDiviY;
        }

        float GetTamaCasillaX() const {
            return tamaCasillaX;
        }

        float GetTamaCasillaY() const {
            return tamaCasillaY;
        }

        void insertar(float x, float y, T& dato){
            Casilla* c;
            
            c=obtenerCasilla(x,y);
            c->insertarCasilla(dato);
            numelementos++;
            if(c->listaDatos.size()>max_elemento_casilla)
                max_elemento_casilla=c->listaDatos.size();
        }
        
        T* buscar(float x, float y, T& dato){
            Casilla *c;
            c=obtenerCasilla(x,y);
            return c->buscarCasilla(dato);
        }
        
        void borrar(float x, float y, T& dato){
            Casilla *c;
            c=obtenerCasilla(x,y);
            c->borrarCasilla(dato);
            numelementos--;
        }
        
        T* buscarCercano(float x, float y){
            T* masCercano=nullptr;
            float distancia=0;
            float distancia_menor=10000000;
            Casilla *c;
           
            float inicio_x=x-tamaCasillaX;
            float final_x=x+tamaCasillaX;
            
            float inicio_y=y-tamaCasillaY;
            float final_y=y+tamaCasillaY;
            
            for(float i=inicio_x;i<=final_x;i=i+tamaCasillaX){
                for(float j=inicio_y;j<=final_y; j=j+tamaCasillaY){

                    c=obtenerCasilla(i,j);
                    typename list<T>::iterator it;

                    for(it=c->listaDatos.begin();it!=c->listaDatos.end();it++){
                        float _x=(*it).getX();
                        float _y=(*it).getY();
                        distancia=(x-_x)+(y-_y);

                        if(distancia<distancia_menor){
                            distancia_menor=distancia;
                            masCercano=&(*it);
                        }

                    }

                }
            }
            
            
            return masCercano;
            
        }
        
        bool fueraAmbito(float x, float y){
            bool fa=true;
            
            Casilla *c;
            int numelemetos=0;
            
            for(float i=x-tamaCasillaX;i<=x+tamaCasillaX;i=i+tamaCasillaX){
                for(float j=y-tamaCasillaY;j<=y+tamaCasillaY; j=j+tamaCasillaY){
                    
                    c=obtenerCasilla(i,j);
                    numelemetos=numelemetos+c->numElementos();
                
                }
            }
            
            if(numelemetos>0)
                fa=false;
            
            
            return fa;
        }
        
        unsigned maxElementosPorCelda(){
            return max_elemento_casilla;
        }
        
        unsigned mediaElementosPorCelda(){
            float numdiv=numDiviX*numDiviY;
            float num=numelementos;
            
            float media=num/numdiv;
            
            return media;
        }
        
        virtual ~MallaRegular(){
        };
        

};

#endif /* MALLAREGULAR_H */

