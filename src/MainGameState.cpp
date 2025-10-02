#include <MainGameState.hpp>
#include <raylib.h>
#include <iostream>

MainGameState::MainGameState()
{
}

void MainGameState::init()
{
    // Ejercicio 1: Inicializar el pájaro en posición (200, 200)
    bird.x = 200.0f;
    bird.y = 200.0f;
    bird.vy = 0.0f; // Velocidad inicial en 0
    
    std::cout << "🐦 Pájaro inicializado en posición (" << bird.x << ", " << bird.y << ")\n";
}

// 🎯 Propósito: Manejar la entrada del usuario (en este caso, el salto del pájaro)
void MainGameState::handleInput()
{
    // Ejercicio 1: Detectar tecla ESPACIO para saltar
    if (IsKeyPressed(KEY_SPACE))
    {
        bird.vy = JUMP_VELOCITY; // Aplicar impulso hacia arriba
        std::cout << "🚀 ¡Salto! Velocidad: " << bird.vy << "\n";
    }
}

void MainGameState::update(float deltaTime) // deltaTime  es el tiempo en segundos desde el último frame
{
    // Ejercicio 1: Aplicar física de gravedad
    bird.vy += GRAVITY * deltaTime;  // Acelerar hacia abajo
    bird.y += bird.vy * deltaTime;   // Actualizar posición vertical
    
    // Debug: mostrar posición cada segundo (opcional)
    static float debug_timer = 0.0f;
    debug_timer += deltaTime;
    if (debug_timer >= 1.0f)
    {
        std::cout << "🎮 Posición Y: " << bird.y << " | Velocidad: " << bird.vy << "\n";
        debug_timer = 0.0f;
    }
}

void MainGameState::render()
{
    // Ejercicio 1: Renderizado del pájaro como círculo rojo
    BeginDrawing();
    
        ClearBackground(SKYBLUE);
        
        // Dibujar el pájaro
        DrawCircle(
            static_cast<int>(bird.x), 
            static_cast<int>(bird.y), 
            BIRD_RADIUS, 
            RED
        );
        
        // Instrucciones en pantalla
        DrawText("Presiona ESPACIO para saltar", 10, 10, 20, WHITE);
        DrawText("Presiona ESC para salir", 10, 40, 15, LIGHTGRAY);
        
        // Mostrar posición del pájaro (debug)
        DrawText(("Posicion: " + std::to_string(static_cast<int>(bird.y))).c_str(), 
                 10, 70, 15, YELLOW);
    
    EndDrawing();
}