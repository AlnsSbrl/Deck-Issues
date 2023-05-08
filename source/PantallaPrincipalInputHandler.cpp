#include "PantallaPrincipalInputHandler.hpp"

PantallaPrincipalInputHandler::PantallaPrincipalInputHandler(){

};

PantallaPrincipalInputHandler::PantallaPrincipalInputHandler(Escena* escena){
    this->escena=escena;
};
void PantallaPrincipalInputHandler::onA_ButtonPress(){
    escena->cambiaEscena=true;
};

void PantallaPrincipalInputHandler::onTouch(){
    InputHandler::onTouch();
    escena->cambiaEscena=true;
};

void PantallaPrincipalInputHandler::onStartPress(){
    escena->cambiaEscena=true;
};

void PantallaPrincipalInputHandler::onSelectPress(){
    //todo: menu de opciones
};