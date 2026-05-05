#include <conio2.h>
#include "Pantallas.h"
#include "LogicaDeJuego.h"
#include <windows.h>

int main() {
	system("mode con cols=80 lines=35");
	pantallaEntrada();
	
	bool reiniciar = true;
	while (reiniciar)
		reiniciar = jugar();
	
	clrscr();
	return 0;
}
