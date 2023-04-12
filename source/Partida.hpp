#include <vector>
#include <3ds.h>
#include "Jugador.hpp"
#include "Carta.hpp"

#ifndef PARTIDA_H
#define PARTIDA_H
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 240
#define CARTAS_TOTALES 12

enum Escena {INICIO, REPARTO_INICIAL,MUEVE_CPU1,MUEVE_CPU2,MUEVE_CPU3,MUEVE_PLAYER,TERMINA_BAZA,PREGUNTA_SEGUIR,FINAL};

class Partida{
public:
    Jugador jugadores[4];
    std::vector<Carta> cartasRepartidas;
    Palo triunfo;
    size_t playerThatShuffled;
    size_t playerToPlay;
    size_t escena;
    static C2D_SpriteSheet spriteSheet;
    //en una partida se juegan 3 bazas, el ganador de una baza juega la siguiente carta, hasta terminar
    //pero quien echa en la primera baza? pues el siguiente al jugador que repartió las cartas.
    //En este juego se irá rotando, cada 4 partidas el jugador lanzaría la primera carta en la primera baza (esto da bastante ventaja en el juego)
    Partida();
    void repartirCartas(); //TODO-> asignar el que reparte++ y playerToPlay accordingly
    void muestraVerdaderoValor(Carta* carta);
    void ocultaValor(Carta* carta);
    void avanzaEscena();

private:
    size_t numImages;
};

#endif