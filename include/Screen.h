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
  constexpr auto getWidth() -> int;
  /// Returns the heiget of the screen.
  constexpr auto getHeight() -> int;
  /// Returns the scale of the screen.
  constexpr auto getScale() -> int;
  
  /// Returns the scaled width of the screen.
  constexpr auto getScaledWidth() -> int;
  /// Returns the scaled heiget of the screen.
  constexpr auto getScaledHeight() -> int;
};

#endif // SCREEN_H