#ifndef BALA_H
#define BALA_H

#include <ctime>

class Bala {
public:
	int x, y;
	int velocidad; // -1 sube (jugador), +1 baja (enemigo)
	bool activa;
	clock_t tempo;
	clock_t paso;
	
	Bala();
	void init(int posX, int posY, int veloc);// inicializa
	void dibujar();
	void borrar();
	void mover();
};

#endif
