//
// Die with me
//

import Foundation
import Raylib

let screenWidth: Int32 = 800
let screenHeight: Int32 = 480

Raylib.setConfigFlags([
  // .msaa4xHint,
  .vsyncHint,
])
Raylib.initWindow(screenWidth, screenHeight, "Particles")

let particleCount = 1000
var particles = [Particle](
  repeating: Particle(screenWidth: 0, screenHeight: 0),
  count: particleCount
)

for i in 0..<particleCount {
  particles[i] = Particle(screenWidth: screenWidth, screenHeight: screenHeight)
}

while !Raylib.windowShouldClose {
  let mousePosition = Vector2(x: Float(Raylib.getMouseX()), y: Float(Raylib.getMouseY()))

  for i in 0..<particleCount {
    particles[i].attract(to: mousePosition, withMultiplier: 1)
    particles[i].applyFriction(amount: 0.99)
    particles[i].move(screenWidth: screenWidth, screenHeight: screenHeight)
  }

  Raylib.beginDrawing()

  Raylib.clearBackground(.black)

  for particle in particles {
    Raylib.drawPixelV(particle.position, particle.color)
    // Raylib.drawCircleV(particle.position, 2, particle.color)
  }

  Raylib.drawFPS(10, 10)

  Raylib.endDrawing()
}

Raylib.closeWindow()
