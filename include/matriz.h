#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "torneo.h"

void llenarMatriz(const Partido partidos[], int goles[][MAX_EQUIPOS])
{
    for (int i = 0; i < MAX_EQUIPOS; i++)
    {
        for (int j = 0; j < MAX_EQUIPOS; j++)
        {
            goles[i][j] = 0;
        }
    }

    for (int p = 0; p < TOTAL_PARTIDOS; p++)
    {
        goles[partidos[p].local][partidos[p].visitante] = partidos[p].golesLocal;
        goles[partidos[p].visitante][partidos[p].local] = partidos[p].golesVisitante;
    }
}

int golesAFavor(const int goles[][MAX_EQUIPOS], int equipo)
{
    int suma = 0;

    for (int rival = 0; rival < MAX_EQUIPOS; rival++)
    {
        if (rival != equipo)
        {
            suma = suma + goles[equipo][rival];
        }
    }
    return suma;
}

int golesEnContra(const int goles[][MAX_EQUIPOS], int equipo)
{
    int suma = 0;

    for (int rival = 0; rival < MAX_EQUIPOS; rival++)
    {
        if (rival != equipo)
        {
            suma = suma + goles[rival][equipo];
        }
    }
    return suma;
}





void mostrarReporteMatriz(const Equipo equipos[], const int goles[][MAX_EQUIPOS], bool simulado)
{
    if (!simulado)
    {
        cout << "Primero debes simular el torneo." << endl;
        return;
    }

    cout << "--- MATRIZ DE ENFRENTAMIENTOS ---" << endl;
    mostrarMatriz(equipos, goles);
    cout << endl;
    mostrarMejorAtaque(equipos, goles);
    mostrarMejorDefensa(equipos, goles);
}
void mostrarMatriz(const Equipo equipos[], const int goles[][MAX_EQUIPOS])
{
    cout << left << setw(17) << "" << right;
    for (int j = 0; j < MAX_EQUIPOS; j++)
    {
        cout << setw(6) << equipos[j].abreviatura;
    }
    cout << endl;
    for (int i = 0; i < MAX_EQUIPOS; i++)
    {
        cout << left << setw(17) << equipos[i].nombre << right;
        for (int j = 0; j < MAX_EQUIPOS; j++)
        {
            string celda = "---";
            if (i != j)
            {
                celda = to_string(goles[i][j]) + "-" + to_string(goles[j][i]);
            }
            cout << setw(6) << celda;
        }
        cout << endl;
    }
}