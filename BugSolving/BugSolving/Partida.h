#pragma once
#include "Jugador.h"
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 240
#define CARTAS_TOTALES 12
enum Escena { INICIO, REPARTO_INICIAL, MUEVE_CPU1, MUEVE_CPU2, MUEVE_CPU3, MUEVE_PLAYER, TERMINA_BAZA, PREGUNTA_SEGUIR, FINAL };

class Partida {
public:
    std::vector<Jugador> jugadores;
    std::vector<Carta> cartasDeLosJugadores;
    std::vector<size_t> cartasRepartidas;
    Carta* cartaTriunfo;
    size_t playerThatShuffled;
    size_t playerToPlay;
    size_t escena;
    //static C2D_SpriteSheet spriteSheet;
    int spriteSheet[40];
    //en una partida se juegan 3 bazas, el ganador de una baza juega la siguiente carta, hasta terminar
    //pero quien echa en la primera baza? pues el siguiente al jugador que reparti� las cartas.
    //En este juego se ir� rotando, cada 4 partidas el jugador lanzar�a la primera carta en la primera baza (esto da bastante ventaja en el juego)
    Partida();
    void repartirCartas(); //TODO-> asignar el que reparte++ y playerToPlay accordingly
    void muestraVerdaderoValor(Carta* carta);
    void ocultaValor(Carta* carta);
    void avanzaEscena();

private:
    size_t numImages;
};

