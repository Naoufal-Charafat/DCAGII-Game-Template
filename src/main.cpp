#include <StateMachine.hpp>
#include <MainGameState.hpp>
#include <raylib.h>
#include <memory>
#include <chrono>
#include <iostream>

int main()
{ 
    // Ejercicio 0: Inicialización de ventana
    InitWindow(288, 512, "Flappy Bird DCA");
    
    // Verificar que la ventana se inicializó correctamente
    if (!IsWindowReady())
    {
        std::cerr << "\n❌ ERROR: No se pudo inicializar la ventana de raylib\n";
        std::cerr << "Posibles causas:\n";
        std::cerr << "  - No hay entorno gráfico (X11) disponible\n";
        std::cerr << "  - La variable DISPLAY no está configurada\n";
        std::cerr << "  - Estás ejecutando en un servidor sin GUI\n\n";
        std::cerr << "💡 Solución: Ejecuta el juego en una máquina con interfaz gráfica\n";
        std::cerr << "   o usa SSH con X11 forwarding: ssh -X usuario@servidor\n\n";
        return 1;
    }
    
    SetTargetFPS(60);
    
    float delta_time = 0.0f;

    StateMachine state_machine = StateMachine();
    state_machine.add_state(std::make_unique<MainGameState>(), false);
    state_machine.handle_state_changes(delta_time);

    while (!state_machine.is_game_ending() && !WindowShouldClose())// Detectar cierre de ventana
    {
        delta_time = GetFrameTime();
        
        state_machine.handle_state_changes(delta_time);
        state_machine.getCurrentState()->handleInput();
        state_machine.getCurrentState()->update(delta_time);
        state_machine.getCurrentState()->render();       
    }

    // Cerrar ventana al finalizar
    CloseWindow();

    return 0;
}