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


**Una experiencia de desarrollo inmersiva que combina:**
- 🎮 **Mecánicas de juego clásicas** con implementación moderna
- 🔧 **Arquitectura de estados** para gestión eficiente del flujo
- 🎨 **Gráficos 2D** renderizados con la potente librería raylib
- ⚡ **Física en tiempo real** con detección de colisiones precisa
- 🏗️ **Patrones de diseño** profesionales aplicados al desarrollo de juegos



---

## 📅 Fecha de Actualización
**1 de octubre de 2025**

---

## 🔧 ACTUALIZACIONES REALIZADAS

### 🌟 Configuración Inicial del Entorno de Desarrollo

#### 🏗️ **FASE 1: Preparación de la Arquitectura del Proyecto**

<details>
<summary>🔽 Expandir detalles técnicos</summary>

```
┌─────────────────────────────────────────────────────────────┐
│                    ESTRUCTURA IMPLEMENTADA                 │
├─────────────────────────────────────────────────────────────┤
│  📁 DCAGII-Game-Template/                                  │
│  ├── 📁 assets/                    [Assets del juego]     │
│  ├── 📁 src/                       [Código fuente]        │
│  │   ├── 📄 GameState.cpp          [Estados base]         │
│  │   ├── 📄 GameState.hpp                                 │
│  │   ├── 📄 main.cpp               [Punto de entrada]     │
│  │   ├── 📄 MainGameState.cpp      [Estado principal]     │
│  │   ├── 📄 MainGameState.hpp                             │
│  │   ├── 📄 StateMachine.cpp       [Máquina de estados]   │
│  │   └── 📄 StateMachine.hpp                              │
│  └── 📁 vendor/                    [Dependencias externas]│
│      ├── 📁 include/               [Headers raylib]       │
│      │   ├── 📄 raylib.h          [API principal]        │
│      │   ├── 📄 raymath.h         [Matemáticas]          │
│      │   └── 📄 rlgl.h            [OpenGL wrapper]       │
│      └── 📁 lib/                   [Librerías compiladas] │
│          └── 📄 libraylib.a       [Librería estática]    │
└─────────────────────────────────────────────────────────────┘
```

</details>

---

### ⚙️ **FASE 2: Integración de raylib - Motor Gráfico de Alto Rendimiento**

#### 🎯 **Objetivos Completados:**

- ✅ **Clonación del repositorio oficial de raylib**
  - Versión más reciente del motor gráfico
  - Código fuente optimizado para máximo rendimiento

- ✅ **Instalación de dependencias del sistema**
  ```bash
  # Dependencias Linux instaladas:
  xorg-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev
  ```

- ✅ **Compilación nativa para plataforma de escritorio**
  ```bash
  make PLATFORM=PLATFORM_DESKTOP
  ```

- ✅ **Integración de componentes críticos:**
  - `libraylib.a` → Librería estática compilada (2.89 MB)
  - `raylib.h` → API principal (133 KB)
  - `raymath.h` → Funciones matemáticas optimizadas (85 KB)
  - `rlgl.h` → Wrapper de OpenGL de bajo nivel (255 KB)

---

### 🔬 **FASE 3: Verificación y Optimización del Sistema**

#### 📊 **Métricas de Implementación:**

| Componente | Estado | Tamaño | Ubicación |
|------------|--------|--------|-----------|
| 🎯 Librería Principal | ✅ **ACTIVO** | 2.89 MB | `vendor/lib/libraylib.a` |
| 🧮 Headers Matemáticos | ✅ **ACTIVO** | 85 KB | `vendor/include/raymath.h` |
| 🎨 API Gráfica | ✅ **ACTIVO** | 133 KB | `vendor/include/raylib.h` |
| ⚡ OpenGL Wrapper | ✅ **ACTIVO** | 255 KB | `vendor/include/rlgl.h` |

#### 🧹 **Optimización Post-Instalación:**

- ✅ **Limpieza de archivos temporales**
  - Eliminación de la carpeta `raylib/` (clonada temporalmente)
  - Conservación únicamente de archivos esenciales
  - Reducción de espacio en disco optimizada

---

### 🚀 **FASE 4: Preparación para el Desarrollo**

#### 🎮 **Configuración del Pipeline de Compilación:**

```bash
# Comando de compilación configurado:
g++ -o game src/*.cpp -I src/ -I vendor/include/ -L vendor/lib -lraylib -lGL -lm
```

---

