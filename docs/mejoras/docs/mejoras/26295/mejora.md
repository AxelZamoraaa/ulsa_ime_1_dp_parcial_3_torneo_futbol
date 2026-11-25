**Matrícula:** 26295 
**Título de la propuesta:** Registro de equipos

## 1. Impacto

Es una mejora, cuando el usuario registra un equipo, el programa solo dice "Equipo registrado". El usuario tiene que ir a "Mostrar equipos" para saber cuantos le faltan antes de poder simular, que necesita los 6.

Con la mejora, despues de cada registro el programa dice cuantos equipos faltan (por ejemplo, "Faltan 4 equipos por registrar"). Cuando ya estan los 6, avisa que ya se puede simular. Beneficia a quien usa el programa, porque sabe en que paso va sin revisar la lista.

## 2. Qué implica en el diseño

Solo cambia una funcion del modulo 1: registrarEquipo, en registro.h. No cambian los registros, los arreglos, las constantes, los demas modulos ni el menu.

- Cambia registrarEquipo: al final, despues de aumentar total, calcula cuantos faltan con MAX_EQUIPOS - total e imprime el mensaje con un if. Usa la constante MAX_EQUIPOS y no el numero 6 escrito, para que si cambia el tamaño del torneo el mensaje siga bien.
- No cambia nada mas: el mensaje es libre (la guia solo fija el formato de los reportes), asi que no afecta el escenario obligatorio ni el formato de ningun reporte.

## 3. Receta

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
8. Mostrar "Equipo registrado" con el nombre y la abreviatura
9. [NUEVO] Si total es menor a MAX_EQUIPOS:
   9.1 [NUEVO] Calcular faltan = MAX_EQUIPOS - total
   9.2 [NUEVO] Mostrar "Faltan (faltan) equipos por registrar"
10. [NUEVO] Si no, mostrar "Ya estan los 6 equipos, puedes simular el torneo"
```