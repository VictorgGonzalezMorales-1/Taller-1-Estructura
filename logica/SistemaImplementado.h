
#pragma once
#include "../logica/Sistema.h"
#include "../estructuras/List.h"
#include <string>

class SistemaImplementado: public Sistema {
public:

    SistemaImplementado(); //Constructor

    //Metodos
    Paciente* makePaciente(std:: string line) override;
    List<std:: string>* split(std:: string line, char separador) override;

    ~SistemaImplementado() override = default; //Sistema Implementado

};