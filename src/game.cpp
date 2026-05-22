#include "../include/game.h"
#include <algorithm>
#include <nlohmann/json.hpp>
#include <raylib.h>

Game::Game() {
    currentState = GameState::MENU;
    gameOver = false;

    camera.target = player.GetCenter();
    camera.offset = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    worldWidth = 900;
    worldHeight = 900;
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

    DrawRectangleLines(0, 0, worldWidth, worldHeight, BLACK);

    player.Draw();

    for (XPOrb &xporb : xporbs) {
        xporb.Draw();
    }
    for (Bullet &bullet : bullets) {
        bullet.Draw();
    }
    for (Enemy &enemy : enemies) {
        enemy.Draw();
    }

    EndMode2D();

    ui.DrawPlayerStats(player.GetHp(), player.GetMaxHp(), player.GetXP());
    ui.DrawWaveCounter(waveManager.GetCurrentWave(), enemies.size());
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
    player.ClampToWorld(worldWidth, worldHeight);
    Vector2 target = player.GetCenter();
    camera.target.x += (target.x - camera.target.x) * 0.1f;
    camera.target.y += (target.y - camera.target.y) * 0.1f;

    camera.target.x = roundf(camera.target.x);
    camera.target.y = roundf(camera.target.y);

    waveManager.Update(enemies);

    for (Bullet &bullet : bullets) {
        bullet.Update();
    }
    for (Enemy &enemy : enemies) {
        enemy.Update(player.GetCenter());
    }

    CheckCollosions();
    RemoveDeadBullets();
    RemoveDeadEnemies();
    RemoveDeadXP();
}

void Game::UpdateGameover() {}

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
            player.TakeDamage(enemy.GetDamage());
        }
    }

    for (XPOrb &xporb : xporbs) {
        if (CheckCollisionRecs(player.GetRect(), xporb.GetRec())) {
            player.AddXP(xporb.GetXP());
            xporb.Kill();
        }
    }
}

void Game::RemoveDeadEnemies() {
    for (Enemy &enemy : enemies) {
        if (!enemy.IsAlive()) {
            xporbs.push_back(XPOrb({enemy.GetRect().x, enemy.GetRect().y}));
        }
    }

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

void Game::RemoveDeadXP() {
    xporbs.erase(std::remove_if(xporbs.begin(), xporbs.end(),
                                [](XPOrb &xporb) { return !xporb.isAlive(); }),
                 xporbs.end());
}
