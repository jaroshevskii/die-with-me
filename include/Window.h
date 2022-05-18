#ifndef WINDOW_H
#define WINDOW_H

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
};

#endif // WINDOW_H