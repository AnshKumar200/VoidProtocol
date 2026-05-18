#include "../include/bullet.h"
#include <cmath>
#include <raylib.h>

Bullet::Bullet(Vector2 playerPos, Vector2 mousePos) {
    Vector2 playerCenter = {playerPos.x + 30.0f / 2, playerPos.y + 30.0f / 2};
    float dx = mousePos.x - playerCenter.x;
    float dy = mousePos.y - playerCenter.y;
    float length = sqrtf((dx * dx) + (dy * dy));

    if (length < 0.01f) {
        alive = false;
        return;
    }
    direction.x = dx / length;
    direction.y = dy / length;
    position = playerCenter;
    speed = 10;
    alive = true;
}

void Bullet::Update() {
    position.x += direction.x * speed;
    position.y += direction.y * speed;
}

void Bullet::Draw() { DrawRectangleV(position, {10, 10}, BLACK); }
