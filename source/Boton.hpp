#pragma once
#include <3ds.h>
#include <citro2d.h>

class Boton{

public:
//no creo ni que haga falta

float px,py;
float width, height;
bool onTouch(float posx,float posy);
void dibuja(); //todo drawrectangle
};