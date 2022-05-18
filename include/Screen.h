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
  constexpr auto getWidth() -> int const;
  /// Returns the heiget of the screen.
  constexpr auto getHeight() -> int const;
  /// Returns the scale of the screen.
  constexpr auto getScale() -> int const;
  
  /// Returns the scaled width of the screen.
  constexpr auto getScaledWidth() -> int const;
  /// Returns the scaled heiget of the screen.
  constexpr auto getScaledHeight() -> int const;
};

#endif // SCREEN_H