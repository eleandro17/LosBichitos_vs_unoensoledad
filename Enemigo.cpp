#include <conio2.h>
#include "Enemigo.h"

Enemigo::Enemigo(int posX, int posY, int r) : Entidad(posX, posY), resistencia(r) {}

void Enemigo::dibujar() {
	textcolor(RED);
	gotoxy(x, y);
	putch('X'); // enemigo representado por 'X'
}

void Enemigo::mover() {
	// movimiento básico, después lo expandimos
	x++;
}
