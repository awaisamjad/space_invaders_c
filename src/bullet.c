#include "bullet.h"

void create_bullet(BULLET *bullet, int speed)
{
  bullet->y_pos -= speed;

  // TODO When the bullet goes off the screen, it should be destroyed
  //  if (bullet->y_pos < 0) {
  //    bullet->y_pos = SCREEN_HEIGHT;
  //  }
  DrawTexture(bullet->texture, bullet->x_pos, bullet->y_pos, WHITE);
}

void shoot_bullet(BULLET *bullet, int speed)
{
  for (int i = 0; i < 10; i++)
  {
    create_bullet(bullet, speed);
  }
}
