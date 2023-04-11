# Deck Issues
Es un juego de cartas de la baraja española para Nintendo 3DS desarrollado con DevKitPro en C/C++.
## Instalación
Existen dos opciones para poder jugar al juego:
- >Se necesita un emulador de 3DS como [Citra](https://citra-emu.org/). Tras instalar y ejecutar el emulador, simplemente se abre el archivo `.3dsx`.
- >De querer jugar en una consola, esta tendría que haber sido modificada siguiendo [estos pasos](https://3ds.hacks.guide/). Tras ello se pone el archivo `.3dsx` en la tarjeta SD en la carpeta `/3ds`. Tras insertar la SD de nuevo en la consola, se podrá abrir el juego accediendo a él desde el `homebrew launcher`.
- >En el caso de querer modificar el juego, es necesario descargarse las librerías de [DevKitPro](https://devkitpro.org/wiki/Getting_Started). Configurando el IDE para detectar dependencias, se podrán modificar los archivos C/C++ en `source` o los sprites que se emplean en `gfx`, sin olvidar que hay que incluirlos en `gfx\sprites.t3s`. Para compilar el proyecto y generar los archivos para poder jugarlo es necesario usar la `cmd`, situarnos en la carpeta del proyecto y ejecutar el comando `make`. Si todo funciona correctamente se generarán los archivos necesarios, incluido el archivo `.3dsx` que es el empleado para propiamente jugar al juego. 

## Contenido
Ahora mismo el juego solo dispone de una pantalla. Al abrir el juego se reparten las cartas y se colocan en la pantalla superior ocultándolas, si son de la futura IA, o en la pantalla inferior mostrando su valor, si son las del jugador. En todo momento se aseguran que las cartas repartidas no se repiten.

## Última actualización (11/04) v2

La jugabilidad no ha cambiado en absoluto. Se han cambiado las clases dividiendo la definición en headers (.hpp) y la implementación en archivos cpp, siguiendo así el estándar en C++ para proyectos grandes.

<img src=https://i.kym-cdn.com/photos/images/original/001/043/243/419.gif>
