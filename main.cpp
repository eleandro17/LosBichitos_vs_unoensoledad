#include<iostream>
#include <conio2.h>   // la libre para manejar los caracteres en consola
#include "Jugador.h"
#include "Enemigo.h"
#include <windows.h> //esta para el sleep, tal vez lo puedo integrar al reloj conctime

using namespace std;

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
	//clrscr();
	
	Jugador jugador(40, 20, 3);
	Enemigo enemigo(10, 5, 2);
	
	bool running = true;
	while (running) {
		
		jugador.borrar();
		enemigo.borrar();
		
		enemigo.mover();
		if (_kbhit()) {
			char tecla = _getch();
			if (tecla == 'q' || tecla == 27) { running = false; continue; }
			jugador.mover(tecla);
		}
		
		
		jugador.dibujar();
		enemigo.dibujar();
		
		Sleep(30);
	}
	
	// volver a pantalla anterior
	clrscr();
	pantallaEntrada();
	
	return 0;
}
