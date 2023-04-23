#include <citro2d.h>
#include <citro3d.h>
#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Carta.hpp"
#include <vector>

#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador
{
public:
    std::vector<Carta*> cartas;
    std::vector<Carta*> cartasPermitidas;
    Carta cartaJugada;
    bool isPlayer;
    bool CalculoCartasPermitidas(Carta *primeraCartaJugada, Carta *cartaQueGanaActualmente, Palo triunfo);
    Carta* lanzaCarta();
    Jugador(Carta* carta, Carta* carta2, Carta* carta3);
    Jugador();
};

#endif