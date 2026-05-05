#include "LogicaDeJuego.h"
#include <conio2.h>
#include <windows.h>

#include "GrupoEnemigos.h"
#include "Pantallas.h"

int cosecharPuntaje(Jugador& jugador) {
	return jugador.puntajeParcial * jugador.vidas; //solo acá se dá una variacion. Porque la suma de ptos a a ser siempre la misma
}
bool jugar() {
	Jugador jugador(40, 27, 3);
	GrupoEnemigos grupo;
	grupo.inicializar();
	clrscr();
	
	bool running = true;
	while (running) {
		dibujarColumnas();
		dibujarPiso();
		
		jugador.borrar();
		grupo.borrar();
		
		jugador.actualizarBalas();
		grupo.actualizarBalas();
		grupo.mover();
		grupo.chequearColisiones(jugador);
		
			if (!jugador.estaVivo() || grupo.llegaronAlPiso()) { 
			running = false; 
			continue; 
		}		
			if (grupo.todosEliminados())
			return pantallaGanar(cosecharPuntaje(jugador));
		
		if (_kbhit()) {
			char tecla = _getch();
			if (tecla == 'q' || tecla == 27) return false;  // salir sin reiniciar
			jugador.mover(tecla);
			if (tecla == ' ') jugador.disparar();
		}
		
		jugador.dibujar();
		jugador.dibujarHUD();
		grupo.dibujar();
		
		Sleep(10);
	}
	
	if (grupo.todosEliminados())
		return pantallaGanar(cosecharPuntaje(jugador)); 
	else
		return pantallaFin();
}
