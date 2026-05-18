#include "../include/player.h"
#include <raylib.h>

Player::Player() {
    position = {400.0f, 225.0f};
    speed = 5.0f;
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

void Player::Draw() { DrawRectangleV(position, {30, 30}, YELLOW); }

Vector2 Player::GetPosition() { return position; }
