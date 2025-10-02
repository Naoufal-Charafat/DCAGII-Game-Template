#include <StateMachine.hpp>
#include <MainGameState.hpp>
#include <raylib.h>
#include <memory>
#include <chrono>
#include <iostream>

// 🎯 Propósito: Inicialización del motor raylib y control del bucle principal del juego.
int main()
{ 
    // Ejercicio 0: Inicialización de ventana
    InitWindow(360, 740, "Flappy Bird DCA");
    
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
    
    SetTargetFPS(60);// Establecer FPS objetivo
    
    float delta_time = 0.0f;

    StateMachine state_machine = StateMachine(); // Crear máquina de estados
    state_machine.add_state(std::make_unique<MainGameState>(), false); // Agregar estado principal
    state_machine.handle_state_changes(delta_time); // Inicializar primer estado
    
    
    /*
     Por qué es importante: Controla el bucle de vida completo del juego y garantiza un FPS consistente.
    */
    while (!state_machine.is_game_ending() && !WindowShouldClose())// Detectar cierre de ventana
    {
        delta_time = GetFrameTime();// Tiempo entre frames
        
        state_machine.handle_state_changes(delta_time);// Procesar cambios de estado
        state_machine.getCurrentState()->handleInput();// Manejar entrada
        state_machine.getCurrentState()->update(delta_time);// Actualizar lógica
        state_machine.getCurrentState()->render();       // Renderizar
    }

    // Cerrar ventana al finalizar
    CloseWindow();

    return 0;
}