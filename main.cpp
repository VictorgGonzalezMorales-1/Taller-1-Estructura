
/*
 * Taller 1 Estructura de Datos
 * Integrante: Victor Manuel Gonzalez Morales
 */

#include <iostream>
#include <fstream>
#include <string>

#include "logica/Sistema.h"
#include "logica/SistemaImplementado.h"
#include "estructuras/List.h"

using namespace std;

Sistema* S = new SistemaImplementado();

//Metodo para imprimir rapido
void p(string t) {
    cout << t << endl;
}

//Metodo para leer el archivo y procesar a los Pacientes
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
    int cant = 0;
    cin >> cant;

    p(S->atencion(cant));
}

//Metodo para generar la entrega de los departamentos
void opcion2() {
    p(S->entregarDepartamentos());

    int departamento = 0;
    p("Seleccionar opción: ");
    cin >> departamento;

    p(S->informacionSector(departamento));
}

//Metodo para generar la entrega del historial desde el más nuevo al más antiguo
void opcion3() {
    p(S->informacionHistorial());
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
                opcion2();
                break;

            case 3:
                opcion3();
                break;

            case 4:
                p("Hasta luego :D.");
                break;

            default:
                p("Opcion invalida, ingrese otra");
                break;

        }

    }

}

int main() {

    if (read() == true) {
        menu();
    }

    return 0;
}