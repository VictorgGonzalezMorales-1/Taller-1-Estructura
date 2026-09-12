
/*
 * Taller 1 Estructura de Datos
 * Integrante: Victor Manuel Gonzalez Morales
 */

#include <iostream>
#include <fstream>
#include <string>

#include "logica/Sistema.h"
#include "logica/SistemaImplementado.h"

using namespace std;

Sistema* S = new SistemaImplementado();

//Metodo para imprimir rapido
void p(string t) {
    cout << t << endl;
}

//Metodo para leer el archivo y procesar a los Pacientes
void read() {

    ifstream archivo("../Pacientes.txt"); //Cargar Archivo

    //Revisar que esté
    if (!archivo.is_open()) {
        cout << "No se pude abrir el archivo" << endl;
        return;
    }

    string line; //String para guardar el contenido

    //Bucle para leer la línea
    while (getline(archivo,line)) {
        S->makePaciente(line);
    }

    archivo.close(); //Cerrar el Archivo

}

// Metodo para generar la atencion a pacientes
void opcion1() {
    p("=== PACIENTES EN ESPERA ===\n");
    p(S->entregarCola());
    p("Indique la cantidad de pacientes a atender:");
    int cant = 0;
    cin >> cant;
    S->atencion(cant);
}

//El menú del hospital
void menu() {

    int opcion = 0;

    while (opcion != 4) {

        p("=== HOSPITAL MARMAJA ===\n");
        p("1. Atender pacientes");
        p("2. Ver departamento");
        p("3. Revisar historial de atencion");
        p("4. Salir");

        cout << "Seleccionar opcion:";
        cin >> opcion;

        switch (opcion) {

            case 1:
                opcion1();
                break;

            case 2:
                p("2");
                break;

            case 3:
                p("3");
                break;

            case 4:
                p("4");
                break;

            default:
                p("Opcion invalida, ingrese otra");
                break;

        }

    }

    p("Hasta luego :D.");

}

int main() {
    read();
    menu();
    return 0;
}