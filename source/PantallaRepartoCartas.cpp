#include "PantallaRepartoCartas.hpp"

PantallaRepartoCartas::PantallaRepartoCartas(C2D_SpriteSheet *spriteSheet)
{
    numEscena = REPARTO_INICIAL;
    nuevaEscena = INICIO;
    this->cambiaEscena = false;
    this->spriteSheet = spriteSheet;
    playerToPlay = 3;
    numImages = C2D_SpriteSheetCount(*spriteSheet);
    for (size_t i = 0; i <= 12; i++)
    {
        Carta carta;
        cartasDeLosJugadores.push_back(carta);
    }

    for (size_t i = 0; i < 4; i++)
    {
        Jugador jug(&cartasDeLosJugadores[3 * i], &cartasDeLosJugadores[3 * i + 1], &cartasDeLosJugadores[3 * i + 2]);
        jugadores.push_back(jug);
    }
}

void PantallaRepartoCartas::dibuja(C3D_RenderTarget *topScreen, C3D_RenderTarget *bottomScreen)
{
        C2D_TargetClear(topScreen, C2D_Color32f(0.0f, 0.0f, 0.0f, 1.0f));
            C2D_SceneBegin(topScreen);
    for (size_t i = 0; i < CARTAS_TOTALES; i++)
    {
        if (i == 9)
        {
            C2D_TargetClear(bottomScreen, C2D_Color32f(0.0f, 0.0f, 0.0f, 1.0f));
            C2D_SceneBegin(bottomScreen);
        }
        C2D_DrawSprite(&this->cartasDeLosJugadores[i].sprite);
    }
}

void PantallaRepartoCartas::actualizaEscena()
{
}

// inicializa el juego, limpiando las posibles colecciones que tengan cartas (las que se han repartido previamente y las de los jugadores)
void PantallaRepartoCartas::repartirCartas()
{
    srand(time(NULL));
    cartasRepartidas.clear();
    Carta *cartaTriunfo = &(cartasDeLosJugadores[12]);
    cartaTriunfo->setValor((rand() % numImages - 1) + 1);
    this->cartaTriunfo = cartaTriunfo;

    for (size_t i = 0; i < CARTAS_TOTALES; i++)
    {
        Carta *carta = (jugadores[i / 3].cartas[i % 3]);
        bool yaSeRepartioEsaCarta;
        do
        {
            yaSeRepartioEsaCarta = false;
            carta->setValor((rand() % (numImages - 1)) + 1);
            for (size_t i = 0; i < cartasRepartidas.size(); i++)
            {
                if (cartasRepartidas[i] == carta->valor)
                {
                    yaSeRepartioEsaCarta = true;
                    break;
                }
            }
        } while (yaSeRepartioEsaCarta);
        cartasRepartidas.push_back(carta->valor);
        switch (i)
        {
        case 0:
        case 1:
        case 2:
            ocultaValor(carta);
            C2D_SpriteSetPos(&(carta->sprite), 3 * SCREEN_WIDTH / CARTAS_TOTALES, (1.5 * i + 5) * SCREEN_HEIGHT / CARTAS_TOTALES);
            C2D_SpriteSetRotation(&(carta->sprite), C3D_AngleFromDegrees(90));
            break;
        case 3:
        case 4:
        case 5:
            ocultaValor(carta);
            C2D_SpriteSetPos(&(carta->sprite), (1.25 * (i)) * SCREEN_WIDTH / CARTAS_TOTALES, SCREEN_HEIGHT / CARTAS_TOTALES);
            break;
        case 6:
        case 7:
        case 8:
            ocultaValor(carta);
            C2D_SpriteSetPos(&(carta->sprite), 10 * SCREEN_WIDTH / CARTAS_TOTALES, (1.5 * i - 4) * SCREEN_HEIGHT / CARTAS_TOTALES);
            C2D_SpriteSetRotation(&(carta->sprite), C3D_AngleFromDegrees(90));
            break;
        case 9:
        case 10:
        case 11:
            muestraVerdaderoValor(carta);
            C2D_SpriteSetPos(&(carta->sprite), (1.25 * (i - 7)) * SCREEN_WIDTH / CARTAS_TOTALES, 8 * SCREEN_HEIGHT / CARTAS_TOTALES);
            carta->px1 = 1.25 * (i - 7) * SCREEN_WIDTH / CARTAS_TOTALES;
            carta->px2 = 1.25 * (i - 7) * SCREEN_WIDTH / CARTAS_TOTALES + 37;
            carta->py1 = 8 * SCREEN_HEIGHT / CARTAS_TOTALES;
            carta->py1 = (8 * SCREEN_HEIGHT / CARTAS_TOTALES) + 57;
            break;
        }
    }
}
// oculta el valor de la carta y el sprite se vuelve el dorso
void PantallaRepartoCartas::ocultaValor(Carta *carta)
{
    carta->estaMostrandoValor = false; // que esto es una prueba leñe
    if (spriteSheet != NULL)
    {
        C2D_SpriteFromSheet(&(carta->sprite), *spriteSheet, 0);
    }
}

// le coloca el sprite del valor de la carta
void PantallaRepartoCartas::muestraVerdaderoValor(Carta *carta)
{
    carta->estaMostrandoValor = true; // repito, pruebas :)
    if (spriteSheet != NULL)
    {
        C2D_SpriteFromSheet(&(carta->sprite), *spriteSheet, carta->valor);
    }
}