#include <citro2d.h>
#include <citro3d.h>
#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "carta.hpp"

class Jugador
{
public:
    std::vector<Carta> cartas;
    std::vector<Carta> cartasPermitidas;
    Carta cartaJugada;
    bool isPlayer;
    bool CalculoCartasPermitidas(Carta *primeraCartaJugada, Carta *cartaQueGanaActualmente, Palo triunfo);
    Carta lanzaCarta();
    
};