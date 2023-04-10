#include <citro2d.h>
#include <citro3d.h>
#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

enum class Palo {Oros,Copas,Espadas,Bastos};

class Carta{
    public:
        size_t valor;
        C2D_Sprite sprite;
        float px1,px2,py1,py2;
        Palo palo;
    
    bool onTouch(float posx,float posy){
        return posx<=px1&&posx>=px2&&posy<=py1&&posy>=py2;
    }

    
};