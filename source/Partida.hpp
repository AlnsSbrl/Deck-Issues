#include <vector>
#include <3ds.h>
#include "Jugador.hpp"
#include "Carta.hpp"

class Partida{
public:
    Jugador jugadores[4];
    std::vector<Carta> cartasRepartidas;
    size_t playerThatShuffled;
    size_t playerToPlay;
    static C2D_SpriteSheet spriteSheet;
    //en una partida se juegan 3 bazas, el ganador de una baza juega la siguiente carta, hasta terminar
    //pero quien echa en la primera baza? pues el siguiente al jugador que repartió las cartas.
    //En este juego se irá rotando, cada 4 partidas el jugador lanzaría la primera carta en la primera baza (esto da bastante ventaja en el juego)
    void repartirCartas();
}