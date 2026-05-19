#pragma once

#include <raylib.h>

class Enemy {
  public:
    Enemy();
    void Update(Vector2 playerPos);
    void Draw();
    bool IsAlive();
    Rectangle GetRect();
    void TakeDamage(float damage);

  private:
    Vector2 position;
    float speed;
    int hp;
    float damage;
    bool alive;
};
