#pragma once

#include <raylib.h>

enum class PlayerState { IDLE, WALK };

class Player {
  public:
    Player();
    ~Player();
    void Update();
    void Draw();
    Vector2 GetPosition();
    bool isAlive();
    void TakeDamage(int damage);
    Rectangle GetRect();
    Vector2 GetCenter();
    void ClampToWorld(float width, float height);
    int GetHp();
    int GetMaxHp();
    int GetXP();
    void AddXP(int xp);

  private:
    Vector2 position;
    float speed;
    int hp;
    int maxHp;
    bool alive;
    int XP;

    Texture2D player;
    Rectangle frameRect;
    int currentFrame;
    int frameCounter;
    int frameSpeed;
    int frameHeight;
    int frameWidth;
};
