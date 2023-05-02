#include "PantallaFinalPartida.hpp"

bool PantallaFinalPartida::onTouch(float posx,float posy){
    for (size_t i = 0; i < botones.size(); i++)
    {
        if(botones[i].onTouch(posx, posy)){
            this->cambiaEscena=true;
            this->nuevaEscena=i==0?REPARTO_INICIAL:INICIO;
            //TODO MOVER AL HANDLER, para qué hago 90 funciones ontouch jjjjjjj 
        }; //todo asignar a cada on touch algo 
    }
}


PantallaFinalPartida::PantallaFinalPartida(std::vector<Jugador>* xogadors){
    this->jugadores=xogadors; //para saber quien gana o asi IGUESS
};
