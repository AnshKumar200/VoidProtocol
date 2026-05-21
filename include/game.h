#pragma once

#include "bullet.h"
#include "enemy.h"
#include "player.h"
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
    Camera2D camera;

    nlohmann::json mapData;
    int mapWidth;
    int mapHeight;
    int tileWidth;
    int tileHeight;
    std::vector<int> tiles;
    Texture2D tile;

    GameState currentState;
    void SpawnEnemy();
    Player player;
    float spwanTimer;
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    // WaveManager waveManager;
    // UpgradeSystem upgradeSystem;
    // UI ui;
};
