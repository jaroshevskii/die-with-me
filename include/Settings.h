#ifndef SETTINGS_H
#define SETTINGS_H

#include "Types.h"
#include <raylib.h>
#include <string>
#include <vector>

/// Settings.
class Settings {
public:
  using Flags = unsigned int;

private:
  // Screen settings
  const Types::Resolution myScreenResolution{.width = 640, .height = 360};

  // Window settings.
  const Types::Resolution myWindowResolution{
      .width = myScreenResolution.width,
      .height = myScreenResolution.height + 120};
  const std::string myWindowTitle{"Project Void"};

  const Flags myFlags{FLAG_VSYNC_HINT};
  const int myFPS{60};

public:
  /// Default Constructor.
  Settings() = default;

  /// Returns screen resolution.
  auto getScreenResolution() const -> const Types::Resolution &;

  /// Returns window resolution.
  auto getWindowResolution() const -> const Types::Resolution &;
  /// Returns window title.
  auto getWindowTitile() const -> const std::string &;

  /// Returns flags.
  auto getFlags() const -> const Flags &;
  /// Returns FPS.
  auto getFPS() const -> int;
};

#endif // SETTINGS_H