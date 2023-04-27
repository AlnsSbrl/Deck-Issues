# Deck Issues
Es un juego de cartas de la baraja española para Nintendo 3DS desarrollado con DevKitPro en C/C++.
## Instalación
Existen dos opciones para poder jugar al juego:
- >Se necesita un emulador de 3DS como [Citra](https://citra-emu.org/). Tras instalar y ejecutar el emulador, simplemente se abre el archivo `.3dsx`.
- >De querer jugar en una consola, esta tendría que haber sido modificada siguiendo [estos pasos](https://3ds.hacks.guide/). Tras ello se pone el archivo `.3dsx` en la tarjeta SD en la carpeta `/3ds`. Tras insertar la SD de nuevo en la consola, se podrá abrir el juego accediendo a él desde el `homebrew launcher`.
- >En el caso de querer modificar el juego, es necesario descargarse las librerías de [DevKitPro](https://devkitpro.org/wiki/Getting_Started). Configurando el IDE para detectar dependencias, se podrán modificar los archivos C/C++ en `source` o los sprites que se emplean en `gfx`, sin olvidar que hay que incluirlos en `gfx\sprites.t3s`. Para compilar el proyecto y generar los archivos para poder jugarlo es necesario usar la `cmd`, situarnos en la carpeta del proyecto y ejecutar el comando `make`. Si todo funciona correctamente se generarán los archivos necesarios, incluido el archivo `.3dsx` que es el empleado para propiamente jugar al juego. 

## Contenido
Ahora mismo el juego solo dispone de una pantalla. Al abrir el juego se reparten las cartas y se colocan en la pantalla superior ocultándolas, si son de la futura IA, o en la pantalla inferior mostrando su valor, si son las del jugador. En todo momento se aseguran que las cartas repartidas no se repiten.

## Actualizaciones: 

(12/04) La jugabilidad no ha cambiado en absoluto. Se ha modularizado completamente el proyecto en clases siguiendo el estándar de C++, separando las clases en headers y en archivos cpp. Se han creado los métodos básicos que seguirán las clases dentro del juego y se ha modificado el mainLoop del juego para detectar cuándo se toca una carta, en teoría dándole la vuelta, ~~pero esto sólo se comprobará si funciona cuando se arreglen los errores de compilación~~ :)

(21/04) Se creó la rama [Debug Changes](https://github.com/AlnsSbrl/Deck-Issues/tree/debug-changes) para situar un proyecto de consola en Visual Studio que se usará para encontrar errores de lógica.

(23/04) Se hicieron cambios en las clases Jugador y Partida, así como los métodos usados al repartir cartas para asegurar que cada jugador tiene 3 cartas y que éstas son las mismas (mismo objeto) que las que están en la colección de cartas repartidas en la partida. Estos cambios fueron introducidos porque tras la modularización en distintas clases no se pueden apreciar las cartas en pantalla, como sí ocurría en el primer commit. Estos cambios parecen no haber afectado en el resultado.

(27/04) Tras haber averiguado que los bugs que impedían ver algo por pantalla al ejecutar el archivo `.3dsx` se debían a una fórmula y un bucle mal hechos, se ha seguido con el desarrollo de las clases del juego. Se ha introducido la clase base `InputHandler`, que tiene funciones para las distintas combinaciones de teclas que se pretenden emplear en todo el juego. También se ha creado la clase base `Escena`, que tendrá los contenidos que se quieran representar en esa escena a su disposición. Cada escena tendrá su inputhandler y se aprovechará el polimorfismo para poder ir cambiando de escenas y de mapeos de botones con facilidad.

<img src=https://i.kym-cdn.com/photos/images/original/001/043/243/419.gif>
