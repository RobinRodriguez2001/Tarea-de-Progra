#include <iostream>
#include <string>

using namespace std;

struct Estudiante {
    int id;
    string nombre;
    string apellido;
    float notas[4];
};

float calcularPromedio(const float* notas) {
    float suma = 0;
    for (int i = 0; i < 4; ++i) {
        suma += notas[i];
    }
    return suma / 4;
}

string determinarEstado(float promedio) {
    if (promedio >= 60) {
        return "Aprobado";
    } else {
        return "Reprobado";
    }
}

int main() {
    int cantidadEstudiantes;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> cantidadEstudiantes;

    Estudiante* estudiantes = new Estudiante[cantidadEstudiantes];

    for (int i = 0; i < cantidadEstudiantes; ++i) {
        cout << "Ingrese la información del estudiante " << i + 1 << ":" << endl;
        cout << "ID del estudiante: ";
        cin >> estudiantes[i].id;
        cout << "Nombre del estudiante: ";
        cin >> estudiantes[i].nombre;
        cout << "Apellido del estudiante: ";
        cin >> estudiantes[i].apellido;
        cout << "Notas del estudiante (nota1 nota2 nota3 nota4): ";
        for (int j = 0; j < 4; ++j) {
            cin >> estudiantes[i].notas[j];
        }
    }

    cout << "\nInformación de los estudiantes:" << endl;
    for (int i = 0; i < cantidadEstudiantes; ++i) {
        float promedio = calcularPromedio(estudiantes[i].notas);
        string estado = determinarEstado(promedio);
        cout << "ID: " << estudiantes[i].id << ", Nombre: " << estudiantes[i].nombre
             << ", Apellido: " << estudiantes[i].apellido << ", Promedio: " << promedio
             << ", Estado: " << estado << endl;
    }

    delete[] estudiantes;

    return 0;
}

