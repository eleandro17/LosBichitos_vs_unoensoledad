#include<iostream>
#include <conio2.h>   // la libre para manejar los caracteres en consola
#include "Jugador.h"
#include <windows.h> //esta para el sleep, tal vez lo puedo integrar al reloj conctime
#include "GrupoEnemigos.h"
#include "Pantallas.h"
using namespace std;


int main() {
	system("mode con cols=80 lines=35");
	pantallaEntrada();
	
			
	bool reiniciar = true;
	while (reiniciar) {
		
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
			
			if (!jugador.estaVivo()) { running = false; continue; }
			
			// condicion de ganar
			if (grupo.todosEliminados()) {
				running = false;
				continue;
			}
			
			if (_kbhit()) {
				char tecla = _getch();
				if (tecla == 'q' || tecla == 27) {
					running = false;
					reiniciar = false;
					continue;
				}
				jugador.mover(tecla);
				if (tecla == ' ') jugador.disparar();
			}
			
			jugador.dibujar();
			jugador.dibujarHUD();
			grupo.dibujar();
			
			Sleep(10);
		}
		
						
		if (grupo.todosEliminados()) {
			reiniciar = pantallaGanar();  // igual que pantallaFin
		}
		else if (reiniciar) {
			reiniciar = pantallaFin();
		}
		
		
	}
	
	clrscr();
	return 0;
}
