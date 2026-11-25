DOCUMENTACIÓN DEL MÓDULO

1. Autor

Nombre: Pablo Mussa
Matrícula: 026165
Módulo: Consultas de equipos y matriz de resultados
Archivo de código: consultas.h y matriz.h

2. Propósito

Mi módulo sirve para consultar la información de cualquier equipo que participa en el torneo. Permite buscar un equipo por su nombre, mostrar sus estadísticas generales y consultar los resultados que obtuvo contra los demás equipos.

También incluye una función para mostrar la matriz de resultados, donde se pueden observar los marcadores de todos los partidos de una manera ordenada.

Esto ayuda al usuario a revisar la información del torneo sin tener que buscar manualmente cada resultado.

3. Entradas y salidas

Entradas:

* Arreglo de equipos con sus nombres, abreviaturas y estadísticas.
* Total de equipos registrados.
* Matriz de goles de los partidos.
* Variable booleana que indica si el torneo ya fue simulado.
* Nombre del equipo que el usuario escribe por teclado.

Salidas:

* Nombre del equipo consultado.
* Partidos jugados, ganados, empatados y perdidos.
* Goles a favor y en contra.
* Puntos obtenidos.
* Nombre de los rivales.
* Marcadores y resultados de cada partido.
* Matriz general con los resultados del torneo.
* Mensajes cuando el equipo no existe o todavía no se ha simulado el torneo.

4. Decisiones de diseño

¿Qué funciones tiene tu módulo y qué tarea hace cada una?

Mi módulo tiene las siguientes funciones:

1. mismoNombre: Compara dos nombres sin importar si están escritos con mayúsculas o minúsculas.
2. buscarEquipo: Busca un equipo dentro del arreglo utilizando su nombre y devuelve un apuntador al equipo encontrado. Si no existe, devuelve nullptr.
3. posicionEquipo: Busca la posición que ocupa un equipo dentro del arreglo y devuelve su índice.
4. textoResultado: Compara los goles a favor y en contra para determinar si el equipo ganó, empató o perdió.
5. mostrarFicha: Muestra toda la información de un equipo, incluyendo sus estadísticas y los resultados contra sus rivales.
6. consultarEquipo: Permite al usuario escribir el nombre de un equipo y consultar su ficha. También verifica que el torneo ya haya sido simulado.
7. mostrarMatriz: Muestra los resultados de todos los partidos en forma de matriz, utilizando las abreviaturas de los equipos.

¿Qué estructuras de datos usa tu módulo, por qué las elegiste y cómo pasas los datos a cada función?

Utilizo las siguientes estructuras:

* Registros: Utilizo el registro Equipo, que contiene información como el nombre, abreviatura, partidos jugados, ganados, empatados, perdidos, goles y puntos.
* Arreglos: Utilizo un arreglo de equipos para almacenar y recorrer la información de los participantes.
* Matrices: Utilizo una matriz de goles para guardar los resultados de los partidos entre los equipos.
* Apuntadores: Utilizo apuntadores de tipo Equipo para encontrar y consultar un equipo sin tener que copiar toda su información.

Los datos se pasan por valor cuando solamente necesito comparar números o cadenas. Los arreglos y matrices se pasan como parámetros para consultar sus datos. También utilizo const para evitar modificar información que solamente necesito leer.

¿Dónde demuestras los temas asignados a tu módulo?

Demuestro los temas de programación en diferentes partes del código:

* Funciones: En buscarEquipo, mostrarFicha, consultarEquipo y mostrarMatriz.
* Arreglos: En el almacenamiento y recorrido de los equipos.
* Matrices: En la consulta de los goles de cada partido.
* Apuntadores: En la búsqueda y localización de equipos.
* Condicionales: En la comparación de resultados y validación de consultas.
* Cadenas de texto: En la comparación de nombres de equipos.
* Parámetros: En el envío de información entre funciones.

¿Qué ciclos usaste y por qué esos?

Utilicé principalmente ciclos for porque necesito recorrer los arreglos y matrices una cantidad determinada de veces.

* En buscarEquipo, el ciclo recorre los equipos hasta encontrar el nombre solicitado.
* En posicionEquipo, el ciclo busca la posición del equipo dentro del arreglo.
* En mostrarFicha, el ciclo recorre los rivales para mostrar sus resultados.
* En mostrarMatriz, utilizo ciclos for anidados para recorrer filas y columnas de la matriz.

Elegí estos ciclos porque conozco la cantidad de equipos que debo recorrer y permiten organizar mejor la información.

¿Qué constantes usaste y por qué son constantes?

Utilicé la constante MAX_EQUIPOS, que establece el tamaño máximo del arreglo y de la matriz de resultados.

Es una constante porque representa un límite definido del programa y no debe cambiar durante la ejecución.

¿Qué funciones reutilizaste de utilerias.h, de torneo.h o de otro módulo?

