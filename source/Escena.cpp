#include "Escena.hpp"

Escena::Escena(){
    
}

void Escena::dibuja(C3D_RenderTarget *topScreen, C3D_RenderTarget *bottomScreen)
{
    C2D_TargetClear(topScreen, C2D_Color32f(0.0f, 0.0f, 0.0f, 1.0f));
    C2D_SceneBegin(topScreen);
    // aqui hacer condicionales de qué dibujar?? o
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

void Escena::actualizaEscena(TipoEscena movimiento)
{
    switch (movimiento)
    {

    case MUEVE_CPU:
        if (seHaTerminadoLaBaza)
        {
            goto TERMINA_BAZA;
        }
        if (playerToPlay != 3)
        {
            if (turno == 0)
            {
                this->cartaOpener = jugadores[playerToPlay].lanzaCarta();
                this->cartaGanadora = cartaOpener;
            }
            else
            {
                if (jugadores[playerToPlay].CalculoCartasPermitidas(cartaOpener, cartaGanadora, this->cartaTriunfo->palo))
                {
                    this->cartaGanadora = jugadores[playerToPlay].lanzaCarta();
                }
                else
                {
                    jugadores[playerToPlay].lanzaCarta();
                }
            }
            this->muestraVerdaderoValor(jugadores[playerToPlay].cartaJugada);
            terminaTurno();
        }
        break;
    case MUEVE_PLAYER:

        break;

    TERMINA_BAZA:
        repartirCartas();
        seHaTerminadoLaBaza = false;
        break;

    default:
        break;
    }
}

void Escena::terminaEscena()
{
    seHaTerminadoLaBaza = true;
};

Escena::Escena(C2D_SpriteSheet *spriteSheet)
{
    // numEscena = REPARTO_INICIAL;
    // nuevaEscena = INICIO;
    this->cambiaEscena = false;
    this->spriteSheet = spriteSheet;

    numImages = C2D_SpriteSheetCount(*spriteSheet);
    seHaTerminadoLaBaza = true; // esto es para pulsar A y repartir las cartas

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
    jugadores[0].posXLanzamiento = 4 * SCREEN_WIDTH / CARTAS_TOTALES;
    jugadores[0].posYLanzamiento = 6 * SCREEN_HEIGHT / CARTAS_TOTALES;

    jugadores[1].posXLanzamiento = 6 * SCREEN_WIDTH / CARTAS_TOTALES;
    jugadores[1].posYLanzamiento = 3 * SCREEN_HEIGHT / CARTAS_TOTALES;

    jugadores[2].posXLanzamiento = 8 * SCREEN_WIDTH / CARTAS_TOTALES;
    jugadores[2].posYLanzamiento = 6 * SCREEN_HEIGHT / CARTAS_TOTALES;

    jugadores[3].posXLanzamiento = 6 * SCREEN_WIDTH / CARTAS_TOTALES;
    jugadores[3].posYLanzamiento = 3 * SCREEN_HEIGHT / CARTAS_TOTALES;

    srand(time(NULL));
    playerToShuffle = (rand() % 4);
    playerToPlay = playerToShuffle + 1;
    if (playerToPlay >= jugadores.size())
    {
        playerToPlay = 0;
    }
}

void Escena::terminaTurno()
{
    setNextPlayerToPlay();
    turno++;
    if (turno >= jugadores.size())
    {
        finalizaBaza();
    }
}

// inicializa el juego, limpiando las posibles colecciones que tengan cartas (las que se han repartido previamente y las de los jugadores)
void Escena::repartirCartas()
{
    srand(time(NULL));
    cartasRepartidas.clear();
    Carta *cartaTriunfo = &(cartasDeLosJugadores[12]);
    cartaTriunfo->setValor((rand() % numImages - 1) + 1);
    this->cartaTriunfo = cartaTriunfo;

    for (size_t i = 0; i < CARTAS_TOTALES; i++)
    {
        Carta *carta = (jugadores[i / 3].cartas[i % 3]);
        carta->jugadorDeLaCarta = i / 3;
        carta->isAvailableToPlay = true;
        jugadores[i / 3].hasWon = false;
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
    setNextPlayerToShuffle();
}

void Escena::finalizaBaza()
{
    for (size_t i = 0; i < jugadores.size(); i++)
    {
        if (jugadores[i].cartaJugada == this->cartaGanadora)
        {
            jugadores[i].hasWon = true; // no lo asigno directamente al boolean del if porque son 3 rondas, puede haber 3 ganadores
            playerToPlay = i;
        }
        jugadores[i].cartaJugada->isAvailableToPlay = false;
        // TODO jugadores[i].cartaJugada.CAMBIAPOSICION(coordenadas del jugador que ha ganado en este turno)
        // todo: cambio en todas las cartas jugadas zzz
    }
    turno = 0;
    for (size_t i = 0; i < jugadores[i].cartas.size(); i++)
    {
        if (jugadores[i].cartas[i]->isAvailableToPlay)
        {
            return; // aun quedan cartas disponibles, se sigue jugando
        }
    }
    this->terminaEscena();
}

void Escena::setNextPlayerToPlay()
{
    this->playerToPlay++;
    if (playerToPlay >= jugadores.size())
    {
        this->playerToPlay = 0;
    }
};

void Escena::setNextPlayerToShuffle()
{
    this->playerToShuffle++;
    if (playerToShuffle >= jugadores.size())
    {
        this->playerToShuffle = 0;
    }
    this->setNextPlayerToPlay();
};

// permite conocer si la carta seleccionada se puede jugar en la partida. De ser cierto también comprueba si sería la nueva carta ganadora
bool Escena::juegaCartaJugador(Carta *cartaSeleccionada)
{

    if (playerToPlay != 3)
        return false; // no es tu turno de jugar!!

    if (turno == 0)
    {
        jugadores[3].cartaJugada = cartaSeleccionada;
        this->cartaOpener = cartaSeleccionada;
        this->cartaGanadora = cartaSeleccionada;
        return true;
    }
    bool wouldBeWinning = jugadores[3].CalculoCartasPermitidas(cartaOpener, cartaGanadora, cartaTriunfo->palo);
    for (size_t i = 0; i < jugadores[3].cartasPermitidas.size(); i++)
    {
        if (jugadores[3].cartasPermitidas[i] == cartaSeleccionada)
        {
            jugadores[3].cartaJugada = cartaSeleccionada;
            if (wouldBeWinning)
                this->cartaGanadora = cartaSeleccionada;
            return true;
        }
    }
    return false;
}
// oculta el valor de la carta y el sprite se vuelve el dorso
void Escena::ocultaValor(Carta *carta)
{
    carta->estaMostrandoValor = false; // que esto es una prueba leñe
    if (spriteSheet != NULL)
    {
        C2D_SpriteFromSheet(&(carta->sprite), *spriteSheet, 0);
    }
}

// le coloca el sprite del valor de la carta
void Escena::muestraVerdaderoValor(Carta *carta)
{
    carta->estaMostrandoValor = true; // repito, pruebas :)
    if (spriteSheet != NULL)
    {
        C2D_SpriteFromSheet(&(carta->sprite), *spriteSheet, carta->valor);
    }
}