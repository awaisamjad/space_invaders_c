#ifndef BULLET_H
#define BULLET_H

#include <raylib.h>

typedef struct
{
  int x_pos;
  int y_pos;
  Texture2D texture;
} BULLET;

void shoot_bullet(BULLET *bullet, int speed);
void create_bullet(BULLET *bullet, int speed);
#endif