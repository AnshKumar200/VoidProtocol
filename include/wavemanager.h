#pragma once

#include "enemy.h"
#include <vector>
class WaveManager {
  public:
    WaveManager();
    void Update(std::vector<Enemy> &enemies);
    int GetCurrentWave();

  private:
    int currentWave;
    float spawnTimer;
    float nextSpawnTime;

    int enemiesToSpawn;

    bool bossSpawned;
};
