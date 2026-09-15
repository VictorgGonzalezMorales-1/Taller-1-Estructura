
#pragma once
#include "../logica/Sistema.h"
#include "../estructuras/List.h"
#include "../estructuras/Queue.h"
#include "../estructuras/Stack.h"
#include "../dominio/Paciente.h"
#include <string>

class SistemaImplementado: public Sistema {

private:
    Queue<Paciente*>* colaPacientes;
    Stack<Paciente*>* pilaPacientes;
    List<List<Paciente*>*>* hospital;
    string sectores[8] = {
        "Urgencias",
        "Medicina General",
        "Cardiologia",
        "Neurologia",
        "Traumatologia",
        "Cirugia",
        "Pediatria",
        "Hospitalizacion"
    };

public:

    SistemaImplementado(); //Constructor

    //Metodos
    Paciente* makePaciente(std:: string line) override;
    List<std:: string>* split(std:: string line, char separador) override;
    bool existS(std:: string sector) override;
    void makeHospital() override;
    std:: string atencion(int cant) override;
    int sizeCola() override;
    void toSector(Paciente* p) override;
    std:: string entregarCola() override;
    string entregarDepartamentos() override;
    std:: string informacionSector(int pos) override;
    std:: string informacionHistorial() override;

    ~SistemaImplementado() override; //Sistema Implementado

};