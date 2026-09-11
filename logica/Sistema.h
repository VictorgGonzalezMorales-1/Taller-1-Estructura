
#pragma once
#include "../dominio/Paciente.h"
#include "../estructuras/List.h"
#include <string>

class Sistema {

public:

    //Metodo para crear a los pacientes
    virtual Paciente* makePaciente(std::string line) = 0;
    virtual List<std:: string>* split(std::string line, char separador) = 0;

    //Destructor Virtual
    virtual ~Sistema() = default;

};