#include "Partida.h"
#include <time.h>
#include <iostream>

Partida::Partida() {
    for (size_t i = 0; i < 40; i++)
    {
        spriteSheet[i] = i;
    }
    numImages = 40;
    escena = INICIO;
    playerToPlay = 3;
    for (size_t i = 0; i < 4; i++)
    {
        Jugador jug;
        jugadores.push_back(jug);
    }
}

//inicializa el juego, limpiando las posibles colecciones que tengan cartas (las que se han repartido previamente y las de los jugadores)
void Partida::repartirCartas() {
    srand(time(NULL));
    cartasRepartidas.clear();
    for (size_t i = 0; i < 4; i++)
    {
        jugadores[i].nuevaMano(); //genera una nueva mano de 3 cartas, sin asignar
    }

    Carta cartaTriunfo;
    cartaTriunfo.setValor((rand() % numImages - 1) + 1);
    cartasRepartidas.push_back(cartaTriunfo);
    triunfo = cartaTriunfo.palo;

    for (size_t i = 0; i < CARTAS_TOTALES; i++)
    {
        Carta* carta = &(jugadores[i / 3].cartas[i % 3]);
        //TODO: la f�rmula anterior hac�a que el �ltimo player no tuviese ninguna carta
        //(asignaba 4 cartas a 3 jugadores, eso generaba problemas en el mainLoop al hacer la comprobaci�n de si se toca la carta del player, que, casualmente, era Jugador[3]
        std::cout << "\njugador num:" << i / 3;
        std::cout << "\ncarta de su mano num: " << i % 3;
        bool yaSeRepartioEsaCarta;
        do {
            yaSeRepartioEsaCarta = false;
            carta->setValor((rand() % (numImages - 1)) + 1);
            for (size_t i = 0; i < cartasRepartidas.size(); i++)
            {
                if (cartasRepartidas[i].valor == carta->valor) {
                    yaSeRepartioEsaCarta = true;
                    break;
                }
            }
        } while (yaSeRepartioEsaCarta);
        cartasRepartidas.push_back(*carta);

        switch (i)
        {
        case 0:
        case 1:
        case 2:
            ocultaValor(carta);
            //C2D_SpriteSetPos(&(carta->sprite), 3 * SCREEN_WIDTH / CARTAS_TOTALES, (1.5 * i + 5) * SCREEN_HEIGHT / CARTAS_TOTALES);
            //C2D_SpriteSetRotation(&(carta->sprite), C3D_AngleFromDegrees(90));
            break;
        case 3:
        case 4:
        case 5:
            ocultaValor(carta);
            //C2D_SpriteSetPos(&(carta->sprite), (1.25 * (i)) * SCREEN_WIDTH / CARTAS_TOTALES, SCREEN_HEIGHT / CARTAS_TOTALES);
            break;
        case 6:
        case 7:
        case 8:
            ocultaValor(carta);
            //C2D_SpriteSetPos(&(carta->sprite), 10 * SCREEN_WIDTH / CARTAS_TOTALES, (1.5 * i - 4) * SCREEN_HEIGHT / CARTAS_TOTALES);
            //C2D_SpriteSetRotation(&(carta->sprite), C3D_AngleFromDegrees(90));
            break;
        case 9:
        case 10:
        case 11:
            muestraVerdaderoValor(carta);
            //C2D_SpriteSetPos(&(carta->sprite), (1.25 * (i - 7)) * SCREEN_WIDTH / CARTAS_TOTALES, 8 * SCREEN_HEIGHT / CARTAS_TOTALES);
            carta->px1 = 1.25 * (i - 7) * SCREEN_WIDTH / CARTAS_TOTALES;
            carta->px2 = 1.25 * (i - 7) * SCREEN_WIDTH / CARTAS_TOTALES + 37;
            carta->py1 = 8 * SCREEN_HEIGHT / CARTAS_TOTALES;
            carta->py1 = (8 * SCREEN_HEIGHT / CARTAS_TOTALES) + 57;
            break;
        }
    }
}

//le coloca el sprite del valor de la carta
void Partida::muestraVerdaderoValor(Carta* carta) {
    carta->estaMostrandoValor = true; //repito, pruebas :)
    //std::cout << "\nvalor de la carta: " << carta->valor;
}

//oculta el valor de la carta y el sprite se vuelve el dorso
void Partida::ocultaValor(Carta* carta) {
    carta->estaMostrandoValor = false; //que esto es una prueba le�e
    //std::cout << "\nla carta no muestra el valor";
}

void Partida::avanzaEscena()
{
}