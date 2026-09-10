
#include "Paciente.h"

// Constructor
Paciente:: Paciente(string id, string nombre, string edad, string servicio){
    this->id = id;
    this->nombre = nombre;
    this->edad = edad;
    this->servicio = servicio;
}

//Getters
string Paciente:: getId(){return this->id;}
string Paciente:: getNombre(){return this->nombre;}
string Paciente:: getEdad(){return this->edad;}
string Paciente:: getServicio(){return this->servicio;}

//Destructor
Paciente:: ~Paciente(){};
