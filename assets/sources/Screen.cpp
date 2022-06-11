#include "Screen.h"
#include <raylib.h>

/// Returns the width of the screen.
auto Screen::getWidth() const -> int { return myWidth; }
/// Returns the heiget of the screen.
auto Screen::getHeight() const -> int { return myHeight; }
/// Returns the scale of the screen.
auto Screen::getScale() const -> int { return myScale; }

/// Returns the scaled width of the screen.
auto Screen::getScaledWidth() const -> int { return myWidth * myScale; }
/// Returns the scaled heiget of the screen.
auto Screen::getScaledHeight() const -> int { return myHeight * myScale; }

/// Returns the render of the screen.
auto Screen::getRender() const -> const RenderTexture & { return myRender; }

/// Load.
auto Screen::load() -> void {
  myRender = LoadRenderTexture(myWidth, myHeight);
}

/// Unload.
auto Screen::unload() -> void {
  UnloadRenderTexture(myRender);
}