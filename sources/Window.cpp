#include "Window.h"
#include <raylib.h>

/// Constructor.
Window::Window(int width, int height) : myWidth{width}, myHeight{height} {
  InitWindow(myWidth, myHeight, "Void Project");
}

/// Destructor.
Window::~Window() { CloseWindow(); }