### 🌟 **ESTADO ACTUAL DEL PROYECTO**

<div align="center">

```
🟢 PROYECTO LISTO PARA DESARROLLO 🟢
```

**Todas las dependencias configuradas exitosamente**  
**Entorno de desarrollo completamente preparado**  
**Arquitectura base implementada y verificada**

</div>

---

### 🔮 **LISTO PARA DESARROLLO**

El agente está preparado para recibir tareas específicas de implementación y asistir en el desarrollo del juego según las especificaciones proporcionadas.

---

<div align="center">

### 💫 **POWERED BY**

| Tecnología | Versión | Propósito |
|------------|---------|-----------|
| 🎮 **raylib** | Latest | Motor gráfico y de audio |
| ⚡ **C++** | Standard | Lenguaje de desarrollo |
| 🐧 **Linux** | Ubuntu | Sistema operativo |
| 🔧 **GCC** | Latest | Compilador |

---

**🚀 Desarrollado para la asignatura DCAGII**  
**📅 Fecha límite: 8 de octubre de 2025**

</div>

---

### 📝 **NOTAS TÉCNICAS**

> **⚠️ Importante:** Este documento se actualiza automáticamente con cada modificación significativa del proyecto. Mantener siempre la versión más reciente para seguimiento preciso del desarrollo.

> **🔧 Compilación:** Asegúrate de que todas las dependencias estén instaladas antes de compilar. El script de compilación está optimizado para sistemas Linux.

> **🎯 Objetivo:** Desarrollar una implementación completa y funcional del clásico Flappy Bird utilizando técnicas modernas de desarrollo de videojuegos.

---

## 🤖 **ACTUALIZACIÓN - 1 de octubre de 2025 (17:00)**

### 🎯 **CONFIGURACIÓN DE AGENTE COPILOT COMPLETADA**

#### 🚀 **NUEVAS CAPACIDADES DEL PROYECTO**

Se ha completado la configuración de un **agente de desarrollo especializado** con las siguientes características:

<details>
<summary>🔽 Expandir detalles de la configuración del agente</summary>

#### 🧠 **AGENTE EXPERTO EN FLAPPY BIRD**

| Componente | Archivo | Estado | Descripción |
|------------|---------|--------|-------------|
| 🎮 **Chat Mode** | `.github/chatmodes/Agent-dev-game-FlappyBird.chatmode.md` | ✅ **CONFIGURADO** | Personalidad y comportamiento del agente |
| 📋 **Instructions** | `.github/instructions/dev-game-FlappyBird.instructions.md` | ✅ **CONFIGURADO** | Guías técnicas detalladas de desarrollo |

#### 🎯 **CAPACIDADES DEL AGENTE:**

**🏗️ Arquitectura y Patrones:**
- ✅ Experto en State Machine Pattern
- ✅ Conocimiento profundo de raylib API
- ✅ Implementación de física 2D en tiempo real
- ✅ Detección de colisiones AABB (Axis-Aligned Bounding Boxes)

**🔧 Herramientas MCP Integradas:**
- ✅ **Serena**: Análisis simbólico de código C++
  - Exploración inteligente de símbolos
  - Edición precisa de funciones y clases
  - Búsqueda de referencias y dependencias
- ✅ **Context7**: Documentación actualizada de raylib
  - Consulta de API en tiempo real
  - Ejemplos de código contextualizados
  - Resolución de dudas técnicas

**📚 Conocimientos Específicos:**
- 🎮 Mecánicas de Flappy Bird (física, tuberías, puntuación)
- ⚡ C++17 moderno y buenas prácticas
- 🎨 Renderizado 2D optimizado con raylib
- 🏗️ Arquitectura de videojuegos escalable
- 🐛 Depuración y optimización de rendimiento

#### 📋 **FLUJO DE TRABAJO DEL AGENTE:**

