#ifndef GAME_H
#define GAME_H

#include "Screen.h"
#include "Settings.h"
#include "Window.h"
#include <string>

/// Game.
class Game {
private:
  const Settings mySettings{};
  const Window myWindow{mySettings};
  
  Screen myScreen{};

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