#include "../include/player.h"
#include <raylib.h>

Player::Player() {
    position = {400.0f, 225.0f};
    speed = 5.0f;
    hp = 100;
    maxHp = 100;
    alive = true;
}

void Player::Update() {
    if (IsKeyDown(KEY_W))
        position.y -= speed;
    if (IsKeyDown(KEY_S))
        position.y += speed;
    if (IsKeyDown(KEY_A))
        position.x -= speed;
    if (IsKeyDown(KEY_D))
        position.x += speed;
}

void Player::Draw() {
    DrawText(TextFormat("%i / %i", hp, maxHp), position.x - 5, position.y - 10,
             10, BLACK);
    DrawRectangleV(position, {30, 30}, YELLOW);
}

Vector2 Player::GetPosition() { return position; }

bool Player::isAlive() { return alive; }

void Player::TakeDamage(int damage) {
    hp -= damage;
    if (hp <= 0) {
        hp = 0;
        alive = false;
    }
}

Rectangle Player::GetRect() { return {position.x, position.y, 30, 30}; }
