#pragma once

#include "enemy.h"
#include "player.h"

class UI {
  public:
    UI();
    void DrawPlayerStats(Player &player);
    void DrawWaveCounter(int currentWave, int enemiesRemaining);
    void DrawBossBar(Enemy *boss);
    void MiniMap();
    void BossWarning();
    void Cooldowns();

  private:
};
