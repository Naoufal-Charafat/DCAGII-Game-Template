#include <GameOverState.hpp>
#include <MainGameState.hpp>
#include <StateMachine.hpp>
#include <raylib.h>
#include <iostream>
#include <memory>
#include <string>

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
    // Ejercicio 3 y 4: Renderizado de pantalla Game Over con puntuación
    BeginDrawing();
    
        // Fondo igual al juego (azul cielo)
        ClearBackground(SKYBLUE);
        
        // Texto principal "GAME OVER"
        const char* game_over_text = "GAME OVER";
        int text_width = MeasureText(game_over_text, 40);
        DrawText(game_over_text, (360 - text_width) / 2, 250, 40, RED);
        
        // Ejercicio 4: Mostrar puntuación final
        std::string score_label = "Puntuacion: ";
        std::string score_value = std::to_string(final_score);
        std::string full_score = score_label + score_value;
        int score_width = MeasureText(full_score.c_str(), 30);
        DrawText(full_score.c_str(), (360 - score_width) / 2, 320, 30, WHITE);
        
        // Instrucciones para reiniciar
        const char* restart_text = "Presiona ESPACIO para reiniciar";
        int restart_width = MeasureText(restart_text, 20);
        DrawText(restart_text, (360 - restart_width) / 2, 400, 20, WHITE);
        
        // Instrucción para salir
        const char* exit_text = "Presiona ESC para salir";
        int exit_width = MeasureText(exit_text, 15);
        DrawText(exit_text, (360 - exit_width) / 2, 440, 15, LIGHTGRAY);
    
    EndDrawing();
}
