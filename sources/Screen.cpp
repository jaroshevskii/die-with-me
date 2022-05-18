#include "Screen.h"

/// Returns the width of the screen.
constexpr auto Screen::getWidth() -> int { return myWidth; }
/// Returns the heiget of the screen.
constexpr auto Screen::getHeight() -> int { return myHeight; }
/// Returns the scale of the screen.
constexpr auto Screen::getScale() -> int { return myScale; }

/// Returns the scaled width of the screen.
constexpr auto Screen::getScaledWidth() -> int { return myWidth * myScale; }
/// Returns the scaled heiget of the screen.
constexpr auto Screen::getScaledHeight() -> int { return myHeight * myScale; }