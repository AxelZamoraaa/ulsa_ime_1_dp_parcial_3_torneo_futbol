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
