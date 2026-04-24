#include "Enemigo.h"
#include <conio2.h>
#include <cstdlib>  // para usar rand()


Enemigo::Enemigo() {
	x = 0; y = 0; resistencia = 1;
	paso = CLOCKS_PER_SEC / 2;
	tempo = clock();
}

Enemigo::Enemigo(int posX, int posY, int res, char sim) {
	x = posX; y = posY; resistencia = res;
	simbolo = sim;// el elemento simbolo
	paso = CLOCKS_PER_SEC /2;
	tempo = clock();
}
	
void Enemigo::dibujar() {
	gotoxy(x, y);
	textcolor(RED);
	putch(simbolo); // dibujito enemigo
}

void Enemigo::mover() {
	if (tempo + paso > clock()) return;  // todavía no es hora
	tempo = clock();                      // reinicia el reloj
	
	if (y < 23) {
		y+=1;
	} else {
		y = 5;// esto lo vuelve arriba cuando se pasa. Despues lo saco
	}
}
void Enemigo::borrar() {
	gotoxy(x,y);
	textcolor(BLUE);
	putch('-');
}

void Enemigo::disparar() {
	if (!bala.activa) {
		bala.init(x, y + 1, +1); // velocBaja
	}
}
void Enemigo::actualizarBala() {
	if (rand() % 1000 == 0) disparar();
	bala.mover();
}



