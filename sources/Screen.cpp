#include "Screen.h"
#include "Types.h"

/// Constructor.
Screen::Screen(const Settings &settings)
    : myRender{LoadRenderTexture(settings.getScreenResolution().width,
                                 settings.getScreenResolution().height)} {}

/// Destructor.
Screen::~Screen() { UnloadRenderTexture(myRender); }

/// Returns the render.
auto Screen::getRender() const -> const RenderTexture & { return myRender; }

/// Returns the resolution.
auto Screen::getResolution() const -> Types::Resolution {
  // Screen resolution is the same as the render texture.
  return Types::Resolution{.width = myRender.texture.width,
                           .height = myRender.texture.height};
}