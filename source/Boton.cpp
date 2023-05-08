#include "Boton.hpp"

bool Boton::onTouch(float posx, float posy){
    return posx>=this->px&&posx<=(this->px+this->width)&& posy>=this->py && posy<=(this->py+this->height); 
    //no sé si estartía bien así, tengo que comprobar el sistema de coordenadas empleado por la pantalla de la ds
}

void Boton::dibuja(){
    C2D_DrawRectangle(px,py,0,width,height,0,0,0,0);//esos son los colores??
}