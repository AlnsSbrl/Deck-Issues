#pragma once
#include "Jugador.hpp"
#include <3ds.h>
#include <citro2d.h>
#include <citro3d.h>

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 240
#define CARTAS_TOTALES 12

enum TipoEscena {INICIO, REPARTO_INICIAL,MUEVE_CPU,MUEVE_PLAYER,TERMINA_BAZA,PREGUNTA_SEGUIR,FINAL}; //ya iré viendo cuáles tener con el tiempo

class Escena
{
public:
    Escena();
    Escena(C2D_SpriteSheet* spriteSheet);
    //~Escena();
    TipoEscena numEscena; //representa a ESTA escena
    TipoEscena nuevaEscena; //escena a la que CAMBIA al terminar 
    bool cambiaEscena;
    bool hasStarted;
    std::vector<Jugador> jugadores;
    std::vector<Carta> cartasDeLosJugadores;
    std::vector<size_t> cartasRepartidas;
    Carta* cartaTriunfo;
    Carta* cartaGanadora;
    Carta* cartaOpener;
    int playerToShuffle;
    int playerToPlay;
    size_t turno;
    bool seHaTerminadoLaBaza;
    //void operator++(int playerToShuffle);//queria ver de usar este overload para controlar playerToPlay y playerThatShuffled
    C2D_SpriteSheet* spriteSheet;//que apunte al de Partida
    
    void dibuja(C3D_RenderTarget *topScreen, C3D_RenderTarget *bottomScreen);
    void actualizaEscena(TipoEscena movimiento);
    void terminaEscena();
    void terminaTurno();
    void repartirCartas(); //TODO-> asignar el que reparte++ y playerToPlay accordingly
    void muestraVerdaderoValor(Carta* carta);
    void ocultaValor(Carta* carta);
    void finalizaBaza();
    void setNextPlayerToPlay();
    void setNextPlayerToShuffle();
    bool juegaCartaJugador(Carta* carta);
    //void vuelveAtras();
    private:
    size_t numImages;
    C2D_TextBuf textBuffer;
    C2D_Font font;
};




