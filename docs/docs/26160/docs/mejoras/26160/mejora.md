Propuesta de mejora elaborada por: [Luis Cortés Gallegos]

**Matrícula:** [26160]  
**Título de la propuesta:** [Tabla de goleadores]

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

[Es una mejora. Lo que adiciona al programa, es que en cada partido ya se guardan los nombres de los equipos y el marcador, mi propuesta es agregar en cada partido quien metió cada gol, asi se tendrá un registro de quién metió cada gol en el torneo,  se recopilarán las veces que cada nombre se repitió y con esto se tendrá una cifra de goles de cada jugador que realizó al menos una anotación. Con esta cifra se guardaran los nombres en una tabla donde el jugador con más anotaciones encabezará la tabla]

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (registros, arreglos, constantes, funciones, menú)? Justifica cada cambio.

[Implica agregar un registro que guarda el jugador que anotó, y el arreglo goleadores que es el que guarda esos registros.
 Y como funciones nuevas, registrar goleadores, contar goleadores, ordenar goleadores y mostrar goleadores.]

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
[Es mi misma receta de modulo pero añadiendo las partes del registro de goleadores
    
    Funcion de pedir modo

1. Mostrar el menu: "1 Modo aleatorio" y "2 Modo de prueba"
2. Leer el entero del usuario y guardarlo en modo
3. Si modo no es 1 ni 2, mostrar "Modo invalido, elige 1 o 2"
4. Mientras modo no sea 1 ni 2, volver al paso 1
5. Devolver modo

Rechazo: un modo que no sea 1 o 2 muestra el aviso y repite la pregunta.

- Registro Goleador: nombre del jugador y goles que lleva                                         TODO EL PARRAFO ES NUEVO
- El registro Partido se modifica: ademas de local, visitante y los goles,
  guarda una lista de nombres: anotadores
- Arreglo goleadores: guarda los registros Goleador.
- Constante MAX_GOLEADORES = 150 (15 partidos x 5 goles x 2 equipos),
  que es el maximo de jugadores distintos posible, en caso de que todos los
  partidos quedaran 5-5 y cada gol lo metiera un jugador diferente

Funcion de generar los partidos
Recibe: el arreglo de partidos y el modo
Devuelve: nada (se llena el arreglo que recibe)
1. Poner numeroPartido en 0
2. Para cada equipo i desde el 0 hasta el penultimo (MAX_EQUIPOS - 1):
3. Para cada equipo j desde i + 1 hasta el ultimo (MAX_EQUIPOS):
4. Guardar i como local del partido numeroPartido
5. Guardar j como visitante del partido numeroPartido
Si el modo es prueba:
- Tomar los goles del local de la tabla GOLES_PRUEBA,
  fila numeroPartido, columna del local
- Tomar los goles del visitante de la misma fila,
  columna del visitante
Si es modo aleatorio:
- Pedir un numero aleatorio para los goles del local
- Pedir otro numero aleatorio para los goles del visitante
Sumar 1 a numeroPartido
6. Registrar los goleadores del partido numeroPartido                                                   ESTO ES NUEVO

Funcion de simular el torneo
Recibe: el total de equipos registrados y el arreglo de partidos 
Devuelve: verdadero si se simulo, falso si se rechazo
1. Si el total de equipos es menor que MAX_EQUIPOS:
 mostrar "No se puede simular: hay X de 6 equipos registrados"
 y devolver falso
2. Si simulado es verdadero:
  mostrar "El torneo ya fue simulado." y devolver falso
3. Después aplicar pedirModo y guardar el resultado en modo
4. Usar generarPartidos con el arreglo de partidos y el modo
5. Poner simulado en verdadero
6. Mostrar "Torneo simulado correctamente"
7. Devolver verdadero

Rechazos: faltan equipos, o el torneo ya fue simulado

Funcion de contar goleadores                                                                      TODO EL PARRAFO ES NUEVO

Recibe: el arreglo de partidos y el arreglo goleadores 
1. Poner totalGoleadores en 0.
2. Para cada partido p, desde el 0 hasta TOTAL_PARTIDOS:
   Para cada gol, desde el 0 hasta goles:
    - Tomar el nombre en anotadores
    - Buscar ese nombre en goleadores
    - Si ya esta, sumarle 1 a sus goles.
    - Si no esta, agregarlo en la casilla totalGoleadores con 1 gol

Funcion de mostrar los resultados de los paritdos
Recibe: el arreglo de equipos y el de partidos 
Devuelve: nada
1. Si simulado es falso:
  mostrar "Primero debes simular el torneo." y terminar
2. Mostrar el titulo "Resultados de los partidos"
3. Mostrar el encabezado: LOCAL, MARCADOR, VISITANTE
4. Para cada partido, desde el 0 hasta TOTAL_PARTIDOS
5. Armar el marcador como texto: "goles del local y goles del visitante"
6. Mostrar en una fila: el numero de partido, el nombre del equipo local, el marcador y el nombre del visitante
7. Terminar el programa

Rechazo: pedir resultados antes de simular el torneo]
```
