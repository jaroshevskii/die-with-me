#ifndef SCREEN_H
#define SCREEN_H

/// Screen.
class Screen {
private:
  const int myWidth{640};
  const int myHeight{360};
  const int myScale{1};

public:
  /// Default constructor.
  Screen() = default;

  /// Returns the width of the screen.
  auto getWidth() const -> int;
  /// Returns the heiget of the screen.
  auto getHeight() const -> int;
  /// Returns the scale of the screen.
  auto getScale() const -> int;

  /// Returns the scaled width of the screen.
  auto getScaledWidth() const -> int;
  /// Returns the scaled heiget of the screen.
  auto getScaledHeight() const -> int;
};

#endif // SCREEN_H