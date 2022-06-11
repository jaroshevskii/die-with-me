#include "Screen.h"
#include <raylib.h>

/// Returns the width of the screen.
auto Screen::getWidth() const -> int { return myWidth; }
/// Returns the heiget of the screen.
auto Screen::getHeight() const -> int { return myHeight; }

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