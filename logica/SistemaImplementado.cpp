
#include "SistemaImplementado.h"
#include "../estructuras/List.h"
#include <string>

//Constructor
SistemaImplementado:: SistemaImplementado() {}

//Metodo para crear Pacientes
Paciente* SistemaImplementado:: makePaciente(string line) {
    List<string>* list = split(line, ';');

    Paciente* paciente = new Paciente(list->get(0), list->get(1), list->get(2), list->get(3));
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



