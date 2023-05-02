#pragma once
#include "Escena.hpp"
#include "Jugador.hpp"
#include "Boton.hpp"

class PantallaFinalPartida: public Escena{
public:
    std::vector<Boton> botones;
    C2D_Image topImage;
    C2D_Image bottomImage;
    PantallaFinalPartida(bool didPlayerWin);
};