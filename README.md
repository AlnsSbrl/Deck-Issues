# Deck Issues
Es un juego de cartas de la baraja española para Nintendo 3DS desarrollado con DevKitPro en C/C++.
## Instalación
Existen dos opciones para poder jugar al juego:
- >Se necesita un emulador de 3DS como [Citra](https://citra-emu.org/). Tras instalar y ejecutar el emulador, simplemente se abre el archivo `.3dsx`.
- >De querer jugar en una consola, esta tendría que haber sido modificada siguiendo [estos pasos](https://3ds.hacks.guide/). Tras ello se pone el archivo `.3dsx` en la tarjeta SD en la carpeta `/3ds`. Tras insertar la SD de nuevo en la consola, se podrá abrir el juego accediendo a él desde el `homebrew launcher`.


## Contenido
Ahora mismo el juego solo dispone de una pantalla. Al abrir el juego se reparten las cartas y se colocan en la pantalla superior ocultándolas, si son de la futura IA, o en la pantalla inferior mostrando su valor, si son las del jugador. En todo momento se aseguran que las cartas repartidas no se repiten.
