#include <MenuState.hpp>
#include <MainGameState.hpp>
#include <StateMachine.hpp>
#include <raylib.h>
#include <iostream>
#include <memory>

MenuState::MenuState() : blink_timer(0.0f), show_text(true)
{
    std::cout << "🎮 Estado de Menú creado\n";
}

void MenuState::init()
{
    blink_timer = 0.0f;
    show_text = true;
    std::cout << "🎮 Menú principal inicializado\n";
}

void MenuState::handleInput()
{
    // Iniciar juego al presionar ESPACIO
    if (IsKeyPressed(KEY_SPACE))
    {
        std::cout << "🚀 Iniciando partida...\n";
        
        // Transición a MainGameState
        this->state_machine->add_state(
            std::make_unique<MainGameState>(), 
            true  // Reemplazar estado actual
        );
    }
}

void MenuState::update(float deltaTime)
{
    // Actualizar temporizador de parpadeo
    blink_timer += deltaTime;
    
    // Alternar visibilidad cada 0.5 segundos
    if (blink_timer >= 0.5f)
    {
        show_text = !show_text;
        blink_timer = 0.0f;
    }
}

void MenuState::render()
{
    BeginDrawing();
    
        // Fondo negro
        ClearBackground(BLACK);
        
        // Título principal "FLAPPY BIRD"
        const char* title_text = "FLAPPY BIRD";
        int title_size = 40;
        int title_width = MeasureText(title_text, title_size);
        DrawText(title_text, (360 - title_width) / 2, 250, title_size, GREEN);
        
        // Subtítulo "DCA Edition"
        const char* subtitle_text = "DCA Edition";
        int subtitle_size = 25;
        int subtitle_width = MeasureText(subtitle_text, subtitle_size);
        DrawText(subtitle_text, (360 - subtitle_width) / 2, 310, subtitle_size, DARKGREEN);
        
        // Texto parpadeante: "Presiona ESPACIO para comenzar"
        if (show_text)
        {
            const char* start_text = "Presiona ESPACIO para comenzar";
            int start_size = 18;
            int start_width = MeasureText(start_text, start_size);
            DrawText(start_text, (360 - start_width) / 2, 400, start_size, YELLOW);
        }
        
        // Instrucciones de salida (siempre visible)
        const char* exit_text = "Presiona ESC para salir";
        int exit_size = 14;
        int exit_width = MeasureText(exit_text, exit_size);
        DrawText(exit_text, (360 - exit_width) / 2, 650, exit_size, DARKGRAY);
    
    EndDrawing();
}

void MenuState::pause()
{
    // No requiere lógica especial de pausa en el menú
}

void MenuState::resume()
{
    // Reiniciar el parpadeo al volver al menú
    blink_timer = 0.0f;
    show_text = true;
}
