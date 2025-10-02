#pragma once
#include <GameState.hpp>

// 🎯 Ejercicio 3: Estado de Game Over
// Propósito: Mostrar pantalla de derrota y permitir reiniciar el juego
class GameOverState : public GameState
{
    public:
        GameOverState();
        ~GameOverState() = default;

        void init() override;
        void handleInput() override;
        void update(float deltaTime) override;
        void render() override;

        void pause() override {};
        void resume() override {};
        
        // Ejercicio 4: Método para recibir puntuación final
        void setScore(int score) { final_score = score; }
    
    private:
        // Ejercicio 4: Almacenar puntuación final
        int final_score;
};
