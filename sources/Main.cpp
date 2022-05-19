#include "Game.h"

#include "CustomColor.h"
#include <raylib.h>
#include <iostream>
#include <string>

namespace old {

int main() {
  const auto defaultGameWidth = 640;
  const auto defaultGameHeight = 360;

  auto gameScale = 1.0f;
  auto gameWidth = defaultGameWidth * gameScale;
  auto gameHeight = defaultGameHeight * gameScale;

  // const auto windowWidth = gameWidth * gameScale + 64;
  // const auto windowHeight = gameHeight * gameScale + 64;
  
  auto windowWidth = defaultGameWidth;
  auto windowHeight = defaultGameHeight;

  // SetConfigFlags(FLAG_FULLSCREEN_MODE | FLAG_VSYNC_HINT /*| FLAG_WINDOW_UNDECORATED*/);
  // SetConfigFlags(FLAG_WINDOW_RESIZABLE);

  InitWindow(windowWidth, windowHeight, "Void Project");
  // Set our game to run at 60 frames-per-second.
  SetTargetFPS(60);
  // SetTargetFPS(30);
  
  // Initialization of the render texture used to store the render result so we
  // can easily resize it.
  const auto render = LoadRenderTexture(defaultGameWidth, defaultGameHeight);
  
  const auto testTexture = LoadTexture(ASSETS_PATH"Heart.png");

  const auto fontSize = 50;

  auto greeting = "Scale 1x";
  auto greetingWidth = MeasureText(greeting, fontSize);
  auto greetingHeight = fontSize;

  auto greetingPosition =
      Vector2{.x = (defaultGameWidth - greetingWidth) / 2.0f,
              .y = (defaultGameHeight - greetingHeight) / 2.0f};

  // Main game loop.
  // Detect window close button or ESC key.
  while (!WindowShouldClose()) {

    // MARK: Input.

    switch (GetKeyPressed()) {
    case KEY_F1:
      gameScale = 1.0f;
      greeting = "Scale 1x";
      break;
    case KEY_F2:
      gameScale = 2.0f;
      greeting = "Scale 2x";
      break;
    case KEY_F3:
      gameScale = 3.0f;
      greeting = "Scale 3x";
      break;
    case KEY_F4:
      gameScale = 4.0f;
      greeting = "Scale 4x";
    case KEY_UP:
      gameScale += 0.5f;
      greeting = std::to_string(gameScale).c_str();
      break;
    case KEY_DOWN:
      gameScale -= 0.5f;
      greeting = std::to_string(gameScale).c_str();
      break;
    }

    // MARK: Update.
    
    gameWidth = defaultGameWidth * gameScale;
    gameHeight = defaultGameHeight * gameScale;
    windowWidth = gameWidth;
    windowHeight = gameHeight;
    SetWindowSize(gameWidth, gameHeight);

    // MARK: Draw.

    // Draw everything on the render texture.
    // Note: that this won't be rendered to the screen yet.
    BeginTextureMode(render);
    ClearBackground(CustomColor::RaisinBlack);

    DrawText(greeting, greetingPosition.x, greetingPosition.y, fontSize,
             CustomColor::ChineseWhite);

    DrawTexture(testTexture, defaultGameWidth - 32, 16, WHITE);
    
    DrawFPS(16, 16);

    EndTextureMode();
    
    BeginDrawing();
    ClearBackground(BLACK);
    // DrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest,
    // Vector2 origin, float rotation, Color tint);

    // DrawTextureEx(render.texture, Vector2{32, 32}, 0.0f, gameScale, WHITE);

    DrawTexturePro(
        render.texture,
        Rectangle{0.0f, 0.0f, static_cast<float>(render.texture.width),
                  static_cast<float>(-render.texture.height)},

         Rectangle{(windowWidth - gameWidth) * 0.5f,
                  (windowHeight - gameHeight) * 0.5f,
                  static_cast<float>(gameWidth),
                  static_cast<float>(gameHeight)},

        // Rectangle{0.0f,
        //           0.0f,
        //           static_cast<float>(windowWidth),
        //           static_cast<float>(windowHeight)},

        // Rectangle{(windowWidth - gameWidth) * 0.5f,
        //           (windowHeight - gameHeight) * 0.5f,
        //           static_cast<float>(gameWidth),
        //           static_cast<float>(gameHeight)},

        Vector2{}, 0.0f, WHITE);

    // DrawTextureRec(
    //     render.texture, // Texture2D texture
    //     Rectangle{
    //         0.0f, 0.0f, static_cast<float>(render.texture.width),
    //         static_cast<float>(-render.texture.height)}, // Rectangle source
    //     Vector2{32, 32},                                 // Vector2 position
    //     WHITE                                            // Color tint
    // );

    EndDrawing();
  }

  // MARK: De-Initialization.
  
  // Unload test texture.
  UnloadTexture(testTexture);

  // Unload render texture.
  UnloadRenderTexture(render);
  // Close window and OpenGL context.
  CloseWindow();
  return 0;
}

} // namespace old

int main() {
  auto game = Game{};
  game.load();

  game.loop();
  
  game.unload();
  return 0;
}