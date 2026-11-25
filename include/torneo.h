#pragma once


#include <string>
const int MAX_EQUIPOS = 6;

const int TOTAL_PARTIDOS = 15;

const int MIN_CARACTERES_NOMBRE = 3;
const int MAX_CARACTERES_NOMBRE = 15;

const int CARACTERES_ABREVIATURA = 3;

const int PUNTOS_VICTORIA = 3;
const int PUNTOS_EMPATE = 1;
const int PUNTOS_DERROTA = 0;

using namespace std;

struct Equipo
{
    string nombre;
    string abreviatura;
    int pj;
    int pg;
    int pe;
    int pp;
    int gf;
    int gc;
    int pts;
};

void iniciarEquipo(Equipo &equipo, string nombre, string abreviatura)
{
    equipo.nombre = nombre;
    equipo.abreviatura = abreviatura;
    equipo.pj = 0;
    equipo.pg = 0;
    equipo.pe = 0;
    equipo.pp = 0;
    equipo.gf = 0;
    equipo.gc = 0;
    equipo.pts = 0;
}

struct Partido
{
    int local;
    int visitante;
    int golesLocal;
    int golesVisitante;
};

void registrarResultado(Equipo &equipo, int golesFavor, int golesContra)
{
    equipo.pj++;
    equipo.gf = equipo.gf + golesFavor;
    equipo.gc = equipo.gc + golesContra;

    if (golesFavor > golesContra)
    {
        equipo.pg++;
        equipo.pts = equipo.pts + PUNTOS_VICTORIA;
    }
    else if (golesFavor == golesContra)
    {
        equipo.pe++;
        equipo.pts = equipo.pts + PUNTOS_EMPATE;
    }
    else
    {
        equipo.pp++;
        equipo.pts = equipo.pts + PUNTOS_DERROTA;
    }
}
bool mismoNombre(string nombre1, string nombre2)
{
    return textoEnMinusculas(nombre1) == textoEnMinusculas(nombre2);