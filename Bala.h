#ifndef BALA_H
#define BALA_H

#include <ctime>

class Bala {
public:
	int x, y;
	int velocidad; // -1 sube, +1 baja 
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
