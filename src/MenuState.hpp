#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <GameState.hpp>
#include <raylib.h>

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
    
    // Audio y fuente
    Sound menu_select_sound;  // Sonido al seleccionar inicio
    Font custom_font;         // Fuente personalizada
    bool use_custom_font;     // Flag para usar fuente personalizada
    
    // Textura de fondo
    Texture2D background_texture;  // Imagen de fondo del menú
    
public:
    MenuState();
    ~MenuState() override;
    
    void init() override;
    void handleInput() override;
    void update(float deltaTime) override;
    void render() override;
    void pause() override;
    void resume() override;
};

#endif // MENUSTATE_HPP
