<div align="center">

# 🎮 FLAPPY BIRD DCA EDITION

### *La experiencia arcade clásica reimaginada con tecnología moderna*

```
███████╗██╗      █████╗ ██████╗ ██████╗ ██╗   ██╗    ██████╗ ██╗██████╗ ██████╗ 
██╔════╝██║     ██╔══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝    ██╔══██╗██║██╔══██╗██╔══██╗
█████╗  ██║     ███████║██████╔╝██████╔╝ ╚████╔╝     ██████╔╝██║██████╔╝██║  ██║
██╔══╝  ██║     ██╔══██║██╔═══╝ ██╔═══╝   ╚██╔╝      ██╔══██╗██║██╔══██╗██║  ██║
██║     ███████╗██║  ██║██║     ██║        ██║       ██████╔╝██║██║  ██║██████╔╝
╚═╝     ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝        ╚═╝       ╚═════╝ ╚═╝╚═╝  ╚═╝╚═════╝ 
```

[![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![raylib](https://img.shields.io/badge/raylib-5.6-FF0000?style=for-the-badge&logo=raylib&logoColor=white)](https://www.raylib.com/)
[![Linux](https://img.shields.io/badge/Linux-Ubuntu-FCC624?style=for-the-badge&logo=linux&logoColor=black)](https://ubuntu.com/)
[![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)](LICENSE)

---

### 🌟 *Un viaje adictivo donde cada pixel cuenta y cada salto desafía la gravedad*

</div>

---

## 🎯 SOBRE EL JUEGO

**Flappy Bird DCA Edition** es una reimplementación moderna del icónico juego arcade que capturó los corazones (y la frustración) de millones. Desarrollado desde cero con **C++17** y la poderosa librería gráfica **raylib**, este proyecto combina nostalgia retro con arquitectura de software profesional.

### 🎪 La Experiencia

Controla a un valiente pájaro azul en su épica travesía a través de un laberinto interminable de tuberías verdes. Cada tap del espacio es una decisión de vida o muerte. Cada tubería superada es una victoria contra la gravedad. ¿Cuánto puedes durar?

<div align="center">

### 🏆 **TU RÉCORD TE ESTÁ ESPERANDO** 🏆

</div>

---

## ✨ CARACTERÍSTICAS PRINCIPALES

<div align="center">

| 🎨 **Visual** | 🎵 **Audio** | 🎮 **Gameplay** | 🏗️ **Arquitectura** |
|:---:|:---:|:---:|:---:|
| Sprites HD | Efectos de sonido inmersivos | Física realista | State Machine Pattern |
| Fuente personalizada | Audio espacial | Colisiones precisas | Código modular |
| Fondos dinámicos | 5 efectos únicos | Dificultad progresiva | Gestión de recursos |
| Interfaz pulida | Sistema de audio completo | Controles responsivos | C++ moderno |

</div>

### 🎨 **SISTEMA VISUAL AVANZADO**

- 🖼️ **Sprites Originales** - Gráficos pixel-art de alta calidad
- 🎭 **Menú Animado** - Texto parpadeante con efectos visuales
- 🌈 **Paleta de Colores** - Esquema cromático optimizado
  - 🟢 Menú: Fondo personalizado + textos verdes neón
  - 🟡 Juego: Puntuación amarilla con sombra dinámica
  - 🔴 Game Over: Pantalla dramática en rojo intenso
- 🔤 **Tipografía Custom** - Fuente "Luckiest Guy" para máximo impacto
- ⚡ **60 FPS** - Fluidez garantizada con sincronización perfecta

### 🎵 **EXPERIENCIA SONORA INMERSIVA**

```
🔊 SISTEMA DE AUDIO COMPLETO
├── 🚀 jump.wav        → Efecto al saltar (swoosh)
├── 🏆 point.wav       → Sonido al sumar puntos (ding)
├── 💥 hit.wav         → Impacto con obstáculos (crash)
├── 💀 die.wav         → Sonido de derrota (game over)
└── 🎵 menu_select.wav → Inicio de partida (confirmación)
```

- **Formato Optimizado**: WAV PCM 16-bit, 44.1kHz
- **Audio Engine**: Sistema miniaudio de raylib
- **Respuesta Instantánea**: Latencia < 10ms
- **Mix Dinámico**: Múltiples canales simultáneos

### 🎮 **MECÁNICAS DE JUEGO**

#### 🕹️ Controles Intuitivos
```
┌────────────────────────────────────┐
│  ESPACIO  →  Saltar / Aletear     │
│  ESC      →  Salir del juego      │
└────────────────────────────────────┘
```

#### ⚙️ Física Realista
- **Gravedad**: 980 px/s² (simulación física precisa)
- **Impulso de Salto**: -300 px/s (sensación arcade auténtica)
- **Delta Time**: Independiente de FPS para consistencia
- **Colisiones**: Hitbox optimizado al 70% para jugabilidad justa

#### 🏗️ Sistema de Tuberías Dinámico
- Generación procedural infinita
- Separación óptima de 250 píxeles
- Altura aleatoria del gap (100-300px)
- Velocidad constante de 100 px/s
- Eliminación automática fuera de pantalla

---

## 🛠️ STACK TECNOLÓGICO

<div align="center">

### 🔧 **CORE TECHNOLOGY**

</div>

```cpp
┌─────────────────────────────────────────────────────────────┐
│                    ARQUITECTURA DEL PROYECTO                │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   ┌───────────────────────────────────────────────────┐   │
│   │         C++17 (ISO/IEC 14882:2017)                │   │
│   │  • Smart Pointers (unique_ptr)                    │   │
│   │  • STL Containers (deque, string)                 │   │
│   │  • Lambda Expressions                             │   │
│   │  • Move Semantics                                 │   │
│   └───────────────────────────────────────────────────┘   │
│                           ⬇️                                │
│   ┌───────────────────────────────────────────────────┐   │
│   │         raylib 5.6-dev (Graphics Engine)          │   │
│   │  • OpenGL 4.1 Core Profile                        │   │
│   │  • GLFW Window Management                         │   │
│   │  • miniaudio Backend (PulseAudio)                 │   │
│   │  • Texture Management                             │   │
│   │  • Collision Detection (AABB)                     │   │
│   └───────────────────────────────────────────────────┘   │
│                           ⬇️                                │
│   ┌───────────────────────────────────────────────────┐   │
│   │         State Machine Pattern                     │   │
│   │  • MenuState      → Pantalla inicial              │   │
│   │  • MainGameState  → Lógica del juego              │   │
│   │  • GameOverState  → Pantalla de derrota           │   │
│   └───────────────────────────────────────────────────┘   │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

### 📦 **DEPENDENCIAS**

| Librería | Versión | Propósito |
|----------|---------|-----------|
| **raylib** | 5.6-dev | Motor gráfico y de audio |
| **OpenGL** | 4.1+ | Renderizado acelerado por GPU |
| **GLFW** | 3.x | Gestión de ventanas y eventos |
| **miniaudio** | (integrado) | Backend de audio multiplataforma |

### 🏗️ **PATRONES DE DISEÑO**

```cpp
🎯 State Machine Pattern
   ├── GameState (interfaz abstracta)
   │   ├── init()        → Inicialización
   │   ├── handleInput() → Gestión de entrada
   │   ├── update()      → Lógica de juego
   │   ├── render()      → Renderizado
   │   ├── pause()       → Pausa
   │   └── resume()      → Reanudación
   │
   └── StateMachine (gestor de estados)
       ├── add_state()           → Agregar estado
       ├── remove_state()        → Eliminar estado
       └── handle_state_changes()→ Transiciones
```

---

## 📁 ESTRUCTURA DEL PROYECTO

```
DCAGII-Game-Template/
│
├── 📂 src/                      # Código fuente C++
│   ├── 🎮 main.cpp              # Punto de entrada
│   ├── 🏛️ StateMachine.{hpp,cpp}# Gestor de estados
│   ├── 🎯 GameState.{hpp,cpp}   # Clase base abstracta
│   ├── 🎪 MenuState.{hpp,cpp}   # Estado del menú
│   ├── 🕹️ MainGameState.{hpp,cpp}# Estado del juego
│   └── 💀 GameOverState.{hpp,cpp}# Estado de game over
│
├── 📂 assets/                   # Recursos multimedia
│   ├── 🎨 sprites/              # Texturas y sprites
│   │   ├── bluebird-midflap.png # Sprite del pájaro
│   │   ├── pipe-green.png       # Textura de tuberías
│   │   ├── background-day.png   # Fondo del juego
│   │   └── start-game.png       # Fondo del menú
│   ├── 🔊 sounds/               # Efectos de sonido
│   │   ├── jump.wav             # Sonido de salto
│   │   ├── point.wav            # Sonido de punto
│   │   ├── hit.wav              # Sonido de colisión
│   │   ├── die.wav              # Sonido de muerte
│   │   └── menu_select.wav      # Sonido de inicio
│   └── 🔤 fonts/                # Fuentes personalizadas
│       └── LuckiestGuy.ttf      # Tipografía principal
│
├── 📂 vendor/                   # Librerías externas
│   ├── include/                 # Headers de raylib
│   │   ├── raylib.h             # API principal
│   │   ├── raymath.h            # Matemáticas
│   │   └── rlgl.h               # OpenGL wrapper
│   └── lib/                     # Librerías compiladas
│       └── libraylib.a          # raylib estática
│
├── 📂 build/                    # Ejecutables compilados
│   └── game                     # Binario del juego
│
└── 📄 readme.md                 # Este archivo
```

---

## 🚀 INSTALACIÓN Y EJECUCIÓN

### 📋 Requisitos Previos

```bash
# Sistema Operativo
Ubuntu 24.04 LTS (o superior)

# Compilador
GCC 13+ con soporte C++17

# Dependencias del sistema
sudo apt-get install -y \
    build-essential \
    libgl1-mesa-dev \
    libx11-dev \
    libxrandr-dev \
    libxinerama-dev \
    libxcursor-dev \
    libxi-dev \
    libpthread-stubs0-dev
```

### ⚡ Compilación Rápida

```bash
# 1. Clonar el repositorio
git clone https://github.com/Naoufal-Charafat/DCAGII-Game-Template.git
cd DCAGII-Game-Template

# 2. Compilar el juego
g++ -std=c++17 -Wall -Wextra -g \
    -I src/ \
    -I vendor/include/ \
    src/*.cpp \
    -L vendor/lib/ \
    -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 \
    -o build/game

# 3. Ejecutar
./build/game
```

### 🎮 Ejecución con Script

```bash
# Dar permisos de ejecución
chmod +x run

# Ejecutar el juego
./run
```

---

## 🎯 CÓMO JUGAR

<div align="center">

### 🕹️ **CONTROLES**

</div>

```
╔═══════════════════════════════════════════════════════════╗
║                                                           ║
║    🎮  ESPACIO  →  Hacer que el pájaro aletee           ║
║                                                           ║
║    🚪  ESC      →  Salir del juego                       ║
║                                                           ║
╚═══════════════════════════════════════════════════════════╝
```

### 📖 **REGLAS**

1. **🐦 Mantén al pájaro volando** - Presiona ESPACIO para aletear
2. **🚫 Evita las tuberías** - No choques con los obstáculos verdes
3. **⬆️⬇️ Mantente en pantalla** - No toques el techo ni el suelo
4. **🏆 Acumula puntos** - Cada tubería superada = +1 punto
5. **💀 Un error y pierdes** - No hay segundas oportunidades

### 🎯 **OBJETIVOS**

```
┌─────────────────────────────────────────┐
│  🥉  BRONCE    →    10 puntos          │
│  🥈  PLATA     →    25 puntos          │
│  🥇  ORO       →    50 puntos          │
│  💎  DIAMANTE  →   100 puntos          │
│  👑  LEYENDA   →   200+ puntos         │
└─────────────────────────────────────────┘
```

---

## 🎨 CAPTURAS DE PANTALLA

<div align="center">

### 🎪 **MENÚ PRINCIPAL**
*Pantalla de inicio con fondo personalizado y texto parpadeante*

---

### 🕹️ **GAMEPLAY**
*Físicas realistas, sprites HD y puntuación con sombra dinámica*

---

### 💀 **GAME OVER**
*Pantalla de derrota con puntuación final en rojo dramático*

</div>

---

## 🔧 CARACTERÍSTICAS TÉCNICAS AVANZADAS

### ⚡ **OPTIMIZACIÓN DE RENDIMIENTO**

```cpp
✅ Delta Time Implementation
   → Movimiento independiente de FPS
   → Física consistente en cualquier hardware

✅ Resource Management
   → Carga única de texturas/sonidos
   → Liberación automática de memoria
   → Sin memory leaks

✅ Smart Pointers (C++17)
   → unique_ptr para gestión de estados
   → Eliminación automática de recursos
   → Arquitectura memory-safe

✅ Efficient Collision Detection
   → AABB (Axis-Aligned Bounding Boxes)
   → Hitbox optimizado al 70%
   → Cálculos O(n) con early-exit
```

### 🎯 **SISTEMA DE COLISIONES PRECISO**

```cpp
// Hitbox ajustado según sprite real
if (use_sprites) {
    width  = bird_texture.width  * 0.70f;  // 70% del ancho
    height = bird_texture.height * 0.70f;  // 70% del alto
}

// Colisiones justas y responsivas
→ Menos falsos positivos
→ Jugabilidad más satisfactoria
→ Desafío balanceado
```

### 🌊 **GENERACIÓN PROCEDURAL**

```cpp
🔄 Sistema de Tuberías Infinito
├── Posición Y aleatoria (min-max range)
├── Gap variable (100-300px)
├── Distancia entre tuberías: 250px
├── Velocidad constante: 100 px/s
└── Reciclaje automático fuera de pantalla
```

---

## 🧠 ARQUITECTURA DEL SOFTWARE

### 🏛️ **STATE MACHINE PATTERN**

```
    ┌─────────────┐
    │   INICIO    │
    └──────┬──────┘
           │
           ▼
    ┌─────────────┐
    │  MenuState  │◄──────────────┐
    └──────┬──────┘               │
           │ [SPACE]              │
           ▼                      │
    ┌─────────────┐               │
    │MainGameState│               │
    └──────┬──────┘               │
           │ [COLISIÓN]           │
           ▼                      │
    ┌─────────────┐               │
    │GameOverState│───────────────┘
    └──────┬──────┘ [SPACE]
           │
           ▼ [ESC]
      🚪 SALIR
```

### 📊 **FLUJO DE DATOS**

```
Input Layer
    ↓
 ┌─────────────┐
 │handleInput()│
 └──────┬──────┘
        │
        ▼
 ┌─────────────┐     ┌──────────────┐
 │  update()   │────→│ Física       │
 │             │     │ Colisiones   │
 │             │     │ Puntuación   │
 └──────┬──────┘     └──────────────┘
        │
        ▼
 ┌─────────────┐     ┌──────────────┐
 │  render()   │────→│ Sprites      │
 │             │     │ Texturas     │
 │             │     │ Textos       │
 └─────────────┘     └──────────────┘
        │
        ▼
    Display
```

---

## 🎓 CONCEPTOS IMPLEMENTADOS

<div align="center">

| 💻 **Programación** | 🎮 **Game Development** | 🏗️ **Software Engineering** |
|:---:|:---:|:---:|
| Smart Pointers | Game Loop | State Pattern |
| RAII Pattern | Delta Time | Separation of Concerns |
| STL Containers | Collision Detection | Modular Architecture |
| Move Semantics | Sprite Rendering | Resource Management |
| Lambda Functions | Audio Systems | Clean Code |

</div>

---

## 🚧 ROADMAP FUTURO

### 🔮 **VERSIÓN 2.0** (En Planificación)

- [ ] 🎵 **Música de Fondo** - Soundtrack atmosférico
- [ ] 🏆 **Sistema de Récords** - Persistencia de high scores
- [ ] 🎨 **Temas Visuales** - Día, Noche, Cyber
- [ ] 🌐 **Multijugador Local** - Pantalla dividida
- [ ] 📊 **Estadísticas** - Gráficas de progreso
- [ ] 🎯 **Logros** - Sistema de achievements
- [ ] 💎 **Power-ups** - Escudos, slowmo, doble salto
- [ ] 📱 **Port a Android** - Controles táctiles

---

## 🤝 CONTRIBUCIONES

¿Quieres mejorar el juego? ¡Las contribuciones son bienvenidas!

```bash
# 1. Fork el repositorio
# 2. Crea una rama para tu feature
git checkout -b feature/nueva-funcionalidad

# 3. Commit tus cambios
git commit -m "✨ Añadir nueva funcionalidad épica"

# 4. Push a tu rama
git push origin feature/nueva-funcionalidad

# 5. Abre un Pull Request
```

---

## 📜 LICENCIA

Este proyecto está bajo la licencia **MIT**.

```
MIT License

Copyright (c) 2025 DCAGII Flappy Bird

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
```

---

## 🙏 AGRADECIMIENTOS

- **raylib** - Por el increíble motor gráfico
- **Dong Nguyen** - Creador del Flappy Bird original
- **Comunidad Open Source** - Por los assets y recursos
- **Stack Overflow** - Por resolver dudas existenciales de C++

---

<div align="center">

## 💫 ¡EMPIEZA TU AVENTURA AHORA!

```bash
./build/game
```

### 🎮 *¿Cuánto puedes durar antes de chocar?* 🎮

---

**Hecho con 💙 y mucho ☕ **

[![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Naoufal-Charafat/DCAGII-Game-Template)
[![raylib](https://img.shields.io/badge/Powered_by-raylib-FF0000?style=for-the-badge&logo=raylib&logoColor=white)](https://www.raylib.com/)
[![C++](https://img.shields.io/badge/Made_with-C++17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)

---

### ⭐ *Si te gustó el proyecto, considera darle una estrella* ⭐

</div>
 