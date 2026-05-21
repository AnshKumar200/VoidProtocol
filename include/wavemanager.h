#pragma once

#include "enemy.h"
#include <vector>
class WaveManager {
  public:
    WaveManager();
    void Update(std::vector<Enemy> &enemies);
    int GetCurrentWave();
    float GetBossTimer();

  private:
    int currentWave;
    float spawnTimer;
    float nextSpawnTime;

    int enemiesToSpawn;

    float bossTimer;
    bool bossSpawned;
};
