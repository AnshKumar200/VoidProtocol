#pragma once

#include "player.h"

class UI {
  public:
    UI();
    void DrawHealthBar(int hp, int maxHp);
    void DrawWaveCounter(int currentWave, int enemiesRemaining);
    void MiniMap();
    void BossWarning();
    void Cooldowns();

  private:
};
