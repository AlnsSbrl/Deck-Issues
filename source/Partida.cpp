#include <stdio.h>
#include "Partida.hpp"

Partida::Partida()
{
    romfsInit();
    gfxInitDefault();
    spriteSheet = C2D_SpriteSheetLoad("romfs:/gfx/sprites.t3x");
    if (!spriteSheet){
        svcBreak(USERBREAK_PANIC);
    }
    Escena escena(&spriteSheet);
    InputHandler inputHandler(&escena);
    this->escena = escena;
    this->inputHandler = inputHandler;
    terminaJuego=false;
    top = C3D_RenderTargetCreate(240, 400, GPU_RB_RGBA8, GPU_RB_DEPTH24_STENCIL8);
    C3D_RenderTargetSetOutput(top, GFX_TOP, GFX_LEFT, DISPLAY_TRANSFER_FLAGS);
    bot = C3D_RenderTargetCreate(240, 320, GPU_RB_RGBA8, GPU_RB_DEPTH24_STENCIL8);
    C3D_RenderTargetSetOutput(bot, GFX_BOTTOM, GFX_LEFT, DISPLAY_TRANSFER_FLAGS);
}
/*
void Partida::cambiaEscena(TipoEscena nuevaEscena)
{
    if (nuevaEscena != this->escena.numEscena)
    {
        // todo changes
        escena.terminaEscena();
        switch (nuevaEscena)
        {
        case INICIO:
        {

            PantallaPrincipal pantalla;
            this->escena = pantalla;
            PantallaPrincipalInputHandler pHandler(&escena);
            this->inputHandler = pHandler;
            break;
        }
        case REPARTO_INICIAL:
        {
            // por qué necesito poner esto entre corchetes para que compile?? mmm
            PantallaRepartoCartas pantallaRepartoCartas(&spriteSheet);
            this->escena = pantallaRepartoCartas;
            PantallaRepartoCartasInputHandler pHandler(&pantallaRepartoCartas); // supongo que apuntan al mismo sitio y asi me ahorro el static cast???
            this->inputHandler = pHandler;
        }
        break;
        // todo rest
        default:
        {
            
        }
            break;

            // TipoEscena {INICIO, REPARTO_INICIAL,MUEVE_CPU1,MUEVE_CPU2,MUEVE_CPU3,MUEVE_PLAYER,TERMINA_BAZA,PREGUNTA_SEGUIR,FINAL};
        }
    }
}*/

// todo hacer esto dependiente del enum de la escena
// y luego hacer una funcion especifica para cada escena donde se manejen qué cartas se dibujan dónde
void Partida::dibujaEscena()
{
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    C2D_TargetClear(top, C2D_Color32f(0.0f, 0.0f, 0.0f, 1.0f));
    escena.dibuja(top, bot);
    C3D_FrameEnd(0);
}

void Partida::empiezaPartida()
{
   
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();
    // consoleInit(GFX_BOTTOM, NULL);
    while (aptMainLoop())
    {
        //escena.actualizaEscena();
        if(inputHandler.gestionaInputs())break;
        dibujaEscena();
    }
    finalizaPartida();
}

void Partida::finalizaPartida()
{
    C2D_SpriteSheetFree(spriteSheet);
    C2D_Fini();
    C3D_Fini();
    gfxExit();
    romfsExit();
}