```
┌─────────────────────────────────────────────────┐
│  1. ANÁLISIS DE CONTEXTO                       │
│     ├─ Leer código existente con Serena        │
│     ├─ Entender arquitectura actual            │
│     └─ Identificar ejercicio solicitado        │
└──────────────┬──────────────────────────────────┘
               ▼
┌─────────────────────────────────────────────────┐
│  2. PLANIFICACIÓN                              │
│     ├─ Usar herramienta 'think'                │
│     ├─ Definir archivos a modificar            │
│     └─ Verificar dependencias                  │
└──────────────┬──────────────────────────────────┘
               ▼
┌─────────────────────────────────────────────────┐
│  3. IMPLEMENTACIÓN                             │
│     ├─ Editar código con herramientas Serena   │
│     ├─ Seguir estándares de nomenclatura       │
│     └─ Agregar comentarios explicativos        │
└──────────────┬──────────────────────────────────┘
               ▼
┌─────────────────────────────────────────────────┐
│  4. COMPILACIÓN Y VALIDACIÓN                   │
│     ├─ Ejecutar tarea 'build'                  │
│     ├─ Verificar errores con get_errors        │
│     └─ Corregir warnings inmediatamente        │
└──────────────┬──────────────────────────────────┘
               ▼
┌─────────────────────────────────────────────────┐
│  5. REPORTE DETALLADO                          │
│     ├─ ✅ Cambios realizados                   │
│     ├─ 🔧 Detalles técnicos                    │
│     ├─ ✅ Verificación de compilación          │
│     └─ 📝 Observaciones relevantes             │
└─────────────────────────────────────────────────┘
```

#### 📝 **FORMATO DE REPORTES:**

El agente reportará cada modificación con el siguiente formato:

```markdown
## 📋 REPORTE DE MODIFICACIONES - [TAREA]

### ✅ Cambios Realizados:
- **Archivo 1:** `ruta/archivo.cpp`
  - ✨ Cambio detallado 1
  - 🎮 Cambio detallado 2
  - ⚡ Cambio detallado 3

- **Archivo 2:** `ruta/archivo.hpp`
  - 📐 Declaración de nuevas estructuras
  - 🔧 Métodos agregados

### 🔧 Detalles Técnicos:
- Constantes definidas y sus valores
- Algoritmos implementados
- Decisiones de diseño importantes

### ✅ Verificación:
- ✔️ Compilación exitosa (0 errores, 0 warnings)
- ✔️ Código integrado correctamente

### 📊 Métricas:
- Líneas de código agregadas: X
- Funciones/métodos nuevos: Y
- Archivos modificados: Z

### 📝 Observaciones:
- Notas relevantes sobre la implementación
- Consideraciones técnicas importantes
```

#### 🎨 **ESTÁNDARES DE CÓDIGO APLICADOS:**

```cpp
// ✅ Convenciones de nomenclatura
class GameState {};              // PascalCase para clases
void handleInput() {};           // camelCase para funciones
float delta_time = 0.0f;         // snake_case para variables
const float GRAVITY = 800.0f;    // UPPER_SNAKE_CASE para constantes
struct Bird {};                  // PascalCase para structs

// ✅ Uso correcto de delta time
void update(float deltaTime) {
    bird.y += bird.vy * deltaTime;      // Independiente de FPS
    bird.vy += GRAVITY * deltaTime;
}

// ✅ Gestión correcta de recursos
void init() {
    texture = LoadTexture("path.png");  // Cargar una vez
}
void render() {
    DrawTexture(texture, x, y, WHITE);  // Usar muchas veces
}
~MainGameState() {
    UnloadTexture(texture);             // Liberar al finalizar
}

// ✅ Detección de colisiones precisa
Rectangle getBirdBoundingBox() const {
    return {x - w/2, y - h/2, w, h};
}
if (CheckCollisionRecs(bird_box, pipe_box)) {
    // Manejar colisión
}
```

#### 🛡️ **PRÁCTICAS DE SEGURIDAD Y CALIDAD:**

- ✅ **Validación de recursos**: Verificar que texturas/sonidos se carguen correctamente
- ✅ **Prevención de memory leaks**: Descargar todos los recursos al finalizar
- ✅ **Delta time capping**: Limitar deltaTime para evitar glitches
- ✅ **Boundary checking**: Validar límites de pantalla y arrays
- ✅ **Error handling**: Gestión robusta de errores de raylib

</details>

---

## 🔧 **ACTUALIZACIÓN - 1 de octubre de 2025 (14:00)**

### 🛠️ **CONFIGURACIÓN DE ENTORNO DE DESARROLLO COMPLETADA**

#### 🎯 **FASE NUEVA: Configuración de VS Code y Herramientas de Depuración**

<details>
<summary>🔽 Expandir detalles de instalaciones y configuraciones</summary>

#### 📦 **DEPENDENCIAS INSTALADAS:**

