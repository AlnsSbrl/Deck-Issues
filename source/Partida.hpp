#pragma once
#include "Jugador.hpp"
#include "Carta.hpp"
#include "InputHandler.hpp"

#define DISPLAY_TRANSFER_FLAGS \
	(GX_TRANSFER_FLIP_VERT(0) | GX_TRANSFER_OUT_TILED(0) | GX_TRANSFER_RAW_COPY(0) | \
	GX_TRANSFER_IN_FORMAT(GX_TRANSFER_FMT_RGBA8) | GX_TRANSFER_OUT_FORMAT(GX_TRANSFER_FMT_RGB8) | \
	GX_TRANSFER_SCALING(GX_TRANSFER_SCALE_NO))

class Partida{
public:
    
    C3D_RenderTarget* top;
    C3D_RenderTarget* bot;
    Escena escena;
    C2D_SpriteSheet spriteSheet;
    InputHandler inputHandler;
    //en una partida se juegan 3 bazas, el ganador de una baza juega la siguiente carta, hasta terminar
    //pero quien echa en la primera baza? pues el siguiente al jugador que repartió las cartas.
    //En este juego se irá rotando, cada 4 partidas el jugador lanzaría la primera carta en la primera baza (esto da bastante ventaja en el juego)
    bool terminaJuego;
    Partida();
    //void cambiaEscena(TipoEscena nuevaEscena);
    void dibujaEscena();
    void empiezaPartida();
    void finalizaPartida();

};