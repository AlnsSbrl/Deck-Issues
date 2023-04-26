// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Partida.h"

int main()
{
	Partida partida;
	bool seguir = true;
	while (seguir) {
		partida.repartirCartas();
		for (size_t i = 0; i < partida.jugadores.size(); i++)
		{
			std::cout << "\nJugador número: " << i;
			for (Carta* carta : partida.jugadores[i].cartas) {
				std::cout << "\n	valor carta: " << carta->valor;
			}
		}
		std::cout << "\nCartas repartidas:\n\n";
		for (size_t i = 0; i < partida.cartasDeLosJugadores.size(); i++)
		{
			std::cout << " | carta: "<<partida.cartasDeLosJugadores[i].valor;
		}
		//para ver si cada jugador apuntaba a donde debía simplemente :)
		system("pause");
	}
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
