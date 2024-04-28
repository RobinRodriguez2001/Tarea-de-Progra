#include <iostream>
#include <vector> 

using namespace std;

float calcularPromedio(const vector<float>& notas) {
    float suma = 0;
    for (size_t i = 0; i < notas.size(); ++i) {
        suma += notas[i];
    }
    return suma / notas.size();
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

    vector<int> ids(cantidadEstudiantes);
    vector<string> nombres(cantidadEstudiantes);
    vector<string> apellidos(cantidadEstudiantes);
    vector<vector<float> > notas(cantidadEstudiantes, vector<float>(4)); 

    for (int i = 0; i < cantidadEstudiantes; ++i) {
        cout << "Ingrese la información del estudiante " << i + 1 << ":" << endl;
        cout << "ID del estudiante: ";
        cin >> ids[i];
        cout << "Nombre del estudiante: ";
        cin >> nombres[i];
        cout << "Apellido del estudiante: ";
        cin >> apellidos[i];
        cout << "Notas del estudiante (nota1 nota2 nota3 nota4): ";
        for (int j = 0; j < 4; ++j) {
            cin >> notas[i][j];
        }
    }

    cout << "\nInformación de los estudiantes:" << endl;
    for (int i = 0; i < cantidadEstudiantes; ++i) {
        float promedio = calcularPromedio(notas[i]);
        string estado = determinarEstado(promedio);
        cout << "ID: " << ids[i] << ", Nombre: " << nombres[i] << ", Apellido: " << apellidos[i]
             << ", Promedio: " << promedio << ", Estado: " << estado << endl;
    }

    return 0;
}


