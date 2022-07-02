#include "Game.h"
#include "CustomColors.h"

/// Game input.
auto Game::input() const -> void {
  // Some game input.
}

/// Game update.
auto Game::update() const -> void {
  // Some game update.
}

/// Game render.
auto Game::render() const -> void {
  //--
  const auto *text = "This is game screen";
  const auto textSize = 30;
  const auto textPosX =
      (myScreen.getResolution().width - MeasureText(text, textSize)) / 2;
  const auto textPosY = (myScreen.getResolution().height - textSize) / 2;
  //--

  BeginTextureMode(myScreen.getRender());
  ClearBackground(CustomColors::ChineseWhite);
  DrawText(text, textPosX, textPosY, textSize, CustomColors::RichBlack);
  EndTextureMode();

  // Rendering the game screen in a window.
  myWindow.render(myScreen);
}

/// Game loop.
auto Game::loop() const -> void {
  while (!WindowShouldClose()) {
    input();
    update();
    render();
  }
}