#ifndef GAME_H
#define GAME_H

#include "Screen.h"
#include "Window.h"
#include <istream>

/// Game.
class Game {
private:
  const Screen screen{};
  const Window window{screen.getScaledWidth(), screen.getScaledHeight()};

public:
  /// Default constructor.
  Game() = default;

  /// Game loop.
  auto loop() -> void;
};

#endif // GAME_H