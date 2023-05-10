#include "InputHandler.hpp"

InputHandler::InputHandler()
{
}
InputHandler::InputHandler(Escena *escena)
{
    this->escena = escena;
}
bool InputHandler::gestionaInputs()
{
    hidScanInput();
    u32 kDown = hidKeysDown();
    hidTouchRead(&touch);
    if (KEY_A & kDown)
    {
        onA_ButtonPress();
    }
    if (KEY_B & kDown)
    {
        onB_ButtonPress();
    }
    if (KEY_X & kDown)
    {
        onX_ButtonPress();
    }
    if (KEY_Y & kDown)
    {
        onY_ButtonPress();
    }
    if (KEY_L & KEY_R & KEY_SELECT & kDown)
    {
        onLRSelect_buttonsPress();
        return true;
    }
    if (KEY_DLEFT & kDown || KEY_CPAD_LEFT & kDown)
    {
        onLeftPress();
    }
    if (KEY_DRIGHT & kDown || KEY_CPAD_RIGHT & kDown)
    {
        onRightPress();
    }
    if (KEY_DUP & kDown || KEY_CPAD_UP & kDown)
    {
        onUpPress();
    }
    if (KEY_DDOWN & kDown || KEY_CPAD_DOWN & kDown)
    {
        onDownPress();
    };
    if (KEY_START & kDown)
    {
        onStartPress();
    }
    if (KEY_SELECT & kDown)
    {
        onSelectPress();
    }
    if (KEY_TOUCH & kDown)
    {
        onTouch();
    }
    return false;
}

void InputHandler::onLeftPress()
{

    if (escena->juegaCartaJugador(escena->jugadores[3].cartas[0]))
    {
        escena->jugadores[3].lanzaCarta(escena->jugadores[3].cartaJugada);
        escena->actualizaEscena(MUEVE_PLAYER);
        escena->terminaTurno();
    }
}

// haria lo mismo que el onTouch() seleccionando la carta de la derecha
void InputHandler::onRightPress()
{

    if (escena->juegaCartaJugador(escena->jugadores[3].cartas[2]))
    {
        escena->jugadores[3].lanzaCarta(escena->jugadores[3].cartaJugada);
        escena->actualizaEscena(MUEVE_PLAYER);
        escena->terminaTurno();
    }
}

// haria lo mismo que el onTouch() seleccionando la carta del medio
void InputHandler::onUpPress()
{

    if (escena->juegaCartaJugador(escena->jugadores[3].cartas[1]))
    {
        escena->jugadores[3].lanzaCarta(escena->jugadores[3].cartaJugada);
        escena->actualizaEscena(MUEVE_PLAYER);
        escena->terminaTurno();
    }
}
void InputHandler::onA_ButtonPress()
{
    
    escena->actualizaEscena(MUEVE_CPU);
};

void InputHandler::onTouch()
{
    hidTouchRead(&touch);

    for (size_t i = 0; i < escena->jugadores[3].cartas.size(); i++)
    {
        if (escena->jugadores[3].cartas[i]->onTouch(this->touch.px, this->touch.py))
        {
            if (escena->juegaCartaJugador(escena->jugadores[3].cartas[i]))
            {
                escena->jugadores[3].lanzaCarta(escena->jugadores[3].cartaJugada);
                escena->actualizaEscena(MUEVE_PLAYER);
                escena->terminaTurno();
            }
        };
        // todo: hacer prueba para ver si me gestiona esto correctamente :)
    }
};
void InputHandler::onStartPress()
{
    escena->repartirCartas();
}

void InputHandler::onLRSelect_buttonsPress()
{
    //throw std::invalid_argument("saliendo del programa");
    // yo buscando durante 20 min como lanzar una excepcion...
    // y al final el ejemplo de MS hacia un "import static" con el std.....
}

void InputHandler::onX_ButtonPress(){

};
void InputHandler::onY_ButtonPress(){

};
void InputHandler::onSelectPress(){

};
void InputHandler::onB_ButtonPress()
{
    /*escena->cambiaEscena=true;
    escena->nuevaEscena=INICIO;*/
}
void InputHandler::onDownPress(){

};