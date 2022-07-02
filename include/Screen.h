#ifndef SCREEN_H
#define SCREEN_H

#include "Settings.h"
#include "Types.h"
#include <raylib.h>

/// Screen.
class Screen {
private:
  const RenderTexture myRender{};

public:
  /// Constructor.
  Screen(const Settings &setting);
  /// Destructor.
  ~Screen();

  /// Returns the render.
  auto getRender() const -> const RenderTexture &;

  /// Returns the resolution.
  auto getResolution() const -> Types::Resolution;
};

#endif // SCREEN_H