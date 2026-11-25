## 1. Autor

**Nombre:** Emilio Guillermo Gonzalez Viesca 
**Matrícula:** 26209
**Módulo:** 3 
**Archivo de código:** tabla.h

## 2. Propósito

Mi módulo toma los partidos jugados del torneo y calcula la tabla de posiciones. Para cada partido actualiza los datos de los dos equipos que jugaron (partidos jugados, ganados, empatados, perdidos, goles a favor, goles en contra y puntos). A quien usa el programa le sirve porque ya no tiene que sacar las cuentas a mano: con los 15 resultados, la tabla queda lista para mostrarse u ordenarse.

## 3. Entradas y salidas

**Entradas:** mi módulo no pide nada por teclado. Recibe por parámetros el arreglo de equipos (`Equipo equipos[]`) y el partido (`const Partido &partido`) o el arreglo de partidos (`const Partido partidos[]`). Los datos de los partidos (equipo local, visitante y goles) ya vienen capturados por otro módulo.

**Salidas:** no imprime ni devuelve nada (las funciones son `void`). Su resultado es que modifica el arreglo `equipos`, dejando las estadísticas de cada equipo actualizadas.

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

- `registrarPartido(Equipo equipos[], const Partido &partido)`: registra un solo partido. Llama dos veces a `registrarResultado`: una para el equipo local (sus goles a favor son `golesLocal`) y otra para el visitante (sus goles a favor son `golesVisitante`), invirtiendo los goles para cada uno.
- `calcularTabla(Equipo equipos[], const Partido partidos[])`: recorre los 15 partidos y llama a `registrarPartido` por cada uno, para armar toda la tabla.

Las separé así para que cada función haga una sola cosa: una registra un partido y la otra repite eso para todos.

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

- Registros (`struct Equipo` y `struct Partido`): juntan en un solo dato todo lo que va junto (las estadísticas de un equipo o los datos de un partido), en vez de tener muchas variables sueltas.
- Arreglos de registros (`Equipo equipos[]` y `Partido partidos[]`): porque hay varios equipos y varios partidos del mismo tipo, y así los puedo recorrer con un ciclo. Los índices `local` y `visitante` del partido indican qué posición del arreglo de equipos usar.
- Paso de datos: los arreglos se pasan como arreglo (en C++ así se pasan siempre por referencia, entonces los cambios sí se quedan en el original, que es lo que necesito en `equipos`). `partidos[]` lo marqué `const` porque solo lo leo y no debe modificarse. El `partido` individual lo paso por referencia constante (`const Partido &`) para no copiarlo y para proteger que no se cambie.

**¿Dónde demuestras los temas asignados a tu módulo?**

**[COMPLETA TÚ]** Revisa en tu práctica cuáles son los temas que te tocaron y señala la línea o función. Por ejemplo, si te tocó arreglos: en `calcularTabla` con `partidos[]` y `equipos[]`; si te tocó paso por referencia: en `registrarPartido` con `const Partido &partido`; si te tocó registros: el uso de `partido.local`, `partido.golesLocal`, etc.

**¿Qué ciclos usaste y por qué esos?**

Usé un ciclo `for` en `calcularTabla` porque ya sé exactamente cuántas veces se repite: `TOTAL_PARTIDOS` (15) veces, una por cada partido. No usé `while` porque no dependo de una condición que cambie, solo de un contador.

**¿Qué constantes usaste y por qué son constantes?**

Usé `TOTAL_PARTIDOS` (definida en `torneo.h`) para el límite del ciclo. Es constante porque el número de partidos del torneo no cambia mientras corre el programa, y así, si algún día cambia, se modifica en un solo lugar. Indirectamente también se usan `PUNTOS_VICTORIA`, `PUNTOS_EMPATE` y `PUNTOS_DERROTA`, porque están dentro de `registrarResultado`.

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

De `torneo.h` reutilicé la función `registrarResultado` (la que suma pj, gf, gc y puntos), los registros `Equipo` y `Partido` y la constante `TOTAL_PARTIDOS`. De `utilerias.h` no reutilicé ninguna.

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

No aplica.

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
FUNCION registrarPartido(equipos, partido)
    registrarResultado(equipos[partido.local], partido.golesLocal, partido.golesVisitante)
    registrarResultado(equipos[partido.visitante], partido.golesVisitante, partido.golesLocal)
FIN FUNCION

FUNCION calcularTabla(equipos, partidos)
    PARA i DESDE 0 HASTA TOTAL_PARTIDOS - 1
        registrarPartido(equipos, partidos[i])
    FIN PARA
FIN FUNCION
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

**[COMPLETA TÚ]** Prueba a mano con un partido, por ejemplo Local 2 - Visitante 1: el local queda con pj=1, pg=1, gf=2, gc=1, pts=3 y el visitante con pj=1, pp=1, gf=1, gc=2, pts=0. Escribe aquí si te salió igual y qué corregiste (por ejemplo, si al inicio se te olvidaba invertir los goles para el visitante). Si no corregiste nada, dilo tal cual.

## 6. Pruebas

Incluye casos normales y casos límite.

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | Un partido con ganador (caso normal) | Local 0, Visitante 1, goles 2 - 1 | Local: pj=1, pg=1, gf=2, gc=1, pts=3. Visitante: pj=1, pp=1, gf=1, gc=2, pts=0 | **[COMPLETA TÚ]** |
| 2 | Empate sin goles (caso límite) | Local 2, Visitante 3, goles 0 - 0 | Ambos: pj=1, pe=1, gf=0, gc=0, pts=1 | **[COMPLETA TÚ]** |
| 3 | Los 15 partidos completos con `calcularTabla` | Los 15 partidos del escenario | Cada equipo con pj=5; la suma de pg es igual a la suma de pp; la suma de gf es igual a la suma de gc | **[COMPLETA TÚ]** |

## 7. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | **[COMPLETA TÚ]** | **[COMPLETA TÚ]** |
| 2 | **[COMPLETA TÚ]** | **[COMPLETA TÚ]** |
| 3 | **[COMPLETA TÚ]** | **[COMPLETA TÚ]** |

## 8. Reflexión

**¿Qué aprendiste?**

**[COMPLETA TÚ]** con tus palabras.

**¿Qué cambiarías de tu proceso?**

**[COMPLETA TÚ]** con tus palabras.
