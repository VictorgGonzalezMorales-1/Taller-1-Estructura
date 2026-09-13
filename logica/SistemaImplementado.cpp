
#include "SistemaImplementado.h"
using namespace std;

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
string  SistemaImplementado:: atencion(int cant) {

    string t = "=== ATENDIENDO PACIENTES ===\n";

    for (int a = 0; a < cant; a++) {

        if (this->colaPacientes->isEmpty()) {
            break;
        }

        Paciente* p = this->colaPacientes->front();
        this->colaPacientes->pop();
        toSector(p);

        t+= "ID: " + p->getId() + "\n";
        t+= "Nombre: " + p->getNombre()+ "\n";
        t+= "Servicio: " + p->getServicio() + "\n\n";
        t+= "Paciente enviado a " + p->getServicio() +"\n\n";

        this->pilaPacientes->push(p);

    }
    return t;
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

//Metodo para entregar un string con los pacientes de la lista de espera en orden
std:: string SistemaImplementado:: entregarCola() {

    string t = "";

    for (int a = 1; a < this->colaPacientes->size() + 1 ; a++) {
        Paciente* p = this->colaPacientes->front();
        t += to_string(a) + ". " + p->getId() + " - " + p->getNombre() + "\n" ;
        this->colaPacientes->pop();
        this->colaPacientes->push(p);
    }

    return t;
}

//Metodo para entregar todos los departamentos en orden
string SistemaImplementado:: entregarDepartamentos() {

    string t = "=== DEPARTAMENTOS/SERVICIOS ===\n";
    int count = 1;

    for (string s: sectores) {
        t += to_string(count)  + ". " + s + "\n";
        count++;
    }

    return t;

}

//Metodo para entregar los paciente dentro de un sector
std:: string SistemaImplementado:: informacionSector(int pos) {
    int index = pos - 1;

    List<Paciente*>* c = this->hospital->get(index);
    string t = "Pacientes en el departamento de " + sectores[index] + ": " + to_string(c->getSize()) + "\n";

    Paciente* cP;

    for (int a = 0; a < c->getSize(); a++) {
        cP = c->get(a);
        t += cP->getNombre() + "(" + cP->getEdad() + ")\n";
    }

    return t;
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


