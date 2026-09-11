
/*
 * Taller 1 Estructura de Datos
 * Integrante: Victor Manuel Gonzalez Morales
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Metodo para leer el archivo
void read() {

    ifstream archivo("../Pacientes.txt"); //Cargar Archivo

    //Revisar que esté
    if (!archivo.is_open()) {
        cout << "No se pude abrir el archivo" << endl;
        return;
    }

    string line; //String para guardar el contenido

    //Bucle para leer la línea e imprimirla
    while (getline(archivo,line)) {
        cout << line << endl;
    }

    archivo.close(); //Cerrar el Archivo

}


int main() {
    read();
    return 0;
}