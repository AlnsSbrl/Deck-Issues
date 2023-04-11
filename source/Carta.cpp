#include "Carta.hpp"

//constructor
Carta::Carta(size_t valor, float px1, float px2,float py1,float py2, C2D_Sprite spr){
     this->valor=valor;
     this->px1=px1;
     this->px2=px2;
     this->py1=py1;
     this->py2=py2;
     this->spr=spr;
     this->palo=static_cast<Palo>((valor-1)/10);
}

//detecta si se toca dentro de la carta
bool Carta::onTouch(float posx,float posy){
     return posx<=px1&&posx>=px2&&posy<=py1&&posy>=py2;
}