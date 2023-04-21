#include "Carta.h"
Carta::Carta() {
}

void Carta::setValor(size_t valor)
{
    this->valor = valor;
    AsignaPalo();
}

void Carta::AsignaPalo()
{
    switch ((this->valor - 1) / 10)
    {
    case 0:
        this->palo = Palo::OROS;
        break;
    case 1:
        this->palo = Palo::COPAS;
        break;
    case 2:
        this->palo = Palo::ESPADAS;
        break;
    case 3:
        this->palo = Palo::BASTOS;
        break;
    }
}

bool Carta::onTouch(float posx, float posy) {
    return posx <= px1 && posx >= px2 && posy <= py1 && posy >= py2;
}

