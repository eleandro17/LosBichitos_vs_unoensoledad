#include "GrupoEnemigos.h"
#include <conio2.h>
#include <cstdlib>

GrupoEnemigos::GrupoEnemigos() {
	dirX = 1;
	paso = CLOCKS_PER_SEC /2;
	tempo = clock();
}

GrupoEnemigos::~GrupoEnemigos() {
	for (int f = 0; f < FILAS; f++)
		for (int c = 0; c < COLS; c++)
			delete enemigos[f][c];
}

void GrupoEnemigos::inicializar() {
	char fila0[] = "TP_FINAL";
	char fila1[] = "_INTRO__";
	char fila2[] = "PROGRAMAC";
	
	for (int c = 0; c < COLS; c++)
		enemigos[0][c] = new EnemigoDuro(10 + c*7, 3, fila0[c]);// achico un poco el espaciado 
		
	for (int c = 0; c < COLS; c++)
		enemigos[1][c] = new EnemigoMed(10 + c*7, 5, fila1[c]);
			
	for (int c = 0; c < COLS; c++)
		enemigos[2][c] = new Enemigo(10 + c*7, 7, 1, fila2[c], RED);
}

void GrupoEnemigos::mover() {
	if (tempo + paso > clock()) return;
	tempo = clock();
	
	bool tocoBorde = false;
	for (int f = 0; f < FILAS; f++)
		for (int c = 0; c < COLS; c++) {
			if (!enemigos[f][c]->vivo) continue;  // acá tambien el flag de VIVO
			int nx = enemigos[f][c]->x + dirX;
			if (nx <= 6 || nx >= 74) tocoBorde = true;// y cambio llos bordes
	}
		
		if (tocoBorde) {
			dirX *= -1;
			for (int f = 0; f < FILAS; f++)
				for (int c = 0; c < COLS; c++)
					enemigos[f][c]->y += 1;
		} else {
			for (int f = 0; f < FILAS; f++)
				for (int c = 0; c < COLS; c++)
					enemigos[f][c]->x += dirX;
		}
}

void GrupoEnemigos::dibujar() {
	for (int f = 0; f < FILAS; f++)
		for (int c = 0; c < COLS; c++)
			if (enemigos[f][c]->vivo)        // seguir prestando atencion a esto
				enemigos[f][c]->dibujar();
}

void GrupoEnemigos::borrar() {
	for (int f = 0; f < FILAS; f++)
		for (int c = 0; c < COLS; c++)
			if (enemigos[f][c]->vivo)        // y aca tambiennn
				enemigos[f][c]->borrar();
}
// Este es el loop viejo de actualizar balas. Mucho mas simple pero me daba unas lluvias de balas muy a merced del rand()
//void GrupoEnemigos::actualizarBalas() {
//	for (int f = 0; f < FILAS; f++)
//		for (int c = 0; c < COLS; c++)
//			if (enemigos[f][c]->vivo)        // y acá para que los zombiechar no disparen
//				enemigos[f][c]->actualizarBala();
//}
void GrupoEnemigos::actualizarBalas() {
	for (int f = 0; f < FILAS; f++) {
		bool hayBalaActiva = false;
		for (int c = 0; c < COLS; c++)
			if (enemigos[f][c]->vivo && enemigos[f][c]->bala.activa)
				hayBalaActiva = true;
		
		if (!hayBalaActiva && rand() % 300 == 0) {
			// elegir un enemigo vivo al azar en la fila
			int c = rand() % COLS;
			if (enemigos[f][c]->vivo)
				enemigos[f][c]->disparar();
		}
		
		// siempre actualizar todas las balas
		for (int c = 0; c < COLS; c++)
			enemigos[f][c]->actualizarBala();
	}
}

void GrupoEnemigos::chequearColisiones(Jugador& jugador) {
//	gotoxy(5, 35);
//	for (int c = 0; c < COLS; c++) {
//		if (abs(jugador.balas[0].x - enemigos[0][c]->x) <= 1) {
//			cprintf("MATCH X: bala x=%d y=%d | enem[0][%d] x=%d y=%d vivo=%d   ",
//					jugador.balas[0].x, jugador.balas[0].y,
//					c, enemigos[0][c]->x, enemigos[0][c]->y, enemigos[0][c]->vivo);
//		}
//	}
	
	// balas del jugador contra enemigos
	for (int i = 0; i < MAX_BALAS_JUGADOR; i++) {
		Bala& bala = jugador.balas[i];
		if (!bala.activa) continue;
		
		bool impacto = false;
		for (int f = 0; f < FILAS && !impacto; f++)
			for (int c = 0; c < COLS && !impacto; c++) {
				Enemigo* enem = enemigos[f][c];
				if (!enem->vivo) continue;
				
					if (abs(bala.x - enem->x) <= 1 && bala.y <= enem->y + 1 && bala.y >= enem->y - 3)  {
					bala.borrar();
					bala.activa = false;
					enem->recibirImpacto();
					
					jugador.puntajeParcial += 1;
				}
		}
	}
	
	// balas de los enemigos contra el jugador
	for (int f = 0; f < FILAS; f++)
		for (int c = 0; c < COLS; c++) {
			Bala& bala = enemigos[f][c]->bala;
			if (!bala.activa) continue;
			if (abs(bala.x - jugador.x) <= 1 && abs(bala.y - jugador.y) <= 1) {
				bala.borrar();
				bala.activa = false;
				jugador.recibirImpacto();
			}
	}
}
bool GrupoEnemigos::todosEliminados() {
	for (int f = 0; f < FILAS; f++)
		for (int c = 0; c < COLS; c++)
			if (enemigos[f][c]->vivo) return false;
	return true;
}
// la ultima condicion de derrota, medio dificil que  suceda, pero esta en la consigna asi que lo pongo
bool GrupoEnemigos::llegaronAlPiso() {
	for (int f = 0; f < FILAS; f++)
		for (int c = 0; c < COLS; c++)
			if (enemigos[f][c]->vivo && enemigos[f][c]->y >= 27)
				return true;
	return false;
}
	
	
	
	
