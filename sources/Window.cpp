#include "Window.h"
#include "Screen.h"
#include "Settings.h"
#include <algorithm>
#include <raylib.h>

/// Constructor.
Window::Window(const Settings &settings)
    : myScreenRenderSource{.x = 0.0f,
                           .y = 0.0f,
                           .width = static_cast<float>(
                               settings.getScreenResolution().width),
                           .height = static_cast<float>(
                               -settings.getScreenResolution().height)},

      myScreenRenderScale{
          std::min(static_cast<float>(settings.getWindowResolution().width) /
                       settings.getScreenResolution().width,
                   static_cast<float>(settings.getWindowResolution().height) /
                       settings.getScreenResolution().height)},

      myScreenRenderDest{
          .x = (settings.getWindowResolution().width -
                settings.getScreenResolution().width * myScreenRenderScale) /
               2.0f,
          .y = (settings.getWindowResolution().height -
                settings.getScreenResolution().height * myScreenRenderScale) /
               2.0f,
          .width = settings.getScreenResolution().width * myScreenRenderScale,
          .height =
              settings.getScreenResolution().height * myScreenRenderScale} {
  SetConfigFlags(settings.getFlags());
  SetTargetFPS(settings.getFPS());

  InitWindow(settings.getWindowResolution().width,
             settings.getWindowResolution().height,
             settings.getWindowTitile().c_str());
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
