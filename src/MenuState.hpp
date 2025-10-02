#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <GameState.hpp>

/**
 * 🎮 MenuState - Estado del menú principal
 * Pantalla de inicio del juego con:
 * - Fondo negro
 * - Título verde centrado
 * - Indicación parpadeante en amarillo
 */
class MenuState : public GameState
{
private:
    float blink_timer;  // Temporizador para efecto de parpadeo
    bool show_text;     // Control de visibilidad del texto parpadeante
    
public:
    MenuState();
    ~MenuState() override = default;
    
    void init() override;
    void handleInput() override;
    void update(float deltaTime) override;
    void render() override;
    void pause() override;
    void resume() override;
};

#endif // MENUSTATE_HPP
