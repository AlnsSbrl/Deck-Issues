#pragma once
#include "Escena.hpp"

class PantallaPrincipal{
public:
    PantallaPrincipal();
    C2D_Image topImage;
    C2D_Image bottomImage;
    C2D_Text bottomText;
    void dibuja(C3D_RenderTarget *topScreen, C3D_RenderTarget *bottomScreen);
    void actualizaEscena() ;
    void terminaEscena() ;
    private:
    C2D_TextBuf textBuffer;
    C2D_Font font;
};
