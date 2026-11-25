Propuesta de mejora elaborada por: PABLO MUSSA

Matrícula: 026165

Título de la propuesta: Sistema de reconocimiento de premios individuales para los jugadores destacados del torneo.

1. Impacto

La propuesta es una mejora, porque agrega una nueva función al programa que permite reconocer el desempeño individual de los jugadores destacados al finalizar el torneo.

El objetivo es identificar a los jugadores que tuvieron un mejor rendimiento y mostrar sus premios individuales, por ejemplo: mejor goleador, jugador más destacado y mejor portero.

Esta mejora beneficia a los jugadores, ya que permite reconocer su esfuerzo y participación, y también a los organizadores del torneo, porque facilita la entrega de reconocimientos sin tener que revisar manualmente todas las estadísticas.

Además, hace que el programa sea más completo, ya que no solamente muestra los resultados de los equipos, sino que también reconoce el desempeño individual de los participantes.

2. Qué implica en el diseño

Para implementar esta mejora se necesitan agregar y modificar algunas partes del programa:

* Registros: Se agregaría información para identificar a los jugadores y almacenar sus estadísticas individuales, como goles, atajadas y rendimiento durante el torneo.
* Arreglos: Se utilizaría un arreglo para guardar los datos de los jugadores y poder recorrerlos para identificar quién cumple con los requisitos de cada premio.
* Constantes: Se podrían agregar constantes para establecer la cantidad máxima de jugadores que puede registrar el programa.
* Funciones: Se agregarían funciones para comparar las estadísticas de los jugadores y determinar quién obtiene cada premio individual.
* Menú: Se agregaría una opción para consultar los premios individuales al finalizar la simulación del torneo.

Estos cambios permiten ampliar el funcionamiento del programa sin afectar las funciones que ya existen, como la consulta de equipos, la ficha de resultados y la matriz de goles.

3. Receta

INICIO
1. Registrar los equipos del torneo.
2. Registrar los jugadores de cada equipo. [NUEVO]
3. Guardar las estadísticas individuales de cada jugador. [NUEVO]
4. Simular los partidos del torneo.
5. Actualizar los resultados y estadísticas de los equipos.
6. Actualizar las estadísticas individuales de los jugadores. [NUEVO]
7. Mostrar la tabla de posiciones.
8. Mostrar la matriz de resultados.
9. Mostrar el menú principal.
10. Agregar la opción "Premios individuales". [NUEVO]
11. Si el usuario selecciona premios individuales:
    11.1. Verificar que el torneo ya haya sido simulado.
    11.2. Recorrer el arreglo de jugadores. [NUEVO]
    11.3. Comparar los goles anotados por cada jugador. [NUEVO]
    11.4. Identificar al jugador con más goles. [NUEVO]
    11.5. Comparar las estadísticas de los porteros. [NUEVO]
    11.6. Identificar al jugador con mejor rendimiento. [NUEVO]
    11.7. Mostrar los ganadores de cada premio individual. [NUEVO]
12. Permitir consultar nuevamente los resultados o los premios.
13. Finalizar el programa.
FIN