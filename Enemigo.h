#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <ctime>
#include "Bala.h"

class Enemigo {
public:
	int x, y;
	int resistencia;
	char simbolo;
	int color;
	
	clock_t tempo;
	clock_t paso;
	Bala bala;
	
	Enemigo();
	Enemigo(int posX, int posY, int res, char sim, int col);
	
	virtual void dibujar(); //  virtual, la mama dibuja en RED
	void mover();
	void borrar();
	void disparar();
	void actualizarBala();
	
	virtual ~Enemigo() {} // destructor virtual, porque hay delete con puntero
};

class EnemigoMed : public Enemigo {
public:
	EnemigoMed();
	EnemigoMed(int posX, int posY, char sim);
	void dibujar() override; //  dibuja YELLOW
};

class EnemigoDuro : public Enemigo {
public:
	EnemigoDuro();
	EnemigoDuro(int posX, int posY, char sim);
	void dibujar() override; //  dibuja LIGHTGREEN
};

#endif
