#pragma once
#include <vector>
#include "Carta.h"
class Jugador
{
public:
    std::vector<Carta> cartas;
    std::vector<Carta> cartasPermitidas;
    Carta cartaJugada;
    bool isPlayer;
    bool CalculoCartasPermitidas(Carta* primeraCartaJugada, Carta* cartaQueGanaActualmente, Palo triunfo);
    Carta lanzaCarta();
    void nuevaMano();
    Jugador(std::vector<Carta> cartas, bool isPlayer);
    Jugador();
};

