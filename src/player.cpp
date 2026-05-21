#include "../include/player.h"
#include <algorithm>
#include <raylib.h>

Player::Player() {
    position = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    speed = 2.0f;
    hp = 100;
    maxHp = 100;
    alive = true;

    player = LoadTexture("assets/player.png");
    frameWidth = 64;
    frameHeight = 64;
    currentFrame = 0;
    frameCounter = 0;
    frameSpeed = 5;

    frameRect = {0.0f, 0.0f, 64.0f, 64.0f};
}

Player::~Player() { UnloadTexture(player); }

void Player::Update() {
    frameCounter++;
    if (frameCounter >= (60 / frameSpeed)) {
        frameCounter = 0;
        currentFrame++;

        if (currentFrame > 1)
            currentFrame = 0;
        frameRect.x = currentFrame * frameWidth;
    }

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
    DrawTextureRec(player, frameRect, position, WHITE);
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

Vector2 Player::GetCenter() {
    return {position.x + frameWidth / 2.0f, position.y + frameHeight / 2.0f};
}

void Player::ClampToWorld(float width, float height) {
    position.x = std::clamp(position.x, 0.0f, width - frameWidth);
    position.y = std::clamp(position.y, 0.0f, height - frameHeight);
}

int Player::GetHp() { return hp; }
int Player::GetMaxHp() { return maxHp; }
