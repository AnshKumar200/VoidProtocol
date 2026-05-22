#pragma once

#include <raylib.h>

class XPOrb {
  public:
    XPOrb(Vector2 pos);
    //    void Update()
    void Draw();
    Rectangle GetRec();
    bool isAlive();
    void Kill();
    int GetXP();

  private:
    Vector2 position;
    int xpValue;
    bool alive;
};
