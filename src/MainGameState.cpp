#include <MainGameState.hpp>
#include <GameOverState.hpp>
#include <StateMachine.hpp>
#include <raylib.h>
#include <iostream>
#include <memory>
#include <string>

MainGameState::MainGameState()
{
}

// Ejercicio 5: Destructor para liberar texturas, sonidos y fuente
MainGameState::~MainGameState()
{
    if (use_sprites)
    {
        if (bird_texture.id != 0) UnloadTexture(bird_texture);
        if (pipe_texture.id != 0) UnloadTexture(pipe_texture);
        if (background_texture.id != 0) UnloadTexture(background_texture);
        std::cout << "🧹 Texturas liberadas correctamente\n";
    }
    
    // Liberar sonidos
    if (jump_sound.frameCount > 0) UnloadSound(jump_sound);
    if (point_sound.frameCount > 0) UnloadSound(point_sound);
    if (hit_sound.frameCount > 0) UnloadSound(hit_sound);
    std::cout << "🔊 Sonidos liberados correctamente\n";
    
    // Liberar fuente
    if (use_custom_font)
    {
        UnloadFont(custom_font);
        std::cout << "🔤 Fuente liberada correctamente\n";
    }
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
    
    // Ejercicio 3: Inicializar estado del juego
    game_over = false;              // Sin game over al inicio
    
    // Ejercicio 4: Inicializar puntuación
    score = 0;                      // Puntuación inicial en 0
    
    // Ejercicio 5: Cargar texturas
    use_sprites = false;  // Por defecto, no usar sprites (fallback)
    
    // Intentar cargar sprite del pájaro
    bird_texture = LoadTexture("assets/sprites/bluebird-midflap.png");
    if (bird_texture.id != 0)
    {
        std::cout << "✅ Sprite del pájaro cargado: " << bird_texture.width << "x" << bird_texture.height << " px\n";
        use_sprites = true;
    }
    else
    {
        std::cout << "⚠️  No se pudo cargar sprite del pájaro, usando círculo rojo\n";
    }
    
    // Intentar cargar sprite de tubería
    pipe_texture = LoadTexture("assets/sprites/pipe-green.png");
    if (pipe_texture.id != 0)
    {
        std::cout << "✅ Sprite de tubería cargado: " << pipe_texture.width << "x" << pipe_texture.height << " px\n";
    }
    else
    {
        std::cout << "⚠️  No se pudo cargar sprite de tubería, usando rectángulos verdes\n";
        use_sprites = false;
    }
    
    // Intentar cargar fondo (opcional)
    background_texture = LoadTexture("assets/sprites/background-day.png");
    if (background_texture.id != 0)
    {
        std::cout << "✅ Fondo cargado: " << background_texture.width << "x" << background_texture.height << " px\n";
    }
    else
    {
        std::cout << "ℹ️  No se cargó fondo, usando color sólido\n";
    }
    
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
    
    // Cargar efectos de sonido
    jump_sound = LoadSound("assets/sounds/jump.wav");
    if (jump_sound.frameCount > 0)
    {
        std::cout << "✅ Sonido de salto cargado correctamente\n";
    }
    else
    {
        std::cout << "⚠️  No se pudo cargar sonido de salto\n";
    }
    
    point_sound = LoadSound("assets/sounds/point.wav");
    if (point_sound.frameCount > 0)
    {
        std::cout << "✅ Sonido de punto cargado correctamente\n";
    }
    else
    {
        std::cout << "⚠️  No se pudo cargar sonido de punto\n";
    }
    
    hit_sound = LoadSound("assets/sounds/hit.wav");
    if (hit_sound.frameCount > 0)
    {
        std::cout << "✅ Sonido de colisión cargado correctamente\n";
    }
    else
    {
        std::cout << "⚠️  No se pudo cargar sonido de colisión\n";
    }
    
    // Generar algunas tuberías iniciales
    generatePipe();
    
    std::cout << "🐦 Pájaro inicializado en posición (" << bird.x << ", " << bird.y << ")\n";
    std::cout << "🏗️  Sistema de tuberías inicializado\n";
    std::cout << "🏆 Puntuación inicializada: " << score << "\n";
    std::cout << "🎨 Modo de renderizado: " << (use_sprites ? "SPRITES" : "PRIMITIVAS") << "\n";
}

