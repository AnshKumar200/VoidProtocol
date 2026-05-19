#pragma once

#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include <raylib.h>
#include <vector>

class Game {
  public:
    bool gameOver;
    Game();
    void Draw();
    void Update();
    void CheckCollosions();
    void RemoveDeadBullets();
    void RemoveDeadEnemies();

  private:
    void SpawnEnemy();
    Player player;
    float spwanTimer;
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    // WaveManager waveManager;
    // UpgradeSystem upgradeSystem;
    // UI ui;
};
