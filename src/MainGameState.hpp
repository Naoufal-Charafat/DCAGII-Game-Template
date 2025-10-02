#pragma once
#include <GameState.hpp>
#include <raylib.h>
#include <deque>

// Estructura para representar al pájaro
struct Bird
{
    float x;  // Posición horizontal
    float y;  // Posición vertical
    float vy; // Velocidad vertical
};

// Ejercicio 2: Estructura para representar un par de tuberías
struct PipePair
{
    Rectangle top;    // Tubería superior
    Rectangle bot;    // Tubería inferior
    bool scored;      // Si ya se ha contado el punto
    
    // Constructor por defecto
    PipePair() : top{0, 0, 0, 0}, bot{0, 0, 0, 0}, scored(false) {}
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
        
        // Ejercicio 2: Constantes de tuberías
        const float PIPE_WIDTH = 52.0f;    // Ancho de las tuberías
        const float PIPE_HEIGHT = 320.0f;  // Altura de las tuberías
        const float PIPE_SPEED = 100.0f;   // Velocidad de movimiento horizontal
        const float PIPE_SPACING = 200.0f; // Espacio entre pares de tuberías
        const float PIPE_GAP = 150.0f;     // Hueco entre tubería superior e inferior
        const float PIPE_SPAWN_TIME = 2.0f; // Tiempo entre generación de tuberías
        
        // Entidades del juego
        Bird bird;
        
        // Ejercicio 2: Sistema de tuberías
        std::deque<PipePair> pipes;        // Cola de tuberías activas
        float pipe_spawn_timer;            // Timer para generar nuevas tuberías
        
        // Métodos auxiliares para tuberías
        void generatePipe();               // Generar nueva tubería
        void updatePipes(float deltaTime); // Actualizar movimiento y eliminación
        void renderPipes();                // Renderizar todas las tuberías
        
        // Ejercicio 3: Métodos de colisiones
        Rectangle getBirdBoundingBox() const;  // Calcular bounding box del pájaro
        bool checkCollisions();                // Detectar colisiones con tuberías y límites
};