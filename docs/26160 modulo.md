
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

[- `pedirModo()`: muestra las opciones, pide el modo y repite hasta que sea 1 o 2.
- `generarPartidos(partidos, modo)`: crea los 15 partidos y les asigna goles según el modo.
- `simularTorneo(totalEquipos, partidos, simulado)`: valida que se pueda simular, pide el modo, genera los partidos y marca el torneo como simulado.
- `mostrarResultados(equipos, partidos, simulado)`: imprime la tabla de resultados si ya se simuló.]

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

[- Arreglo de `Partido` (`partidos[]`): cada partido junta local, visitante y goles en un registro, así que es más claro que usar cuatro arreglos separados. Se pasa como arreglo, lo que equivale a pasar su dirección, por eso `generarPartidos` y `simularTorneo` lo llenan directamente.
- Arreglo de `Equipo` (`equipos[]`): solo se lee para obtener los nombres, por eso se pasa como `const`. `Partido` guarda el índice del equipo y no su nombre, para no duplicar datos.
- Matriz `GOLES_PRUEBA` (15 filas, 2 columnas): guarda los marcadores del modo de prueba. Se accede con `COLUMNA_LOCAL` y `COLUMNA_VISITANTE`.
- Paso de parámetros: `totalEquipos` y `modo` por valor, porque solo se leen. `simulado` por referencia (`bool &`), porque la función necesita cambiarlo y que el cambio se vea afuera. `partidos` y `equipos` como arreglo.]

**¿Dónde demuestras los temas asignados a tu módulo?**

[Inserta aquí tu respuesta]

**¿Qué ciclos usaste y por qué esos?**

[Inserta aquí tu respuesta]

**¿Qué constantes usaste y por qué son constantes?**

[Inserta aquí tu respuesta]

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

[Inserta aquí tu respuesta]

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

[Inserta aquí tu respuesta]

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
[Inserta aquí tu respuesta]
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

[Inserta aquí tu respuesta]

## 6. Pruebas

Incluye casos normales y casos límite.

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |

## 7. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |

## 8. Reflexión

**¿Qué aprendiste?**

[Inserta aquí tu respuesta]

**¿Qué cambiarías de tu proceso?**

[Inserta aquí tu respuesta]
