#include <citro2d.h>
#include <citro3d.h>
#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

#define MAX_SPRITES 12
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 240
#define DISPLAY_TRANSFER_FLAGS \
	(GX_TRANSFER_FLIP_VERT(0) | GX_TRANSFER_OUT_TILED(0) | GX_TRANSFER_RAW_COPY(0) | \
	GX_TRANSFER_IN_FORMAT(GX_TRANSFER_FMT_RGBA8) | GX_TRANSFER_OUT_FORMAT(GX_TRANSFER_FMT_RGB8) | \
	GX_TRANSFER_SCALING(GX_TRANSFER_SCALE_NO))

//Struct que representa a una carta
typedef struct
{
	C2D_Sprite spr;
	float px1, py1; //, px2, py2; // definen la hitbox de la carta, para poder clickar en ella
	bool isTriunfo;
	bool isFirstHand;
	size_t valor; // esto seria entre 1 y 40
} Carta;

static C2D_SpriteSheet spriteSheet; 
static Carta sprites[MAX_SPRITES];
static size_t numSprites = MAX_SPRITES / 2;
static std::vector<size_t> cartasRepartidas;
//---------------------------------------------------------------------------------

static void repartirCartas()
{
	//---------------------------------------------------------------------------------
	size_t numImages = C2D_SpriteSheetCount(spriteSheet); // obtiene el numero de cartas disponibles (de los sprites)
	srand(time(NULL));									  // genera un seed aleatorio
	// genera cartas hasta que se repartan todas
	cartasRepartidas.clear();
	for (size_t i = 0; i < MAX_SPRITES; i++)
	{
		Carta *sprite = &sprites[i];
		size_t carta;
		bool isAlreadyAssigned; //garantizar que son cartas diferentes
		do
		{
			isAlreadyAssigned = false;
			carta = (rand() % (numImages - 1)) + 1;
			for (size_t i = 0; i < cartasRepartidas.size(); i++)
			{
				if (cartasRepartidas[i] == carta)
				{
					isAlreadyAssigned = true;
					break;
				}
			}
		} while (isAlreadyAssigned);
		cartasRepartidas.push_back(carta);
		// C2D_SpriteScale(&sprite->spr,0.5f,0.5f);
		C2D_SpriteSetCenter(&sprite->spr, 0.5f, 0.5f);
		if (i < 3)		// izquierda de la pantalla
		{
			C2D_SpriteFromSheet(&sprite->spr, spriteSheet, 0);
			C2D_SpriteSetPos(&sprite->spr, 3*SCREEN_WIDTH/MAX_SPRITES, (1.5*i+5)*SCREEN_HEIGHT/MAX_SPRITES);
			C2D_SpriteSetRotation(&sprite->spr, C3D_AngleFromDegrees(90));
		}
		else if (i < 6) //top
		{
			C2D_SpriteFromSheet(&sprite->spr, spriteSheet, 0);
			C2D_SpriteSetPos(&sprite->spr,  (1.25*(i))*SCREEN_WIDTH/MAX_SPRITES, SCREEN_HEIGHT / MAX_SPRITES);
		}
		else if (i < 9) //derecha
		{

			C2D_SpriteFromSheet(&sprite->spr, spriteSheet, 0);
			C2D_SpriteSetPos(&sprite->spr, 10*(SCREEN_WIDTH/ MAX_SPRITES), (1.5*i-4)*SCREEN_HEIGHT/MAX_SPRITES);
			C2D_SpriteSetRotation(&sprite->spr, C3D_AngleFromDegrees(90));
		}
		else //bottom
		{
			C2D_SpriteFromSheet(&sprite->spr, spriteSheet, carta);
			C2D_SpriteSetPos(&sprite->spr,  (1.25*(i-7))*SCREEN_WIDTH/MAX_SPRITES, 8*SCREEN_HEIGHT / MAX_SPRITES);
		}
		sprite->valor = carta;
		sprite->isFirstHand = false;
		sprite->isTriunfo = false;
		sprite->px1 = 0;
		sprite->py1 = 0;
	}
}

int main(int argc, char *argv[])
{
	romfsInit();
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	//consoleInit(GFX_BOTTOM, NULL);

	// Initialize the render target
	C3D_RenderTarget* top = C3D_RenderTargetCreate(240, 400, GPU_RB_RGBA8, GPU_RB_DEPTH24_STENCIL8);
	C3D_RenderTargetSetOutput(top, GFX_TOP, GFX_LEFT, DISPLAY_TRANSFER_FLAGS);
	C3D_RenderTarget* bot = C3D_RenderTargetCreate(240, 320, GPU_RB_RGBA8, GPU_RB_DEPTH24_STENCIL8);
	C3D_RenderTargetSetOutput(bot, GFX_BOTTOM, GFX_LEFT, DISPLAY_TRANSFER_FLAGS);
	// Load graphics
	spriteSheet = C2D_SpriteSheetLoad("romfs:/gfx/sprites.t3x");
	if (!spriteSheet)
		svcBreak(USERBREAK_PANIC);
	repartirCartas();

	// Main loop
	while (aptMainLoop())
	{
		// Scan all the inputs. This should be done once for each frame
		hidScanInput();
		// hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();

		touchPosition touch;
		// Read the touch screen coordinates
		hidTouchRead(&touch);

		// Print the touch screen coordinates
		//printf("\x1b[2;0H%03d; %03d", touch.px, touch.py);

		if (kDown & KEY_START)
			break; // break in order to return to hbmenu

		//printf("\x1b[1;1HCartas: %zu/%u\x1b[K", numSprites, MAX_SPRITES);

		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, C2D_Color32f(0.0f, 0.0f, 0.0f, 1.0f));
		C2D_SceneBegin(top);
		for (size_t i = 0; i < MAX_SPRITES; i++)
		{
			if(i==9){
				C2D_TargetClear(bot, C2D_Color32f(0.0f, 0.0f, 0.0f, 1.0f));
				C2D_SceneBegin(bot);
			}
			C2D_DrawSprite(&sprites[i].spr);
		}
		C3D_FrameEnd(0);

		// Flush and swap framebuffers
		// gfxFlushBuffers();
		// gfxSwapBuffers();

		// Wait for VBlank
		// gspWaitForVBlank();
	}
	// Delete graphics
	C2D_SpriteSheetFree(spriteSheet);

	// Deinit libs
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	romfsExit();
	return 0;
}
