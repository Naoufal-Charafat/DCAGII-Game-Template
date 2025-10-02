#include <MenuState.hpp>
#include <MainGameState.hpp>
#include <StateMachine.hpp>
#include <raylib.h>
#include <iostream>
#include <memory>

MenuState::MenuState() : blink_timer(0.0f), show_text(true), use_custom_font(false)
{
    std::cout << "🎮 Estado de Menú creado\n";
}

MenuState::~MenuState()
{
    // Liberar recursos de audio y fuente
    if (menu_select_sound.frameCount > 0)
    {
        UnloadSound(menu_select_sound);
        std::cout << "🔊 Sonido de menú liberado\n";
    }
    
    if (use_custom_font)
    {
        UnloadFont(custom_font);
        std::cout << "🔤 Fuente personalizada liberada\n";
    }
    
    // Liberar textura de fondo
    if (background_texture.id != 0)
    {
        UnloadTexture(background_texture);
        std::cout << "🖼️  Textura de fondo del menú liberada\n";
    }
}

void MenuState::init()
{
    blink_timer = 0.0f;
    show_text = true;
    
    // Inicializar audio
    InitAudioDevice();
    
    // Cargar fuente personalizada
    custom_font = LoadFontEx("assets/fonts/LuckiestGuy.ttf", 80, nullptr, 0);
    if (custom_font.texture.id != 0)
    {
        use_custom_font = true;
        std::cout << "✅ Fuente personalizada cargada correctamente\n";
    }
    else
    {
        use_custom_font = false;
        std::cout << "⚠️  No se pudo cargar la fuente, usando fuente por defecto\n";
    }
    
    // Cargar sonido de selección
    menu_select_sound = LoadSound("assets/sounds/menu_select.wav");
    if (menu_select_sound.frameCount > 0)
    {
        std::cout << "✅ Sonido de menú cargado correctamente\n";
    }
    else
    {
        std::cout << "⚠️  No se pudo cargar sonido de menú\n";
    }
    
    // Cargar imagen de fondo
    background_texture = LoadTexture("assets/sprites/start-game.png");
    if (background_texture.id != 0)
    {
        std::cout << "✅ Fondo del menú cargado: " << background_texture.width << "x" << background_texture.height << " px\n";
    }
    else
    {
        std::cout << "⚠️  No se pudo cargar fondo del menú\n";
    }
    
    std::cout << "🎮 Menú principal inicializado\n";
}

void MenuState::handleInput()
{
    // Iniciar juego al presionar ESPACIO
    if (IsKeyPressed(KEY_SPACE))
    {
        // Reproducir sonido de selección
        if (menu_select_sound.frameCount > 0)
        {
            PlaySound(menu_select_sound);
            std::cout << "🔊 Reproduciendo sonido de inicio\n";
        }
        
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
    
        // Dibujar imagen de fondo si está cargada
        if (background_texture.id != 0)
        {
            // Escalar imagen de fondo para cubrir toda la pantalla (360x740)
            DrawTexturePro(
                background_texture,
                {0, 0, (float)background_texture.width, (float)background_texture.height},  // Source
                {0, 0, 360, 740},  // Destination (pantalla completa)
                {0, 0},  // Origin
                0.0f,    // Rotation
                WHITE    // Tint
            );
        }
        else
        {
            // Fallback: Fondo negro si no hay imagen
            ClearBackground(BLACK);
        }
        
        if (use_custom_font)
        {
            // Usar fuente personalizada
            
            // Título principal "FLAPPY BIRD"
            const char* title_text = "FLAPPY BIRD";
            float title_size = 48.0f;
            Vector2 title_measure = MeasureTextEx(custom_font, title_text, title_size, 2);
            Vector2 title_pos = {(360 - title_measure.x) / 2, 220};
            DrawTextEx(custom_font, title_text, title_pos, title_size, 2, GREEN);
            
            // Subtítulo "DCA Edition"
            const char* subtitle_text = "DCA Edition";
            float subtitle_size = 30.0f;
            Vector2 subtitle_measure = MeasureTextEx(custom_font, subtitle_text, subtitle_size, 1);
            Vector2 subtitle_pos = {(360 - subtitle_measure.x) / 2, 280};
            DrawTextEx(custom_font, subtitle_text, subtitle_pos, subtitle_size, 1, DARKGREEN);
            
            // Texto parpadeante: "Presiona ESPACIO para comenzar"
            if (show_text)
            {
                const char* start_text = "Presiona ESPACIO";
                float start_size = 22.0f;
                Vector2 start_measure = MeasureTextEx(custom_font, start_text, start_size, 1);
                Vector2 start_pos = {(360 - start_measure.x) / 2, 380};
                DrawTextEx(custom_font, start_text, start_pos, start_size, 1, YELLOW);
                
                const char* start_text2 = "para comenzar";
                Vector2 start_measure2 = MeasureTextEx(custom_font, start_text2, start_size, 1);
                Vector2 start_pos2 = {(360 - start_measure2.x) / 2, 410};
                DrawTextEx(custom_font, start_text2, start_pos2, start_size, 1, YELLOW);
            }
            
            // Instrucciones de salida (siempre visible)
            const char* exit_text = "Presiona ESC para salir";
            float exit_size = 18.0f;
            Vector2 exit_measure = MeasureTextEx(custom_font, exit_text, exit_size, 1);
            Vector2 exit_pos = {(360 - exit_measure.x) / 2, 650};
            DrawTextEx(custom_font, exit_text, exit_pos, exit_size, 1, DARKGRAY);
        }
        else
        {
            // Fallback: fuente por defecto
            
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
        }
    
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
