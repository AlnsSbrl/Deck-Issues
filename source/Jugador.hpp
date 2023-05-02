#pragma once
#include "Carta.hpp"

class Jugador
{
public:
    std::vector<Carta*> cartas;
    std::vector<Carta*> cartasPermitidas;
    Carta* cartaJugada;
    bool isPlayer;
    bool hasWon;
    float posXLanzamiento, posYLanzamiento; //cuando se juega una carta se moverá el sprite a ese sitio??
    bool CalculoCartasPermitidas(Carta *primeraCartaJugada, Carta *cartaQueGanaActualmente, Palo triunfo);
    Carta* lanzaCarta(Carta* carta=0);//puedo poner que esto reciba como parametro la carta a lanzar, pero si es nula que siga funcionando como hasta ahora??
    Jugador(Carta* carta, Carta* carta2, Carta* carta3);
    Jugador();
};