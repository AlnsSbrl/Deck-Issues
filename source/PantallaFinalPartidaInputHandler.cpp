#include "PantallaFinalPartidaInputHandler.hpp"

PantallaFinalPartidaInputHandler::PantallaFinalPartidaInputHandler(PantallaFinalPartida *escena)
{
    this->escena = escena;
};

void PantallaFinalPartidaInputHandler::onA_ButtonPress()
{
    this->escena->cambiaEscena=true;
    this->escena->nuevaEscena=REPARTO_INICIAL;
}

void PantallaFinalPartidaInputHandler::onB_ButtonPress()
{
    this->escena->cambiaEscena=true;
    this->escena->nuevaEscena=INICIO;
}

void PantallaFinalPartidaInputHandler::onTouch()
{
    if (PantallaFinalPartida *scn = dynamic_cast<PantallaFinalPartida *>(this->escena))
    {
        for (size_t i = 0; i < scn->botones.size(); i++)
        {
            if (scn->botones[i].onTouch(this->touch.px, this->touch.py))
            {
                scn->cambiaEscena = true;
                scn->nuevaEscena = i == 0 ? REPARTO_INICIAL : INICIO;
            }; 
        }
    }
}
