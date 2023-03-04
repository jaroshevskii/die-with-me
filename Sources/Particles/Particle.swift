//
// Die with me
//

import Foundation
import Raylib

/// A struct representing a particle that can be attracted by other positions and move with friction.
struct Particle {
  /// The position of the particle.
  var position: Vector2
  /// The velocity of the particle.
  var velocity: Vector2
  /// The color of the particle.
  var color: Color

  /// Creates a new particle at a random position and velocity with a given screen size.
  init(screenWidth: Int32, screenHeight: Int32) {
    self.position = Vector2(
      x: Float.random(in: 0...Float(screenWidth)),
      y: Float.random(in: 0...Float(screenHeight))
    )
    self.velocity = Vector2(
      x: Float.random(in: -1...1),
      y: Float.random(in: -1...1)
    )
    self.color = Color(r: 255, g: 255, b: 255, a: 255)
    // self.color = Color(
    //   r: .random(in: 0...255),
    //   g: .random(in: 0...255),
    //   b: .random(in: 0...255),
    //   a: 255
    // )
  }

  /// Creates a new particle with a given position, velocity, and color.
  init(position: Vector2, velocity: Vector2, color: Color) {
    self.position = position
    self.velocity = velocity
    self.color = color
  }

  /// Attracts the particle towards a given position with a given multiplier.
  mutating func attract(to positionToAttract: Vector2, withMultiplier multiplier: Float) {
    let dist = max(getDistance(to: positionToAttract), 0.5)
    let normal = getNormal(to: positionToAttract)
    velocity.x -= normal.x / dist * multiplier
    velocity.y -= normal.y / dist * multiplier
  }

  /// Applies friction to the particle's velocity.
  mutating func applyFriction(amount: Float) {
    velocity.x *= amount
    velocity.y *= amount
  }

  /// Moves the particle according to its velocity and wraps around the screen.
  mutating func move(screenWidth: Int32, screenHeight: Int32) {
    position.x += velocity.x
    position.y += velocity.y
    if position.x < 0 {
      position.x += Float(screenWidth)
    }
    if position.x >= Float(screenWidth) {
      position.x -= Float(screenWidth)
    }
    if position.y < 0 {
      position.y += Float(screenHeight)
    }
    if position.y >= Float(screenHeight) {
      position.y -= Float(screenHeight)
    }
  }

  /// Gets the distance between the particle's position and another position.
  private func getDistance(to otherPos: Vector2) -> Float {
    let dx = position.x - otherPos.x
    let dy = position.y - otherPos.y
    return sqrt((dx * dx) + (dy * dy))
  }

  /// Gets the normal vector between the particle's position and another position.
  private func getNormal(to otherPos: Vector2) -> Vector2 {
    var normal = Vector2(x: 0, y: 0)
    let dist = getDistance(to: otherPos)
    if dist != 0 {
      normal.x = (position.x - otherPos.x) / dist
      normal.y = (position.y - otherPos.y) / dist
    }
    return normal
  }
}
