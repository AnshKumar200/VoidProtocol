#include "../include/enemy.h"
#include <cmath>
#include <raylib.h>

Enemy::Enemy() {
    position = {0, 0};
    speed = 1;
    hp = 100;
    damage = 0;
    alive = true;
}

void Enemy::Draw() {
    DrawText(TextFormat("%i", hp), position.x - 2, position.y - 10, 10, BLACK);
    DrawRectangleV(position, {10, 20}, RED);
}

void Enemy::Update(Vector2 playerPos) {
    Vector2 playerCenter = {playerPos.x + 30.0f / 2, playerPos.y + 30.0f / 2};
    float dx = playerCenter.x - position.x;
    float dy = playerCenter.y - position.y;
    float length = sqrtf((dx * dx) + (dy * dy));

    if (length < 0.01f) {
        return;
    }
    position.x += (dx / length) * speed;
    position.y += (dy / length) * speed;
}

bool Enemy::IsAlive() { return alive; }

Rectangle Enemy::GetRect() { return {position.x, position.y, 10, 20}; }

void Enemy::TakeDamage(float damage) {
    hp -= floor(damage);
    if (hp <= 0) {
        hp = 0;
        alive = false;
    }
}
