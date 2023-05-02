#pragma once
#include <citro2d.h>
#include <citro3d.h>
#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

enum class Palo {OROS,COPAS,ESPADAS,BASTOS};

class Carta{
public:
        size_t valor;
        size_t jugadorDeLaCarta;
        C2D_Sprite sprite;
        float px1,px2,py1,py2;
        bool estaMostrandoValor; //esto es de prueba para ver si me detecta las hitboxes :)
        bool isAvailableToPlay; //para cuando se juegue la carta se pone en false, impidiendo que se juegue o se use en los calculos Y mantengo así la integridad de los vector, también podría condicionar que se dibuje o no etccc
        Palo palo;
        bool onTouch(float posx,float posy);
        Carta(size_t valor, float px1, float px2, float py1, float py2, C2D_Sprite spr);
        Carta();
        void setValor(size_t valor);
private:
    void AsignaPalo();
};