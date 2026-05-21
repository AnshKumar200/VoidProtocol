
#include "../include/wavemanager.h"
#include <raylib.h>
#include <vector>

/*
 WHEN enemies should spawn
WHAT enemies should spawn
HOW MANY enemies should spawn
WHEN boss appears
WHEN next wave starts
 * */

// aliveEnemies
// wave cooldown like a time before the next wave spawns? would be nice

WaveManager::WaveManager() {
    currentWave = 1;
    enemiesToSpawn = 5;

    spawnTimer = 0;
    nextSpawnTime = 1.0f;
    bossSpawned = false;
}

void WaveManager::Update(std::vector<Enemy> &enemies) {
    spawnTimer += GetFrameTime();

    if (enemiesToSpawn > 0 && spawnTimer >= nextSpawnTime) {
        enemies.push_back(Enemy());
        enemiesToSpawn--;

        spawnTimer = 0;
    }

    if (enemies.empty() && enemiesToSpawn == 0) {
        currentWave++;
        enemiesToSpawn = currentWave * 5;
    }
}

int WaveManager::GetCurrentWave() { return currentWave; }