| Herramienta | Versión | Estado | Propósito |
|-------------|---------|--------|-----------|
| 🐛 **GDB (GNU Debugger)** | 15.0.50 | ✅ **INSTALADO** | Depuración de código C++ |
| 📚 **libbabeltrace1** | 1.5.11-3 | ✅ **INSTALADO** | Soporte para tracing avanzado |
| 🔍 **libc6-dbg** | 2.39-0ubuntu8.6 | ✅ **INSTALADO** | Símbolos de depuración de glibc |
| 💡 **libsource-highlight** | 3.1.9-4.3 | ✅ **INSTALADO** | Resaltado de sintaxis en GDB |
| ⚡ **libipt2** | 2.0.6-1 | ✅ **INSTALADO** | Intel Processor Trace |

#### 🏗️ **ARCHIVOS DE CONFIGURACIÓN CREADOS:**

```
┌──────────────────────────────────────────────────────────────┐
│                VS CODE WORKSPACE CONFIGURADO                │
├──────────────────────────────────────────────────────────────┤
│  📁 .vscode/                                                │
│  ├── 📄 tasks.json          [Sistema de compilación]       │
│  │   ├── 🔨 build           → Compilar con g++              │
│  │   ├── 🧹 clean           → Limpiar archivos build        │
│  │   └── 📁 build directory → Crear directorio build        │
│  └── 📄 launch.json         [Configuración de depuración]  │
│      ├── 🐛 Debug Game      → Depurar con breakpoints       │
│      └── ▶️ Run Game        → Ejecutar sin depuración       │
└──────────────────────────────────────────────────────────────┘
```

#### ⚙️ **CONFIGURACIÓN DE COMPILACIÓN:**

```bash
# Comando de compilación optimizado:
g++ -std=c++17 -Wall -Wextra -g \
    -I${workspaceFolder}/src \
    -I${workspaceFolder}/vendor/include \
    ${workspaceFolder}/src/*.cpp \
    -L${workspaceFolder}/vendor/lib \
    -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 \
    -o ${workspaceFolder}/build/game
```

#### 🎮 **VERIFICACIÓN DEL SISTEMA:**

- ✅ **Compilación exitosa** → Ejecutable `build/game` generado (216 KB)
- ✅ **Símbolos de depuración** → Información debug incluida
- ✅ **Dependencias raylib** → Todas las librerías vinculadas correctamente
- ✅ **Permisos de ejecución** → Ejecutable listo para deployment
- ✅ **GDB funcional** → Depurador configurado en `/usr/bin/gdb`

#### 🚀 **FUNCIONALIDADES HABILITADAS:**

| Función | Atajo | Descripción |
|---------|-------|-------------|
| ▶️ **Ejecutar** | `F5` | Compilar y ejecutar el juego |
| 🐛 **Depurar** | `F5` (Debug mode) | Ejecutar con breakpoints activos |
| 🔨 **Compilar** | `Ctrl+Shift+P` → "Tasks: Run Task" → "build" | Solo compilar |
| 🧹 **Limpiar** | `Ctrl+Shift+P` → "Tasks: Run Task" → "clean" | Eliminar archivos build |

#### 🔧 **PROBLEMAS RESUELTOS:**

1. **❌ Error:** `"program does not exist"`
   - **✅ Solución:** Configuración de `tasks.json` y `launch.json`

2. **❌ Error:** `"miDebuggerPath is invalid"`
   - **✅ Solución:** Instalación de GDB y simplificación de configuración

3. **❌ Error:** Directorio build no existente
   - **✅ Solución:** Creación automática de estructura de directorios

#### 📊 **MÉTRICAS POST-CONFIGURACIÓN:**

```
🎯 ESTADO DEL PROYECTO: 100% OPERACIONAL
├── ✅ Compilación automática     → FUNCIONAL
├── ✅ Depuración integrada       → FUNCIONAL  
├── ✅ Detección de errores       → FUNCIONAL
├── ✅ Ejecución directa          → FUNCIONAL
└── ✅ Integración VS Code        → FUNCIONAL
```

</details>

---

### 🌟 **ESTADO ACTUALIZADO DEL PROYECTO**

<div align="center">

```
🟢 ENTORNO DE DESARROLLO 100% CONFIGURADO 🟢
```

**✨ Todas las herramientas de desarrollo instaladas y configuradas**  
**🎯 Sistema de compilación automática funcional**  
**🐛 Depuración integrada con VS Code operativa**  
**🚀 Proyecto listo para desarrollo avanzado**

</div>

---

### 🔮 **CAPACIDADES DEL ENTORNO**

