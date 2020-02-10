/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   VDinamico.h
  * Author: Poo
  *
  * Created on 24 de septiembre de 2018, 18:43
  */

#ifndef VDINAMICO_H
#define VDINAMICO_H
#include <string>
#include <climits>
#include <cmath>
#include <stdexcept>
#include <algorithm>

using namespace std;

template<class T>
class VDinamico {
public:
	VDinamico();
	VDinamico(const VDinamico& orig);
	virtual ~VDinamico();
	VDinamico& operator=(const VDinamico<T>& right);
	VDinamico(unsigned tam);
	VDinamico(const VDinamico& orig, unsigned inicio, unsigned num);
	T& operator[](unsigned int pos);
	void insertar(const T& dato, unsigned int pos = UINT_MAX);
	unsigned int tam();
	T eliminar(unsigned int pos = UINT_MAX);
	void aumentar();
	void disminuye();
	void ordenar();
	bool compare(Cliente& a, Cliente& b);
	int busquedaBin(string& dato);
private:
	int taml, tamf;
	T* v;
};

template<class T>
VDinamico<T>::VDinamico() { //Constructor por defecto
	tamf = 1;
	taml = 0;
	v = new T[tamf];
}

template<class T>
VDinamico<T>::VDinamico(const VDinamico& orig) {    //Constructor copia de VDinamico
	taml = orig.taml;
	v = new T[orig.tamf];
	for (int i = 0; i < orig.taml; i++) {

		v[i] = orig.v[i];
	}
}

template<class T>
VDinamico<T>::~VDinamico() {    //Destructor de VDinamico
	delete[] v;

}

template<class T>
VDinamico<T>::VDinamico(unsigned tam) { //Constructor que dado un tamaño se inicia el tamaño fisico a la potencia de 2 inmediantamente superior a taml
	float a;
	a = ceil(log2(tam));
	tamf = pow(2, a);
	taml = tam;
	v = new T[this->tamf];
}

template <class T>
VDinamico<T>::VDinamico(const VDinamico& orig, unsigned inicio, unsigned num) {     //Operador de copia parcial de VDinamico
	if (inicio > orig.taml || inicio + num > orig.taml) throw std::out_of_range("Posición invalida");
	for (int i = inicio; i < num; i++) {
		v[i] = orig.v[i];
	}
}

template<class T>
VDinamico<T>& VDinamico<T>::operator=(const VDinamico<T>& right) {  //Operador de asignación de VDinamico
	if (this != &right) {
		taml = right.taml;
		delete[] v;
		v = new T[taml];
		for (int i = 0; i < taml; i++) {
			v[i] = right.v[i];

		}

	}
	return *this;
}

template <class T>
T& VDinamico<T>::operator[](unsigned int pos) {             //Operador [] para lectura/escritura
	if (pos > taml) throw std::out_of_range("Posición inválida");
	return v[pos];
}
template <class T>
bool VDinamico<T>::compare(Cliente& a, Cliente& b) {

	return a<b ;
}

template<class T>
void VDinamico<T>::insertar(const T& dato, unsigned int pos) { //Metodo de inserción para VDinamico

	aumentar();

	//if (pos < 0 || pos >taml) {
	//	throw string("La posicion es erronea");
	//}
	if (pos == UINT_MAX) {
		v[taml++] = dato;
	}
	else {
		for (int i = taml - 1; i >= pos; i--) {
			v[i + 1] = v[i];
		}
		v[pos] = dato;
		taml++;
	}
}

template<class T>
T VDinamico<T>::eliminar(unsigned int pos) {    //Método de borrado para VDinamico
	T vuelve = v[pos];

	if (pos < 0 || pos > taml) {
		throw std::out_of_range("La posicion es erronea");
	}

	if (pos == UINT_MAX) {
		taml--;
	}
	else {
		for (int i = pos; i < taml - 1; i++) {
			v[i] = v[i + 1];
		}

		taml--;
	}
	disminuye();
	return vuelve;
}

template<class T>
unsigned int VDinamico<T>::tam() {  //Metodo para obtener el tamaño lógico del vector
	return taml;
}


template<class T>
void VDinamico<T>::aumentar() { //Método para aumentar el tamaño del VDinamico
	if (taml == tamf) {

		T* aux;
		aux = new T[tamf = tamf * 2];
		for (int i = 0; i < taml; i++) {
			aux[i] = v[i];
		}
		delete[] v;
		v = aux;
	}
}

template<class T>
void VDinamico<T>::disminuye() {    //Método para disminuir el tam del VDinamico
	if (taml * 3 < tamf) {
		tamf = tamf / 2;
		T* aux = new T[tamf];
		for (int i = 0; i < taml; i++) {
			aux[i] = v[i];
		}
		delete[] v;
		v = aux;
	}
}

template<class T>
void VDinamico<T>::ordenar() {    //Método para ordenar el  VDinamico
	std::sort(v, v+taml);
}
template<class T>
int  VDinamico<T>::busquedaBin(string& dato) {
	int inf = 0;
	int sup = taml - 1;
	int curIn;
	while (inf <= sup) {
		curIn = (inf + sup) / 2;
		if (v[curIn].GetNombre().find(dato) != std::string::npos)
			return curIn;
		else if (v[curIn].GetNombre() < dato) inf = curIn + 1;
		else sup = curIn - 1;
	}

return -1;
}
#endif /* VDINAMICO_H */

