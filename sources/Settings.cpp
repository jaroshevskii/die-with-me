#include "Settings.h"

/// Returns screen resolution.
auto Settings::getScreenResolution() const -> const Types::Resolution & {
  return myScreenResolution;
}

/// Returns window resolution.
auto Settings::getWindowResolution() const -> const Types::Resolution & {
  return myWindowResolution;
}

/// Returns window title.
auto Settings::getWindowTitile() const -> const std::string & {
  return myWindowTitle;
}