#include "Game.h"
#include <raylib.h>

/// Game loop.
auto Game::loop() -> void {
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
  }
}