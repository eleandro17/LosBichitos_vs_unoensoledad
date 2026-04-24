#include "Enemigo.h"
#include <conio2.h>
#include <cstdlib>

// -- Enemigo clase madre ------------------------------------------
Enemigo::Enemigo() {
	x = 0; y = 0; resistencia = 1; color = RED; simbolo = '?';
	paso = CLOCKS_PER_SEC *2;
	tempo = clock();
}

Enemigo::Enemigo(int posX, int posY, int res, char sim, int col) {
	x = posX; y = posY; resistencia = res; simbolo = sim; color = col;
	paso = CLOCKS_PER_SEC * 5;
	tempo = clock();
}

void Enemigo::dibujar() {
	gotoxy(x, y);
	textcolor(RED);
	putch(simbolo);
}

void Enemigo::borrar() {
	gotoxy(x, y);
	textcolor(BLUE);
	putch('-');
}
// este metodo queda sin llamarse porque paso a mover del bloque, pero lo dejo por si llego a necesitar despues
void Enemigo::mover() {
	if (tempo + paso > clock()) return;
	tempo = clock();
	if (y < 23) y += 1;
	else        y = 5;
}

void Enemigo::disparar() {
	if (!bala.activa)
		bala.init(x, y + 1, +1);
}

void Enemigo::actualizarBala() {
	if (rand() % 1000 == 0) disparar();
	bala.mover();
}

// -- EnemigoMed --------------------------------------------
EnemigoMed::EnemigoMed() : Enemigo() {
	resistencia = 2; color = YELLOW;
}

EnemigoMed::EnemigoMed(int posX, int posY, char sim)
	: Enemigo(posX, posY, 2, sim, YELLOW) {}

void EnemigoMed::dibujar() {
	gotoxy(x, y);
	textcolor(YELLOW);
	putch(simbolo);
}

// -- EnemigoDuro ---------
EnemigoDuro::EnemigoDuro() : Enemigo() {
	resistencia = 3; color = LIGHTGREEN;
}

EnemigoDuro::EnemigoDuro(int posX, int posY, char sim)
	: Enemigo(posX, posY, 3, sim, LIGHTGREEN) {}

void EnemigoDuro::dibujar() {
	gotoxy(x, y);
	textcolor(LIGHTGREEN);
	putch(simbolo);
}


