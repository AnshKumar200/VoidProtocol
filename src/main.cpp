#include "../include/game.h"
#include <raylib.h>

int main(void) {
    InitWindow(800, 800, "Void Protocol");
    SetTargetFPS(60);

    Game game = Game();

    while (!WindowShouldClose()) {
        game.Update();

        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("VOID PROTOCOL", 10, 10, 20, BLACK);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
