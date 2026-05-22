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
    void MakeBoss();
    float GetDamage();
    int GetHp();
    int GetMaxHp();
    bool IsBoss();
    int GetXp();

  private:
    Vector2 position;
    float speed;
    int hp;
    int maxHp;
    float damage;
    bool alive;
    bool isBoss;
    int xp;
};
