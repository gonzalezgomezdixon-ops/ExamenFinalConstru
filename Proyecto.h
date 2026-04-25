#pragma once
#include <string>
#include <iostream>
using namespace std;
//Clase del Proyecto de construccion
class Proyecto {
	//Atributos
private:
    int codigo;
    string nombre;
    string fechaInicio;
    string fechaFin;
    //Constructor y metodos
public:
    Proyecto() : codigo(0), nombre(""), fechaInicio(""), fechaFin("") {}
    Proyecto(int codigo, string nombre, string fechaInicio, string fechaFin);
    //Getters
    int getCodigo() { return codigo; }
    string getNombre() { return nombre; }
    //Muestra la informacion del proyecto
    void mostrarInformacion();
};
