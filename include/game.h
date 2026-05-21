#pragma once

#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include "ui.h"
#include "wavemanager.h"
#include <nlohmann/json.hpp>
#include <raylib.h>
#include <vector>

enum class GameState { MENU, PLAYING, GAMEOVER };

class Game {
  public:
    bool gameOver;
    Game();
    ~Game();
    void Draw();
    void DrawMenu();
    void DrawGameplay();
    void DrawGameover();
    void Update();
    void UpdateMenu();
    void UpdateGameplay();
    void UpdateGameover();
    void CheckCollosions();
    void RemoveDeadBullets();
    void RemoveDeadEnemies();

  private:
    UI ui;
    Camera2D camera;
    float worldWidth;
    float worldHeight;

    GameState currentState;
    void SpawnEnemy();
    Player player;
    WaveManager waveManager;
    float spwanTimer;
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    // WaveManager waveManager;
    // UpgradeSystem upgradeSystem;
    // UI ui;
};
