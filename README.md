# "Los Bichitos vs Uno en Soledad" --> Este es el nuevo nombre poético
 
TPDVJ
FICH
UNL 

 TP Final — Introducción a la Programación 
 Alumno: Emilio Leandro Gómez Viera

Este es el readme del 4to commit, lo debí haber creado al principio para trackear  mejor. Pero lo cree ahora que hice cambios en el diseño que no se me habían aparecido antes. Los explico mas abajo.

---

## Descripción

Una simplificación del clásico *Space Invaders* pero desarrollado en C++ con consola de texto. Tenes que eliminar tres filas de enemigos que avanzan en el patrón de movimiento característico (esto en este commit), mientras evitas sus ataques.



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

```
├── main.cpp
├── Jugador.h / Jugador.cpp
├── Enemigo.h / Enemigo.cpp ---> acá creé 2 subclases que sobreescriben dibujar()
├── GrupoEnemigos.h / GrupoEnemigos.cpp
└── Bala.h / Bala.cpp
```

---

## Diseño orientado a objetos

Recien en este commit es que aplico --> Herencia y polimorfismo.
Antes había pensado hacer una clase madre Entidad con hijas: Jugador y Enemigo, pero me iba a resultar poco práctico.
Despues decidí hacer subclases a partir de Enemigo: EnemigoMedio y EnemigoDuro

## SUBCLASES nuevas (o clases hijas)
La clase `Enemigo` es la clase Madre. Define el comportamiento común (moverse, disparar, dibujar) y declara `dibujar()` como método `virtual`, lo que permite que cada subclase lo sobreescriba con su propio color:

El array de punteros `Enemigo*` puede contener objetos de cualquiera de los tres tipos. Al llamar `enemigos[f][c]->dibujar()`.

Enemigo          → color RED,        resistencia 1 // estas todavías no implementadas
>(hija)EnemigoMed   → color YELLOW,     resistencia 2
>(hija)EnemigoDuro  → color LIGHTGREEN, resistencia 3

 Este es mi mejor polimorfismo por ahora. Son conceptos que todavía me resultan incómodos de aplicar.

### Punteros

Este es otro punto que me cuesta bastante aún. Incluso habiendo visto los smartpopinters en Programacion1 

Los enemigos se crean con `new` y se liberan con `delete` en el destructor de `GrupoEnemigos`:

```cpp
enemigos[0][c] = new EnemigoDuro(...);
enemigos[1][c] = new EnemigoMed(...);
enemigos[2][c] = new Enemigo(...);
```

Hay un destructor virtual en `Enemigo` que hace que al hacer `delete` sobre un puntero base se llame el destructor correcto. Esto no está en la cátedra, pero tuve que buscar porque no supe  sortear un montón de warnings de compilación.

# Clase nueva: GrupoEnemigos

Encapsula toda la lógica colectiva de los enemigos: inicialización, movimiento grupal, detección de borde los disparos. No hereda de `Enemigo`, maneja el bloque de los 3 arrays ( correspondientes a las clases madre, y las 2 hijas)
Tuve que crearla al darme cuenta que tenía que hacer el movimiento típico del spaceinvaders(toca borde, baja) y se me complicaba manejandolo de la forma anterior. 
Tambien es que el main se me iba quedando muy congestionado y con esto queda mas limpio.



# Las balas

El jugador como el enemigo tienen su propio array/instancia de `Bala`. Cada bala maneja su propio temporizador interno (los saqué del código de ejemplo)para moverse a velocidad independiente del loop principal. 


