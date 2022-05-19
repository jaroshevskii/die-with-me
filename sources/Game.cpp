#include "Game.h"
#include "CustomColor.h"
#include <raylib.h>

/// Game input.
auto Game::input() -> void {
  // Some game input.
}

/// Game update.
auto Game::update() -> void {
  // Some game update.
}

/// Game render.
auto Game::render() -> void {
  BeginTextureMode(myScreen.getRender());
  ClearBackground(CustomColor::ChineseWhite);
  DrawText("Hello!", 32, 64, 40, CustomColor::RichBlack);
  EndTextureMode();

  // Render game window.
  myWindow.render(myScreen);
}

/// Game load.
auto Game::load() -> void {
  // Load game screen.
  myScreen.load();
}

/// Game unload.
auto Game::unload() -> void {
  // Unload game screen.
  myScreen.unload();
}

/// Game loop.
auto Game::loop() -> void {
  while (!WindowShouldClose()) {
    input();
    update();
    render();
  }
}