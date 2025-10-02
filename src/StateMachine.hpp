#pragma once
#include <GameState.hpp>
#include <stack>
#include <memory>
#include <unordered_map>
#include <string>

//🎯 Propósito: Gestor principal que controla las transiciones entre diferentes estados del juego.
class StateMachine 
{
    public:
        StateMachine();
        ~StateMachine() = default;

        void add_state(std::unique_ptr<GameState> state, bool is_replacing); // Agregar nuevo estado
        void remove_state(bool value); // Remover estado actual
        void handle_state_changes(float& deltaTime); // Procesar cambios de estado

        void stop() {is_running = false;} // Detener la máquina de estados
        bool isRunning() {return this->is_running;} // Verificar si la máquina de estados está en ejecución

        bool is_game_ending() {return this->is_ending;}

        std::unique_ptr<GameState>& getCurrentState() {return this->states_machine.top();}
    
    private:
        std::stack<std::unique_ptr<GameState>> states_machine; // Pila de estados
        std::unique_ptr<GameState> new_state;
        bool is_running;

        bool is_removing = false,
             is_Adding = false,
             is_Replacing = false,
             is_ending = false;
};