## 1. Autor

**Nombre:** Sergio Axel Zamora Coronado
**Matrícula:** 26295 
**Módulo:** 1
**Archivo de código:** registro.h

## 2. Propósito

Mi modulo captura los 6 equipos del torneo y muestra la lista de equipos registrados. Antes de guardar un equipo revisa que el nombre sea valido y que no este repetido, y le crea una abreviatura de 3 letras. Le sirve al usuario para dejar listos los equipos antes de simular el torneo.

## 3. Entradas y salidas

**Recibe:** el arreglo equipos, el contador total de equipos registrados y, por teclado, el nombre del equipo.  
**Produce:** guarda el equipo nuevo en el arreglo (con su abreviatura y sus estadisticas en 0), aumenta total e imprime el reporte "EQUIPOS REGISTRADOS" o un mensaje de rechazo.

## 4. Decisiones de diseño

Explica cada decision y por que la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

- `caracterValido`: dice si un caracter es letra sin acento, numero o espacio.
- `nombreValido`: revisa que el nombre tenga de 3 a 15 caracteres, que no empiece con espacio y que todos sus caracteres sean validos.
- `nombreRepetido`: busca si el nombre ya esta en el arreglo, sin distinguir mayusculas.
- `abreviaturaRepetida`: busca si una abreviatura ya la tiene otro equipo.
- `crearAbreviatura`: arma la abreviatura con las 3 primeras letras en mayuscula y resuelve las repetidas.
- `registrarEquipo`: pide el nombre hasta que sea correcto y guarda el equipo.
- `mostrarEquipos`: imprime la lista de equipos.

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

Uso el registro Equipo y un arreglo de Equipo, porque los datos de cada equipo van juntos y el arreglo se recorre fácil con un for. El arreglo equipos[] se pasa como arreglo (la funcion trabaja sobre el arreglo original), y con const en las funciones que solo lo leen. El contador total se pasa por referencia (int &total), porque registrarEquipo necesita aumentarlo. Los textos (nombre y abreviatura) se pasan por valor, porque solo se leen.

**¿Dónde demuestras los temas asignados a tu módulo?**

- Registros: en registrarEquipo, iniciarEquipo(equipos[total], nombre, abreviatura) guarda un Equipo. El registro y iniciarEquipo los escribi en torneo.h.
- Arreglos: equipos[] en registrarEquipo, mostrarEquipos y nombreRepetido.
- Validacion de cadenas: nombreValido y caracterValido revisan el largo y cada caracter del nombre.

**¿Qué ciclos usaste y por qué esos?**

- for: para recorrer el nombre letra por letra y para recorrer el arreglo de equipos, porque se cuantas vueltas dar.
- do-while: en registrarEquipo, porque el nombre se pide por lo menos una vez y se repite mientras no sea correcto.
- while: en crearAbreviatura, para cambiar la abreviatura mientras siga repetida, porque no se cuantas veces pasara.

**¿Qué constantes usaste y por qué son constantes?**

MAX_EQUIPOS, MIN_CARACTERES_NOMBRE, MAX_CARACTERES_NOMBRE y CARACTERES_ABREVIATURA. Son constantes porque las reglas del torneo no cambian mientras corre el programa, y asi no escribo numeros sueltos como 6 o 15 en medio del codigo.

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

De utilerias.h: leerCadena. De torneo.h: iniciarEquipo, aMayuscula y mismoNombre (esta ultima es de la Persona 5, y tambien la usa su modulo de consultas).

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu modulo es el 3, escribe "No aplica".

- Nombre invalido: "Nombre invalido: debe tener de 3 a 15 caracteres, solo letras sin acento, numeros o espacios."
- Nombre repetido: "Ese equipo ya esta registrado."
- Lista llena (septimo equipo): "La lista esta llena: ya hay 6 equipos registrados."
- Mostrar equipos sin equipos registrados: "No hay equipos registrados."

## 5. Receta

Tu receta en pseudocodigo, escrita antes de programar.

```
registrarEquipo
1. Si total es igual a MAX_EQUIPOS, avisar que la lista esta llena y terminar
2. Poner correcto en falso
3. Repetir
   3.1 Leer el nombre
   3.2 Si el nombre no es valido, avisar
   3.3 Si no, si el nombre ya existe, avisar
   3.4 Si no, poner correcto en verdadero
4. Hasta que correcto sea verdadero
5. Crear la abreviatura
6. Guardar el equipo en equipos[total]
7. Sumar 1 a total

nombreValido
1. Si el largo es menor a 3 o mayor a 15, regresar falso
2. Si la primera letra es espacio, regresar falso
3. Para cada letra del nombre:
   si la letra no es valida, regresar falso
4. Regresar verdadero

crearAbreviatura
1. Tomar las 3 primeras letras del nombre y pasarlas a mayuscula
2. Si alguna es espacio, cambiarla por X
3. Poner digito en '1'
4. Mientras la abreviatura este repetida:
   4.1 Cambiar la tercera letra por digito
   4.2 Sumar 1 a digito
5. Regresar la abreviatura

mostrarEquipos
1. Si total es 0, avisar y terminar
2. Imprimir el titulo y los encabezados
3. Para cada equipo, imprimir su numero y su nombre
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

Si. Probe con Aguilas, Halcones, Jaguares, Leones, Pumas y Tigres, y las abreviaturas salieron AGU, HAL, JAG, LEO, PUM y TIG. Al revisar la receta con nombres parecidos, como Pumas y Pumitas, vi que darian la misma abreviatura (PUM), por eso agregue el paso 4, que cambia la tercera letra por un numero (PU1).

## 6. Pruebas

Incluye casos normales y casos límite.

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | Nombre demasiado corto | ab | Rechazo y vuelve a pedir el nombre | Rechazo y vuelve a pedir el nombre |
| 2 | Nombre repetido con otras mayusculas | Aguilas y luego aguilas | Rechaza el segundo | Rechaza el segundo |
| 3 | Nombre con ñ | Ñandu | Rechazo | Rechazo |
| 4 | Nombre de mas de 15 caracteres | NombreDemasiadoLargo | Rechazo | Rechazo |
| 5 | Septimo equipo | Opcion 1 con 6 equipos registrados | "La lista esta llena" | "La lista esta llena" |
| 6 | Abreviatura repetida | Pumas, Pumitas, Pumax | PUM, PU1, PU2 | PUM, PU1, PU2 |
| 7 | Mostrar equipos sin equipos | Opcion 2 al inicio | "No hay equipos registrados." | "No hay equipos registrados." |

## 7. Bitácora de dudas y errores

| # | Duda o error | Como lo resolvi |
| --- | --- | --- |
| 1 | ¿Como comparo Pumas con pumas, si para C++ son distintos? | Paso los dos nombres a minusculas con mismoNombre, que está en torneo.h, y los comparo. |
| 2 | ¿Que hago si dos abreviaturas salen iguales? | Cambio la tercera letra por un numero (PU1, PU2) con un while. |
| 3 | ¿Como detecto los acentos y la ñ? | Acepto solo letras de la a a la z, numeros y espacio; todo lo demas se rechaza. |

## 8. Reflexión

**¿Qué aprendiste?**

Aprendi a validar una cadena letra por letra, y que conviene separar la validacion (nombreValido) de la captura (registrarEquipo). Tambien entendi por que el contador total se pasa por referencia.

**¿Qué cambiaría de tu proceso?**

Escribiria primero los casos de prueba (nombre corto, repetido, con ñ) y despues el codigo, porque asi encontraria los errores mas rapido.