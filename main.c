#include "Mover.h"
#include "rnd.h"
#include "sgi.h"
#include "v2d.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  rnd_Seed(time(NULL), 33);
  Mover *mover = NewMover(800, 600);
  sgi_Init(800, 600, "Mover Test");
  Vec2D pt = {400, 300};
  int x, y;
  while (!sgi_Done()) {
    sgi_Clear(RGB_Black);
    sgi_GetMouseState(&x, &y);
    pt = (Vec2D){(float)x, (float)y};
    mover->Update(mover, &pt);
    sgi_Disk((int)mover->location.x, (int)mover->location.y, 10, RGB_Green);
    sgi_Update();
    sgi_Delay(16);
  }
  mover->Destroy(mover);
  sgi_Fini();
  return 0;
}
