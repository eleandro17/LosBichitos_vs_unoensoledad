#ifndef JUGADOR_H
#define JUGADOR_H

#include "Entidad.h"

class Jugador : public Entidad {
private:
	int vidas;
public:
	Jugador(int posX, int posY, int v);
	void dibujar() override;
	void mover() override;
	
	void perderVida();
	int getVidas() const;
};

#endif
