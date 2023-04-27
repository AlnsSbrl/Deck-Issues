#pragma once
#include "InputHandler.hpp"
#include "PantallaPrincipal.hpp"

class PantallaPrincipalInputHandler: public InputHandler{

public:
    PantallaPrincipalInputHandler(PantallaPrincipal* escena);
    virtual void onA_ButtonPress()override;  
    virtual void onTouch()override;
    virtual void onStartPress()override;
    virtual void onSelectPress()override;
};

PantallaPrincipalInputHandler::PantallaPrincipalInputHandler(PantallaPrincipal* escena){
    this->escena=escena;
}
