#pragma once

#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include "ui.h"
#include "wavemanager.h"
#include "xporb.h"
#include <nlohmann/json.hpp>
#include <raylib.h>
#include <vector>

// TODO - UpgradeSystem upgradeSystem;

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
    void RemoveDeadXP();

  private:
    UI ui;
    Camera2D camera;

    GameState currentState;
    void SpawnEnemy();
    Player player;
    WaveManager waveManager;
    float spwanTimer;
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    std::vector<XPOrb> xporbs;

    nlohmann::json mapData;
    int worldWidth;
    int worldHeight;
    int mapWidth;
    int mapHeight;
    int tileWidth;
    int tileHeight;
    std::vector<int> tiles;
    Texture2D tile;
};
