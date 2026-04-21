#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Entidad.h"

class Enemigo : public Entidad {
private:
	int resistencia;
public:
	Enemigo(int posX, int posY, int r);
	void dibujar() override;
	void mover() override;
};

#endif

