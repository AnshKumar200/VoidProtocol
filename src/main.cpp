#include "raylib.h"
#include <cmath>

int main(void) {
    InitWindow(1000, 1000, "Void Protocol");

    Vector2 playerPos = {400.0f, 225.0f};
    Vector2 aimPos = {};

    const float playerSize = 30.0f;
    const float aimDistance = 40.0f;
    const float aimSize = 20.0f;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        aimPos = GetMousePosition();

        Vector2 playerCenter = {
            playerPos.x + playerSize / 2,
            playerPos.y + playerSize / 2,
        };

        Vector2 mousePos = GetMousePosition();
        float dx = mousePos.x - playerCenter.x;
        float dy = mousePos.y - playerCenter.y;
        float angle = atan2f(dy, dx);
        aimPos.x = playerCenter.x + cosf(angle) * aimDistance - aimSize / 2;
        aimPos.y = playerCenter.y + sinf(angle) * aimDistance - aimSize / 2;

        // UPDATE
        if (IsKeyDown(KEY_D))
            playerPos.x += 2.0f;
        if (IsKeyDown(KEY_A))
            playerPos.x -= 2.0f;
        if (IsKeyDown(KEY_W))
            playerPos.y -= 2.0f;
        if (IsKeyDown(KEY_S))
            playerPos.y += 2.0f;

        // DRAW
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("VOID PROTOCOL", 10, 10, 20, BLACK);
        DrawRectangleV(playerPos, {playerSize, playerSize}, YELLOW);
        DrawRectangleV(aimPos, {aimSize, aimSize}, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
