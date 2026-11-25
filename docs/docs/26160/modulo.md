
## 1. Autor

**Nombre:** [Luis Cortés Gallegos]  
**Matrícula:** [26160]  
**Módulo:** [Simulación de partidos]  
**Archivo de código:** [Simulacion.h]

## 2. Propósito

¿Qué hace tu módulo y para qué le sirve a quien usa el programa?

[Mi módulo es la parte que simula los partidos del torneo, simula los partidos de los seis equipos y le asigna goles a cada partido pidiendo antes si es modo aleatorio o modo de prueba. Después muestra la tabla.]

## 3. Entradas y salidas

¿Qué recibe tu módulo (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

[Primero recibe el modo de simulación, 1= aleatorio, 2= prueba
 Y la también `totalEquipos` (cuántos equipos hay registrados), el arreglo `partidos`, el indicador `simulado` y el arreglo `equipos` (solo es para mostrar nombres)
 Y lo que imprime o devuelve es `true` si si se pudo simular o `false` si no poudo
  tambien imprime "Torneo simulado correctamente" y la tabla de resultados con número de partido, local, marcador y visitante.]

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

[ `pedirModo()`: muestra las opciones, pide el modo y repite hasta que sea 1 o 2. (que es 1= aleatorio, 2= prueba)
 `generarPartidos(partidos, modo)`: crea los 15 partidos y les asigna goles según el modo (alwatorio o de prueba).
`simularTorneo(totalEquipos, partidos, simulado)`: comprueba que se pueda simular, pide el modo, genera los partidos y marca el torneo como simulado.
 `mostrarResultados(equipos, partidos, simulado)`: imprime la tabla de resultados si ya se simuló.]

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

[ arreglo de `Partido` : cada partido junta local, visitante y goles en un registro, así que es más claro que usar cuatro arreglos separados. Se pasa como arreglo por eso `generarPartidos` y `simularTorneo` lo llenan directamente.
Arreglo de `Equipo`: solo se lee para obtener los nombres por eso se pasa como `const`. Y `Partido` guarda el índice del equipo y no su nombre, para no duplicar datos.
Matriz `GOLES_PRUEBA` : guarda los marcadores del modo de prueba. Se accede con `COLUMNA_LOCAL` y `COLUMNA_VISITANTE`.
Paso de parámetros: `totalEquipos` y `modo` por valor porque solo se leen. `simulado` por referencia (`bool &`), porque la función necesita cambiarlo y que el cambio se vea afuera. `partidos` y `equipos` como arreglo.]

**¿Dónde demuestras los temas asignados a tu módulo?**

[Creando el arreglo de registros, en el cual guardo los partidos]

**¿Qué ciclos usaste y por qué esos?**

[use do-while para cuando el usuario al momento de ingresar un modo no sea ni uno ni dos, pida otra vez la elección, use for para generar los partidos y para mostrar los resultados]

**¿Qué constantes usaste y por qué son constantes?**

[Use modo aleatorio y modo de prueba, tambien las columnas de local y visitante, y son constantes porque no cambian cuando dorre el proghrama]

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

[De utilerias leerEntero y numeroAleatorio que me permitieron leer lo que registro el ususario y repetirlo hasta que ingrese un numero  valido y de torneo use los registros de equipos y partidos y tambien use las constantes de max equipos y total partidos]

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

[ El primero es para caundo se ingresaron menos de seis equipos y muestra "no se puede simular, hay x equupos registrados", otro es cuando quiere simular el torneo cuando ya fue simulado, otro cuando se ingresa un modo que no es ni uno ni dos, se muestra "modo invalido" y otro es cuando se piden resultados sin haber simulado el torneo, muestra "primero debes simular el torneo"]

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
[Funcion de pedir modo

1. Mostrar el menu: "1 Modo aleatorio" y "2 Modo de prueba"
2. Leer el entero del usuario y guardarlo en modo
3. Si modo no es 1 ni 2, mostrar "Modo invalido, elige 1 o 2"
4. Mientras modo no sea 1 ni 2, volver al paso 1
5. Devolver modo

Rechazo: un modo que no sea 1 o 2 muestra el aviso y repite la pregunta.

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

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

[Si, el orden en el que se muestran en la tabla los equipos y su marcador]

## 6. Pruebas

Incluye casos normales y casos límite.

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | [ Si simulaba con 5 equipos ] | [ cinco equipos ] | [Marcarme rechazo e indicrame que faltan equipos] | [No se puede simular hay 5 equipos de seis] |
| 2 | [Modo aleatorio] | [1 (en modo)] | [La simulacion aleatoria del torneo] | [15 Partidos con resultados aleatorios] |
| 3 | [Escribir algo mal en el modo] | [3, o letras] | [Rechazo al no ser 1 o 2] | [Modo invalido elige 1 o 2] |

## 7. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | [Como implementar apuntadores en los arreglos] | [Lo hice de la manera antigua] |
| 2 | [Como hacer que solo se acepten numeros enteros] | [Leer entero] |
| 3 | [Como no aceptar un numero que no sea uno ni dos] | [pedriModo, if y do-while] |

## 8. Reflexión

**¿Qué aprendiste?**

[Sobre todo tomar en practica y llevar al siguiente nivel el dominio del programa y llevar una cantidad mayor de arreglos, registros, etc.]

**¿Qué cambiarías de tu proceso?**

[La inclución de apuntadores en los arreglos]
