#pragma once
#include "PantallaPrincipalInputHandler.hpp"
#include "Escena.hpp"

class PantallaPrincipal : public Escena{
public:
    C2D_Image topImage;
    C2D_Image bottomImage;
    C2D_Text bottomText;
    void dibuja(C3D_RenderTarget *topScreen, C3D_RenderTarget *bottomScreen) override;
    void actualizaEscena() override;
    private:
    C2D_TextBuf textBuffer;
    C2D_Font font;
};

PantallaPrincipal::PantallaPrincipal(){
    PantallaPrincipalInputHandler ppHandler(this);
    this->inputHandler=ppHandler;
    cambiaEscena=false;
    textBuffer= C2D_TextBufNew(4096);
    font=C2D_FontLoad("romfs:/jadjfakd.bcfnt"); //todo: cargar mi propia fuente Y modificar el MAKEFILE para poder generar ese archivo a raiz de un ttf
    C2D_TextFontParse(&bottomText,font,textBuffer,"Toca para continuar");
    C2D_TextOptimize(&bottomText);
}

void PantallaPrincipal::dibuja(C3D_RenderTarget *topScreen, C3D_RenderTarget *bottomScreen) {
    C2D_SceneBegin(topScreen);
    C2D_DrawText(&bottomText,0,8.0f,8.0f,0.5f,0.5f,0.5f);
}

void PantallaPrincipal::actualizaEscena(){
    //todo: iluminar y desiluminar el texto
    //no parece haber funciones que sirvan para eso......
}

void PantallaPrincipalInputHandler::onTouch(){
    escena->cambiaEscena=true;
}
void PantallaPrincipalInputHandler::onA_ButtonPress(){
    escena->cambiaEscena=true;
}
void PantallaPrincipalInputHandler::onStartPress(){
    escena->cambiaEscena=true;
}
void PantallaPrincipalInputHandler::onSelectPress(){
    //opciones o algo así??
}