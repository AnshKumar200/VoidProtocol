#include "../include/game.h"
#include <algorithm>
#include <raylib.h>

Game::Game() { gameOver = false; }

void Game::Draw() {
    player.Draw();
    for (Bullet &bullet : bullets) {
        bullet.Draw();
    }
    for (Enemy &enemy : enemies) {
        enemy.Draw();
    }
}

void Game::Update() {
    //    const float dt = GetFrameTime();
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 playerPos = player.GetPosition();
        Vector2 mousePos = GetMousePosition();
        bullets.push_back(Bullet(playerPos, mousePos));
    }
    player.Update();
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
