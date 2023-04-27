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
    //necesita como referencia la escena que gestiona, para poder modificar una booleana para cambiar de escena (igual podría haber puesto la booleana DENTRO de inputhandler...por qué no lo pensé antes? quién sabe)
    Escena* escena;
    touchPosition touch;
    void gestionaInputs();
    virtual void onDownPress();
    virtual void onLeftPress();
    virtual void onRightPress();
    virtual void onUpPress();
    virtual void onA_ButtonPress();
    virtual void onB_buttonPress();
    virtual void onX_buttonPress();
    virtual void onY_buttonPress();
    virtual void onTouch();
    virtual void onLRSelect_buttonsPress()final; //esto será para terminar la app I guess
    virtual void onStartPress();
    virtual void onSelectPress();
    //hay infinidades de combinaciones tbh, no creo ni que use todas estas
};


