**Matrícula:** 26209  
**Título de la propuesta:** Tabla ordenada por puntos con desempate por diferencia de goles

## 1. Impacto

Es una **mejora**. Ahorita la tabla se calcula bien, pero los equipos salen en el mismo orden en que se registraron, no en orden de posición. Eso no es una tabla de posiciones de verdad, porque el primer lugar debería aparecer arriba. Con la propuesta, la tabla se ordena de mayor a menor por puntos, y si dos equipos empatan en puntos, se desempata con la diferencia de goles (goles a favor menos goles en contra). Si siguen empatados, se desempata por goles a favor. Beneficia a quien usa el programa, porque ve de inmediato quién va ganando el torneo sin tener que comparar los puntos a mano.

## 2. Qué implica en el diseño

- **Registro `Equipo`:** se agrega el campo `dg` (diferencia de goles). Se actualiza en `registrarResultado` como `gf - gc`. Lo guardo como campo para no recalcularlo cada vez que se compara y para poder mostrarlo en la tabla.
- **`iniciarEquipo`:** también se inicializa `dg = 0`, igual que los demás contadores, para que no tenga basura al inicio.
- **Funciones:**
  - `registrarResultado` cambia: ahora también actualiza `dg`.
  - Nueva función `ordenarTabla(Equipo equipos[])` en `tabla.h`: ordena el arreglo con el método de burbuja y usa una función auxiliar para saber si un equipo va antes que otro.
  - Nueva función `va_antes(const Equipo &a, const Equipo &b)`: devuelve `true` si `a` debe ir arriba de `b` (más puntos, si empatan más `dg`, si empatan más `gf`).
- **Arreglos:** se usa el mismo arreglo `equipos[]`. Se pasa como arreglo (por referencia) porque `ordenarTabla` lo modifica, y los equipos se intercambian de lugar. Como `Equipo` es un registro, el intercambio se hace con una variable auxiliar de tipo `Equipo`.
- **Constantes:** se usa `MAX_EQUIPOS` como límite de los ciclos del ordenamiento. No hace falta una constante nueva.
- **Ciclos:** dos ciclos `for` anidados (burbuja), porque se sabe cuántas vueltas hay que dar.
- **Menú:** la opción de mostrar la tabla debe llamar a `ordenarTabla` después de `calcularTabla` y antes de imprimir. No cambia el número de opciones.
- **Importante:** `ordenarTabla` se llama una sola vez después de calcular, porque `registrarPartido` usa los índices `local` y `visitante` y, si se reordena antes de registrar todos los partidos, los índices ya no apuntarían al equipo correcto.

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
FUNCION iniciarEquipo(equipo, nombre, abreviatura)
    equipo.nombre = nombre
    equipo.abreviatura = abreviatura
    equipo.pj, pg, pe, pp, gf, gc, pts = 0
    equipo.dg = 0                                          [NUEVO]
FIN FUNCION

FUNCION registrarResultado(equipo, golesFavor, golesContra)
    equipo.pj = equipo.pj + 1
    equipo.gf = equipo.gf + golesFavor
    equipo.gc = equipo.gc + golesContra
    equipo.dg = equipo.gf - equipo.gc                      [NUEVO]
    SI golesFavor > golesContra ENTONCES
        equipo.pg = equipo.pg + 1
        equipo.pts = equipo.pts + PUNTOS_VICTORIA
    SINO SI golesFavor == golesContra ENTONCES
        equipo.pe = equipo.pe + 1
        equipo.pts = equipo.pts + PUNTOS_EMPATE
    SINO
        equipo.pp = equipo.pp + 1
        equipo.pts = equipo.pts + PUNTOS_DERROTA
    FIN SI
FIN FUNCION

FUNCION registrarPartido(equipos, partido)
    registrarResultado(equipos[partido.local], partido.golesLocal, partido.golesVisitante)
    registrarResultado(equipos[partido.visitante], partido.golesVisitante, partido.golesLocal)
FIN FUNCION

FUNCION calcularTabla(equipos, partidos)
    PARA i DESDE 0 HASTA TOTAL_PARTIDOS - 1
        registrarPartido(equipos, partidos[i])
    FIN PARA
FIN FUNCION

FUNCION va_antes(a, b)                                     [NUEVO]
    SI a.pts != b.pts ENTONCES                             [NUEVO]
        REGRESAR a.pts > b.pts                             [NUEVO]
    FIN SI                                                 [NUEVO]
    SI a.dg != b.dg ENTONCES                               [NUEVO]
        REGRESAR a.dg > b.dg                               [NUEVO]
    FIN SI                                                 [NUEVO]
    REGRESAR a.gf > b.gf                                   [NUEVO]
FIN FUNCION                                                [NUEVO]

FUNCION ordenarTabla(equipos)                              [NUEVO]
    PARA i DESDE 0 HASTA MAX_EQUIPOS - 2                   [NUEVO]
        PARA j DESDE 0 HASTA MAX_EQUIPOS - 2 - i           [NUEVO]
            SI va_antes(equipos[j + 1], equipos[j]) ENTONCES   [NUEVO]
                aux = equipos[j]                           [NUEVO]
                equipos[j] = equipos[j + 1]                [NUEVO]
                equipos[j + 1] = aux                       [NUEVO]
            FIN SI                                         [NUEVO]
        FIN PARA                                           [NUEVO]
    FIN PARA                                               [NUEVO]
FIN FUNCION                                                [NUEVO]

OPCION DE MENU "Mostrar tabla"
    calcularTabla(equipos, partidos)
    ordenarTabla(equipos)                                  [NUEVO]
    imprimir tabla (ahora también con la columna DG)       [CAMBIA]
```