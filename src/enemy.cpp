#include "../include/enemy.h"
#include <cmath>
#include <raylib.h>

Enemy::Enemy() {
    position = {0, 0};
    speed = 1.0f;
    hp = 100;
    damage = 0;
    alive = true;
    isBoss = false;
}

void Enemy::Draw() {
    DrawText(TextFormat("%i", hp), position.x - 2, position.y - 10, 10, BLACK);
    if (isBoss) {
        DrawRectangleV(position, {40, 40}, BLUE);
    } else {
        DrawRectangleV(position, {10, 20}, RED);
    }
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
float Enemy::GetDamage() { return damage; }

Rectangle Enemy::GetRect() { return {position.x, position.y, 10, 20}; }

void Enemy::TakeDamage(float damage) {
    hp -= floor(damage);
    if (hp <= 0) {
        hp = 0;
        alive = false;
    }
}

void Enemy::MakeBoss() {
    isBoss = true;
    hp = 500;
    speed = 1.0f;
    damage = 5;
}
