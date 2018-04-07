# Sala de juegos

Es un progama de consola escrito en **C** que permite inscribir jugadores para participar en los diferentes juegos, ver la clasificación, y grabar los datos en un archivo *.txt*. Consta de 3 juegos: palabras encadenadas, números curiosos y siguiente elemento. Para usarlo es necesario compilar el codigo.

## Intrucciones de uso

* Pulsar la opción ‘1’ del menú principal permite introducir 1 o más jugadores en el programa. Se solicitarán los datos del primer jugador y se preguntará si se desea solicitar los datos del siguiente (‘s’) y así sucesivamente hasta pulsar la opción ‘n’. Si se pulsa la opción ‘1’ y ya se han introducido los 5 jugadores se mostrará un mensaje indicando que se ha llegado al máximo de jugadores y no se pueden introducir más. A cada jugador se le puede aplicar un coeficiente de handicap.

* Pulsar la opción ‘2’ permite ingresar en el menú de juegos. Se seleccionara el juego que se desea y se introducirá el número de los jugadores que participen. 

Para jugar a las palabras encadenadas se deberá introducir una palabra cuyos dos primeros caracteres concidan con los dos ultimos de la palabra anteriror. El juego finaliza cuando uno de los dos jugadores comete un error.

Para jugar a números curiosos el jugador A introducirá dos números y el jugador B deberá averiguar si lo es o no. Un número es curioso cuando cumple que la suma de las cifras del primer número elevadas al segundo número da como resultado el primer número. Por ejemplo, 153 y 3:
```
1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
```
Para juagr al elemento siguiente (juego de un jugador) se deberá introducir el siguiente elemento de la serie de Fibonacci al mostrado en la pantalla.

* Pulsar la opción ‘3’ mostrará la clasificación de los jugadores ordenada por el número de puntos de mayor a menor.

* Pulsar la opción ‘4’ permite la opción de grabar los datos en un fichero con extensión ‘txt’.

* Pulsar la opción ‘5’ permite salir del programa.

## Autor

* **Luis Cambero** - [lcambero](https://github.com/lcambero)

## Ultima actualización

Viernes 11 de diciembre de 2015

## Licencia

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
