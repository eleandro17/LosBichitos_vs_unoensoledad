#include "Enemigo.h"
#include <conio2.h>


Enemigo::Enemigo(int posX, int posY, int resistencia) {
	x= posX;
	y = posY;
	paso = CLOCKS_PER_SEC / 2;  // velocidad 2 = 2 por segundo
	tempo = clock();
}
void Enemigo::dibujar() {
	gotoxy(x, y);
	textcolor(RED);
	putch('X'); // dibujito enemigo
}

void Enemigo::mover() {
	if (tempo + paso > clock()) return;  // todavía no es hora
	tempo = clock();                      // reinicia el reloj
	
	if (y < 23) {
		y++;
	} else {
		y = 5;
	}
}
void Enemigo::borrar() {
	gotoxy(x,y);
	textcolor(BLUE);
	putch('-');
}

