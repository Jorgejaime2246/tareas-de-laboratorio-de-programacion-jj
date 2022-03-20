#include <iostream>
#include <stdlib.h>

using namespace std;

string seccion;

const int numeroDeEstudiantesEnSeccionA = 10;
const int numeroDeEstudiantesEnSeccionB = 15;
const int numeroDeEstudiantesEnSeccionC = 20;
int n;
int numeroDeEstudiantes;
int notaDelEstudianteActual;
int sumNotaTotal = 0;
int cantidadDeAprobados = 0;
int cantidadDeReprobados = 0;

float promedioNotas;


int ContadorDeAprobadosYReprobados (int nota )
{
    if (nota >= 10 && nota <= 20 )
        {
        cantidadDeAprobados++;
        }
    else if (nota >= 0 && nota <= 9 )
        {
        cantidadDeReprobados++;
        }
}

string Aprobatoria (int nota)
{
     if (nota <= 20 && nota >= 10 )
        {
        return "Aprobado";
        }
     else if (nota <= 9 && nota >= 0 )
        {
        return "Reprobado";
        }
}

string CalificacionCuantitativa (int nota)
{
    if (nota <= 20 && nota >= 19 )
        {
        return "Sobresaliente";
        }
    else if (nota <= 18 && nota >= 16  )
        {
        return "Muy Bueno";
        }
    else if (nota <= 15 && nota >= 13  )
        {
        return "Bueno";
        }
    else if (nota <= 12 && nota >= 10 )
        {
        return "Regular";
        }
    else if (nota <= 9 && nota >= 6  )
        {
        return "Mejorable";
        }
    else if (nota <= 5 && nota >= 0 )
        {
        return "Deficiente";
        }
}





int main()
{
    cout << "Ingrese la seccion (A, B, C)"  << endl;
    cin >> seccion;
    cout << "Ud. ha seleccionado la seccion " + seccion << endl;



    if (seccion == "A" || seccion == "a")
    {
      cout << "La cual tiene 10 estudiantes" << endl;
      numeroDeEstudiantes = numeroDeEstudiantesEnSeccionA;
    }
    else if (seccion == "B" || seccion == "b")
    {
      cout << "La cual tiene 15 estudiantes" << endl;
       numeroDeEstudiantes = numeroDeEstudiantesEnSeccionB;
    }
    else if (seccion == "C" || seccion == "c")
    {
      cout << "La cual tiene 20 estudiantes" << endl;
      numeroDeEstudiantes = numeroDeEstudiantesEnSeccionC;
    }
    else
    {
      cout << "seccion no valida" << endl;
      exit (3);
      return 3;
    }



    for(n = 1; n <= numeroDeEstudiantes; n++)
    {
        if (n == 1)
        {
        cout << "Ingrese la nota del primer estudiante" << endl;
        cin >> notaDelEstudianteActual;
        if (notaDelEstudianteActual > 20 || notaDelEstudianteActual < 0 )
        {
        cout << "" << endl;
        cout << "****Nota invalida. La nota debe ser un numero entre 0 y 20****" << endl;
        exit (4);
        return 4;
        }
        cout << "Estudiante #" + to_string (n) + ":" + " " + CalificacionCuantitativa (notaDelEstudianteActual) + "," + " " + Aprobatoria (notaDelEstudianteActual)  << endl;
        }

        else if (n > 1 && n <= numeroDeEstudiantes)
        {
        cout << "Ingrese la nota del siguiente estudiante" << endl;
        cin >> notaDelEstudianteActual;
        if (notaDelEstudianteActual > 20 || notaDelEstudianteActual < 0 )
        {
        cout << "" << endl;
        cout << "****Nota invalida. La nota debe ser un numero entre 0 y 20****" << endl;
        exit (5);
        return 5;
        }
        cout << "Estudiante #" + to_string (n) + ":" + " " + CalificacionCuantitativa (notaDelEstudianteActual) + "," + " " +  Aprobatoria (notaDelEstudianteActual) << endl;
        }
        ContadorDeAprobadosYReprobados (notaDelEstudianteActual);
        sumNotaTotal = sumNotaTotal + notaDelEstudianteActual;
    }
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "****Estadisticas de la Seccion****" << endl;
    cout << "" << endl;

    promedioNotas = static_cast <float>(sumNotaTotal) / static_cast <float>(numeroDeEstudiantes);

    cout << "Promedio: " + to_string (promedioNotas) << endl;
    cout << "" << endl;
    cout << "Numero de Aprobados:  " + to_string (cantidadDeAprobados) << endl;
    cout << "" << endl;
    cout << "Numero de Reprobados:  " + to_string (cantidadDeReprobados) << endl;
    cout << "" << endl;
    cout << "Total de Estudiantes de la Seccion: " + to_string (numeroDeEstudiantes) << endl;
    cout << "" << endl;
    return 0;



}


