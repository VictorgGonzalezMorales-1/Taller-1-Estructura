
#include "SistemaImplementado.h"

//Constructor
SistemaImplementado:: SistemaImplementado() {
    this->colaPacientes = new Queue<Paciente*>();
    this->pilaPacientes = new Stack<Paciente*>();
    this->hospital = new List<List<Paciente*>*>();

    makeHospital();
}

//Metodo para crear Pacientes
Paciente* SistemaImplementado:: makePaciente(string line) {
    List<string>* list = split(line, ';');

    Paciente* paciente = new Paciente(list->get(0), list->get(1), list->get(2), list->get(3));
    colaPacientes->push(paciente);
    delete list;

    return paciente;
}

//Literalmente un split maomeno
List<std:: string>*  SistemaImplementado:: split(std:: string line, char separador) {

    string text;
    List<string>* list = new List<string>;

    for (char c: line) {
        if (c == separador) {
            list->insertLast(text);
            text = "";
        }else {
            text += c;
        }
    }

    if (text != "") {
        list->insertLast(text);
    }

    return list;

}

//Metodo que genera el hospital con sus sectores en orden dentro de una lista
void SistemaImplementado:: makeHospital() {
    int count = 0;

    while (count < 8) {
        List<Paciente*>* sector = new List<Paciente*>();
        this->hospital->insertLast(sector);
        count++;
    }

}

//Metodo para generar la atencion de pacientes
void SistemaImplementado:: atencion(int cant) {

    for (int a = 0; a < cant; a++) {

        if (this->colaPacientes->isEmpty()) {
            break;
        }

        Paciente* p = this->colaPacientes->front();
        this->colaPacientes->pop();
        toSector(p);
        this->pilaPacientes->push(p);

    }

}

//Metodo para direccionar a cada paciente a su sector correspondiente
void SistemaImplementado:: toSector(Paciente* p) {
    int index = 0;

    for (std:: string s : this->sectores) {
        if (s == p->getServicio()) {
            this->hospital->get(index)->insertLast(p);
        }
        index++;
    }
}

//Destructor
SistemaImplementado:: ~SistemaImplementado() {
    delete this->colaPacientes;
    delete this->pilaPacientes;

    for (int a = 0; a < this->hospital->getSize(); a++) {
        List<Paciente*>* sector = hospital->get(a);
        delete sector;
    }

    delete hospital;

}


