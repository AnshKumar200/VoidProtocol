#include "../include/enemy.h"
#include <cmath>
#include <raylib.h>

// TODO - enum ENEMY_TYPE - normal, boss

Enemy::Enemy() {
    position = {0, 0};
    speed = 1.0f;
    hp = 100;
    maxHp = 100;
    damage = 0;
    xp = 1;
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
    float dx = playerPos.x - position.x;
    float dy = playerPos.y - position.y;
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
    maxHp = 500;
    speed = 1.0f;
    damage = 5;
    xp = 100;
}

int Enemy::GetHp() { return hp; }
int Enemy::GetMaxHp() { return maxHp; }
bool Enemy::IsBoss() { return isBoss; }
int Enemy::GetXp() { return xp; }
