#ifndef WINDOW_H
#define WINDOW_H

#include "Screen.h"

/// Window.
class Window {
private:
  const int myWidth{};
  const int myHeight{};
  
public:
  /// Constructor.
  Window(int width, int height);
  /// Destructor.
  ~Window();

  /// Render the screen on the window.
  auto render(const Screen &screen) const -> void;
};

#endif // WINDOW_H