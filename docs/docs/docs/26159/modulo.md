## 1. Autor

**Nombre:** [Alfredo Josue Coss Cardona]  
**Matrícula:** [26159]  
**Módulo:** [4]  
**Archivo de código:** [campeon.h]

## 2. Propósito

¿Qué hace tu módulo y para qué le sirve a quien usa el programa?

ordenar a los 6 equipos según sus puntos cuando ya se jugó el torneo y mostrar en pantalla la tabla de posiciones. También sirve para mostrar al equipo campeón y, si hay un empate en el primer lugar, dejar que el usuario elija al ganador.

## 3. Entradas y salidas

¿Qué recibe tu módulo (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

Recibe: el arreglo equipos, la bandera booleana simulado que indica si ya se jugaron los partidos y, por teclado (solo cuando hay empate en primer lugar), el número del equipo elegido como campeón.

Produce: ordena una copia de los equipos por puntos sin alterar el arreglo original, imprime la "TABLA DE POSICIONES" o el anuncio de "CAMPEON DEL TORNEO" con sus puntos, o muestra un mensaje de rechazo si el torneo aún no se simula o la opción elegida no es válida.

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

intercambiarEquipos: intercambia dos equipos en memoria usando apuntadores y una variable temporal.
ordenarTabla: ordena un arreglo de equipos de mayor a menor según sus puntos (pts) con el método burbuja.
copiarEquipos: copia los datos del arreglo original a un arreglo nuevo para poder ordenarlo sin desacomodar el arreglo original.
contarEmpatadosPrimerLugar: cuenta cuántos equipos tienen los mismos puntos que el primer lugar (tabla[0].pts).
mostrarTabla: revisa si el torneo ya se simuló, ordena una copia de los equipos e imprime la tabla de posiciones alineada.
mostrarCampeon: revisa si el torneo ya se simuló, ordena una copia, verifica si hay empate en primer lugar (pidiendo elegir al ganador si hace falta) e imprime al campeón y sus puntos.


**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

Uso el registro Equipo, arreglos de Equipo y apuntadores a Equipo, porque los datos de cada equipo van juntos, el arreglo se recorre fácil con un for y los apuntadores permiten intercambiar estructuras completas al ordenar. El arreglo equipos[] se pasa como arreglo con const en las funciones que solo lo leen (copiarEquipos, contarEmpatadosPrimerLugar, mostrarTabla y mostrarCampeon) para no modificar el orden original, y sin const en ordenarTabla para poder reordenar la copia. En intercambiarEquipos paso dos apuntadores (Equipo *a, Equipo *b) con las direcciones de memoria (&) para intercambiarlos directamente. Las variables simples (total y simulado) se pasan por valor porque solo se leen.

**¿Dónde demuestras los temas asignados a tu módulo?**

Apuntadores: en intercambiarEquipos(Equipo *a, Equipo *b), desreferenciando *a y *b para intercambiar dos registros en memoria, llamada desde ordenarTabla con &tabla[j] y &tabla[j + 1].

Arreglos y registros: Equipo equipos[] y la copia local Equipo tabla[MAX_EQUIPOS] en copiarEquipos, ordenarTabla, mostrarTabla y mostrarCampeon.


**¿Qué ciclos usaste y por qué esos?**

for: en ordenarTabla (anidados para comparar pares), copiarEquipos, contarEmpatadosPrimerLugar, mostrarTabla y mostrarCampeon (para listar empatados), porque sé exactamente cuántas vueltas dar (MAX_EQUIPOS, total o empatados).

do-while: en mostrarCampeon, porque cuando hay empate la opción se pide por lo menos una vez y se repite mientras el número ingresado no esté en la lista.

**¿Qué constantes usaste y por qué son constantes?**

MAX_EQUIPOS. Es constante porque el torneo siempre tiene 6 equipos mientras corre el programa, y así puedo declarar el tamaño del arreglo local Equipo tabla[MAX_EQUIPOS] y controlar los ciclos sin escribir el número 6 suelto en medio del código.

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

De utilerias.h: leerEntero en mostrarCampeon para leer el número elegido en el desempate. De torneo.h: el registro Equipo y la constante MAX_EQUIPOS.

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

Mostrar tabla sin simular el torneo: "Primero debes simular el torneo."

Mostrar campeón sin simular el torneo: "Primero debes simular el torneo."

Número fuera de rango al desempatar el primer lugar: "Opcion invalida. Elige un numero de la lista."

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
mostrarTabla
1. Si simulado es falso, avisar y terminar
2. Copiar equipos en un arreglo local tabla[MAX_EQUIPOS]
3. Ordenar tabla de mayor a menor segun sus puntos
4. Imprimir el titulo y los encabezados (POS, EQUIPO, PJ, PG, PE, PP, GF, GC, PTS)
5. Para cada equipo en tabla:
   imprimir su posicion (i + 1) y sus estadisticas

mostrarCampeon
1. Si simulado es falso, avisar y terminar
2. Copiar equipos en un arreglo local tabla[MAX_EQUIPOS]
3. Ordenar tabla de mayor a menor segun sus puntos
4. Contar cuantos equipos empatan con tabla[0].pts
5. Poner elegido en 0
6. Si empatados es mayor a 1:
   6.1 Avisar del empate y mostrar los puntos
   6.2 Para cada equipo empatado, imprimir su numero (i + 1) y su nombre
   6.3 Repetir
       6.3.1 Leer elegido con leerEntero
       6.3.2 Si elegido es menor a 1 o mayor a empatados, avisar
   6.4 Hasta que elegido este entre 1 y empatados
   6.5 Restar 1 a elegido para ajustar al indice del arreglo
7. Imprimir el nombre y los puntos de tabla[elegido]
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

Sí. Probé con 6 equipos después de simular los 15 partidos, incluyendo un caso donde dos equipos empataban en primer lugar con 12 puntos. Al revisar la receta vi dos cosas: primero, que si ordenaba directo equipos[] se perdía el orden original en que fueron registrados, por eso agregué copiarEquipos; segundo, que el usuario elige un número empezando en 1 pero el arreglo empieza en 0, por eso agregué el paso 6.5 (elegido = elegido - 1).


## 6. Pruebas

Incluye casos normales y casos límite.

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | Mostrar tabla sin simular | Opcion 4 al inicio | "Primero debes simular el torneo." | "Primero debes simular el torneo." |
| 2 | Mostrar campeon sin simular | Opcion 5 al inicio | "Primero debes simular el torneo." | "Primero debes simular el torneo." |
| 3 | Tabla ordenada por puntos | 6 equipos simulados | Equipos ordenados de mayor a menor puntaje | Equipos ordenados de mayor a menor puntaje |
| 4 | Campeon sin empate | Lider con 13 pts y segundo con 10 pts | Muestra directo al campeon y sus 13 pts | Muestra directo al campeon y sus 13 pts |
| 5 | Empate en primer lugar | 2 equipos con 11 pts y elijo 2 | Muestra la lista y elige al segundo equipo | Muestra la lista y elige al segundo equipo |
| 6 | Opcion invalida en desempate | 0 o 5 con 2 equipos empatados | Rechazo y vuelve a pedir el numero | Rechazo y vuelve a pedir el numero |

## 7. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | Si ordenaba `equipos[]` directamente, se desacomodaban los equipos originales del torneo. | Hice `copiarEquipos` y recibí `equipos[]` con `const` para ordenar solo una copia local (`tabla[]`). |
| 2 | ¿Cómo uso apuntadores de forma útil en mi módulo? | Creé `intercambiarEquipos(Equipo *a, Equipo *b)` para intercambiar dos estructuras usando sus direcciones (`&`) dentro del ordenamiento. |
| 3 | Al elegir al campeón en un empate, seleccionaba el equipo siguiente de la lista. | Resté 1 a `elegido` (`elegido = elegido - 1`) para convertir la opción del usuario (1 a N) al índice del arreglo (0 a N-1). |

## 8. Reflexión

**¿Qué aprendiste?**

Aprendí a ordenar un arreglo de registros sin alterar los datos originales usando una copia con const, y a intercambiar estructuras en memoria con apuntadores

**¿Qué cambiarías de tu proceso?**

Probaría primero en papel el manejo de los índices del desempate antes de escribir el código, para evitar desde el inicio el desfase entre el número que ve el usuario y la posición del arreglo
