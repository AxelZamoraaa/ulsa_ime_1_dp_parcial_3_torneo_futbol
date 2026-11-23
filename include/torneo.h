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