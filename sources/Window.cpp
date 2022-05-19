#include "Window.h"
#include "Screen.h"
#include <raylib.h>

/// Constructor.
Window::Window(int width, int height) : myWidth{width}, myHeight{height} {
  SetConfigFlags(FLAG_VSYNC_HINT);
  InitWindow(myWidth, myHeight, "Void Project");
}

/// Destructor.
Window::~Window() { CloseWindow(); }

/// Render the screen on the window.
auto Window::render(const Screen &screen) const -> void {
  const auto source =
      Rectangle{.x = 0.0f,
                .y = 0.0f,
                .width = static_cast<float>(screen.getWidth()),
                .height = static_cast<float>(-screen.getHeight())};

  const auto dest =
      Rectangle{.x = (screen.getScaledWidth() - myWidth) / 2.0f,
                .y = (screen.getScaledHeight() - myHeight) / 2.0f,
                .width = static_cast<float>(screen.getScaledWidth()),
                .height = static_cast<float>(screen.getScaledHeight())};

  const auto origin = Vector2{};
  const auto rotation = 0.0f;
  const auto color = WHITE;

  BeginDrawing();
  ClearBackground(BLACK);
  DrawTexturePro(screen.getRender().texture, source, dest, origin, rotation,
                 color);
  DrawFPS(16, 16);
  EndDrawing();
}