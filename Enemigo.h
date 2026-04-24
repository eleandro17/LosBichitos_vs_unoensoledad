#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <ctime>
#include "Bala.h"


class Enemigo {
public:
	int x, y;
	int resistencia; //declaro aca pero todavia no lo uso
	Enemigo(int posX, int posY, int resistencia, char sim);
	void dibujar();
	void mover();
	void borrar();
	
	clock_t tempo;
	clock_t paso;
	
	Bala bala; // cada enemigo tiene una sola bala
	void disparar();
	void actualizarBala();
	char simbolo;
	
	Enemigo(); // constructor por defecto
};
#endif

