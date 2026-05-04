# "Los Bichitos vs Uno en Soledad" --> Este es el nuevo nombre poético
 
TPDVJ
FICH
UNL 

 TP Final — Introducción a la Programación 
 Alumno: Emilio Leandro Gómez Viera

6to COMMIT. 
-Agregada condición de victoria con un método previo(todosEliminados())
-Algunos ajustes y cuestiones estéticas (funciones que dibujan columnas y piso)

-Acotar la pantalla (algo así como la resolución pero en términos de caracteres) con SYSTEM. Una funcion interna: lo encontré en internet

-Reacomodamientos de la lógica de pantallas


---

## Descripción

Una simplificación del clásico *Space Invaders* pero desarrollado en C++ con consola de texto. Tenes que eliminar tres filas de enemigos que avanzan en el patrón de movimiento característico .


---

## El input ##

| Tecla | Acción |
|-------|--------|
| `A` | Mover  a la izquierda |
| `D` | Mover a la derecha |
| `SPACE` | Tirar Tiros |
| `Q` o `ESC` | salgo del loop de juego |//esto tal vez cambia después cuando haga las condiciones de ganar/perder.

---

## Estructura del proyecto

├── main.cpp
├── Jugador.h / Jugador.cpp
├── Enemigo.h / Enemigo.cpp ---> acá creé 2 subclases que sobreescriben dibujar()
├── GrupoEnemigos.h / GrupoEnemigos.cpp
└── Bala.h / Bala.cpp
└──Pantallas.h/Pantallas.cpp --> esto para limpiar el main, y un poco para separar responsabilidades tambien.


---

## Se implementaron ( al poder recibir daño) las diferentes resistencias de las clases hijas.

Enemigo          → color RED,        resistencia 1 //
>(hija)EnemigoMed   → color YELLOW,     resistencia 2
>(hija)EnemigoDuro  → color LIGHTGREEN, resistencia 3



Otros detalles estan comentados en el código.

 


