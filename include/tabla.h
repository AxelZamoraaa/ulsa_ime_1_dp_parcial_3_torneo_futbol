#pragma once

#include "torneo.h"

void registrarPartido(Equipo equipos[], const Partido &partido)
{
    registrarResultado(equipos[partido.local], partido.golesLocal, partido.golesVisitante);
    registrarResultado(equipos[partido.visitante], partido.golesVisitante, partido.golesLocal);
}

void calcularTabla(Equipo equipos[], const Partido partidos[])
{
    for (int i = 0; i < TOTAL_PARTIDOS; i++)
    {
        registrarPartido(equipos, partidos[i]);
    }
}