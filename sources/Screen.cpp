#include "Screen.h"

/// Returns the width of the screen.
constexpr auto Screen::getWidth() -> int const { return myWidth; }
/// Returns the heiget of the screen.
constexpr auto Screen::getHeight() -> int const { return myHeight; }
/// Returns the scale of the screen.
constexpr auto Screen::getScale() -> int const { return myScale; }

/// Returns the scaled width of the screen.
constexpr auto Screen::getScaledWidth() -> int const {
  return myWidth * myScale;
}

/// Returns the scaled heiget of the screen.
constexpr auto Screen::getScaledHeight() -> int const {
  return myHeight * myScale;
}