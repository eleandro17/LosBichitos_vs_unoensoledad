# "Los Bichitos vs Uno en Soledad" --> Este es el nuevo nombre poético
 
TPDVJ
FICH
UNL 

 TP Final — Introducción a la Programación 
 Alumno: Emilio Leandro Gómez Viera

5to COMMIT. Este fue largo, mas bien tedioso
- Se agregaron metodos recibirImpacto en el jugador y en el enemigo.
- En el jugador un bool estaVivo para obtener el flag. Un metodo que escribe un miniHUD con las vidas que va perdiendo
- Se agrega chequearColisiones en Grupoenemigos
- Se crea una pantalla consu metodo pantallafin() pero como se va engordando el main saqué las 2 a un fichero aparte, y seguramente haga lo mismo con el loop de juego despues.


---

## Descripción

Una simplificación del clásico *Space Invaders* pero desarrollado en C++ con consola de texto. Tenes que eliminar tres filas de enemigos que avanzan en el patrón de movimiento característico , mientras evitas sus ataques.



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

Enemigo          → color RED,        resistencia 1 // estas todavías no implementadas
>(hija)EnemigoMed   → color YELLOW,     resistencia 2
>(hija)EnemigoDuro  → color LIGHTGREEN, resistencia 3

El Centro de atención de este commit fue un bug de colisión: podía recibir daño y perder vidas pero no dañar (ni matar) a los enemigos del array.
Eran varias cosas:
- No había inicializado vivo en el constructor de Enemigo ( con lo cual nunca se seteaba el flag para ningun lado) 
- La tolerancia de la colisión era demasiado estricta, después busqué y encontré la solución por ahí ( todavía me confunde esto de usar consola como si estuvieramos en una época pre-framebuffer, pero a la vez escribiendo en una interfaz con framebuffer).
- Los enemigos eran inmortales visualmente ( agregué unos chequeadores para debbuggear que los dejo hasta ultima hora), eran como zombies que se redibujaban y disparaban aunque ya matados en la lógica. Era que el flag nunca se usaba en los métodos de dibujar, de borrar y de actualizarBalas.

Hay otros detalles que estan comentados en el código.

 


