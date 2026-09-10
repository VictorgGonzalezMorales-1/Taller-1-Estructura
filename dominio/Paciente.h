
#pragma once // Hace que la cabecera se incluya solo una vez en la compilación
#include <string> // Para poder usar strings
using namespace std; // Para no tener que agregar std::

class Paciente {

private:

    // Atributos
    string id;
    string nombre;
    string edad;
    string servicio;

public:

    // Constructor
    Paciente(string id, string nombre, string edad, string servicio);

    // Getters
    string getId();
    string getNombre();
    string getEdad();
    string getServicio();

    // Destructor
    ~Paciente();
};
