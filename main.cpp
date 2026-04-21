#include<iostream>
#include <conio2.h>   // la libre para manejar los caracteres en consola
#include "Jugador.h"
#include "Enemigo.h"

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
	cout << "Alumno: Emilio";
	
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
	
	clrscr(); // limpia pantalla
	
	// Crear un jugador en la parte inferior
	Jugador jugador(40, 20, 3); // posición (40,20), 3 vidas
	jugador.dibujar();
	
	// Crear un enemigo en la parte superior
	Enemigo enemigo(10, 5, 2); // posición (10,5), resistencia 2
	enemigo.dibujar();
	
	gotoxy(1, 23);
	cout << "Presione una tecla para salir...";
	getch();
	
	return 0;
}
