#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador {
public:
	int x, y;        
	int vidas;
	Jugador(int posX, int posY, int vidas);
	void dibujar();
	void borrar();
	void mover(char tecla);
};

#endif
