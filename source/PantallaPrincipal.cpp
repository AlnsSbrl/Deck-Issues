#include "PantallaPrincipal.hpp"


PantallaPrincipal::PantallaPrincipal(){
    PantallaPrincipalInputHandler ppHandler(this);
    this->inputHandler=ppHandler;
    numEscena=INICIO;
    nuevaEscena=REPARTO_INICIAL;
    cambiaEscena=false;
    textBuffer= C2D_TextBufNew(4096);
    font=C2D_FontLoad("romfs:/attfshingoproultra.bcfnt"); //todo: cargar mi propia fuente Y modificar el MAKEFILE para poder generar ese archivo a raiz de un ttf
    C2D_TextFontParse(&bottomText,font,textBuffer,"Toca para continuar");
    C2D_TextOptimize(&bottomText);
};

void PantallaPrincipal::dibuja(C3D_RenderTarget *topScreen, C3D_RenderTarget *bottomScreen) {
    C2D_SceneBegin(topScreen);
    C2D_DrawText(&bottomText,0,8.0f,8.0f,0.5f,0.5f,0.5f);
};

void PantallaPrincipal::actualizaEscena(){
    //todo: iluminar y desiluminar el texto
    //no parece haber funciones que sirvan para eso......
};

void PantallaPrincipal::terminaEscena(){
    C2D_TextBufDelete(textBuffer);
    C2D_FontFree(font);
}