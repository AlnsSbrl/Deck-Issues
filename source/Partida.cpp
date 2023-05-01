#include <stdio.h>
#include "Partida.hpp"
#include "PantallaPrincipal.hpp"
#include "PantallaRepartoCartas.hpp"

Partida::Partida()
{
    spriteSheet = C2D_SpriteSheetLoad("romfs:/gfx/sprites.t3x");
    if (!spriteSheet)
        svcBreak(USERBREAK_PANIC);

    PantallaPrincipal pantallaPrincipal;
    this->escena=pantallaPrincipal;
    //escena.numEscena = INICIO;
    // Initialize the render target
    top = C3D_RenderTargetCreate(240, 400, GPU_RB_RGBA8, GPU_RB_DEPTH24_STENCIL8);
    C3D_RenderTargetSetOutput(top, GFX_TOP, GFX_LEFT, DISPLAY_TRANSFER_FLAGS);
    bot = C3D_RenderTargetCreate(240, 320, GPU_RB_RGBA8, GPU_RB_DEPTH24_STENCIL8);
    C3D_RenderTargetSetOutput(bot, GFX_BOTTOM, GFX_LEFT, DISPLAY_TRANSFER_FLAGS);
}

void Partida::cambiaEscena(TipoEscena nuevaEscena)
{
    if (nuevaEscena != this->escena.numEscena)
    {
        // todo changes
        escena.terminaEscena();
        switch (nuevaEscena)
        {
        case INICIO:
            PantallaPrincipal pantalla;
            this->escena = pantalla;
            break;
        case REPARTO_INICIAL:
        {
            //por qué necesito poner esto entre corchetes para que compile?? mmm
            PantallaRepartoCartas pantallaRepartoCartas(&spriteSheet);
            this->escena = pantallaRepartoCartas;
        }
        break;
        // todo rest
        default:
            break;

            // TipoEscena {INICIO, REPARTO_INICIAL,MUEVE_CPU1,MUEVE_CPU2,MUEVE_CPU3,MUEVE_PLAYER,TERMINA_BAZA,PREGUNTA_SEGUIR,FINAL};
        }
    }
}

// todo hacer esto dependiente del enum de la escena
// y luego hacer una funcion especifica para cada escena donde se manejen qué cartas se dibujan dónde
void Partida::dibujaEscena()
{
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    C2D_TargetClear(top, C2D_Color32f(0.0f, 0.0f, 0.0f, 1.0f));
    C2D_SceneBegin(top); // mover esto para dentro de cada dibuja de cada escena
    escena.dibuja(top, bot);
    if (escena.cambiaEscena)
        cambiaEscena(escena.nuevaEscena);
    // switch(escena)
   
    // endswitch
    C3D_FrameEnd(0);
}

void Partida::empiezaPartida()
{
    romfsInit();
    gfxInitDefault();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();
    // consoleInit(GFX_BOTTOM, NULL);
    while (aptMainLoop())
    {
        escena.actualizaEscena();
        try
        {
            escena.inputHandler.gestionaInputs();
        }
        catch (std::invalid_argument &e)
        {
            break;
        }
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