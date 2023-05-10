// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Partida.h"

int main()
{
	Partida partida;
	bool seguir = true;
	partida.repartirCartas();
	partida.jugadores[0].cartas[0]->setValor(3);
	partida.jugadores[0].cartas[1]->setValor(6);
	partida.jugadores[0].cartas[2]->setValor(12);

	for (Carta* carta : partida.jugadores[0].cartas) {
		std::cout << "\n	valor carta: " << carta->valor;
	}

	Carta triunfo;
	triunfo.setValor(11);
	Carta cartaGanadora;
	cartaGanadora.setValor(32);

	/*aqui se pueden configurar distintas combinaciones de cartas para ver si se siguen las normas tm*/
	partida.jugadores[0].CalculoCartasPermitidas(&cartaGanadora, &triunfo, triunfo.palo);
	for (Carta* carta : partida.jugadores[0].cartasPermitidas) {
		std::cout << "\n	 cartas permitidas: " << carta->valor;
	}
	partida.jugadores[0].lanzaCarta();
	partida.jugadores[0].CalculoCartasPermitidas(&triunfo, &triunfo, triunfo.palo);
	for (Carta* carta : partida.jugadores[0].cartasPermitidas) {
		std::cout << "\n	 cartas permitidas: " << carta->valor;
	}
	partida.jugadores[0].lanzaCarta();
	partida.jugadores[0].CalculoCartasPermitidas(&triunfo, &triunfo, triunfo.palo);
	for (Carta* carta : partida.jugadores[0].cartasPermitidas) {
		std::cout << "\n	 cartas permitidas: " << carta->valor;
	}
	partida.jugadores[0].lanzaCarta();
	partida.jugadores[0].CalculoCartasPermitidas(&triunfo, &triunfo, triunfo.palo);
	std::cout << "\n	 cartas que se pueden jugar: " << partida.jugadores[0].cartasPermitidas.size();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
