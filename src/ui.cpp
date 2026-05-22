
#include "../include/ui.h"
#include <raylib.h>

UI::UI() {}

void UI::DrawPlayerStats(int hp, int maxHp, int XP) {
    DrawText("Void Protocol", 10, 10, 20, BLACK);
    DrawText(TextFormat("HP: %i / %i", hp, maxHp), 10, 30, 20, RED);
    DrawText(TextFormat("XP: %i", XP), 10, 50, 20, RED);
}

void UI::DrawWaveCounter(int currentWave, int enemiesRemaining) {
    DrawText(TextFormat("Wave: %i", currentWave), 250, 30, 20, RED);
    DrawText(TextFormat("Enemies Remaining: %i", enemiesRemaining), 250, 50, 20,
             RED);
}
