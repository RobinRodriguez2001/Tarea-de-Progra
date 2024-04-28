#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Estudiante {
    int id;
    string nombre;
    string apellido;
    float notas[4];
    float promedio;
    string resultado;
};

void crearEstudiante(Estudiante* estudiantes, int& cantidadEstudiantes) {
    cout << "Ingrese la información del estudiante:" << endl;
    cout << "ID del estudiante: ";
    cin >> estudiantes[cantidadEstudiantes].id;
    cout << "Nombre del estudiante: ";
    cin >> estudiantes[cantidadEstudiantes].nombre;
    cout << "Apellido del estudiante: ";
    cin >> estudiantes[cantidadEstudiantes].apellido;
    cout << "Notas del estudiante (nota1 nota2 nota3 nota4): ";
    for (int i = 0; i < 4; ++i) {
        cin >> estudiantes[cantidadEstudiantes].notas[i];
    }

    float suma = 0;
    for (int i = 0; i < 4; ++i) {
        suma += estudiantes[cantidadEstudiantes].notas[i];
    }
    estudiantes[cantidadEstudiantes].promedio = suma / 4;

    if (estudiantes[cantidadEstudiantes].promedio >= 60) {
        estudiantes[cantidadEstudiantes].resultado = "Aprobado";
    } else {
        estudiantes[cantidadEstudiantes].resultado = "Reprobado";
    }
    cantidadEstudiantes++;
}

void mostrarEstudiantes(const Estudiante* estudiantes, int cantidadEstudiantes) {
    cout << "Lista de estudiantes:" << endl;
    for (int i = 0; i < cantidadEstudiantes; ++i) {
        cout << "ID: " << estudiantes[i].id << ", Nombre: " << estudiantes[i].nombre
             << ", Apellido: " << estudiantes[i].apellido << ", Promedio: " << estudiantes[i].promedio
             << ", Resultado: " << estudiantes[i].resultado << endl;
    }
}

void escribirEnArchivo(const Estudiante* estudiantes, int cantidadEstudiantes) {
    ofstream archivo("notas.dat", ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }
    archivo.write(reinterpret_cast<const char*>(&cantidadEstudiantes), sizeof(int));
    archivo.write(reinterpret_cast<const char*>(estudiantes), cantidadEstudiantes * sizeof(Estudiante));
    archivo.close();
}

void leerDeArchivo(Estudiante* estudiantes, int& cantidadEstudiantes) {
    ifstream archivo("notas.dat", ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }
    archivo.read(reinterpret_cast<char*>(&cantidadEstudiantes), sizeof(int));
    archivo.read(reinterpret_cast<char*>(estudiantes), cantidadEstudiantes * sizeof(Estudiante));
    archivo.close();
}

int main() {
    Estudiante estudiantes[100]; 
    int cantidadEstudiantes = 0;

    char opcion;
    do {
        cout << "\nMENU:" << endl;
        cout << "1. Agregar estudiante" << endl;
        cout << "2. Mostrar estudiantes" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese la opción: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                crearEstudiante(estudiantes, cantidadEstudiantes);
                escribirEnArchivo(estudiantes, cantidadEstudiantes);
                break;
            case '2':
                leerDeArchivo(estudiantes, cantidadEstudiantes);
                mostrarEstudiantes(estudiantes, cantidadEstudiantes);
                break;
            case '3':
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Inténtelo de nuevo." << endl;
                break;
        }
    } while (opcion != '3');

    return 0;
}

