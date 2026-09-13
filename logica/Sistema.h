
#pragma once
#include "../dominio/Paciente.h"
#include "../estructuras/List.h"
#include <string>

class Sistema {

public:

    //Metodo para crear a los pacientes
    virtual Paciente* makePaciente(std::string line) = 0;
    virtual List<std:: string>* split(std::string line, char separador) = 0;
    virtual void makeHospital() = 0;
    virtual std:: string atencion(int cant) = 0;
    virtual void toSector(Paciente* p) = 0;
    virtual std:: string entregarCola() = 0;
    virtual std:: string entregarDepartamentos() = 0;
    virtual std:: string informacionSector(int pos) = 0;
    virtual std:: string informacionHistorial() = 0;

    //Destructor Virtual
    virtual ~Sistema() = default;

};