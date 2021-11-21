#ifndef HEADER_DF97652C2C1BE970
#define HEADER_DF97652C2C1BE970

#include <math.h>

#define PI 3.141592658539327

typedef struct Vec2_t {
  float x;
  float y;
} Vec2_t;
/*
-- Header define.
*/
Vec2_t Vec2_Zero(void);
Vec2_t Vec2_One(void);
Vec2_t Vec2_Add(Vec2_t v1, Vec2_t v2);
Vec2_t Vec2_AddValue(Vec2_t v, float add);
Vec2_t Vec2_Subtract(Vec2_t v1, Vec2_t v2);
Vec2_t Vec2_SubtractValue(Vec2_t v, float sub);
float Vec2_Length(Vec2_t v);
float Vec2_LengthSqr(Vec2_t v);
float Vec2_DotProduct(Vec2_t v1, Vec2_t v2);
float Vec2_Distance(Vec2_t v1, Vec2_t v2);
float Vec2_Angle(Vec2_t v1, Vec2_t v2);
Vec2_t Vec2_Scale(Vec2_t v, float scale);
Vec2_t Vec2_Multiply(Vec2_t v1, Vec2_t v2);
Vec2_t Vec2_Negate(Vec2_t v);
Vec2_t Vec2_Divide(Vec2_t v1, Vec2_t v2);
Vec2_t Vec2_Normalize(Vec2_t v);
Vec2_t Vec2_Lerp(Vec2_t v1, Vec2_t v2, float amount);
Vec2_t Vec2_Reflect(Vec2_t v, Vec2_t normal);
Vec2_t Vec2_Rotate(Vec2_t v, float angle);
Vec2_t Vec2_MoveTowards(Vec2_t v, Vec2_t target, float maxDistance);

/////////////////////////////////////
Vec2_t Vec2_Zero(void) {
  Vec2_t result = {0.0f, 0.0f};

  return result;
}

Vec2_t Vec2_One(void) {
  Vec2_t result = {1.0f, 1.0f};

  return result;
}

Vec2_t Vec2_Add(Vec2_t v1, Vec2_t v2) {
  Vec2_t result = {v1.x + v2.x, v1.y + v2.y};

  return result;
}

Vec2_t Vec2_AddValue(Vec2_t v, float add) {
  Vec2_t result = {v.x + add, v.y + add};

  return result;
}

Vec2_t Vec2_Subtract(Vec2_t v1, Vec2_t v2) {
  Vec2_t result = {v1.x - v2.x, v1.y - v2.y};

  return result;
}

Vec2_t Vec2_SubtractValue(Vec2_t v, float sub) {
  Vec2_t result = {v.x - sub, v.y - sub};

  return result;
}

float Vec2_Length(Vec2_t v) {
  float result = sqrtf((v.x * v.x) + (v.y * v.y));

  return result;
}

float Vec2_LengthSqr(Vec2_t v) {
  float result = (v.x * v.x) + (v.y * v.y);

  return result;
}

float Vec2_DotProduct(Vec2_t v1, Vec2_t v2) {
  float result = (v1.x * v2.x + v1.y * v2.y);

  return result;
}

float Vec2_Distance(Vec2_t v1, Vec2_t v2) {
  float result =
      sqrtf((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));

  return result;
}

float Vec2_Angle(Vec2_t v1, Vec2_t v2) {
  float result = atan2f(v2.y - v1.y, v2.x - v1.x) * (180.0f / PI);

  if (result < 0)
    result += 360.0f;

  return result;
}

Vec2_t Vec2_Scale(Vec2_t v, float scale) {
  Vec2_t result = {v.x * scale, v.y * scale};

  return result;
}

Vec2_t Vec2_Multiply(Vec2_t v1, Vec2_t v2) {
  Vec2_t result = {v1.x * v2.x, v1.y * v2.y};

  return result;
}

Vec2_t Vec2_Negate(Vec2_t v) {
  Vec2_t result = {-v.x, -v.y};

  return result;
}

Vec2_t Vec2_Divide(Vec2_t v1, Vec2_t v2) {
  Vec2_t result = {v1.x / v2.x, v1.y / v2.y};

  return result;
}

Vec2_t Vec2_Normalize(Vec2_t v) {
  Vec2_t result = {0};
  float length = sqrtf((v.x * v.x) + (v.y * v.y));

  if (length > 0) {
    result.x = v.x * 1.0f / length;
    result.y = v.y * 1.0f / length;
  }

  return result;
}

Vec2_t Vec2_Lerp(Vec2_t v1, Vec2_t v2, float amount) {
  Vec2_t result = {0};

  result.x = v1.x + amount * (v2.x - v1.x);
  result.y = v1.y + amount * (v2.y - v1.y);

  return result;
}

Vec2_t Vec2_Reflect(Vec2_t v, Vec2_t normal) {
  Vec2_t result = {0};

  float dotProduct = (v.x * normal.x + v.y * normal.y); // Dot product

  result.x = v.x - (2.0f * normal.x) * dotProduct;
  result.y = v.y - (2.0f * normal.y) * dotProduct;

  return result;
}

Vec2_t Vec2_Rotate(Vec2_t v, float angle) {
  Vec2_t result = {0};

  result.x = v.x * cosf(angle) - v.y * sinf(angle);
  result.y = v.x * sinf(angle) + v.y * cosf(angle);

  return result;
}

Vec2_t Vec2_MoveTowards(Vec2_t v, Vec2_t target, float maxDistance) {
  Vec2_t result = {0};

  float dx = target.x - v.x;
  float dy = target.y - v.y;
  float value = (dx * dx) + (dy * dy);

  if ((value == 0) ||
      ((maxDistance >= 0) && (value <= maxDistance * maxDistance)))
    return target;

  float dist = sqrtf(value);

  result.x = v.x + dx / dist * maxDistance;
  result.y = v.y + dy / dist * maxDistance;

  return result;
}

#endif // header guard
