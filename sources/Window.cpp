#include "Window.h"
#include "Screen.h"
#include <algorithm>
#include <raylib.h>

/// Constructor.
Window::Window(const Screen &screen, const std::string &title)
    : myScreenRenderSource{.x = 0.0f,
                           .y = 0.0f,
                           .width = static_cast<float>(screen.getWidth()),
                           .height = static_cast<float>(-screen.getHeight())} {
  SetConfigFlags(FLAG_VSYNC_HINT);
  SetTargetFPS(60);

  InitWindow(screen.getWidth(), screen.getHeight() + 120, title.c_str());

  myScreenRenderScale =
      std::min(static_cast<float>(getWidth()) / screen.getWidth(),
               static_cast<float>(getHeight()) / screen.getHeight());

  myScreenRenderDest = Rectangle{
      .x = (getWidth() - screen.getWidth() * myScreenRenderScale) / 2.0f,
      .y = (getHeight() - screen.getHeight() * myScreenRenderScale) / 2.0f,
      .width = screen.getWidth() * myScreenRenderScale,
      .height = screen.getHeight() * myScreenRenderScale};
}

/// Destructor.
Window::~Window() { CloseWindow(); }

/// Returns the width of the window.
auto Window::getWidth() const -> int { return GetScreenWidth(); }

/// Returns the height of the window.
auto Window::getHeight() const -> int { return GetScreenHeight(); }

/// Render the screen on the window.
auto Window::render(const Screen &screen) const -> void {
  BeginDrawing();
  ClearBackground(BLACK);

  DrawTexturePro(screen.getRender().texture, myScreenRenderSource,
                 myScreenRenderDest, Vector2{}, 0.0f, WHITE);

  DrawFPS(8, 8);
  EndDrawing();
}
