#include "../include/game.h"
#include <algorithm>
#include <fstream>
#include <nlohmann/json.hpp>
#include <raylib.h>

Game::Game() {
    currentState = GameState::MENU;
    gameOver = false;

    camera.target = player.GetCenter();
    camera.offset = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.5f;

    //    std::ifstream file("assets/map.json");
    //    file >> mapData;

    //    mapWidth = mapData["width"];
    //    mapHeight = mapData["height"];

    //    tileWidth = mapData["tilewidth"];
    //    tileHeight = mapData["tileheight"];

    //    tiles = mapData["layers"][0]["data"].get<std::vector<int>>();

    //    tile = LoadTexture("assets/tile.png");
}

Game::~Game() {}

void Game::Draw() {
    switch (currentState) {
    case GameState::MENU:
        DrawMenu();
        break;
    case GameState::PLAYING:
        DrawGameplay();
        break;
    case GameState::GAMEOVER:
        DrawGameover();
        break;
    }
}

void Game::DrawMenu() {
    DrawRectangle(300, 300, 200, 200, GRAY);
    DrawText("Start", 400, 400, 10, BLACK);
}

void Game::DrawGameplay() {
    BeginMode2D(camera);

    //   for (int y = 0; y < mapHeight; y++) {
    //        for (int x = 0; x < mapWidth; x++) {

    //            int tileID = tiles[y * mapWidth + x];

    //            if (tileID != 0) {
    //                DrawTexture(tile, x * tileWidth, y * tileHeight, WHITE);
    //            }
    //        }
    //    }

    player.Draw();

    for (Bullet &bullet : bullets) {
        bullet.Draw();
    }

    for (Enemy &enemy : enemies) {
        enemy.Draw();
    }

    EndMode2D();
}

void Game::DrawGameover() {}

void Game::Update() {
    switch (currentState) {
    case GameState::MENU:
        UpdateMenu();
        break;
    case GameState::PLAYING:
        UpdateGameplay();
        break;
    case GameState::GAMEOVER:
        UpdateGameover();
        break;
    }
}

void Game::UpdateMenu() {
    Vector2 mousePos = GetMousePosition();
    bool isHovering = CheckCollisionPointRec(mousePos, {300, 300, 200, 200});

    if (isHovering) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            currentState = GameState::PLAYING;
    }
}

void Game::UpdateGameplay() {
    //    const float dt = GetFrameTime();
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 playerPos = player.GetCenter();
        Vector2 mousePos = GetScreenToWorld2D(GetMousePosition(), camera);
        bullets.push_back(Bullet(playerPos, mousePos));
    }
    player.Update();
    Vector2 target = player.GetCenter();
    camera.target.x += (target.x - camera.target.x) * 0.1f;
    camera.target.y += (target.y - camera.target.y) * 0.1f;

    camera.target.x = roundf(camera.target.x);
    camera.target.y = roundf(camera.target.y);

    SpawnEnemy();
    for (Bullet &bullet : bullets) {
        bullet.Update();
    }
    for (Enemy &enemy : enemies) {
        enemy.Update(player.GetPosition());
    }
    CheckCollosions();
    RemoveDeadBullets();
    RemoveDeadEnemies();
}

void Game::UpdateGameover() {}

void Game::SpawnEnemy() {
    spwanTimer += GetFrameTime();
    if (spwanTimer > 2) {
        enemies.push_back(Enemy());
        spwanTimer = 0;
    }
};

void Game::CheckCollosions() {
    for (Bullet &bullet : bullets) {
        for (Enemy &enemy : enemies) {
            if (CheckCollisionRecs(bullet.GetRect(), enemy.GetRect())) {
                if (enemy.IsAlive()) {
                    enemy.TakeDamage(20);
                    bullet.Kill();
                    break;
                }
            }
        }
    }

    for (Enemy &enemy : enemies) {
        if (CheckCollisionRecs(enemy.GetRect(), player.GetRect())) {
            player.TakeDamage(1);
        }
    }
}

void Game::RemoveDeadEnemies() {
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
                                 [](Enemy &enemy) { return !enemy.IsAlive(); }),
                  enemies.end());
}

void Game::RemoveDeadBullets() {
    bullets.erase(
        std::remove_if(bullets.begin(), bullets.end(),
                       [](Bullet &bullet) { return !bullet.IsAlive(); }),
        bullets.end());
}
