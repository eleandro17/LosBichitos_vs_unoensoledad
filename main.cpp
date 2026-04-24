#include<iostream>
#include <conio2.h>   // la libre para manejar los caracteres en consola
#include "Jugador.h"
#include "Enemigo.h"
#include <windows.h> //esta para el sleep, tal vez lo puedo integrar al reloj conctime

using namespace std;

const int FILAS = 3;
const int COLS = 8;

void pantallaEntrada() {
	clrscr(); // limpia la pantalla
	
	textcolor(LIGHTBLUE);
	gotoxy(20, 2);
	cout << "Uno en Soledad contra los Bichitos";
	
	textcolor(LIGHTGREEN);
	gotoxy(20, 5);
	cout << "SPACE INVADERS LITE";
	
	textcolor(WHITE);
	gotoxy(15, 7);
	cout << "TP FINAL - Programacion en C++";
	
	gotoxy(15, 9);
	cout << u8"Alumno: Emilio Gómez Viera";
	
	gotoxy(15, 11);
	cout << "Instrucciones:";
	gotoxy(17, 12);
	cout << u8"A - movés a la izq";
	gotoxy(17, 13);
	cout << "D - movés a la derecha";
	gotoxy(17, 14);
	cout << "SPACEBAR - tirar tiros";
	
	gotoxy(15, 16);
	cout << "Apretá una tecla para empezar";
	getch(); // espera una tecla
}

int main() {
	pantallaEntrada();
	
	Jugador jugador(40, 20, 3);
		
	Enemigo enemigos[FILAS][COLS];
	
	{//inicializacion de enemigos
		char fila0[] = "TP_FINAL";
		char fila1[] = "_INTRO__";
		char fila2[] = "PROGRAMAC";
		
		for (int c = 0; c < COLS; c++)
			enemigos[0][c] = Enemigo(10 + c*8, 3, 1, fila0[c]);
		for (int c = 0; c < COLS; c++)
			enemigos[1][c] = Enemigo(10 + c*8, 5, 1, fila1[c]);
		for (int c = 0; c < COLS; c++)
			enemigos[2][c] = Enemigo(10 + c*8, 7, 1, fila2[c]);
	}
			//loop de juego
			bool running = true;
			while (running) {
				
				jugador.borrar();
				
				for (int f = 0; f < FILAS; f++)
					for (int c = 0; c < COLS; c++)
						enemigos[f][c].borrar();
						
						jugador.actualizarBalas();
						
						for (int f = 0; f < FILAS; f++)
							for (int c = 0; c < COLS; c++) {
								enemigos[f][c].actualizarBala();
								enemigos[f][c].mover();
						}
							
							if (_kbhit()) {
								char tecla = _getch();
								if (tecla == 'q' || tecla == 27) { running = false; continue; }
								jugador.mover(tecla);
								if (tecla == ' ') jugador.disparar();
							}
							
							jugador.dibujar();
							
							for (int f = 0; f < FILAS; f++)
								for (int c = 0; c < COLS; c++)
									enemigos[f][c].dibujar();
									
									Sleep(20);
			}
	
	// volver a pantalla anterior
	clrscr();
	pantallaEntrada();
	
	return 0;
}
