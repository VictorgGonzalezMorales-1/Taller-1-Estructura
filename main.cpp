
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

int main() {
    read();
    return 0;
}