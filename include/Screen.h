#ifndef SCREEN_H
#define SCREEN_H

#include <raylib.h>

/// Screen.
class Screen {
private:
  const int myWidth{640};
  const int myHeight{360};
  RenderTexture myRender{};

public:
  /// Default constructor.
  Screen() = default;

  /// Returns the width of the screen.
  auto getWidth() const -> int;
  /// Returns the heiget of the screen.
  auto getHeight() const -> int;

  /// Returns the render of the screen.
  auto getRender() const -> const RenderTexture &;

  /// Load.
  auto load() -> void;
  /// Unload.
  auto unload() -> void;
};

#endif // SCREEN_H