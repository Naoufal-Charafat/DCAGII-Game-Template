#include <GameOverState.hpp>
#include <MainGameState.hpp>
#include <StateMachine.hpp>
#include <raylib.h>
#include <iostream>
#include <memory>

GameOverState::GameOverState() : final_score(0)
{
    std::cout << "💀 Transición a Game Over State\n";
}

void GameOverState::init()
{
    // No necesita inicialización especial
    std::cout << "🎮 Game Over State inicializado\n";
}

void GameOverState::handleInput()
{
    // Ejercicio 3: Reiniciar partida al pulsar ESPACIO
    if (IsKeyPressed(KEY_SPACE))
    {
        std::cout << "🔄 Reiniciando partida...\n";
        
        // Eliminar el estado actual (GameOverState)
        this->state_machine->remove_state(false);
        
        // Agregar nuevo MainGameState (reiniciar juego)
        this->state_machine->add_state(
            std::make_unique<MainGameState>(), 
            true  // Reemplazar estado actual
        );
    }
}

void GameOverState::update(float deltaTime)
{
    // Estado estático, no necesita actualización
    // deltaTime no se usa intencionalmente
    (void)deltaTime;  // Evitar warning de parámetro no usado
}

void GameOverState::render()
{
    // Ejercicio 3: Renderizado de pantalla Game Over
    BeginDrawing();
    
        // Fondo igual al juego (azul cielo)
        ClearBackground(SKYBLUE);
        
        // Texto principal "GAME OVER"
        const char* game_over_text = "GAME OVER";
        int text_width = MeasureText(game_over_text, 40);
        DrawText(game_over_text, (360 - text_width) / 2, 300, 40, RED);
        
        // Instrucciones para reiniciar
        const char* restart_text = "Presiona ESPACIO para reiniciar";
        int restart_width = MeasureText(restart_text, 20);
        DrawText(restart_text, (360 - restart_width) / 2, 370, 20, WHITE);
        
        // Instrucción para salir
        const char* exit_text = "Presiona ESC para salir";
        int exit_width = MeasureText(exit_text, 15);
        DrawText(exit_text, (360 - exit_width) / 2, 410, 15, LIGHTGRAY);
    
    EndDrawing();
}
