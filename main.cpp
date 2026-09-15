
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

//Metodo para leer el archivo y procesar a los Pacientes **
bool read() {

    ifstream archivo("../Pacientes.txt"); //Cargar Archivo

    //Revisar que esté
    if (!archivo.is_open()) {
        cout << "No se pude abrir el archivo" << endl;
        return false;
    }

    string line; //String para guardar el contenido
    List<string>* ids = new List<string>();

    //Bucle para leer la línea
    while (getline(archivo,line)) {
        List<string>* datos = S->split(line, ';');

        if (datos->getSize() == 4) {

            string sector = datos->get(3);

            if (S->existS(sector) == true) {

                string idActual = datos->get(0);
            bool duplicado = false;

            int large = ids->getSize();
            for (int a = 0; a < large; a++) {
                if (ids->get(a) == idActual) {
                    duplicado = true;
                    break;
                }
            }

            if (duplicado == false) {
                ids->insertLast(idActual);
                S->makePaciente(line);
            }

            }

        }

        delete datos;

    }

    archivo.close(); //Cerrar el Archivo
    delete ids;

    return true;

}

//Metodo para generar la atencion a pacientes
void opcion1() {
    p("=== PACIENTES EN ESPERA ===\n");
    p(S->entregarCola());

    p("Indique la cantidad de pacientes a atender:");
    string respuesta;
    int cant = 0;
    cin >> respuesta;

    try{
        cant = stoi(respuesta);
        if (cant <= 0) {
            p("Entrada inválida: Ingrese un número mayor a 0");
        }else if (cant > S->sizeCola()){
            p("Solo hay " + to_string(S->sizeCola()) + " en la cola");
        }else {
            p(S->atencion(cant));
        }

    }catch (...) {
        p("Entrada inválida: Ingrese un número");
    }
}

//Metodo para generar la entrega de los departamentos **
void opcion2() {
    p(S->entregarDepartamentos());

    string respuesta;
    int departamento = 0;
    p("Seleccionar opción: ");

    cin >> respuesta;

    try {

        departamento = stoi(respuesta);

        if (departamento <= 0) {
            p("Entrada inválida: Ingrese un número mayor a 0");
        }
        else if (departamento > 8) {
            p("Entrada inválida: Ingrese un número entre 1 y 8");
        }
        else {
            p(S->informacionSector(departamento));
        }

    }catch (...) {
        p("Entrada inválida: Ingrese un número válido ");
    }
}

//Metodo para generar la entrega del historial desde el más nuevo al más antiguo
void opcion3() {
    p(S->informacionHistorial());
}

//El menú del hospital
void menu() {

    string opcion = "";

    while (opcion != "4") {

        p("=== HOSPITAL MARMAJA ===\n");
        p("1. Atender pacientes");
        p("2. Ver departamento");
        p("3. Revisar historial de atencion");
        p("4. Salir");

        cout << "Seleccionar opcion:";
        cin >> opcion;

        if (opcion == "1") {
            opcion1();
        }
        else if (opcion == "2") {
            opcion2();
        }
        else if (opcion == "3") {
            opcion3();
        }
        else if (opcion == "4") {
            p("Hasta luego :D.");
        }
        else {
            p("Opcion invalida, ingrese otra");
        }

    }

}

int main() {

    if (read() == true) {
        menu();
    }

    return 0;
}