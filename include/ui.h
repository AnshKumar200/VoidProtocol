#pragma once

#include "player.h"

class UI {
  public:
    UI();
    void DrawPlayerStats(int hp, int maxHp, int XP);
    void DrawWaveCounter(int currentWave, int enemiesRemaining);
    void MiniMap();
    void BossWarning();
    void Cooldowns();

  private:
};
