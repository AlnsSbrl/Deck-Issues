#pragma once
#include "InputHandler.hpp"
#include "PantallaFinalPartida.hpp"

class PantallaFinalPartidaInputHandler : public InputHandler
{
public:
    PantallaFinalPartidaInputHandler(PantallaFinalPartida *escena);
    virtual void onA_ButtonPress() override;
    virtual void onTouch() override;
    virtual void onB_ButtonPress() override;
};