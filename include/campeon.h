#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "torneo.h"
#include "utilerias.h"

void intercambiarEquipos(Equipo *a, Equipo *b)
{
    Equipo temporal = *a;
    *a = *b;
    *b = temporal;
}

void ordenarTabla(Equipo tabla[], int total)
{
    for (int i = 0; i < total - 1; i++)
    {
        for (int j = 0; j < total - 1 - i; j++)
        {
            if (tabla[j].pts < tabla[j + 1].pts)
            {
                intercambiarEquipos(&tabla[j], &tabla[j + 1]);
            }
        }
    }
}

void copiarEquipos(const Equipo origen[], Equipo destino[], int total)
{
    for (int i = 0; i < total; i++)
    {
        destino[i] = origen[i];
    }
}

int contarEmpatadosPrimerLugar(const Equipo tabla[], int total)
{
    int empatados = 0;

    for (int i = 0; i < total; i++)
    {
        if (tabla[i].pts == tabla[0].pts)
        {
            empatados++;
        }
    }
    return empatados;
}

void mostrarTabla(const Equipo equipos[], bool simulado)
{
    if (!simulado)
    {
        cout << "Primero debes simular el torneo." << endl;
        return;
    }

    Equipo tabla[MAX_EQUIPOS];
    copiarEquipos(equipos, tabla, MAX_EQUIPOS);
    ordenarTabla(tabla, MAX_EQUIPOS);

    cout << "--- TABLA DE POSICIONES ---" << endl;
    cout << left << setw(5) << "POS" << setw(17) << "EQUIPO"
         << right << setw(4) << "PJ" << setw(4) << "PG" << setw(4) << "PE"
         << setw(4) << "PP" << setw(4) << "GF" << setw(4) << "GC" << setw(5) << "PTS" << endl;

    for (int i = 0; i < MAX_EQUIPOS; i++)
    {
        cout << left << setw(5) << (i + 1) << setw(17) << tabla[i].nombre
             << right << setw(4) << tabla[i].pj << setw(4) << tabla[i].pg
             << setw(4) << tabla[i].pe << setw(4) << tabla[i].pp
             << setw(4) << tabla[i].gf << setw(4) << tabla[i].gc
             << setw(5) << tabla[i].pts << endl;
    }
}

void mostrarCampeon(const Equipo equipos[], bool simulado)
{
    if (!simulado)
    {
        cout << "Primero debes simular el torneo." << endl;
        return;
    }

    Equipo tabla[MAX_EQUIPOS];
    copiarEquipos(equipos, tabla, MAX_EQUIPOS);
    ordenarTabla(tabla, MAX_EQUIPOS);

    int empatados = contarEmpatadosPrimerLugar(tabla, MAX_EQUIPOS);
    int elegido = 0;

    cout << "--- CAMPEON DEL TORNEO ---" << endl;

    if (empatados > 1)
    {
        cout << "Hay un empate en el primer lugar con " << tabla[0].pts << " puntos." << endl;
        for (int i = 0; i < empatados; i++)
        {
            cout << (i + 1) << ". " << tabla[i].nombre << endl;
        }

        do
        {
            elegido = leerEntero("Elige al campeon: ");
            if (elegido < 1 || elegido > empatados)
            {
                cout << "Opcion invalida. Elige un numero de la lista." << endl;
            }
        } while (elegido < 1 || elegido > empatados);

        cout << endl;
        elegido = elegido - 1;
    }

    cout << "Campeon: " << tabla[elegido].nombre << endl;
    cout << "Puntos: " << tabla[elegido].pts << endl;
}
