#include "PantallaPrincipalInputHandler.hpp"

PantallaPrincipalInputHandler::PantallaPrincipalInputHandler(PantallaPrincipal* escena){
    this->escena=escena;
};
void PantallaPrincipalInputHandler::onA_ButtonPress(){
    escena->cambiaEscena=true;
};

void PantallaPrincipalInputHandler::onTouch(){
    escena->cambiaEscena=true;
};

void PantallaPrincipalInputHandler::onStartPress(){
    escena->cambiaEscena=true;
};

void PantallaPrincipalInputHandler::onSelectPress(){
    //todo: menu de opciones
};