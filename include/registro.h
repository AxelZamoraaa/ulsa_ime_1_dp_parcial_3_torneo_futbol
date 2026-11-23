#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "torneo.h"
#include "utilerias.h"

bool caracterValido(char c)
{
    bool esLetra = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    bool esNumero = (c >= '0' && c <= '9');
    return esLetra || esNumero || c == ' ';
}

bool nombreValido(string nombre)
{
    int largo = nombre.length();

    if (largo < MIN_CARACTERES_NOMBRE || largo > MAX_CARACTERES_NOMBRE)
    {
        return false;
    }
    if (nombre[0] == ' ')
    {
        return false;
    }
    for (int i = 0; i < largo; i++)
    {
        if (!caracterValido(nombre[i]))
        {
            return false;
        }
    }
    return true;
}


bool nombreRepetido(const Equipo equipos[], int total, string nombre)
{
    for (int i = 0; i < total; i++)
    {
        if (mismoNombre(equipos[i].nombre, nombre))
        {
            return true;
        }
    }
    return false;
}

bool abreviaturaRepetida(const Equipo equipos[], int total, string abreviatura)
{
    for (int i = 0; i < total; i++)
    {
        if (equipos[i].abreviatura == abreviatura)
        {
            return true;
        }
    }
    return false;
}

string crearAbreviatura(string nombre, const Equipo equipos[], int total)
{
    string abreviatura = "";

    for (int i = 0; i < CARACTERES_ABREVIATURA; i++)
    {
        char letra = aMayuscula(nombre[i]);
        if (letra == ' ')
        {
            letra = 'X';
        }
        abreviatura = abreviatura + letra;
    }

    char digito = '1';
    while (abreviaturaRepetida(equipos, total, abreviatura))
    {
        abreviatura[CARACTERES_ABREVIATURA - 1] = digito;
        digito++;
    }
    return abreviatura;
}

void registrarEquipo(Equipo equipos[], int &total)
{
    if (total >= MAX_EQUIPOS)
    {
        cout << "La lista esta llena: ya hay " << MAX_EQUIPOS << " equipos registrados." << endl;
        return;
    }

    string nombre;
    bool correcto = false;

    do
    {
        nombre = leerCadena("Nombre del equipo: ");

        if (!nombreValido(nombre))
        {
            cout << "Nombre invalido: debe tener de " << MIN_CARACTERES_NOMBRE << " a "
                 << MAX_CARACTERES_NOMBRE << " caracteres, solo letras sin acento, numeros o espacios." << endl;
        }
        else if (nombreRepetido(equipos, total, nombre))
        {
            cout << "Ese equipo ya esta registrado." << endl;
        }
        else
        {
            correcto = true;
        }
    } while (!correcto);

    string abreviatura = crearAbreviatura(nombre, equipos, total);
    iniciarEquipo(equipos[total], nombre, abreviatura);
    total++;

    cout << "Equipo registrado: " << nombre << " (" << abreviatura << ")" << endl;
}

void mostrarEquipos(const Equipo equipos[], int total)
{
    if (total == 0)
    {
        cout << "No hay equipos registrados." << endl;
        return;
    }

    cout << "--- EQUIPOS REGISTRADOS ---" << endl;
    cout << left << setw(4) << "#" << "EQUIPO" << endl;

    for (int i = 0; i < total; i++)
    {
        cout << left << setw(4) << (i + 1) << equipos[i].nombre << endl;
    }
}