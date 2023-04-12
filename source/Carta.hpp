#include <citro2d.h>
#include <citro3d.h>
#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

#ifndef CARTA_H
#define CARTA_H

enum class Palo {OROS,COPAS,ESPADAS,BASTOS};

class Carta{
public:
        size_t valor;
        C2D_Sprite sprite;
        float px1,px2,py1,py2;
        bool estaMostrandoValor; //esto es de prueba para ver si me detecta las hitboxes :)
        Palo palo;
        bool onTouch(float posx,float posy);
        Carta(size_t valor, float px1, float px2, float py1, float py2, C2D_Sprite spr);
        Carta();
        void setValor(size_t valor);
private:
    void AsignaPalo();
};
#endif