// 🎯 Propósito: Manejar la entrada del usuario (en este caso, el salto del pájaro)
void MainGameState::handleInput()
{
    // Ejercicio 1: Detectar tecla ESPACIO para saltar
    if (IsKeyPressed(KEY_SPACE))
    {
        bird.vy = JUMP_VELOCITY; // Aplicar impulso hacia arriba
        
        // Reproducir sonido de salto
        if (jump_sound.frameCount > 0)
        {
            PlaySound(jump_sound);
        }
        
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
    
    // Ejercicio 4: Actualizar puntuación
    updateScore();
    
    // Ejercicio 3: Detectar colisiones
    if (checkCollisions())
    {
        // Reproducir sonido de colisión
        if (hit_sound.frameCount > 0)
        {
            PlaySound(hit_sound);
        }
        
        std::cout << "💥 ¡COLISIÓN DETECTADA! Puntuación final: " << score << "\n";
        
        // Crear GameOverState y pasar la puntuación
        auto game_over_state = std::make_unique<GameOverState>();
        game_over_state->setScore(score);  // Pasar puntuación
        
        // Transición a GameOverState
        this->state_machine->add_state(
            std::move(game_over_state), 
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
                  << " | Tuberías: " << pipes.size() << " | Puntuación: " << score << "\n";
        debug_timer = 0.0f;
    }
}

void MainGameState::render()
{
    // Ejercicio 1, 2, 4 y 5: Renderizado completo del juego
    BeginDrawing();
    
        // Ejercicio 5: Dibujar fondo (textura o color sólido)
        if (background_texture.id != 0)
        {
            // Dibujar fondo con textura, escalado si es necesario
            DrawTexturePro(
                background_texture,
                {0, 0, (float)background_texture.width, (float)background_texture.height},
                {0, 0, 360, 740},
                {0, 0},
                0.0f,
                WHITE
            );
        }
        else
        {
            ClearBackground(SKYBLUE);  // Fallback a color sólido
        }
        
        // Ejercicio 2: Dibujar tuberías primero (fondo)
        renderPipes();
        
        // Ejercicio 5: Dibujar el pájaro (sprite o círculo)
        if (use_sprites && bird_texture.id != 0)
        {
            // Calcular posición para centrar el sprite
            float draw_x = bird.x - bird_texture.width / 2.0f;
            float draw_y = bird.y - bird_texture.height / 2.0f;
            
            DrawTexture(bird_texture, static_cast<int>(draw_x), static_cast<int>(draw_y), WHITE);
        }
        else
        {
            // Fallback: círculo rojo
            DrawCircle(
                static_cast<int>(bird.x), 
                static_cast<int>(bird.y), 
                BIRD_RADIUS, 
                RED
            );
        }
        
        // Ejercicio 4: Mostrar puntuación en pantalla (centrada arriba) con sombreado
        std::string score_text = std::to_string(score);
        
        if (use_custom_font)
        {
            // Usar fuente personalizada
            float score_font_size = 60.0f;
            Vector2 score_measure = MeasureTextEx(custom_font, score_text.c_str(), score_font_size, 2);
            Vector2 score_pos = {(360 - score_measure.x) / 2, 40};
            
            // Dibujar sombra (negro, desplazado 4 píxeles)
            DrawTextEx(custom_font, score_text.c_str(), {score_pos.x + 4, score_pos.y + 4}, score_font_size, 2, BLACK);
            // Dibujar puntuación principal en amarillo
            DrawTextEx(custom_font, score_text.c_str(), score_pos, score_font_size, 2, YELLOW);
        }
        else
        {
            // Fallback: fuente por defecto
            int score_font_size = 50;
            int score_width = MeasureText(score_text.c_str(), score_font_size);
            int score_x = (360 - score_width) / 2;
            int score_y = 50;
            
            // Dibujar sombra (negro, desplazado 3 píxeles)
            DrawText(score_text.c_str(), score_x + 3, score_y + 3, score_font_size, BLACK);
            // Dibujar puntuación principal en amarillo
            DrawText(score_text.c_str(), score_x, score_y, score_font_size, YELLOW);
        }
    
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
    // ⚡ SOLUCIÓN 2: Spawning basado en DISTANCIA (no en tiempo)
    // Generar nueva tubería cuando hay suficiente espacio horizontal
    if (pipes.empty() || (360.0f - pipes.back().top.x >= PIPE_SPAWN_DISTANCE))
    {
        generatePipe();
        std::cout << "🏗️  Nueva tubería spawneada (distancia: " << PIPE_SPAWN_DISTANCE << " px)\n";
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
    // Ejercicio 5: Dibujar tuberías con sprites o primitivas
    for (const auto& pipe : pipes)
    {
        if (use_sprites && pipe_texture.id != 0)
        {
            // Renderizar con sprites
            
            // Tubería superior (rotada 180 grados)
            DrawTexturePro(
                pipe_texture,
                {0, 0, (float)pipe_texture.width, (float)pipe_texture.height},  // Source
                {pipe.top.x, pipe.top.y + pipe.top.height, pipe.top.width, pipe.top.height},  // Dest
                {0, 0},  // Origin
                180.0f,  // Rotación 180° para voltear
                WHITE
            );
            
            // Tubería inferior (normal)
            DrawTexturePro(
                pipe_texture,
                {0, 0, (float)pipe_texture.width, (float)pipe_texture.height},  // Source
                {pipe.bot.x, pipe.bot.y, pipe.bot.width, pipe.bot.height},  // Dest
                {0, 0},  // Origin
                0.0f,  // Sin rotación
                WHITE
            );
        }
        else
        {
            // Fallback: rectángulos verdes
            DrawRectangleRec(pipe.top, DARKGREEN);
            DrawRectangleLinesEx(pipe.top, 2, GREEN);
            DrawRectangleRec(pipe.bot, DARKGREEN);
            DrawRectangleLinesEx(pipe.bot, 2, GREEN);
        }
    }
}

// ========== EJERCICIO 3: MÉTODOS DE COLISIONES ==========

Rectangle MainGameState::getBirdBoundingBox() const
{
    // Ajustar hitbox según si usamos sprites o círculo
    if (use_sprites && bird_texture.id != 0)
    {
        // Hitbox basado en el sprite real (34x24 px), pero reducido un 30% para ser más justo
        float width = bird_texture.width * 0.70f;   // 70% del ancho real
        float height = bird_texture.height * 0.70f;  // 70% del alto real
        
        return Rectangle{
            bird.x - width / 2.0f,   // x (centrado)
            bird.y - height / 2.0f,  // y (centrado)
            width,                    // width
            height                    // height
        };
    }
    else
    {
        // Hitbox para círculo (fallback), reducido al 65% para colisiones más justas
        float box_size = BIRD_RADIUS * 2.0f * 0.65f;  // 65% del diámetro
        
        return Rectangle{
            bird.x - box_size / 2.0f,  // x (centrado)
            bird.y - box_size / 2.0f,  // y (centrado)
            box_size,                   // width
            box_size                    // height
        };
    }
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

// ========== EJERCICIO 4: MÉTODO DE PUNTUACIÓN ==========

void MainGameState::updateScore()
{
    // Verificar cada tubería para ver si el pájaro la ha pasado
    for (auto& pipe : pipes)
    {
        // Si la tubería no ha sido contada y el pájaro la pasó
        if (!pipe.scored && bird.x > pipe.top.x + PIPE_WIDTH)
        {
            pipe.scored = true;  // Marcar como contada
            score++;             // Incrementar puntuación
            
            // Reproducir sonido de punto
            if (point_sound.frameCount > 0)
            {
                PlaySound(point_sound);
            }
            
            std::cout << "🏆 ¡Punto! Puntuación: " << score << "\n";
        }
    }
}