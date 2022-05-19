#ifndef GAME_H
#define GAME_H

#include "Screen.h"
#include "Window.h"

/// Game.
class Game {
private:
  Screen myScreen{};
  const Window myWindow{myScreen.getScaledWidth(), myScreen.getScaledHeight()};  
  
  /// Game input.
  auto input() -> void;
  /// Game update.
  auto update() -> void;
  /// Game render.
  auto render() -> void;
public:
  /// Default constructor.
  Game() = default;
  
  /// Game load.
  auto load() -> void;
  /// Game unload.
  auto unload() -> void;

  /// Game loop.
  auto loop() -> void;
};

#endif // GAME_H