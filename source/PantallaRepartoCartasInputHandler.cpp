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
            if(scn->jugadores[3].cartas[i]->onTouch(this->touch.px,this->touch.py)){
                if(scn->juegaCartaJugador(scn->jugadores[3].cartas[i])){
                    scn->jugadores[3].lanzaCarta(scn->jugadores[3].cartaJugada);
                    scn->terminaTurno();
                }
            };
            //todo: hacer prueba para ver si me gestiona esto correctamente :)
        }   
    }
};

//haria lo mismo que el onTouch() seleccionando la carta de la izquierda
void PantallaRepartoCartasInputHandler::onLeftPress(){
    if(PantallaRepartoCartas* scn = dynamic_cast<PantallaRepartoCartas*>(this->escena)){
        if(scn->juegaCartaJugador(scn->jugadores[3].cartas[0])){
            scn->jugadores[3].lanzaCarta(scn->jugadores[3].cartaJugada);
            scn->terminaTurno();
        }
    }
}

//haria lo mismo que el onTouch() seleccionando la carta de la derecha
void PantallaRepartoCartasInputHandler::onRightPress(){
    if(PantallaRepartoCartas* scn = dynamic_cast<PantallaRepartoCartas*>(this->escena)){
        if(scn->juegaCartaJugador(scn->jugadores[3].cartas[2])){
            scn->jugadores[3].lanzaCarta(scn->jugadores[3].cartaJugada);
            scn->terminaTurno();
        }
    }
}

//haria lo mismo que el onTouch() seleccionando la carta del medio
void PantallaRepartoCartasInputHandler::onUpPress(){
    if(PantallaRepartoCartas* scn = dynamic_cast<PantallaRepartoCartas*>(this->escena)){
        if(scn->juegaCartaJugador(scn->jugadores[3].cartas[1])){
            scn->jugadores[3].lanzaCarta(scn->jugadores[3].cartaJugada);
            scn->terminaTurno();
        }
    }
}
