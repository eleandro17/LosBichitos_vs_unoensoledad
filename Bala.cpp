#include "Bala.h"
#include <conio2.h>

Bala::Bala() {
	activa = false;
}

void Bala::init(int posX, int posY, int veloc) {
	x = posX;
	y = posY;
	velocidad = veloc;
	activa = true;
	tempo = clock();
	paso = CLOCKS_PER_SEC / 10; // 10 posiciones por segundo
}

void Bala::dibujar() {
	if (!activa) return;
	gotoxy(x, y);
	textcolor(velocidad == -1 ? YELLOW : RED);
	putch('|');
}

void Bala::borrar() {
	if (!activa) return;
	gotoxy(x, y);
	putch(' ');
}

void Bala::mover() {
	if (!activa) return;
	if (tempo + paso > clock()) return;
	tempo = clock();
	borrar();
	y += velocidad;
	if (y < 1 || y > 24) {
		activa = false;
		return;
	}
	dibujar();
}