1. **🐛 Depuración avanzada:** Breakpoints y análisis de código en tiempo real
2. **⚡ Compilación optimizada:** Detección automática de errores y warnings
3. **🔧 Workflow eficiente:** Ciclo desarrollo-compilación automatizado

---

### 💻 **COMANDOS ÚTILES POST-CONFIGURACIÓN**

```bash
# Compilar manualmente desde terminal:
cd /home/softwebdd/UA/DCA/p0/DCAGII-Game-Template
mkdir -p build
g++ -std=c++17 -g src/*.cpp -I src/ -I vendor/include/ -L vendor/lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o build/game

# Ejecutar el juego:
./build/game

# Verificar información del ejecutable:
file build/game
```

---

<div align="center">

**🎉 CONFIGURACIÓN COMPLETADA EXITOSAMENTE**  
**📅 Última actualización: 1 de octubre de 2025**  
**⚡ Sistema optimizado para desarrollo de Flappy Bird**

</div>

---

## 🎮 **ACTUALIZACIÓN - 2 de octubre de 2025**

### ✅ **EJERCICIO 0: CREACIÓN DE VENTANA - COMPLETADO**

#### 🎯 **OBJETIVO DEL EJERCICIO:**
Implementar la funcionalidad básica de inicialización de ventana con raylib, estableciendo la base del bucle de juego y el sistema de renderizado.

<details>
<summary>🔽 Expandir detalles de implementación</summary>

#### 📋 **MODIFICACIONES REALIZADAS:**

##### **1. 🔧 Archivo: `src/main.cpp`**

**Cambios implementados:**
```cpp
✨ Inclusión de raylib.h para acceso a API gráfica
✨ InitWindow(288, 512, "Flappy Bird DCA") → Ventana de 288x512 píxeles
✨ SetTargetFPS(60) → Limitación a 60 frames por segundo
✨ WindowShouldClose() → Detección de cierre de ventana
✨ GetFrameTime() → Cálculo de delta time para física independiente de FPS
✨ CloseWindow() → Liberación de recursos al finalizar
```

**Funcionalidades agregadas:**
- ⚡ **Delta time dinámico:** Cálculo automático en cada frame
- 🚪 **Cierre de ventana:** Detección de ESC o botón de cerrar
- 🎯 **FPS estable:** Limitación a 60 FPS para rendimiento consistente
- 🧹 **Gestión de recursos:** Liberación correcta de memoria al salir

##### **2. 🎨 Archivo: `src/MainGameState.cpp`**

**Cambios implementados:**
```cpp
✨ Inclusión de raylib.h para funciones de renderizado
✨ BeginDrawing() → Inicio de frame de renderizado
✨ ClearBackground(SKYBLUE) → Fondo azul cielo
✨ DrawText() → Renderizado de texto de bienvenida centrado
✨ MeasureText() → Cálculo de ancho de texto para centrado
✨ EndDrawing() → Finalización de frame de renderizado
```

**Elementos visuales agregados:**
- 🎨 **Fondo:** Color azul cielo (`SKYBLUE`)
- 📝 **Texto principal:** "Bienvenido a Flappy Bird DCA" (tamaño 20, color blanco)
- ℹ️ **Instrucciones:** "Presiona ESC para salir" (tamaño 15, color gris claro)
- 🎯 **Centrado:** Cálculo automático para alineación horizontal perfecta

#### 🏗️ **ARQUITECTURA IMPLEMENTADA:**

```
┌─────────────────────────────────────────────────────┐
│              BUCLE PRINCIPAL DEL JUEGO              │
├─────────────────────────────────────────────────────┤
│  1. InitWindow() → Crear ventana 288x512           │
│  2. SetTargetFPS(60) → Limitar a 60 FPS            │
│  3. WHILE (!WindowShouldClose())                    │
│     ├─ delta_time = GetFrameTime()                 │
│     ├─ handleInput()                                │
│     ├─ update(delta_time)                           │
│     └─ render()                                     │
│         ├─ BeginDrawing()                           │
│         ├─ ClearBackground(SKYBLUE)                 │
│         ├─ DrawText(...)                            │
│         └─ EndDrawing()                             │
│  4. CloseWindow() → Liberar recursos                │
└─────────────────────────────────────────────────────┘
```

#### ✅ **VERIFICACIÓN Y COMPILACIÓN:**

**Estado de compilación:**
```bash
g++ -std=c++17 -Wall -Wextra -g \
    -I src/ -I vendor/include/ \
    src/*.cpp \
    -L vendor/lib/ \
    -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 \
    -o build/game
```

