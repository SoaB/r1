#ifndef HEADER_ECDD855FAF0523A5
#define HEADER_ECDD855FAF0523A5

#include "rnd.h"
#include "simplexNoise.h"
#include "vector2.h"
#include <stdlib.h>


typedef struct RndWalker_t {
  Vec2_t Posi;
  void (*Update)(struct RndWalker_t *self);
  void (*Destroy)(struct RndWalker_t *self);
} RndWalker_t;

static float scaleVal(float n, float min, float max, float range) {
  float scale = range / (max - min);
  float offset = min * scale;
  return (n * scale - offset);
}

static void rw_update(RndWalker_t *walker) {
  static float tx = 0;
  static float ty = 1000;
  walker->Posi.x = scaleVal(snoise1(tx), -1, 1, 800);
  walker->Posi.y = scaleVal(snoise1(ty), -1, 1, 600);
  tx += 0.01;
  ty += 0.02;
}
static void rw_destroy(RndWalker_t *self) {
  if (self != NULL) {
    free(self);
    self = NULL;
  }
}
RndWalker_t *NewRndWalker(float x, float y) {
  RndWalker_t *rw = malloc(sizeof(rw));
  if (rw != NULL) {
    rw->Update = &rw_update;
    rw->Destroy = &rw_destroy;
    rw->Posi.x = x;
    rw->Posi.y = y;
  }
  return rw;
}

#endif // header guard
