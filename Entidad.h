#ifndef ENTIDAD_H
#define ENTIDAD_H

//esta es la clase mamá. Sus Hijos son por ahora Jugador y Enemigo. Y sus metodos dibujar y mover que van a polimorfearse segun se necesite. 
class Entidad {
protected:
	int x, y; // posición en pantalla
public:
	Entidad(int posX, int posY);
	virtual ~Entidad() {} //destructor d entidad
	
	virtual void dibujar() = 0;   // virtual
	virtual void mover() = 0;     // este tambien
	
	int getX() const { return x; }
	int getY() const { return y; }
	void setPos(int posX, int posY) { x = posX; y = posY; }
};

#endif

