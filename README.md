# Bug Solving

Esta rama es un proyecto de consola de C++ en Visual Studio, diseñado para depurar los fallos de lógica que pueden ir ocurriendo, aislándolos del uso de las librerías de 3ds y de las que manejan gráficos.

Tras conseguir compilar el proyecto siguió habiendo errores y, debido a la dificultad que existe en encontrar errores al probarlo en un emulador o una consola, al no existir ni una depuradora ni la opción más sencilla de logs sin tener que manejar cómo dibujar el texto y su posición en pantalla, se tomó la decisión de llevar este proyecto en paralelo.

## Errores encontrados
Se han encontrado los siguientes errores:
- > (21/04) En la clase `Partida` hay una función que reparte 3 cartas entre los jugadores. Tras una inspección, se comprobó que las cartas del último jugador de la colección no daban un valor correcto debido a que no estaban inicializadas: esto se debía a un error en la fórmula. Esto podría generar un problema en la ejecución del juego, ya que una de las primeras funciones que se ejecutaban en el bucle principal era la función `onTouch()` precisamente de las cartas del último jugador, que sería el player.
- > (26/04) En la clase `Partida` se hizo un bucle para crear el vector de jugadores, creando un jugador y asignándole los punteros de las cartas que tendrían cada uno de la colección. El bucle tenía mal especificado hasta cuando contar y creaba 3 jugadores en vez de 4... esto podría llevar a un error similar al del día `21/04`, pero siendo el jugador 3 el que estaría out of bounds, no las cartas.

## "Tests" hechos
- > (21/04) comprobación de que todas las cartas de cada jugador tenían valor :x:
- > (26/04) comprobación de que la partida tenía el número adecuado de jugadores :x:
- > (26/04) comprobación de que las cartas de cada jugador eran las mismas que las de la colección de cartas de la partida :heavy_check_mark:
