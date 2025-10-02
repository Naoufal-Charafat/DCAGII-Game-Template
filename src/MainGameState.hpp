#pragma once
#include <GameState.hpp>

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
        char entered_key;
};