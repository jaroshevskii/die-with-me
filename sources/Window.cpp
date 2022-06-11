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
  // const auto source =
  //     Rectangle{.x = 0.0f,
  //               .y = 0.0f,
  //               .width = static_cast<float>(screen.getWidth()),
  //               .height = static_cast<float>(-screen.getHeight())};

  // const auto dest =
  //     Rectangle{.x = (myWidth - screen.getScaledWidth()) / 2.0f,
  //               .y = (myHeight - screen.getScaledHeight()) / 2.0f,
  //               .width = static_cast<float>(screen.getScaledWidth()),
  //               .height = static_cast<float>(screen.getScaledHeight())};

  // if (true) {
  //   auto width = 0.0f;
  //   auto height = 0.0f;

  //   if (GetScreenWidth() >= GetScreenHeight()) {
  //     width = GetScreenHeight() / 9.0f * 16.0f;
  //     height = width / 16.0f * 9.0f;
  //   } else {
  //     height = GetScreenWidth() / 16.0f * 9.0f;
  //     width = height / 9.0f * 16.0f;
  //   }

  //   dest = Rectangle{.x = (GetScreenWidth() - width) / 2.0f,
  //                    .y = (GetScreenHeight() - height) / 2.0f,
  //                    .width = width,
  //                    .height = height};
  // }

  // const auto scale =
  //     std::min(static_cast<float>(GetScreenWidth()) / screen.getWidth(),
  //              static_cast<float>(GetScreenHeight()) / screen.getHeight());

  // const auto dest = Rectangle{
  //     .x = (GetScreenWidth() - screen.getScaledWidth() * scale) / 2.0f,
  //     .y = (GetScreenHeight() - screen.getScaledHeight() * scale) / 2.0f,
  //     .width = screen.getScaledWidth() * scale,
  //     .height = screen.getScaledHeight() * scale};

  // std::cout << "Scalale: " << scale << '\n';

  // float scale = min((float)GetScreenWidth() / gameScreenWidth,
  //                   (float)GetScreenHeight() / gameScreenHeight);

  // const auto origin = Vector2{};
  // const auto rotation = 0.0f;
  // const auto color = WHITE;

  // DrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2
  // origin, float rotation, Color tint)

  BeginDrawing();
  ClearBackground(BLACK);

  DrawTexturePro(screen.getRender().texture, myScreenRenderSource,
                 myScreenRenderDest, Vector2{}, 0.0f, WHITE);

  DrawFPS(8, 8);
  EndDrawing();
}
