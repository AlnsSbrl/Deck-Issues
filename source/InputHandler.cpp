#include "InputHandler.hpp"
InputHandler::InputHandler(){

}
InputHandler::InputHandler(Escena* escena) 
{
}
void InputHandler::gestionaInputs()
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
}

void InputHandler::onDownPress(){

};
void InputHandler::onLeftPress(){

};
void InputHandler::onRightPress(){

};
void InputHandler::onUpPress(){

};
void InputHandler::onA_ButtonPress(){

};
void InputHandler::onB_ButtonPress(){

};
void InputHandler::onX_ButtonPress(){

};
void InputHandler::onY_ButtonPress(){

};
void InputHandler::onTouch(){
    hidTouchRead(&touch);
};
void InputHandler::onStartPress(){

};
void InputHandler::onSelectPress(){

};
void InputHandler::onLRSelect_buttonsPress()
{
    throw std::invalid_argument("saliendo del programa");
    // yo buscando durante 20 min como lanzar una excepcion...
    // y al final el ejemplo de MS hacia un "import static" con el std.....
}

