#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "torneo.h"
#include "utilerias.h"

Equipo *buscarEquipo(Equipo equipos[], int total, string nombre)
{
    for (int i = 0; i < total; i++)
    {
        if (mismoNombre(equipos[i].nombre, nombre))
        {
            return &equipos[i];
        }
        }
    return nullptr;
}

int posicionEquipo(const Equipo equipos[], int total, const Equipo *buscado)
{
    for (int i = 0; i < total; i++)
    {
        if (&equipos[i] == buscado)
        {
            return i;
        }
    }
    return -1;
}

string textoResultado(int golesFavor, int golesContra)
{
    if (golesFavor > golesContra)
    {
        return "Ganado";
    }
    else if (golesFavor == golesContra)
    {
        return "Empatado";
    }
    return "Perdido";
}

void mostrarFicha(const Equipo *equipo, int posicion, const Equipo equipos[], const int goles[][MAX_EQUIPOS])
{
    cout << "Equipo: " << equipo->nombre << endl;
    cout << "Jugados: " << equipo->pj << endl;
    cout << "Ganados: " << equipo->pg << endl;
    cout << "Empatados: " << equipo->pe << endl;
    cout << "Perdidos: " << equipo->pp << endl;
    cout << "Goles a favor: " << equipo->gf << endl;
    cout << "Goles en contra: " << equipo->gc << endl;
    cout << "Puntos: " << equipo->pts << endl;
    cout << endl;
    cout << left << setw(17) << "RIVAL" << setw(10) << "MARCADOR" << "RESULTADO" << endl;

    for (int rival = 0; rival < MAX_EQUIPOS; rival++)
    {
        if (rival != posicion)
        {
            int golesFavor = goles[posicion][rival];
            int golesContra = goles[rival][posicion];
            string marcador = to_string(golesFavor) + " - " + to_string(golesContra);
            cout << left << setw(17) << equipos[rival].nombre
                 << setw(10) << marcador
                 << textoResultado(golesFavor, golesContra) << endl;
        }
    }
}
void consultarEquipo(Equipo equipos[], int total, const int goles[][MAX_EQUIPOS], bool simulado)
{
    if (!simulado)
    {
        cout << "Primero debes simular el torneo." << endl;
        return;
    }

    string nombre = leerCadena("Nombre del equipo a consultar: ");
    Equipo *encontrado = buscarEquipo(equipos, total, nombre);

    cout << "--- FICHA DE EQUIPO ---" << endl;

    if (encontrado == nullptr)
    {
        cout << "Equipo no encontrado: " << nombre << endl;
    }
    else
    {
        int posicion = posicionEquipo(equipos, total, encontrado);
        mostrarFicha(encontrado, posicion, equipos, goles);
    }
}