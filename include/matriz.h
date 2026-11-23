












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