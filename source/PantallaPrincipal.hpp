#pragma once
#include "PantallaPrincipalInputHandler.hpp"
#include "Escena.hpp"

class PantallaPrincipal : public Escena{
public:
    PantallaPrincipal();
    C2D_Image topImage;
    C2D_Image bottomImage;
    C2D_Text bottomText;
    void dibuja(C3D_RenderTarget *topScreen, C3D_RenderTarget *bottomScreen) override;
    void actualizaEscena() override;
    void terminaEscena() override;
    private:
    C2D_TextBuf textBuffer;
    C2D_Font font;
};
