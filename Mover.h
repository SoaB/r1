#ifndef __MOVER_H__
#define __MOVER_H__

#include "rnd.h"
#include "v2d.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Mover {
  Vec2D location;
  Vec2D velocity;
  Vec2D acceleration;
  float topSpeed;
  void (*Update)(struct Mover *self, Vec2D *pt);
  void (*Destroy)(struct Mover *self);
} Mover;

static void _update(Mover *mv, Vec2D *pt) {
  Vec2D dir = V2D_Subtract(*pt, mv->location);
  dir = V2D_Normalize(dir);
  dir = V2D_Scale(dir, 0.5);
  mv->acceleration.x = dir.x;
  mv->acceleration.y = dir.y;
  mv->velocity = V2D_Add(mv->velocity, mv->acceleration);
  mv->velocity = V2D_Limit(mv->velocity, mv->topSpeed);
  mv->location = V2D_Add(mv->location, mv->velocity);
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
    mv->location = (Vec2D){(float)rnd_R32n(0, w), (float)rnd_R32n(0, h)};
    mv->velocity = (Vec2D){0, 0};
    mv->acceleration = (Vec2D){0, 0};
    mv->topSpeed = 4;
    mv->Update = &_update;
    mv->Destroy = &_destroy;
  }
  return mv;
}

#endif // header guard
