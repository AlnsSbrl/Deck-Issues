#pragma once
#include "Escena.hpp"
#include "Jugador.hpp"
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 240
#define CARTAS_TOTALES 12

class PantallaRepartoCartas: public Escena{
public:
    //C2D_Image topImage;
    //C2D_Image bottomImage;
    //C2D_Text bottomText;
    std::vector<Jugador> jugadores;
    std::vector<Carta> cartasDeLosJugadores;
    std::vector<size_t> cartasRepartidas;
    Carta* cartaTriunfo;
    Carta* cartaGanadora;
    Carta* cartaOpener;
    int playerToShuffle;
    int playerToPlay;
    size_t turno;
    //void operator++(int playerToShuffle);//queria ver de usar este overload para controlar playerToPlay y playerThatShuffled
    C2D_SpriteSheet* spriteSheet;//que apunte al de Partida
    PantallaRepartoCartas(C2D_SpriteSheet* spriteSheet);
    void dibuja(C3D_RenderTarget *topScreen, C3D_RenderTarget *bottomScreen) override;
    void actualizaEscena() override;
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