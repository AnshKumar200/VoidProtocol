
#include "../include/ui.h"
#include <raylib.h>

UI::UI() {}

void UI::DrawPlayerStats(Player &player) {
    DrawText("Void Protocol", 10, 10, 20, BLACK);
    DrawText(TextFormat("HP: %i / %i", player.GetHp(), player.GetMaxHp()), 10,
             30, 20, RED);
    DrawText(TextFormat("XP: %i", player.GetXP()), 10, 50, 20, RED);
}

void UI::DrawWaveCounter(int currentWave, int enemiesRemaining) {
    DrawText(TextFormat("Wave: %i", currentWave), 250, 30, 20, RED);
    DrawText(TextFormat("Enemies Remaining: %i", enemiesRemaining), 250, 50, 20,
             RED);
}

void UI::DrawBossBar(Enemy *boss) {
    if (boss == nullptr)
        return;
    float hpPercent = (float)boss->GetHp() / boss->GetMaxHp();

    DrawRectangle(400, 30, 400, 30, DARKGRAY);
    DrawRectangle(400, 30, 400 * hpPercent, 30, RED);
    DrawText("BOSS", 370, 5, 20, BLACK);
}
