#pragma once
#include "Jugador.hpp"
#include "Carta.hpp"

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 240
#define CARTAS_TOTALES 12
#define MAX_SPRITES 12
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 240
#define DISPLAY_TRANSFER_FLAGS \
	(GX_TRANSFER_FLIP_VERT(0) | GX_TRANSFER_OUT_TILED(0) | GX_TRANSFER_RAW_COPY(0) | \
	GX_TRANSFER_IN_FORMAT(GX_TRANSFER_FMT_RGBA8) | GX_TRANSFER_OUT_FORMAT(GX_TRANSFER_FMT_RGB8) | \
	GX_TRANSFER_SCALING(GX_TRANSFER_SCALE_NO))

enum Escena {INICIO, REPARTO_INICIAL,MUEVE_CPU1,MUEVE_CPU2,MUEVE_CPU3,MUEVE_PLAYER,TERMINA_BAZA,PREGUNTA_SEGUIR,FINAL};

class Partida{
public:
    std::vector<Jugador> jugadores;
    std::vector<Carta> cartasDeLosJugadores;
    std::vector<size_t> cartasRepartidas;
    Carta* cartaTriunfo;
    size_t playerThatShuffled;
    size_t playerToPlay;
    size_t escena;
    C2D_SpriteSheet spriteSheet;
    C3D_RenderTarget* top;
    C3D_RenderTarget* bot; 
    //en una partida se juegan 3 bazas, el ganador de una baza juega la siguiente carta, hasta terminar
    //pero quien echa en la primera baza? pues el siguiente al jugador que repartió las cartas.
    //En este juego se irá rotando, cada 4 partidas el jugador lanzaría la primera carta en la primera baza (esto da bastante ventaja en el juego)
    Partida();
    void repartirCartas(); //TODO-> asignar el que reparte++ y playerToPlay accordingly
    void muestraVerdaderoValor(Carta* carta);
    void ocultaValor(Carta* carta);
    void avanzaEscena();
    void dibujaEscena();

private:
    size_t numImages;
};