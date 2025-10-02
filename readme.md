# 🚀 DCAGII Flappy Bird - Documentación del Proyecto

<div align="center">

## 🎮 HERO SECTION

```
██████╗  ██████╗ █████╗  ██████╗ ██╗██╗    ███████╗██╗      █████╗ ██████╗ ██████╗ ██╗   ██╗
██╔══██╗██╔════╝██╔══██╗██╔════╝ ██║██║    ██╔════╝██║     ██╔══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝
██║  ██║██║     ███████║██║  ███╗██║██║    █████╗  ██║     ███████║██████╔╝██████╔╝ ╚████╔╝ 
██║  ██║██║     ██╔══██║██║   ██║██║██║    ██╔══╝  ██║     ██╔══██║██╔═══╝ ██╔═══╝   ╚██╔╝  
██████╔╝╚██████╗██║  ██║╚██████╔╝██║██║    ██║     ███████╗██║  ██║██║     ██║        ██║   
╚═════╝  ╚═════╝╚═╝  ╚═╝ ╚═════╝ ╚═╝╚═╝    ╚═╝     ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝        ╚═╝   
```

### ⚡ Proyecto de Desarrollo de Videojuegos
### 🎯 Implementación del Clásico Flappy Bird con raylib

</div>

# 📘 Práctica 0: Desarrollo de Flappy Bird con raylib

## 🎯 Objetivo
- Desarrollar una versión básica del clásico **Flappy Bird** usando **raylib** en C/C++.
- Comprender:
  - Bucle de juego  
  - Manejo de entradas de teclado  
  - Dibujo de sprites  
  - Manejo de colisiones  
  - Transiciones de estados  

---

## 🗂️ Entrega
- Subir el proyecto a **UACloud** en formato:  
  `p0_<tu_DNI>.tar.gz`
- **Fecha límite:** 8 de octubre de 2025

---

## 🛠️ Preparación del proyecto

1. Usar la **plantilla de videojuegos** de la asignatura (GitHub → *Use this template*).
2. Clonar el repositorio en local.
3. Estructura final del proyecto:

flappy_bird/
├─ assets/
├─ src/
│ └─ ...
├─ vendor/
├─ include/
└─ lib/


4. Añadir **raylib**:

**Clonar y compilar:**
git clone https://github.com/raysan5/raylib.git  
cd raylib/src  
make PLATFORM=PLATFORM_DESKTOP

**Copiar:**
- `libraylib.a` → `vendor/lib/`  
- `raylib.h`, `raymath.h`, `rlgl.h` → `vendor/include/`

---

## 📚 Recomendación
Revisar documentación y ejemplos de **raylib**:
- Cheatsheet  
- Ejemplos oficiales  

---

## 🧪 Ejercicios

### 🔹 Ejercicio 0: Creación de ventana

**En `main.cpp`:**
- `InitWindow(288, 512, "Flappy Bird DCA")`

**En `MainGameState`:**
- `BeginDrawing()`  
- `ClearBackground()`  
- `DrawText("Bienvenido a Flappy Bird DCA", ...)`  
- `EndDrawing()`

**Compilar:**
g++ -o game src/*.cpp -I src/ -I vendor/include/ -L vendor/lib -lraylib -lGL -lm

**Instalar dependencias si falla:**
sudo apt install xorg-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev

---

### 🔹 Ejercicio 1: Mecánica principal

- Definir `Delta Time` con `GetFrameTime()`.
- Crear `struct Bird { float x, y, vy; };`
- Inicializar en `(200, 200)`.
- **Input:** si `Espacio` → `vy = -300`.
- **Update:**
  - `vy += gravedad * deltaTime`
  - `y += vy * deltaTime`
- **Render:** `DrawCircle(x, y, 17, RED)`

---

### 🔹 Ejercicio 2: Tuberías

- Definir `struct PipePair { Rectangle top, bot; bool scored=false; };`
- Usar `deque<PipePair>`.
- Constantes: `PIPE_W = 32`, `PIPE_H = 320`
- Generar tuberías con `GetRandomValue`.
- Mover tuberías: `x -= PIPE_SPEED * deltaTime`.
- Eliminar tuberías fuera de pantalla.
- Renderizar con `DrawRectangle`.

---

### 🔹 Ejercicio 3: Colisiones y Game Over

- Calcular **bounding box** del jugador (`Rectangle`).
- Usar `CheckCollisionRecs`.
- Crear clase `GameOverState`:
  - Fondo igual  
  - Texto: *Game Over*

**Si colisión →**
this->state_machine->add_state(std::make_unique<GameOverState>(), true);

- Reiniciar partida al pulsar `Espacio`.

---

### 🔹 Ejercicio 4: Puntuación

- Variable `score`.
- Sumar puntos al pasar tuberías.
- Mostrar con `DrawText(std::to_string(score).c_str(), ...)`.
- Pasar puntuación a `GameOverState`.

---

### 🔹 Ejercicio 5: Sprites y mejoras

- Usar assets de [samuelcust/flappy-bird-assets](https://github.com/samuelcust/flappy-bird-assets).
- Copiar carpeta `sprites` → `assets/`.
- Cargar texturas con `LoadTexture`.
- Ajustar `width`, `height`, `PIPE_W`, `PIPE_H`.
- Renderizar con:
  - `DrawTexture` (jugador)
  - `DrawTextureEx` (tuberías, con rotación)

---

## ⭐ Extras (opcionales)

1. Añadir sonidos.  
2. Dificultad progresiva (velocidad y huecos).  
3. Renderizar puntuación con sprites.  
4. Animaciones con cronómetro.  
5. Refactorizar código con patrones de diseño.
