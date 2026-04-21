#include <conio2.h>
#include "Jugador.h"

Jugador::Jugador(int posX, int posY, int v) : Entidad(posX, posY), vidas(v) {}

void Jugador::dibujar() {
	textcolor(LIGHTCYAN);
	gotoxy(x, y);
	putch('A'); // nave representada por 'A'
}

void Jugador::mover() {
	if (kbhit()) {
		char tecla = getch();
		if (tecla == 'a' && x > 1) x--;
		if (tecla == 'd' && x < 78) x++;
	}
}

void Jugador::perderVida() { vidas--; }
int Jugador::getVidas() const { return vidas; }
