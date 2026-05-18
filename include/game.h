#pragma once

#include "bullet.h"
#include "player.h"
#include <raylib.h>
#include <vector>

class Game {
  public:
    bool gameOver;
    Game();
    void Draw();
    void Update();

  private:
    Player player;
    std::vector<Bullet> bullets;
    // std::vector<Enemy> enemies;
    // WaveManager waveManager;
    // UpgradeSystem upgradeSystem;
    // UI ui;
};
