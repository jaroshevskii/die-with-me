#include "Game.h"

int main() {
  auto game = Game{};
  game.load();

  game.loop();
  
  game.unload();
  return 0;
}