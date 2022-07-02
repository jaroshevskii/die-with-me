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
  const Screen myScreen{mySettings};

  /// Game input.
  auto input() const -> void;
  /// Game update.
  auto update() const -> void;
  /// Game render.
  auto render() const -> void;

public:
  /// Default constructor.
  Game() = default;

  /// Game loop.
  auto loop() const -> void;
};

#endif // GAME_H