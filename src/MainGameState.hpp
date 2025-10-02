#pragma once
#include <GameState.hpp>

// Estructura para representar al pájaro
struct Bird
{
    float x;  // Posición horizontal
    float y;  // Posición vertical
    float vy; // Velocidad vertical
};

// 🎯 Propósito: ¡EL CORAZÓN DEL JUEGO! Contiene toda la lógica específica de Flappy Bird.
class MainGameState : public GameState
{
    public:
        MainGameState();
        ~MainGameState() = default;

        void init() override; //  Cargar texturas, inicializar entidades, configurar parámetros
        void handleInput() override; //  Detectar salto del pájaro (SPACE), pausas, etc.
        void update(float deltaTime) override; // Actualizar posiciones, detectar colisiones, gestionar puntuación
        void render() override; // Dibujar fondo, pájaro, tuberías, suelo, puntuación

        void pause(){};
        void resume(){};

    
    private:
        // Constantes de física
        const float GRAVITY = 980.0f;      // Gravedad (píxeles/segundo²)
        const float JUMP_VELOCITY = -300.0f; // Velocidad de salto
        const float BIRD_RADIUS = 17.0f;   // Radio del círculo del pájaro
        
        // Entidades del juego
        Bird bird;
};