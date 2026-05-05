#ifndef JUGADOR_H
#define JUGADOR_H
#include "Bala.h"
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
	
	void recibirImpacto();
	bool estaVivo();      
	void dibujarHUD(); //las vidas del jugador. Y ahora el puntaje parcial
	int puntajeParcial = 0;// Suma los tiros que dan con el enemigo. Al ser una  sola pantalla es trivial la sumatoria. Pero bueno
};

#endif
