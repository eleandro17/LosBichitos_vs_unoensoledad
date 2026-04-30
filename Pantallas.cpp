#include "Pantallas.h"
#include <iostream>
#include <conio2.h>

using namespace std;

void pantallaEntrada() {
	clrscr();
	
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
	getch();
}

bool pantallaFin() {
	clrscr();
	
	textcolor(RED);
	gotoxy(30, 8);
	cout << "GAME OVER";
	
	textcolor(WHITE);
	gotoxy(25, 11);
	cout << "R - Jugar de nuevo";
	gotoxy(25, 12);
	cout << "ESC - Salir";
	
	while (true) {
		char tecla = getch();
		if (tecla == 'r' || tecla == 'R') return true;
		if (tecla == 27) return false; // Escape
		
	}
}
