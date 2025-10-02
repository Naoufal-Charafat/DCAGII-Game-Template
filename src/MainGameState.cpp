#include <MainGameState.hpp>
#include <GameOverState.hpp>
#include <StateMachine.hpp>
#include <raylib.h>
#include <iostream>
#include <memory>

MainGameState::MainGameState()
{
}

void MainGameState::init()
{
    // Ejercicio 1: Inicializar el pájaro en posición (200, 200)
    bird.x = 200.0f;
    bird.y = 200.0f;
    bird.vy = 0.0f; // Velocidad inicial en 0
    
    // Ejercicio 2: Inicializar sistema de tuberías
    pipes.clear();                  // Limpiar tuberías existentes
    pipe_spawn_timer = 1.0f;        // Primera tubería aparece pronto
    
    // Generar algunas tuberías iniciales
    generatePipe();
    
    std::cout << "🐦 Pájaro inicializado en posición (" << bird.x << ", " << bird.y << ")\n";
    std::cout << "🏗️  Sistema de tuberías inicializado\n";
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
    
    // Ejercicio 2: Actualizar sistema de tuberías
    updatePipes(deltaTime);
    
    // Ejercicio 3: Detectar colisiones
    if (checkCollisions())
    {
        std::cout << "💥 ¡COLISIÓN DETECTADA! Transición a Game Over\n";
        
        // Transición a GameOverState
        this->state_machine->add_state(
            std::make_unique<GameOverState>(), 
            true  // Reemplazar estado actual
        );
        return;  // Salir del update para evitar procesar más lógica
    }
    
    // Debug: mostrar posición cada segundo (opcional)
    static float debug_timer = 0.0f;
    debug_timer += deltaTime;
    if (debug_timer >= 1.0f)
    {
        std::cout << "🎮 Posición Y: " << bird.y << " | Velocidad: " << bird.vy 
                  << " | Tuberías activas: " << pipes.size() << "\n";
        debug_timer = 0.0f;
    }
}

void MainGameState::render()
{
    // Ejercicio 1 y 2: Renderizado del juego
    BeginDrawing();
    
        ClearBackground(SKYBLUE);
        
        // Ejercicio 2: Dibujar tuberías primero (fondo)
        renderPipes();
        
        // Ejercicio 1: Dibujar el pájaro (frente)
        DrawCircle(
            static_cast<int>(bird.x), 
            static_cast<int>(bird.y), 
            BIRD_RADIUS, 
            RED
        );
        
        // Instrucciones en pantalla
        DrawText("Presiona ESPACIO para saltar", 10, 10, 20, WHITE);
        DrawText("Presiona ESC para salir", 10, 40, 15, LIGHTGRAY);
        
        // Debug info
        DrawText(("Posicion Y: " + std::to_string(static_cast<int>(bird.y))).c_str(), 
                 10, 70, 15, YELLOW);
        DrawText(("Tuberias: " + std::to_string(pipes.size())).c_str(), 
                 10, 90, 15, YELLOW);
    
    EndDrawing();
}

// ========== EJERCICIO 2: MÉTODOS AUXILIARES PARA TUBERÍAS ==========

void MainGameState::generatePipe()
{
    // Generar posición Y aleatoria para el hueco
    // El hueco debe estar entre los límites de la pantalla
    int min_gap_y = static_cast<int>(PIPE_GAP / 2 + 50);
    int max_gap_y = static_cast<int>(740 - PIPE_GAP / 2 - 50); // 740 es la altura de la ventana
    
    float gap_center_y = static_cast<float>(GetRandomValue(min_gap_y, max_gap_y));
    
    // Crear nueva tubería
    PipePair new_pipe;
    new_pipe.scored = false;
    
    // Tubería superior: desde arriba hasta el inicio del hueco
    new_pipe.top.x = 360.0f; // Aparece fuera de pantalla (ancho ventana)
    new_pipe.top.y = 0.0f;
    new_pipe.top.width = PIPE_WIDTH;
    new_pipe.top.height = gap_center_y - PIPE_GAP / 2;
    
    // Tubería inferior: desde el final del hueco hasta abajo
    new_pipe.bot.x = 360.0f;
    new_pipe.bot.y = gap_center_y + PIPE_GAP / 2;
    new_pipe.bot.width = PIPE_WIDTH;
    new_pipe.bot.height = 740.0f - new_pipe.bot.y; // Hasta el fondo
    
    pipes.push_back(new_pipe);
    
    std::cout << "🏗️  Nueva tubería generada en Y: " << gap_center_y << "\n";
}

