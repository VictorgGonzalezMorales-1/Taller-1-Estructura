
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

//Metodo para revisar que el sector exista
bool SistemaImplementado:: existS(std:: string sector) {

    string* first = this->sectores;
    string* last = this->sectores + 8;

    for (string* puntero = first; puntero < last; puntero++) {

        if (*puntero == sector) {
            return true;
        }

    }

    return false;

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

//Metodo para entregar la cantidad de pacientes en la cola
int SistemaImplementado:: sizeCola() {
    return this->colaPacientes->size();
}

//Metodo para direccionar a cada paciente a su sector correspondiente
void SistemaImplementado:: toSector(Paciente* p) {
    int index = 0;

    string* first = this->sectores;
    string* last = this->sectores + 8;

    for (string* puntero = first; puntero < last; puntero++) {
        if (*puntero == p->getServicio()) {
            this->hospital->get(index)->insertLast(p);
            break;
        }
        index++;
    }
}

//Metodo para entregar un string con los pacientes de la lista de espera en orden
std:: string SistemaImplementado:: entregarCola() {

    string t = "";

    int nPacientes = this->colaPacientes->size();

    for (int a = 1; a < nPacientes + 1 ; a++) {
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

    string* first = this->sectores;
    string* last = this->sectores + 8;

    for (string* puntero = first; puntero < last; puntero++) {
        t += to_string(count)  + ". " + *puntero + "\n";
        count++;
    }

    return t;

}

//Metodo para entregar los paciente dentro de un sector
std:: string SistemaImplementado:: informacionSector(int pos) {
    int index = pos - 1;
    string* sector = this->sectores;

    List<Paciente*>* c = this->hospital->get(index);
    string t = "Pacientes en el departamento de " + *(sector + index) + ": " + to_string(c->getSize()) + "\n";

    Paciente* cP;

    for (int a = 0; a < c->getSize(); a++) {
        cP = c->get(a);
        t += cP->getNombre() + "(" + cP->getEdad() + ")\n";
    }

    return t;
}

//Metodo para entregar a todos los pacientes del historial
string SistemaImplementado:: informacionHistorial() {
    Stack<Paciente*>* original = this->pilaPacientes;
    Stack<Paciente*>* copia = new Stack<Paciente*>();
    string t = "=== HISTORIAL DE ÚLTIMAS ATENCIONES DEL HOSPITAL ===\n";

    while (original->isEmpty() != true) {
        Paciente* p = original->top();
        copia->push(p);
        t += "Nombre: " + p->getNombre() + " | Edad: " + p->getEdad() + " | Departamento: " + p->getServicio() + "\n";
        original->pop();
    }

    while (copia->isEmpty() != true) {
        original->push(copia->top());
        copia->pop();
    }

    delete copia;

    return t;
}

//Destructor
SistemaImplementado:: ~SistemaImplementado() {

    //Eliminar los pacientes que estén en la cola y la cola al final
    while (colaPacientes->isEmpty() != true) {
        delete colaPacientes->front();
        colaPacientes->pop();
    }
    delete this->colaPacientes;

    //Eliminar los pacientes que estén en la pila y la pila al final
    while (pilaPacientes->isEmpty() != true) {
        delete this->pilaPacientes->top();
        this->pilaPacientes->pop();
    }
    delete this->pilaPacientes;

    for (int a = 0; a < this->hospital->getSize(); a++) {
        List<Paciente*>* sectorDelete = hospital->get(a);
        delete sectorDelete;
    }
    delete hospital;

}


