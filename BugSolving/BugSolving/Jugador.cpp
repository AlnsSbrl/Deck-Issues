#include "Jugador.h"
#include <time.h>
#include <iostream>
Jugador::Jugador() {

}

Jugador::Jugador(Carta* carta, Carta* carta2, Carta* carta3) {
    cartas.push_back(carta);
    cartas.push_back(carta2);
    cartas.push_back(carta3);
}

bool Jugador::CalculoCartasPermitidas(Carta* primeraCartaJugada, Carta* cartaQueGanaActualmente, Palo triunfo)
{

    this->cartasPermitidas.clear();
    // la primera regla es asistir al palo de la primera carta jugada
    for (size_t i = 0; i < cartas.size(); i++)
    {
        if (cartas[i]->palo == primeraCartaJugada->palo && cartas[i]->isAvailableToPlay)
        {
            cartasPermitidas.push_back(cartas[i]);
        }
    }

    //en el caso de asistir, la segunda regla indica que es obligatorio echar una carta con más valor
    if (cartasPermitidas.size() > 0)
    {
        std::vector<Carta*> cartasQueSuperanVariasCondiciones;
        // en el caso de que otro jugador haya sacado un triunfo DEJA DE SER OBLIGATORIO subir,
        // ya que las cartas de triunfo tienen prioridad, pero tendremos que asistir de todas formas, dando igual el valor de la carta que echemos
        if (primeraCartaJugada->palo == cartaQueGanaActualmente->palo)
        {
            for (size_t i = 0; i < cartasPermitidas.size(); i++)
            {
                if (cartaQueGanaActualmente->valor < cartasPermitidas[i]->valor)
                {
                    cartasQueSuperanVariasCondiciones.push_back(cartasPermitidas[i]);
                }
            }
            if (cartasQueSuperanVariasCondiciones.size() == 0)
            {
                return false; // no puede subir con ninguna, juega cualquiera
            }
            else
            {
                cartasPermitidas = cartasQueSuperanVariasCondiciones;
                return true; //una o varias cartas cumplen los requisitos (asistir+subir)
            }
        }
        else
        {
            return false; // una carta de triunfo está ganando, no importa qué carta se echa
        }
    }
    else
    {
        // NO puede asistir -> tiene que fallar (si sube a la carta que está ganando (triunfo) o puede jugar cualquier cosa)
        for (size_t i = 0; i < cartas.size(); i++)
        {
            // si la carta que gana NO es triunfo, se añaden todas las que sean del palo de triunfo
            // si la carta que gana ES triunfo, se tiene que comprobar que su valor es más alto
            if (cartas[i]->palo == triunfo && cartas[i]->isAvailableToPlay)
            {
                if (cartaQueGanaActualmente->palo != triunfo)
                {
                    cartasPermitidas.push_back(cartas[i]); // si NO hay triunfo sobre la mesa, puede jugar cualquiera de triunfo
                }
                else if (cartas[i]->valor > cartaQueGanaActualmente->valor)
                {
                    cartasPermitidas.push_back(cartas[i]); // si hay triunfo Y SE LE SUBE, se juega
                }
            }
        }

        if (cartasPermitidas.size() == 0)
        {
            // antes devolvía TODAS las cartas, es decir,
            // cuando solo quedaba una carta posible para jugar es muy probable que no se cumpla ninguna condición previa
            // y por tanto devolvía como posibles TODAS las cartas, no las permitidas para jugar (aka que no se han jugado todavia)

            for (Carta* carta : cartas) {
                if (carta->isAvailableToPlay) {
                    cartasPermitidas.push_back(carta);
                }
            }
            return false;
        }
        else
        {
            return true;
        }
    }
}



/**
* La IA usará esto para lanzar alguna de las cartas que se permiten
*/
Carta* Jugador::lanzaCarta(Carta* cartaSeleccionada) {

    if (cartaSeleccionada != 0) {
        for (size_t i = 0; i < cartasPermitidas.size(); i++)
        {
            if (cartaSeleccionada == cartasPermitidas[i]) {
                //C2D_SpriteSetPos(&cartaSeleccionada->sprite, this->posXLanzamiento, this->posYLanzamiento);
                //probablemente pueda reducir el codigo aqui but idgaf
                return cartaSeleccionada; //esta comprobacion la hago PORSIACASO, pero realmente no haría falta por cómo la llamo
            }
        }
    }
    srand(time(NULL));
    Carta* carta = cartasPermitidas[rand() % cartasPermitidas.size()];
    carta->isAvailableToPlay=false; //esto se lo cambio en cuanto termine la baza (para que pueda seguir dibujandolo¿?)
    std::cout << "\n	 cartas lanzada: " << carta->valor;
    //C2D_SpriteSetPos(&carta->sprite, this->posXLanzamiento, this->posYLanzamiento);
    return carta;
}
