#include <MainGameState.hpp>
#include <raylib.h>
#include <iostream>

MainGameState::MainGameState()
{
}

void MainGameState::init()
{

}

void MainGameState::handleInput()
{

}

void MainGameState::update(float deltaTime)
{

}

void MainGameState::render()
{
    // Ejercicio 0: Renderizado básico de ventana con texto de bienvenida
    BeginDrawing();
    
        ClearBackground(SKYBLUE);
        
        // Texto de bienvenida centrado
        const char* welcome_text = "Bienvenido a Flappy Bird DCA";
        int text_width = MeasureText(welcome_text, 20);
        DrawText(welcome_text, (288 - text_width) / 2, 256, 20, WHITE);
        
        // Instrucciones
        const char* instructions = "Presiona ESC para salir";
        int instructions_width = MeasureText(instructions, 15);
        DrawText(instructions, (288 - instructions_width) / 2, 300, 15, LIGHTGRAY);
    
    EndDrawing();
}