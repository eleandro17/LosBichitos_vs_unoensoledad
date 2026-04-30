#ifndef GRUPOENEMIGOS_H
#define GRUPOENEMIGOS_H

//esta clase es para manejar el movimiento del bloque de enemigos, tambien para limpiar un poco el main

#include <ctime>
#include "Enemigo.h"
#include "Jugador.h"

const int FILAS = 3;
const int COLS  = 8;

class GrupoEnemigos {
public:
	Enemigo* enemigos[FILAS][COLS];
	int dirX;
	clock_t tempo;
	clock_t paso;
	
	GrupoEnemigos();
	~GrupoEnemigos();
	
	void inicializar();
	void mover();
	void dibujar();
	void borrar();
	void actualizarBalas();
	
	void chequearColisiones(Jugador& jugador); //  nuevo
};

#endif
