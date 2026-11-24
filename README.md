# Proyecto Parcial 3: Sistema de Gestión de un Torneo de Fútbol

> **Importante:** este README es del equipo y debe tener aportaciones de todos los integrantes. La guía completa está en [`PROYECTO.md`](PROYECTO.md).

## 1. Integrantes

| Módulo | Matrícula | Nombre | Usuario de GitHub | Tema |
| --- | --- | --- | --- | --- |
| 1 | [26295] | [Sergio Axel Zamora Coronado] | [AxelZamoraaa] | Registro.h |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | Simulación de partidos |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | Tabla de posiciones |
| 4 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | Clasificación y campeón |
| 5 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | Consultas |
| 6 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | Matriz de enfrentamientos |

> **Nota:** en los equipos de 5 integrantes, todos contribuyen al módulo 6. En esa fila escriban "Todo el equipo".

## 2. Opciones del menú

1. Registrar equipo
2. Mostrar equipos
3. Simular torneo
4. Mostrar resultados
5. Mostrar tabla de posiciones
6. Mostrar campeon
7. Consultar equipo
8. Mostrar matriz de enfrentamientos
9. Salir 

## 3. Cómo compilar y ejecutar

Desde la carpeta del proyecto:

```
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o torneo
```

Para ejecutar en macOS:

```
./torneo
```

Para ejecutar en Windows:

```
.\torneo.exe
```

## 4. Tipos de datos abstractos (TDA)

Describan cada TDA que diseñaron como registro (`struct`): qué datos guarda, qué operaciones tiene y por qué.

[Inserta aquí tu respuesta]

## 5. Reglas del programa

Escriban las decisiones que el equipo tomó y que el cálculo a mano necesita. Por ejemplo: cómo se obtiene la abreviatura y qué pasa si dos se repiten.

- **Nombre del equipo:** de 3 a 15 caracteres. Solo acepta letras sin acento ni ñ, números y espacios. No puede empezar con espacio. No se distinguen mayúsculas de minúsculas (`Pumas` y `pumas` son el mismo equipo).
- **Abreviatura:** se calcula automáticamente con las primeras 3 letras del nombre, en mayúsculas (`Aguilas` → `AGU`). Si un espacio cae en esas 3 letras se cambia por `X`.
- **Abreviatura repetida:** si ya existe, se cambia la tercera letra por un número, empezando en 1, hasta que no se repita (`Pumas` → `PUM`, `Pumitas` → `PU1`, `Pumax` → `PU2`).
- **Equipos:** se registran de uno en uno, hasta 6. El orden de registro se conserva en equipos, ficha y matriz.
- **Partidos:** los 15 partidos van en este orden: equipo 1 contra 2 a 6, equipo 2 contra 3 a 6, y así hasta el equipo 5 contra el 6. El primero es el local.
- **Goles:** cada equipo mete de 0 a 5 goles. Victoria 3 puntos, empate 1 punto, derrota 0.
- **Simulación:** solo se simula una vez y solo con los 6 equipos registrados. Al simular se calcula la tabla y se llena la matriz.
- **Reportes:** ninguno funciona antes de simular, excepto la lista de equipos.
- **Tabla:** se ordena por puntos, de mayor a menor, sobre una copia. Si dos equipos tienen los mismos puntos quedan en su orden de registro. El arreglo original no se ordena.
- **Campeón:** si hay empate en el primer lugar, se muestran los empatados y el usuario elige. Si elige una opción que no existe, se vuelve a preguntar.
- **Mejor ataque y mejor defensa:** si hay empate se muestran todos los empatados, en orden de registro.


## 6. Equipos del escenario

Los 6 equipos que registran en el escenario obligatorio, en orden de registro.

| # | Nombre | Abreviatura |
| --- | --- | --- |
| # | Nombre | Abreviatura |
| --- | --- | --- |
| 1 | Aguilas | AGU |
| 2 | Chivas | CHI |
| 3 | CruzAzul  | CRU |
| 4 | Leones | LEO |
| 5 | Pumas | PUM |
| 6 | Tigres | TIG |
## 7. Cálculo a mano

Ejecuten una corrida en modo aleatorio y copien aquí sus 15 resultados.

```
[Inserta aquí tu respuesta]
```

Antes de consultar los demás reportes de esa corrida, calculen a mano los resultados.

**Tabla de posiciones:**

| Equipo | PJ | PG | PE | PP | GF | GC | PTS |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |

**Campeón o equipos empatados en el primer lugar:** [Inserta aquí tu respuesta]  
**Mejor ataque:** [Inserta aquí tu respuesta]  
**Mejor defensa:** [Inserta aquí tu respuesta]

**¿La salida del programa coincidió con el cálculo a mano? Si no, ¿qué corrigieron?**

[Inserta aquí tu respuesta]

## 8. Receta del menú

Receta en pseudocódigo del programa principal: el menú y cómo se conecta con cada módulo.

```
[Inserta aquí tu respuesta]
```

## 9. Documentación individual

Enlace a la documentación y a la propuesta de mejora de cada integrante.

| Módulo | Documentación | Propuesta de mejora |
| --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 4 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 5 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |

<!-- Si el equipo es de seis integrantes, agreguen una fila para el módulo 6. En equipos de cinco, agreguen una fila con el enlace a docs/modulo_6/modulo.md, sin propuesta de mejora. -->

## 10. Cambios a la base común

Si cambiaron una constante de `include/torneo.h`, expliquen qué cambiaron y por qué. Si no cambiaron nada, escriban "Sin cambios".

[Inserta aquí tu respuesta]
