#pragma once
#include <memory>

//🎯 Propósito: Clase base abstracta que define la interfaz común para todos los estados del juego.
class StateMachine;

class GameState
{

    public:
        GameState();
        virtual ~GameState() = default;

        virtual void init() = 0;        // Inicialización del estado
        virtual void handleInput() = 0; // Manejo de entrada de usuario
        virtual void update(float deltaTime) = 0; // Lógica del juego
        virtual void render() = 0;      // Renderizado gráfico
        virtual void pause() = 0;       // Pausar estado
        virtual void resume() = 0;      // Reanudar estado

        void setStateMachine(StateMachine* stt_mch) {state_machine = stt_mch;}

    protected:
        StateMachine* state_machine;
};