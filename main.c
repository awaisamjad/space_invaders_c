#include <raylib.h>
#include <stdio.h>
#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 540

typedef struct {
  int x_pos;
  int y_pos;
  Texture2D texture;
} BULLET;

void draw_ship(Texture2D ship) {
  int offset = 40;
  if (GetMouseX() < 0) {
    DrawTexture(ship, offset, SCREEN_HEIGHT - 50, WHITE);
  } else if (GetMouseX() > SCREEN_WIDTH - offset) {
    DrawTexture(ship, SCREEN_WIDTH - offset, SCREEN_HEIGHT - 50, WHITE);
  } else {
    DrawTexture(ship, GetMouseX(), SCREEN_HEIGHT - 50, WHITE);
  }
}

void shoot_bullet(BULLET bullet, int speed) {
  // SHould start at ship position and move forward
  // For 2 dimension movement there should be a POS struct and BULLET should use
  // that
  for (int i; i < SCREEN_HEIGHT; i++) {
    DrawTexture(bullet.texture, bullet.x_pos, bullet.y_pos + (i * speed),
                WHITE);
  }
}

//~ function that has all the code/functions that are called before the game and
// dont have returns
void Init() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Invaders");
  SetTargetFPS(60);
  HideCursor();
}

void UnloadTextures(Texture2D *textures, int length) {
  for (int i = 0; i < length; i++) {
    UnloadTexture(textures[i]);
  }
}

int main(void) {
  Init();
  Texture ship = LoadTexture("assets/ship_outline.png");
  Texture background = LoadTexture("assets/background.png");

  Texture2D textures[] = {ship, background};
  int textures_length = sizeof(textures) / sizeof(textures[0]);

  BULLET bullet = {1, 1, LoadTexture("assets/bullet.png")};
  while (!WindowShouldClose()) {
    BeginDrawing();

    // if (IsMouseButtonPressed(0)) {
    // shoot_bullet(bullet, 1);
    //}
    int speed = 5;
    for (int i; i < SCREEN_HEIGHT; i++) {
      DrawTexture(bullet.texture, bullet.x_pos, bullet.y_pos + (i * speed),
                  WHITE);
    }
    DrawTexture(background, 0, 0, WHITE);
    ClearBackground(RAYWHITE);

    draw_ship(ship);
    DrawCircle(100, 100, 30, BLUE);
    EndDrawing();
  }

  // Freeing the Textures
  UnloadTextures(textures, textures_length);
  CloseWindow();

  return 0;
}
