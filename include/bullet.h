#pragma once

#include <raylib.h>
#include <vector>

class Bullet {
  public:
    Bullet(Vector2 playerPos, Vector2 mousePos);
    void Update();
    void Draw();

  private:
    Vector2 position;
    Vector2 direction;
    float speed;
    bool alive;
};
