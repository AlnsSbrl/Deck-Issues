#pragma once
#include "InputHandler.hpp"
#include "PantallaRepartoCartas.hpp"

class PantallaRepartoCartasInputHandler: public InputHandler{

public:
    PantallaRepartoCartasInputHandler();
    PantallaRepartoCartasInputHandler(PantallaRepartoCartas* escena);
    virtual void onA_ButtonPress()override;  
    virtual void onTouch()override;
    virtual void onStartPress()override;
    virtual void onB_ButtonPress()override;
    virtual void onLeftPress() override;
    virtual void onRightPress() override;
    virtual void onUpPress() override;
};

PantallaRepartoCartasInputHandler::PantallaRepartoCartasInputHandler(){

};
PantallaRepartoCartasInputHandler::PantallaRepartoCartasInputHandler(PantallaRepartoCartas* escena){
    this->escena=escena;
};
