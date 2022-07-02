#include "Game.h"
#include "CustomColors.h"
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
  //--
  const auto *text = "This is game screen";
  const auto textSize = 30;
  const auto textPosX = (myScreen.getWidth() - MeasureText(text, textSize)) / 2;
  const auto textPosY = (myScreen.getHeight() - textSize) / 2;
  //--

  BeginTextureMode(myScreen.getRender());
  ClearBackground(CustomColors::ChineseWhite);
  DrawText(text, textPosX, textPosY, textSize, CustomColors::RichBlack);
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