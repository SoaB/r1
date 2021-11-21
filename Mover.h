#ifndef __MOVER_H__
#define __MOVER_H__

#include "rnd.h"
#include "vector2.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Mover {
  Vec2_t location;
  Vec2_t velocity;
  Vec2_t acceleration;
  float topSpeed;
  void (*Update)(struct Mover *self, Vec2_t *pt);
  void (*Destroy)(struct Mover *self);
} Mover;

static void _update(Mover *mv, Vec2_t *pt) {
  Vec2_t dir = Vec2_Subtract(*pt, mv->location);
  dir = Vec2_Normalize(dir);
  dir = Vec2_Scale(dir, 0.5);
  mv->acceleration.x = dir.x;
  mv->acceleration.y = dir.y;
  mv->velocity = Vec2_Add(mv->velocity, mv->acceleration);
  mv->velocity = Vec2_Limit(mv->velocity, mv->topSpeed);
  mv->location = Vec2_Add(mv->location, mv->velocity);
}
static void _destroy(Mover *self) {
  if (self != NULL) {
    free(self);
    self = NULL;
  }
}
Mover *NewMover(int w, int h) {
  Mover *mv = (Mover *)malloc(sizeof(Mover));
  if (mv != NULL) {
    mv->location = (Vec2_t){(float)rnd_R32n(0, w), (float)rnd_R32n(0, h)};
    mv->velocity = (Vec2_t){0, 0};
    mv->acceleration = (Vec2_t){0, 0};
    mv->topSpeed = 4;
    mv->Update = &_update;
    mv->Destroy = &_destroy;
  }
  return mv;
}

#endif // header guard
