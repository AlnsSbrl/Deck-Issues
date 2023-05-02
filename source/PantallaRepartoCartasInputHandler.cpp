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
    escena->actualizaEscena();
};

void PantallaRepartoCartasInputHandler::onTouch(){
    if(PantallaRepartoCartas* scn = dynamic_cast<PantallaRepartoCartas*>(this->escena)){
        for (size_t i = 0; i < scn->jugadores[3].cartas.size(); i++)
        {
            /* code */
            if(scn->jugadores[3].cartas[i]->onTouch(this->touch.px,this->touch.py)){
                if(scn->juegaCartaJugador(scn->jugadores[3].cartas[i])){
                    //play the card
                    //next player 
                }
            };
            //todo: hacer prueba para ver si me gestiona esto correctamente :)
        }
        
    }
};