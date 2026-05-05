# "Los Bichitos vs Uno en Soledad" --> Este es el nuevo nombre poético
 
TPDVJ
FICH
UNL 

 TP Final — Introducción a la Programación 
 Alumno: Emilio Leandro Gómez Viera

7mo COMMIT. 
-Agregados puntajesparciales, que luego se calculan y se muestran según las vidas perdidas con el método cosecharPuntaje()
- puntajeparcial se muestra en HUD y lo otro se dibuja en la pantalla final
-Saqué la lógica de juego a un fichero aparte

-Un bug de bala cuyo dibujado se congelaba en el trayecto: creo que se arregló separando borrado/dibujado( el orden de las llamadas), y en recibirImpacto() desactivando la bala del enemigo cuando muere.

- La condicion de derrota que faltaba: la puse porque estaba en la consigna, porque al menos en esta versión de SpaceInvaders es medio dificil que suceda.

-Reacomodamientos de la lógica de pantallas. Ajustes visuales

- Cambio en el loop de actualizarBalas(): el anterior quedaba muy a merced de rand() como bloque. El actual mueve una bala activa por fila, dispara con un  rand() único por frame. De todos modos dejé el anterior comentado. 


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
├── LogicadeJuego.h/.cpp --->>>>> Esto es de este commit
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

 


