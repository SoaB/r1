#include "randomWalker.h"
#include "rnd.h"
#include "sgi.h"
#include "vector2.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  RndWalker_t *walker = NewRndWalker(400, 300);
  sgi_Init(800, 600, "Vector Test");
  rnd_Seed(time(NULL), 33);
  while (!sgi_Done()) {
    sgi_Clear(RGB_Black);
    walker->Update(walker);
    sgi_Disk((int)walker->Posi.x, (int)walker->Posi.y, 10, RGB_Green);
    sgi_Update();
    sgi_Delay(16);
  }
  walker->Destroy(walker);
  sgi_Fini();
  return 0;
}
