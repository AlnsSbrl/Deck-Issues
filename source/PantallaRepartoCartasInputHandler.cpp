#include "PantallaRepartoCartasInputHandler.hpp"

void PantallaRepartoCartasInputHandler::onStartPress(){
    if(PantallaRepartoCartas* scn = dynamic_cast<PantallaRepartoCartas*>(this->escena)){
        scn->repartirCartas();
    }
}

void PantallaRepartoCartasInputHandler::onB_ButtonPress(){
    escena->cambiaEscena=true;
    escena->nuevaEscena=INICIO;
}

void PantallaRepartoCartasInputHandler::onA_ButtonPress(){

};

void PantallaRepartoCartasInputHandler::onTouch(){

};