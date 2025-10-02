#include <GameOverState.hpp>
#include <MainGameState.hpp>
#include <StateMachine.hpp>
#include <raylib.h>
#include <iostream>
#include <memory>
#include <string>

GameOverState::GameOverState() : final_score(0), use_custom_font(false)
{
    std::cout << "💀 Transición a Game Over State\n";
}

GameOverState::~GameOverState()
{
    // Liberar sonidos
    if (die_sound.frameCount > 0)
    {
        UnloadSound(die_sound);
        std::cout << "🔊 Sonido de muerte liberado\n";
    }
    
    // Liberar fuente
    if (use_custom_font)
    {
        UnloadFont(custom_font);
        std::cout << "🔤 Fuente liberada\n";
    }
}

void GameOverState::init()
{
    // Cargar fuente personalizada
    custom_font = LoadFontEx("assets/fonts/LuckiestGuy.ttf", 80, nullptr, 0);
    if (custom_font.texture.id != 0)
    {
        use_custom_font = true;
        std::cout << "✅ Fuente personalizada cargada en Game Over\n";
    }
    else
    {
        use_custom_font = false;
        std::cout << "⚠️  No se pudo cargar la fuente en Game Over\n";
    }
    
    // Cargar sonido de muerte
    die_sound = LoadSound("assets/sounds/die.wav");
    if (die_sound.frameCount > 0)
    {
        // Reproducir sonido de muerte al entrar al estado
        PlaySound(die_sound);
        std::cout << "✅ Sonido de muerte cargado y reproducido\n";
    }
    else
    {
        std::cout << "⚠️  No se pudo cargar sonido de muerte\n";
    }
    
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
    
        // Fondo negro
        ClearBackground(BLACK);
        
        if (use_custom_font)
        {
            // Usar fuente personalizada
            
            // Texto principal "GAME OVER" en rojo
            const char* game_over_text = "GAME OVER";
            float go_size = 45.0f;
            Vector2 go_measure = MeasureTextEx(custom_font, game_over_text, go_size, 2);
            Vector2 go_pos = {(360 - go_measure.x) / 2, 230};
            DrawTextEx(custom_font, game_over_text, go_pos, go_size, 2, RED);
            
            // Ejercicio 4: Mostrar puntuación final en rojo
            std::string score_label = "Puntuacion: ";
            std::string score_value = std::to_string(final_score);
            std::string full_score = score_label + score_value;
            float score_size = 32.0f;
            Vector2 score_measure = MeasureTextEx(custom_font, full_score.c_str(), score_size, 1);
            Vector2 score_pos = {(360 - score_measure.x) / 2, 300};
            DrawTextEx(custom_font, full_score.c_str(), score_pos, score_size, 1, RED);
            
            // Instrucciones para reiniciar en rojo
            const char* restart_text = "Presiona ESPACIO";
            float restart_size = 22.0f;
            Vector2 restart_measure = MeasureTextEx(custom_font, restart_text, restart_size, 1);
            Vector2 restart_pos = {(360 - restart_measure.x) / 2, 380};
            DrawTextEx(custom_font, restart_text, restart_pos, restart_size, 1, RED);
            
            const char* restart_text2 = "para reiniciar";
            Vector2 restart_measure2 = MeasureTextEx(custom_font, restart_text2, restart_size, 1);
            Vector2 restart_pos2 = {(360 - restart_measure2.x) / 2, 410};
            DrawTextEx(custom_font, restart_text2, restart_pos2, restart_size, 1, RED);
            
            // Instrucción para salir en gris oscuro
            const char* exit_text = "Presiona ESC para salir";
            float exit_size = 18.0f;
            Vector2 exit_measure = MeasureTextEx(custom_font, exit_text, exit_size, 1);
            Vector2 exit_pos = {(360 - exit_measure.x) / 2, 600};
            DrawTextEx(custom_font, exit_text, exit_pos, exit_size, 1, DARKGRAY);
        }
        else
        {
            // Fallback: fuente por defecto
            
            // Texto principal "GAME OVER" en rojo
            const char* game_over_text = "GAME OVER";
            int text_width = MeasureText(game_over_text, 40);
            DrawText(game_over_text, (360 - text_width) / 2, 250, 40, RED);
            
            // Ejercicio 4: Mostrar puntuación final en rojo
            std::string score_label = "Puntuacion: ";
            std::string score_value = std::to_string(final_score);
            std::string full_score = score_label + score_value;
            int score_width = MeasureText(full_score.c_str(), 30);
            DrawText(full_score.c_str(), (360 - score_width) / 2, 320, 30, RED);
            
            // Instrucciones para reiniciar en rojo
            const char* restart_text = "Presiona ESPACIO para reiniciar";
            int restart_width = MeasureText(restart_text, 20);
            DrawText(restart_text, (360 - restart_width) / 2, 400, 20, RED);
            
            // Instrucción para salir en gris oscuro
            const char* exit_text = "Presiona ESC para salir";
            int exit_width = MeasureText(exit_text, 15);
            DrawText(exit_text, (360 - exit_width) / 2, 440, 15, DARKGRAY);
        }
    
    EndDrawing();
}