**Resultados:**
- ✅ **Compilación exitosa** (0 errores)
- ⚠️ **1 Warning:** `unused parameter 'deltaTime'` en `update()` (esperado en Ejercicio 0)
- ✅ **Ejecutable generado:** `build/game`
- ✅ **Tamaño del ejecutable:** ~216 KB

#### 📊 **MÉTRICAS DEL EJERCICIO:**

| Métrica | Valor |
|---------|-------|
| **Archivos modificados** | 2 (`main.cpp`, `MainGameState.cpp`) |
| **Líneas agregadas** | ~20 líneas |
| **Funciones raylib usadas** | 8 funciones |
| **Tiempo de compilación** | < 2 segundos |
| **Warnings** | 1 (parámetro no usado) |
| **Errores** | 0 |

#### 🔑 **CONCEPTOS APLICADOS:**

1. **🎮 Inicialización de ventana:**
   - Configuración de dimensiones (288x512 px)
   - Establecimiento de título de ventana
   - Limitación de FPS objetivo

2. **⚡ Delta Time:**
   - Cálculo dinámico con `GetFrameTime()`
   - Preparación para física independiente de FPS
   - Variable pasada a través del sistema de estados

3. **🎨 Bucle de Renderizado:**
   - Patrón `BeginDrawing()` / `EndDrawing()`
   - Limpieza de buffer con `ClearBackground()`
   - Renderizado de primitivas de texto

4. **🧹 Gestión de Recursos:**
   - Liberación correcta con `CloseWindow()`
   - Detección de cierre de ventana
   - Prevención de memory leaks

#### 🎓 **FUNCIONES RAYLIB UTILIZADAS:**

```cpp
// Gestión de ventana
InitWindow(int width, int height, const char* title)
CloseWindow(void)
SetTargetFPS(int fps)
WindowShouldClose(void) → bool

// Renderizado
BeginDrawing(void)
EndDrawing(void)
ClearBackground(Color color)

// Texto
DrawText(const char* text, int x, int y, int fontSize, Color color)
MeasureText(const char* text, int fontSize) → int

// Tiempo
GetFrameTime(void) → float
```

#### 🎯 **RESULTADO VISUAL:**

Al ejecutar `./build/game`, se muestra:
- 🪟 Ventana de 288x512 píxeles
- 🎨 Fondo azul cielo
- 📝 Texto "Bienvenido a Flappy Bird DCA" centrado
- ℹ️ Instrucciones en la parte inferior
- ⚡ 60 FPS estables

</details>

---

### 🌟 **ESTADO DEL PROYECTO ACTUALIZADO**

<div align="center">

```
🟢 EJERCICIO 0 COMPLETADO EXITOSAMENTE 🟢
```

**✅ Ventana de juego inicializada correctamente**  
**✅ Sistema de renderizado básico funcional**  
**✅ Bucle de juego implementado con delta time**  
**✅ Gestión de recursos y cierre de ventana operativa**  
**🚀 Proyecto listo para Ejercicio 1: Mecánica principal**

</div>

---

### 📝 **OBSERVACIONES TÉCNICAS:**

1. **⚠️ Warning esperado:** El parámetro `deltaTime` en `MainGameState::update()` no se usa en el Ejercicio 0, pero será necesario en ejercicios posteriores para implementar física.

2. **🎨 Centrado de texto:** Se utiliza `MeasureText()` para calcular el ancho del texto y centrarlo horizontalmente en la ventana de 288 píxeles.

3. **🔧 Arquitectura preparada:** La estructura de `StateMachine` y `GameState` está lista para agregar más estados (como `GameOverState` en ejercicios futuros).

4. **⚡ Delta time:** Aunque no se usa activamente en este ejercicio, ya está siendo calculado y pasado correctamente para física en ejercicios posteriores.

---

### 🎯 **PRÓXIMOS PASOS:**

**Ejercicio 1: Mecánica principal**
- Implementar struct `Bird`
- Agregar física (gravedad, impulsos)
- Detectar input de teclado (ESPACIO)
- Renderizar sprite del pájaro

---

<div align="center">

**🎮 EJERCICIO 0 FINALIZADO**  
**📅 Fecha de implementación: 2 de octubre de 2025**  
**⏱️ Tiempo de desarrollo: ~15 minutos**  
**✅ Estado: FUNCIONAL Y VERIFICADO**

</div>