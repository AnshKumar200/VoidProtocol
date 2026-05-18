#include "../include/game.h"
#include <raylib.h>

Game::Game() { gameOver = false; }

void Game::Draw() {
    player.Draw();
    for (Bullet &bullet : bullets) {
        bullet.Draw();
    }
}

void Game::Update() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 playerPos = player.GetPosition();
        Vector2 mousePos = GetMousePosition();
        bullets.push_back(Bullet(playerPos, mousePos));
    }
    player.Update();
    for (Bullet &bullet : bullets) {
        bullet.Update();
    }
}
