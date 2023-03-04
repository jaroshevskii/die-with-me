//
// Die With Me
//

import Raylib

struct Player {
  let jumpSpeed: Float = 350.0
  let walkinSpeed: Float = 200.0

  var position: Vector2
  var width: Int
  var height: Int
  var speed: Float
  var canJump: Bool
} 

struct EnvironmentObject {
  var rectangle: Rectangle
  var blocking: Bool
  var color: Color;
}

class Game {
  let windowWidth: Int32 = 640
  // let windowHeight: Int32 = 360 // 16:9
  let windowHeight: Int32 = 400 // 16:10
  let gravity: Float = 400.0

  let environmentObjects = [
    EnvironmentObject(
      rectangle: Rectangle(x: 0.0, y: 0.0, width: 100, height: 400),
      blocking: false,
      color: Color.lightGray
    ),
    EnvironmentObject(
      rectangle: Rectangle(x: 0.0, y: 400.0, width: 1000, height: 200),
      blocking: true,
      color: Color.gray
    ),
    EnvironmentObject(
      rectangle: Rectangle(x: 300.0, y: 2.0, width: 400, height: 10),
      blocking: true,
      color: Color.gray
    ),
    EnvironmentObject(
      rectangle: Rectangle(x: 250.0, y: 300.0, width: 100, height: 10),
      blocking: true,
      color: Color.gray
    ),
    EnvironmentObject(
      rectangle: Rectangle(x: 650.0, y: 300.0, width: 1000, height: 10),
      blocking: true,
      color: Color.gray
    ),
  ]
  let testObject = Rectangle(x: 200, y: 320, width: 96, height: 96)
  
  var player: Player
  var camera: Camera2D

  init() {
    player = Player(
      position: Vector2(x: Float(windowWidth) / 2.0, y: Float(windowHeight) / 2.0),
      width: 32,
      height: 64,
      speed: 0,
      canJump: false
    )
    camera = Camera2D(offset: player.position, target: player.position, rotation: 0.0, zoom: 1.0)

    Raylib.setConfigFlags(.vsyncHint)
    Raylib.initWindow(windowWidth, windowHeight, "Die With Me")
  }
  
  private func update(deltaTime: Float) { 
    if Raylib.isKeyDown(KeyboardKey.left) {
      player.position.x -= player.walkinSpeed * deltaTime
    }
    if Raylib.isKeyDown(KeyboardKey.right) {
      player.position.x += player.walkinSpeed * deltaTime
    }
    if Raylib.isKeyPressed(KeyboardKey.space) && player.canJump {
      player.speed = -player.jumpSpeed;
      player.canJump = false;
    }
    if Raylib.isKeyDown(KeyboardKey.letterR) {
      player.position.y = -100.0
      player.speed = 0.0
    }

    var hitObstacle = false

    for object in environmentObjects {
      if object.blocking
         && object.rectangle.x <= player.position.x
         && object.rectangle.x + object.rectangle.width >= player.position.x
         && object.rectangle.y >= player.position.y
         && object.rectangle.y <= player.position.y + player.speed * deltaTime {
        hitObstacle = true
        player.speed = 0.0
        player.position.y = object.rectangle.y
      }
    }

    if Raylib.checkCollisionRecs(Rectangle(
         x: player.position.x - Float(player.width / 2),
         y: player.position.y - Float(player.height),
         width: Float(player.width),
         height: Float(player.height)
       ), testObject) {
      player.position.x = testObject.x + testObject.width + Float(player.width / 2)
      hitObstacle = true
    }

    if !hitObstacle {
      player.speed += gravity * deltaTime;
      player.position.y += player.speed * deltaTime;
      player.canJump = false;
    } else {
      player.canJump = true;
    }

    camera.target = player.position;
  }

  private func redner() {
    Raylib.beginDrawing()
    Raylib.beginMode2D(camera)
    
    Raylib.clearBackground(.white)

    for object in environmentObjects {
      Raylib.drawRectangleRec(object.rectangle, object.color)
    }
    Raylib.drawRectangleRec(testObject, .black)
    Raylib.drawRectangleRec(
      Rectangle(
        x: player.position.x - Float(player.width / 2),
        y: player.position.y - Float(player.height),
        width: Float(player.width),
        height: Float(player.height)
      ),
      Color.red
    )
    Raylib.drawPixelV(player.position, .black)

    Raylib.endMode2D()

    // Mark: UI

    Raylib.drawFPS(8, 8)
    Raylib.drawText("""
    Player:
    Position: \(Int(player.position.x)), \(Int(player.position.y))
    Speed: \(Int(player.speed))
    Walking speed: \(Int(player.walkinSpeed))
    Can jump: \(player.canJump)

    Gravity: \(gravity)
    """, 8, 36, 10, Color.black)

    Raylib.endDrawing()
  }

  func run() {
    while !Raylib.windowShouldClose {
      update(deltaTime: Raylib.getFrameTime())
      redner()
    }
  }

  deinit {
    Raylib.closeWindow()
  }
}
