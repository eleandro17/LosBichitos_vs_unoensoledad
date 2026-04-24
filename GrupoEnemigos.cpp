#include "GrupoEnemigos.h"
#include <conio2.h>

GrupoEnemigos::GrupoEnemigos() {
	dirX = 1;
	paso = CLOCKS_PER_SEC * 1;
	tempo = clock();
}

GrupoEnemigos::~GrupoEnemigos() {
	for (int f = 0; f < FILAS; f++)
		for (int c = 0; c < COLS; c++)
			delete enemigos[f][c];
}

void GrupoEnemigos::inicializar() {
	char fila0[] = "TP_FINAL";
	char fila1[] = "_INTRO__";
	char fila2[] = "PROGRAMAC";
	
	for (int c = 0; c < COLS; c++)
		enemigos[0][c] = new EnemigoDuro(10 + c*8, 3, fila0[c]);
		for (int c = 0; c < COLS; c++)
			enemigos[1][c] = new EnemigoMed(10 + c*8, 5, fila1[c]);
			for (int c = 0; c < COLS; c++)
				enemigos[2][c] = new Enemigo(10 + c*8, 7, 1, fila2[c], RED);
}

void GrupoEnemigos::mover() {
	if (tempo + paso > clock()) return;
	tempo = clock();
	
	bool tocoBorde = false;
	for (int f = 0; f < FILAS; f++)
		for (int c = 0; c < COLS; c++) {
			int nx = enemigos[f][c]->x + dirX;
			if (nx <= 1 || nx >= 79) tocoBorde = true;
	}
		
		if (tocoBorde) {
			dirX *= -1;
			for (int f = 0; f < FILAS; f++)
				for (int c = 0; c < COLS; c++)
					enemigos[f][c]->y += 1;
		} else {
			for (int f = 0; f < FILAS; f++)
				for (int c = 0; c < COLS; c++)
					enemigos[f][c]->x += dirX;
		}
}

void GrupoEnemigos::dibujar() {
	for (int f = 0; f < FILAS; f++)
		for (int c = 0; c < COLS; c++)
			enemigos[f][c]->dibujar();
}

void GrupoEnemigos::borrar() {
	for (int f = 0; f < FILAS; f++)
		for (int c = 0; c < COLS; c++)
			enemigos[f][c]->borrar();
}

void GrupoEnemigos::actualizarBalas() {
	for (int f = 0; f < FILAS; f++)
		for (int c = 0; c < COLS; c++)
			enemigos[f][c]->actualizarBala();
}
