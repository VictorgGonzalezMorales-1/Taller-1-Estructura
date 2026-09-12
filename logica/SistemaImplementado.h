
#pragma once
#include "../logica/Sistema.h"
#include "../estructuras/List.h"
#include "../estructuras/Queue.h"
#include "../dominio/Paciente.h"
#include <string>

class SistemaImplementado: public Sistema {

private:
    Queue<Paciente*>* colaPacientes;

public:

    SistemaImplementado(); //Constructor

    //Metodos
    Paciente* makePaciente(std:: string line) override;
    List<std:: string>* split(std:: string line, char separador) override;

    ~SistemaImplementado() override; //Sistema Implementado

};