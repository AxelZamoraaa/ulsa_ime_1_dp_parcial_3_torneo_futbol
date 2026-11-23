#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "torneo.h"
#include "utilerias.h"
#include "escenario_prueba.h"

const int MIN_GOLES = 0;
const int MAX_GOLES = 5;
const int MODO_ALEATORIO = 1;
const int MODO_PRUEBA = 2;
const int COLUMNA_LOCAL = 0;
const int COLUMNA_VISITANTE = 1;

int pedirModo()
{
    int modo;

    do
    {
        cout << "1. Modo aleatorio" << endl;
        cout << "2. Modo de prueba" << endl;
        modo = leerEntero("Elige el modo de simulacion: ");

        if (modo != MODO_ALEATORIO && modo != MODO_PRUEBA)
        {
            cout << "Modo invalido. Elige 1 o 2." << endl;
        }
    } while (modo != MODO_ALEATORIO && modo != MODO_PRUEBA);

    return modo;
}

void generarPartidos(Partido partidos[], int modo)
{
    int numeroPartido = 0;

    for (int i = 0; i < MAX_EQUIPOS - 1; i++)
    {
        for (int j = i + 1; j < MAX_EQUIPOS; j++)
        {
            partidos[numeroPartido].local = i;
            partidos[numeroPartido].visitante = j;

            if (modo == MODO_PRUEBA)
            {
                partidos[numeroPartido].golesLocal = GOLES_PRUEBA[numeroPartido][COLUMNA_LOCAL];
                partidos[numeroPartido].golesVisitante = GOLES_PRUEBA[numeroPartido][COLUMNA_VISITANTE];
            }
            else
            {
                partidos[numeroPartido].golesLocal = numeroAleatorio(MIN_GOLES, MAX_GOLES);
                partidos[numeroPartido].golesVisitante = numeroAleatorio(MIN_GOLES, MAX_GOLES);
            }
            numeroPartido++;
        }
    }
}

bool simularTorneo(int totalEquipos, Partido partidos[], bool &simulado)
{
    if (totalEquipos < MAX_EQUIPOS)
    {
        cout << "No se puede simular: hay " << totalEquipos << " de " << MAX_EQUIPOS
             << " equipos registrados." << endl;
        return false;
    }
    if (simulado)
    {
        cout << "El torneo ya fue simulado." << endl;
        return false;
    }

    int modo = pedirModo();
    generarPartidos(partidos, modo);
    simulado = true;

    cout << "Torneo simulado correctamente." << endl;
    return true;
}


void mostrarResultados(const Equipo equipos[], const Partido partidos[], bool simulado)
{
    if (!simulado)
    {
        cout << "Primero debes simular el torneo." << endl;
        return;
    }

    cout << "--- RESULTADOS DE LOS PARTIDOS ---" << endl;
    cout << left << setw(4) << "#" << setw(17) << "LOCAL" << setw(10) << "MARCADOR" << "VISITANTE" << endl;

    for (int i = 0; i < TOTAL_PARTIDOS; i++)
    {
        string marcador = to_string(partidos[i].golesLocal) + " - " + to_string(partidos[i].golesVisitante);

        cout << left << setw(4) << (i + 1)
             << setw(17) << equipos[partidos[i].local].nombre
             << setw(10) << marcador
             << equipos[partidos[i].visitante].nombre << endl;
    }
}