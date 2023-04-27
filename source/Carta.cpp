#include "Carta.hpp"

Carta::Carta(size_t valor, float px1, float px2,float py1,float py2, C2D_Sprite spr){
     this->valor=valor;
     this->px1=px1;
     this->px2=px2;
     this->py1=py1;
     this->py2=py2;
     this->sprite=spr;
     this->palo=static_cast<Palo>((valor-1)/10);
}

Carta::Carta() {
    this->valor = 0;
    this->px1 = 0;
    this->px2 = 0;
    this->py1 = 0;
    this->py2 = 0;
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

//detecta si se toca dentro de la carta
bool Carta::onTouch(float posx,float posy){
     return posx>=px1&&posx<=px2&&posy>=py1&&posy<=py2;
}
//por el momento la funcion onTouch no parece funcionar
//...pensandolo un poco NORMAL, px1 es menor que px2 entonces es imposible que posx cumpla ambas condiciones