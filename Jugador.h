#ifndef JUGADOR_H
#define JUGADOR_H
#include "Bala.h"// añado el metodo de disparar

const int MAX_BALAS_JUGADOR = 3;

class Jugador {
public:
	int x, y;        
	int vidas;
	Jugador(int posX, int posY, int vidas);
	void dibujar();
	void borrar();
	void mover(char tecla);
	//el metodo de disparo y las balas
	Bala balas[MAX_BALAS_JUGADOR];
	void disparar();
	void actualizarBalas();
};

#endif
