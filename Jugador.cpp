#include <conio2.h>
#include "Jugador.h"

Jugador::Jugador(int posX, int posY, int v){
	x = posX;
	y = posY;
	vidas = v;
}

void Jugador::dibujar() {
	gotoxy(x, y);
	textcolor(LIGHTBLUE);
	putch('N'); // dibujito del jugador
	

}

void Jugador::borrar() {
	gotoxy(x,y);
	textcolor(RED);
	putch('-');
	
}
void Jugador::mover(char tecla) {
	if (tecla == 'a' && x > 1)  x--;
	if (tecla == 'd' && x < 79) x++;
}

void Jugador::disparar() {
	for (int i = 0; i < MAX_BALAS_JUGADOR; i++) {
		if (!balas[i].activa) {
			balas[i].init(x, y - 1, -1); // velocSube
			return;
		}
	}
	// si estan todas activas, no dispara
}
void Jugador::actualizarBalas() {
	for (int i = 0; i < MAX_BALAS_JUGADOR; i++) {
		balas[i].mover();
	}
}

void Jugador::recibirImpacto() {
	vidas--;
	// unefectito corto
	gotoxy(x, y);
	textcolor(RED);
	putch('X');
}

bool Jugador::estaVivo() {
	return vidas > 0;
}

void Jugador::dibujarHUD() {
	gotoxy(3, 29);
	textcolor(LIGHTRED);
	cprintf("VIDAS: ");
	for (int i = 0; i < vidas; i++)
		cprintf("<3 ");
	for (int i = vidas; i < 3; i++)
		cprintf("   ");
}
