#include <citro2d.h>
#include <citro3d.h>
#include <3ds.h>
#include <stdio.h>
#include "Partida.hpp"
#include "Jugador.hpp"




Partida::Partida(){
    spriteSheet = C2D_SpriteSheetLoad("romfs:/gfx/sprites.t3x");
    if (!spriteSheet)
		svcBreak(USERBREAK_PANIC);
    numImages= C2D_SpriteSheetCount(spriteSheet);
    escena=INICIO;
    playerToPlay=3;

    for (size_t i = 0; i <= 12; i++)
    {
        Carta carta;
        cartasDeLosJugadores.push_back(carta);
    }
    

    for (size_t i = 0; i < 4; i++)
    {
        Jugador jug(&cartasDeLosJugadores[3*i], &cartasDeLosJugadores[3*i+1], &cartasDeLosJugadores[3*i+2]);
        jugadores.push_back(jug);
    }
    // Initialize the render target
	top = C3D_RenderTargetCreate(240, 400, GPU_RB_RGBA8, GPU_RB_DEPTH24_STENCIL8);
	C3D_RenderTargetSetOutput(top, GFX_TOP, GFX_LEFT, DISPLAY_TRANSFER_FLAGS);
	bot = C3D_RenderTargetCreate(240, 320, GPU_RB_RGBA8, GPU_RB_DEPTH24_STENCIL8);
	C3D_RenderTargetSetOutput(bot, GFX_BOTTOM, GFX_LEFT, DISPLAY_TRANSFER_FLAGS);
}

//inicializa el juego, limpiando las posibles colecciones que tengan cartas (las que se han repartido previamente y las de los jugadores)
void Partida::repartirCartas(){
    srand(time(NULL));
    //cartasRepartidas.clear();
    cartasRepartidas.clear();

    Carta* cartaTriunfo=&(cartasDeLosJugadores[12]);
    cartaTriunfo->setValor((rand()%numImages-1)+1);
    this->cartaTriunfo = cartaTriunfo; 

    for (size_t i = 0; i < CARTAS_TOTALES; i++)
    {          
        Carta* carta=(jugadores[i/3].cartas[i%3]);
        bool yaSeRepartioEsaCarta;
        do{
            yaSeRepartioEsaCarta=false;
            carta->setValor((rand()%(numImages-1))+1);
            for (size_t i = 0; i < cartasRepartidas.size(); i++)
            {
                if(cartasRepartidas[i]==carta->valor){    
                    yaSeRepartioEsaCarta=true;
                    break;
                }
            }            
        }while(yaSeRepartioEsaCarta);
        //cartasDeLosJugadores.push_back(*carta);
        cartasRepartidas.push_back(carta->valor);
        switch (i)
        {
            case 0:
            case 1:  
            case 2:
                ocultaValor(carta);
                C2D_SpriteSetPos(&(carta->sprite),3*SCREEN_WIDTH/CARTAS_TOTALES, (1.5*i+5)*SCREEN_HEIGHT/CARTAS_TOTALES);
                C2D_SpriteSetRotation(&(carta->sprite),C3D_AngleFromDegrees(90));
            break;
            case 3:
            case 4:  
            case 5:
                ocultaValor(carta);
                C2D_SpriteSetPos(&(carta->sprite),(1.25*(i))*SCREEN_WIDTH/CARTAS_TOTALES, SCREEN_HEIGHT/CARTAS_TOTALES);
            break;
            case 6:
            case 7:  
            case 8: 
                ocultaValor(carta);
                C2D_SpriteSetPos(&(carta->sprite),10*SCREEN_WIDTH/CARTAS_TOTALES, (1.5*i-4)*SCREEN_HEIGHT/CARTAS_TOTALES);
                C2D_SpriteSetRotation(&(carta->sprite),C3D_AngleFromDegrees(90));
            break;
            case 9:
            case 10:  
            case 11: 
            
                muestraVerdaderoValor(carta);
                C2D_SpriteSetPos(&(carta->sprite),(1.25*(i-7))*SCREEN_WIDTH/CARTAS_TOTALES, 8*SCREEN_HEIGHT/CARTAS_TOTALES);  
                carta->px1=1.25*(i-7)*SCREEN_WIDTH/CARTAS_TOTALES;
                carta->px2=1.25*(i-7)*SCREEN_WIDTH/CARTAS_TOTALES+37;
                carta->py1=8*SCREEN_HEIGHT/CARTAS_TOTALES;
                carta->py1=(8*SCREEN_HEIGHT/CARTAS_TOTALES)+57;
            break;
        } 
    }
}

//le coloca el sprite del valor de la carta
void Partida::muestraVerdaderoValor(Carta* carta){
    carta->estaMostrandoValor=true; //repito, pruebas :)
    if(spriteSheet!=NULL){
        C2D_SpriteFromSheet(&(carta->sprite), spriteSheet,carta->valor);
    }
}

//oculta el valor de la carta y el sprite se vuelve el dorso
void Partida::ocultaValor(Carta* carta){
    carta->estaMostrandoValor=false; //que esto es una prueba leñe
    if(spriteSheet!=NULL){
        C2D_SpriteFromSheet(&(carta->sprite),spriteSheet,0);
    }
}

void Partida::avanzaEscena(){
    
}

//todo hacer esto dependiente del enum de la escena 
//y luego hacer una funcion especifica para cada escena donde se manejen qué cartas se dibujan dónde
void Partida::dibujaEscena(){
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_TargetClear(top, C2D_Color32f(0.0f, 0.0f, 0.0f, 1.0f));
	C2D_SceneBegin(top);
    //switch(escena)
		for (size_t i = 0; i < MAX_SPRITES; i++)
		{
			if(i==9){
				C2D_TargetClear(bot, C2D_Color32f(0.0f, 0.0f, 0.0f, 1.0f));
				C2D_SceneBegin(bot);
			}
			C2D_DrawSprite(&this->cartasDeLosJugadores[i].sprite);
			
		}
    //endswitch
	C3D_FrameEnd(0);
}