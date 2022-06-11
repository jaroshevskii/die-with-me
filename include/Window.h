#ifndef WINDOW_H
#define WINDOW_H

#include "Screen.h"
#include <raylib.h>
#include <string>

/// Window.
class Window {
private:
  float myScreenRenderScale{};
  const Rectangle myScreenRenderSource{};
  Rectangle myScreenRenderDest{};

public:
  /// Constructor.
  Window(const Screen &screen, const std::string &title);
  /// Destructor.
  ~Window();

  /// Returns the width of the window.
  auto getWidth() const -> int;
  /// Returns the height of the window.
  auto getHeight() const -> int;

  /// Render the screen on the window.
  auto render(const Screen &screen) const -> void;
};

#endif // WINDOW_H