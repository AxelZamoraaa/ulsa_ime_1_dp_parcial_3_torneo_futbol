**Matrícula:** [Inserta aquí tu respuesta]  
**Título de la propuesta:** [Inserta aquí tu respuesta]

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

Es una mejora. Actualmente, en la tabla de posiciones los equipos solo se ordenan por puntos (pts), y si dos o más equipos terminan empatados en el primer lugar, el programa siempre le pide al usuario que elija al campeón a mano.

Con la mejora, la tabla de posiciones y el campeón desempatan automáticamente usando la diferencia de goles (gf - gc), igual que en un torneo real, dejando la elección manual únicamente si siguen empatados tanto en puntos como en diferencia de goles. Beneficia a quien usa el programa porque la tabla muestra posiciones más justas y el campeón se define de forma automática sin pedir intervención innecesaria.

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (registros, arreglos, constantes, funciones, menú)? Justifica cada cambio.

Solo cambian dos funciones de mi módulo: ordenarTabla y contarEmpatadosPrimerLugar, en campeon.h. No cambian los registros, los arreglos, las constantes, los demás módulos ni el menú.

Cambia contarEmpatadosPrimerLugar: en el if donde cuenta los empatados, además de comparar tabla[i].pts == tabla[0].pts, verifica con && que también tengan la misma diferencia de goles ((tabla[i].gf - tabla[i].gc) == (tabla[0].gf - tabla[0].gc)).

No cambia nada más: no se agregan campos nuevos al registro Equipo (la diferencia de goles se calcula al momento con gf - gc), ni se altera el formato de columnas del reporte "TABLA DE POSICIONES" ni de "CAMPEON DEL TORNEO".

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
ordenarTabla
1. Para i desde 0 hasta total - 2:
   1.1 Para j desde 0 hasta total - 2 - i:
       1.1.1 [NUEVO] Calcular difActual = tabla[j].gf - tabla[j].gc
       1.1.2 [NUEVO] Calcular difSiguiente = tabla[j + 1].gf - tabla[j + 1].gc
       1.1.3 [CAMBIA] Si tabla[j].pts es menor a tabla[j + 1].pts, O si tienen los mismos puntos y difActual es menor a difSiguiente:
             intercambiar tabla[j] y tabla[j + 1] con apuntadores

contarEmpatadosPrimerLugar
1. Poner empatados en 0
2. [NUEVO] Calcular difLider = tabla[0].gf - tabla[0].gc
3. Para i desde 0 hasta total - 1:
   3.1 [NUEVO] Calcular difActual = tabla[i].gf - tabla[i].gc
   3.2 [CAMBIA] Si tabla[i].pts es igual a tabla[0].pts Y difActual es igual a difLider:
       sumar 1 a empatados
4. Regresar empatados
```