Reutilicé las siguientes funciones y elementos:

* textoEnMinusculas: De utilerias.h, para convertir los nombres a minúsculas y compararlos correctamente.
* leerCadena: De utilerias.h, para solicitar al usuario el nombre del equipo.
* Equipo: De torneo.h, para trabajar con los datos y estadísticas de cada equipo.
* MAX_EQUIPOS: De torneo.h, para establecer el límite de equipos.
* mostrarMatriz: Se integra en matriz.h para visualizar los resultados generales del torneo.

También reutilicé la información de la matriz de goles generada por el módulo del torneo.

¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?

Mi módulo maneja dos casos principales de rechazo:

1. El torneo todavía no ha sido simulado: No permite realizar consultas y muestra el mensaje: “Primero debes simular el torneo.”
2. El equipo no existe: Cuando el usuario escribe un nombre que no está registrado, muestra: “Equipo no encontrado:” seguido del nombre ingresado.

También la función buscarEquipo devuelve nullptr cuando no encuentra coincidencias.

5. Receta

INICIO
1. Recibir el arreglo de equipos y la matriz de goles.
2. Verificar si el torneo ya fue simulado.
3. Si el torneo no ha sido simulado:
   Mostrar "Primero debes simular el torneo".
   Terminar la consulta.
4. Solicitar al usuario el nombre del equipo.
5. Recorrer el arreglo de equipos.
6. Comparar los nombres sin importar mayúsculas
   o minúsculas.
7. Si se encuentra el equipo:
   Guardar su dirección en un apuntador.
8. Si no se encuentra:
   Mostrar "Equipo no encontrado".
9. Obtener la posición del equipo en el arreglo.
10. Mostrar su ficha:
    - Nombre.
    - Partidos jugados.
    - Ganados.
    - Empatados.
    - Perdidos.
    - Goles a favor.
    - Goles en contra.
    - Puntos.
11. Recorrer los demás equipos.
12. Consultar los goles a favor y en contra
    de cada partido.
13. Determinar si ganó, empató o perdió.
14. Mostrar el nombre del rival, marcador
    y resultado.
15. Para mostrar la matriz general:
    15.1. Recorrer las filas de los equipos.
    15.2. Recorrer las columnas de los equipos.
    15.3. Si el equipo juega contra sí mismo,
          mostrar "---".
    15.4. En los demás casos, mostrar
          los goles de ambos equipos.
16. Finalizar.
FIN

¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?

Sí, revisé la lógica de la receta utilizando ejemplos de equipos y resultados. Comprobé que la búsqueda pudiera encontrar los equipos aunque se escribieran con mayúsculas o minúsculas diferentes.

También revisé que los marcadores se mostraran correctamente y que el resultado indicara si el equipo ganó, empató o perdió.

Una parte importante fue verificar que no se mostrara la ficha cuando el torneo todavía no había sido simulado y que la matriz no mostrara un partido contra el mismo equipo.

6. Pruebas

#	Qué probaste	Entrada	Resultado esperado	Resultado obtenido
1	Consultar un equipo existente	Nombre: Tigres	Mostrar su ficha y estadísticas	Se muestra la información del equipo
2	Consultar un equipo inexistente	Nombre: América	Mostrar mensaje de equipo no encontrado	Se muestra el mensaje de rechazo
3	Consultar antes de simular	simulado = false	Mostrar que primero se debe simular el torneo	Se muestra el mensaje correspondiente
4	Comparar nombres	tigres / TIGRES	Reconocer que son el mismo nombre	La comparación es correcta
5	Mostrar la matriz	Equipos y matriz de goles	Mostrar los marcadores ordenados	Se muestran los resultados en filas y columnas

7. Bitácora de dudas y errores

#	Duda o error	Cómo lo resolví
1	Cómo comparar nombres sin importar mayúsculas y minúsculas.	Utilicé textoEnMinusculas para convertir ambos nombres antes de compararlos.
2	Cómo encontrar un equipo y obtener su posición.	Utilicé apuntadores en buscarEquipo y un ciclo for en posicionEquipo.
3	Cómo mostrar correctamente los resultados de cada partido.	Utilicé la matriz de goles y comparé los goles a favor y en contra.

8. Reflexión

¿Qué aprendiste?

Aprendí a trabajar con arreglos, matrices, funciones y apuntadores en C++. También aprendí a buscar información dentro de un arreglo y a utilizar matrices para organizar los resultados de un torneo.

Además, entendí que es importante dividir el programa en diferentes funciones para que el código sea más ordenado y fácil de entender.

¿Qué cambiarías de tu proceso?

Mejoraría la organización del código desde el principio y realizaría pruebas de cada función antes de unirlas con los demás módulos. También agregaría más validaciones para evitar errores cuando el usuario escriba información incorrecta.

De esta manera el programa sería más fácil de utilizar, mantener y mejorar en el futuro.