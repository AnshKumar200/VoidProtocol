#include "../include/xporb.h"
#include <raylib.h>

XPOrb::XPOrb(Vector2 pos) {
    position = pos;
    xpValue = 1;
    alive = true;
}

void XPOrb::Draw() { DrawCircle(position.x, position.y, 4, GREEN); }

Rectangle XPOrb::GetRec() { return {position.x, position.y, 8, 8}; }

bool XPOrb::isAlive() { return alive; }

void XPOrb::Kill() { alive = false; }

int XPOrb::GetXP() { return xpValue; }