void MainGameState::updatePipes(float deltaTime)
{
    // Actualizar timer para generar nuevas tuberías
    pipe_spawn_timer -= deltaTime;
    if (pipe_spawn_timer <= 0.0f)
    {
        generatePipe();
        pipe_spawn_timer = PIPE_SPAWN_TIME;
    }
    
    // Mover todas las tuberías hacia la izquierda
    for (auto& pipe : pipes)
    {
        pipe.top.x -= PIPE_SPEED * deltaTime;
        pipe.bot.x -= PIPE_SPEED * deltaTime;
    }
    
    // Eliminar tuberías que salieron de la pantalla
    while (!pipes.empty() && pipes.front().top.x < -PIPE_WIDTH)
    {
        pipes.pop_front();
        std::cout << "🗑️  Tubería eliminada (fuera de pantalla)\n";
    }
}

void MainGameState::renderPipes()
{
    // Dibujar todas las tuberías activas
    for (const auto& pipe : pipes)
    {
        // Tubería superior (verde oscuro)
        DrawRectangleRec(pipe.top, DARKGREEN);
        // Borde de la tubería superior
        DrawRectangleLinesEx(pipe.top, 2, GREEN);
        
        // Tubería inferior (verde oscuro)
        DrawRectangleRec(pipe.bot, DARKGREEN);
        // Borde de la tubería inferior
        DrawRectangleLinesEx(pipe.bot, 2, GREEN);
    }
}

// ========== EJERCICIO 3: MÉTODOS DE COLISIONES ==========

Rectangle MainGameState::getBirdBoundingBox() const
{
    // Crear bounding box cuadrado centrado en la posición del pájaro
    // Usamos un tamaño ligeramente menor que el radio visual para colisiones más justas
    float box_size = BIRD_RADIUS * 2.0f * 0.8f;  // 80% del diámetro
    
    return Rectangle{
        bird.x - box_size / 2.0f,  // x (centrado)
        bird.y - box_size / 2.0f,  // y (centrado)
        box_size,                   // width
        box_size                    // height
    };
}

bool MainGameState::checkCollisions()
{
    // Obtener bounding box del pájaro
    Rectangle bird_box = getBirdBoundingBox();
    
    // 1. Colisión con límites de pantalla (arriba y abajo)
    if (bird.y - BIRD_RADIUS <= 0)  // Colisión con techo
    {
        std::cout << "💥 Colisión con el TECHO\n";
        return true;
    }
    
    if (bird.y + BIRD_RADIUS >= 740)  // Colisión con suelo (altura ventana)
    {
        std::cout << "💥 Colisión con el SUELO\n";
        return true;
    }
    
    // 2. Colisión con tuberías
    for (const auto& pipe : pipes)
    {
        // Comprobar colisión con tubería superior
        if (CheckCollisionRecs(bird_box, pipe.top))
        {
            std::cout << "💥 Colisión con TUBERÍA SUPERIOR\n";
            return true;
        }
        
        // Comprobar colisión con tubería inferior
        if (CheckCollisionRecs(bird_box, pipe.bot))
        {
            std::cout << "💥 Colisión con TUBERÍA INFERIOR\n";
            return true;
        }
    }
    
    // No hay colisiones
    return false;
}