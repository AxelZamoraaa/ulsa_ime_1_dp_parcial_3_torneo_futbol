#include <iostream>
#include "torneo.h"
#include "utilerias.h"
#include "registro.h"
#include "Simulacion.h"
#include "tabla.h"
#include "campeon.h"
#include "consultas.h"
#include "matriz.h"

const int OPCION_REGISTRAR = 1;
const int OPCION_MOSTRAR_EQUIPOS = 2;
const int OPCION_SIMULAR = 3;
const int OPCION_RESULTADOS = 4;
const int OPCION_TABLA = 5;
const int OPCION_CAMPEON = 6;
const int OPCION_CONSULTAR = 7;
const int OPCION_MATRIZ = 8;
const int OPCION_SALIR = 9;

void mostrarMenu()
{
    cout << endl;
    cout << "1. Registrar equipo" << endl;
    cout << "2. Mostrar equipos" << endl;
    cout << "3. Simular torneo" << endl;
    cout << "4. Mostrar resultados" << endl;
    cout << "5. Mostrar tabla de posiciones" << endl;
    cout << "6. Mostrar campeon" << endl;
    cout << "7. Consultar equipo" << endl;
    cout << "8. Mostrar matriz de enfrentamientos" << endl;
    cout << "9. Salir" << endl;
}

int main()
{
    Equipo equipos[MAX_EQUIPOS];
    Partido partidos[TOTAL_PARTIDOS];
    int goles[MAX_EQUIPOS][MAX_EQUIPOS] = {};
    int totalEquipos = 0;
    bool simulado = false;
    int opcion;

    do
    {
        mostrarMenu();
        opcion = leerEntero("Opcion: ");
        cout << endl;

        if (opcion == OPCION_REGISTRAR)
        {
            registrarEquipo(equipos, totalEquipos);
        }
        else if (opcion == OPCION_MOSTRAR_EQUIPOS)
        {
            mostrarEquipos(equipos, totalEquipos);
        }
        else if (opcion == OPCION_SIMULAR)
        {
            if (simularTorneo(totalEquipos, partidos, simulado))
            {
                calcularTabla(equipos, partidos);
                llenarMatriz(partidos, goles);
            }
        }
        else if (opcion == OPCION_RESULTADOS)
        {
            mostrarResultados(equipos, partidos, simulado);
        }
        else if (opcion == OPCION_TABLA)
        {
            mostrarTabla(equipos, simulado);
        }
        else if (opcion == OPCION_CAMPEON)
        {
            mostrarCampeon(equipos, simulado);
        }
        else if (opcion == OPCION_CONSULTAR)
        {
            consultarEquipo(equipos, totalEquipos, goles, simulado);
        }
        else if (opcion == OPCION_MATRIZ)
        {
            mostrarReporteMatriz(equipos, goles, simulado);
        }
        else if (opcion == OPCION_SALIR)
        {
            cout << "Hasta luego." << endl;
        }
        else
        {
            cout << "Opcion invalida. Elige un numero del 1 al 9." << endl;
        }
    } while (opcion != OPCION_SALIR);

    return 0;
}