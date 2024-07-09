#include <raylib.h>
#include <stdio.h>
#include "bullet.h"
#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 540
#define MAX_BULLETS 10

void draw_ship(Texture2D ship)
{
  int offset = 40;

  if (GetMouseX() < 0)
  {
    DrawTexture(ship, offset, SCREEN_HEIGHT - 50, WHITE);
  }
  else if (GetMouseX() > SCREEN_WIDTH - offset)
  {
    DrawTexture(ship, SCREEN_WIDTH - offset, SCREEN_HEIGHT - 50, WHITE);
  }
  else
  {
    DrawTexture(ship, GetMouseX(), SCREEN_HEIGHT - 50, WHITE);
  }
}

void Init()
{
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Invaders");
  SetTargetFPS(60);
  HideCursor();
}

void UnloadTextures(Texture2D *textures, int length)
{
  for (int i = 0; i < length; i++)
  {
    UnloadTexture(textures[i]);
  }
}

int main(void)
{
  Init();

  //~ Loading Textures
  Texture2D ship = LoadTexture("assets/ship_outline.png");
  Texture2D background = LoadTexture("assets/background.png");
  Texture2D bullet_texture = LoadTexture("assets/ship.png");
  BULLET bullet = {SCREEN_WIDTH / 2, SCREEN_HEIGHT - 60, bullet_texture};
  Texture2D textures[] = {ship, background, bullet_texture};
  int textures_length = sizeof(textures) / sizeof(textures[0]);

  BULLET bullets[MAX_BULLETS];
  int bullets_shot = 0;
  int bullet_speed = 1.01;

  //~ Main Loop
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw initial stuff
    DrawTexture(background, 0, 0, WHITE);
    draw_ship(ship);
    DrawFPS(10, 10);
    DrawText("Press the left mouse button to shoot", 10, 30, 20, BLACK);

    char bullet_count_text[10];
    if (MAX_BULLETS - bullets_shot == 0)
    {
      DrawText("No Bullets Left", 10, 50, 20, BLACK);
    }
    else
    {

      sprintf(bullet_count_text, "%d", MAX_BULLETS - bullets_shot);
      DrawText(bullet_count_text, 10, 50, 20, BLACK);
    }

    // Draw and update bullets
    if (IsMouseButtonPressed(0) && bullets_shot < MAX_BULLETS)
    {
      bullets[bullets_shot] = (BULLET){GetMouseX(), SCREEN_HEIGHT - 60, bullet_texture};
      bullets_shot++;
    }

    for (int i = 0; i < bullets_shot; i++)
    {
      shoot_bullet(&bullets[i], bullet_speed);
    }

    EndDrawing();
  }

  // Freeing the Textures
  UnloadTextures(textures, textures_length);
  CloseWindow();

  return 0;
}
