#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <ctime>

// #include "Entidad.h" 
// esta clase se fue. Pienso que no tenía real sentido practico. Puedo implementar herencia y polimorfismo en los  tipos de enemigo sin complicar tanto el codigo

class Enemigo {
public:
	int x, y;
	int resistencia; //declaro aca pero todavia no lo uso
	Enemigo(int posX, int posY, int resistencia);
	void dibujar();
	void mover();
	void borrar();
	
	clock_t tempo;
	clock_t paso;
};
#endif

