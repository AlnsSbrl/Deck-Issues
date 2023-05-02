#pragma once
#include "Escena.hpp"
#include "Jugador.hpp"
#include "Boton.hpp"

class PantallaFinalPartida: public Escena{
public:
    std::vector<Boton> botones;
    std::vector<Jugador>* jugadores;
    PantallaFinalPartida(std::vector<Jugador>* xogadors);
    bool onTouch(float posx,float posy); //igual ponerselo a una clase pequeña but idk
};