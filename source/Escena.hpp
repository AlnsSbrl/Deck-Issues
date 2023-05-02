#pragma once
#include <3ds.h>
#include <citro2d.h>
#include <citro3d.h>
enum TipoEscena {INICIO, REPARTO_INICIAL,MUEVE_CPU1,MUEVE_CPU2,MUEVE_CPU3,MUEVE_PLAYER,TERMINA_BAZA,PREGUNTA_SEGUIR,FINAL}; //ya iré viendo cuáles tener con el tiempo

class Escena
{
public:
    Escena();
    //~Escena();
    TipoEscena numEscena; //representa a ESTA escena
    TipoEscena nuevaEscena; //escena a la que CAMBIA al terminar 
    bool cambiaEscena;
    virtual void dibuja(C3D_RenderTarget* topScreen,C3D_RenderTarget* bottomScreen);
    virtual void actualizaEscena();
    virtual void terminaEscena();
};




