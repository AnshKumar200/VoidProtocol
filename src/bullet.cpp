#include "../include/bullet.h"
#include <cmath>
#include <raylib.h>

Bullet::Bullet(Vector2 playerPos, Vector2 mousePos) {
    float dx = mousePos.x - playerPos.x;
    float dy = mousePos.y - playerPos.y;
    float length = sqrtf((dx * dx) + (dy * dy));

    if (length < 0.01f) {
        alive = false;
        return;
    }
    direction.x = dx / length;
    direction.y = dy / length;
    position = playerPos;
    speed = 10;
    alive = true;
}

void Bullet::Update() {
    position.x += direction.x * speed;
    position.y += direction.y * speed;
}

void Bullet::Draw() { DrawRectangleV(position, {10, 10}, BLACK); }

bool Bullet::IsAlive() { return alive; }

Rectangle Bullet::GetRect() { return {position.x, position.y, 10, 10}; }

void Bullet::Kill() { alive = false; }
