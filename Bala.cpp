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
	textcolor(velocidad == -1 ? YELLOW : RED);// operador ternario, para pintar bala roja o amarilla
	putch(velocidad == -1 ? '^' : 'v');  // lo mismo de arriba pero para el ch
}

void Bala::borrar() {
	if (!activa) return;
	gotoxy(x, y);
	putch(' ');
}

void Bala::mover() {
	if (!activa) return;
	borrar();  // borro antes
	
	if (tempo + paso <= clock()) {
		tempo = clock();
		y += velocidad;
		if (y < 1 || y > 27) {
			activa = false;
			return;
		}
	}
	
	dibujar(); // y despues dibujo. Tenia un bug donde se congelaba el dibujo de las balas del enemigo
}
