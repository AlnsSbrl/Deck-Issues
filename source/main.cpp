#include <stdio.h>
#include <stdlib.h>
#include "Partida.hpp"

int main(int argc, char *argv[])
{
	Partida partida;
	//partida.repartirCartas(); //igual cambiar esto a una escena
	partida.empiezaPartida();
		// Flush and swap framebuffers
		// gfxFlushBuffers();
		// gfxSwapBuffers();
		// Wait for VBlank
		// gspWaitForVBlank();
	return 0;
}