#ifndef SETTINGS_H
#define SETTINGS_H

#include "Screen.h"
#include "Types.h"
#include <string>

/// Settings.
class Settings {
private:
  // Screen settings
  const Types::Resolution myScreenResolution{.width = 640, .height = 360};
  
  // Window settings.
  const Types::Resolution myWindowResolution{
      .width = myScreenResolution.width,
      .height = myScreenResolution.height + 120};
  const std::string myWindowTitle{"Project Void"};

public:
  /// Default Constructor.
  Settings() = default;

  /// Returns screen resolution.
  auto getScreenResolution() const -> const Types::Resolution&;

  /// Returns window resolution.
  auto getWindowResolution() const -> const Types::Resolution&;
  /// Returns window title.
  auto getWindowTitile() const -> const std::string&;
};

#endif // SETTINGS_H