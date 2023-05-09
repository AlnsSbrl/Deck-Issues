#pragma once

#include <3ds.h>
#include <stdexcept>
#include <limits>
#include <iostream>
#include "Escena.hpp"

class InputHandler
{
  
public:
    InputHandler();
    InputHandler(Escena* escena);
    //TODO: que la escena NO contenga inputhandler. Inputhandler será un parámetro de la clase partida, así no se incluyen entre sí
    //el inputhandler debería poder acceder a la escena para llamar a funciones específicas con cada input
    Escena* escena;
    touchPosition touch;
    bool gestionaInputs();
    virtual void onDownPress();
    virtual void onLeftPress();
    virtual void onRightPress();
    virtual void onUpPress();
    virtual void onA_ButtonPress();
    virtual void onB_ButtonPress();
    virtual void onX_ButtonPress();
    virtual void onY_ButtonPress();
    virtual void onTouch();
    virtual void onLRSelect_buttonsPress()final; //esto será para terminar la app I guess
    virtual void onStartPress();
    virtual void onSelectPress();
    //hay infinidades de combinaciones tbh, no creo ni que use todas estas
};


