#include <raylib.h>
#include <stdio.h>
#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 540


void drawShip(Texture2D ship) {
  int offset = 40;
  if (GetMouseX() < 0) {
    DrawTexture(ship, offset, SCREEN_HEIGHT - 50, WHITE);
  } 
  else if (GetMouseX() > SCREEN_WIDTH - offset) {
    DrawTexture(ship, SCREEN_WIDTH - offset, SCREEN_HEIGHT - 50, WHITE);
  } 
  else {
    DrawTexture(ship, GetMouseX(), SCREEN_HEIGHT - 50, WHITE);
  }
}

//~ function that has all the code/functions that are called before the game and dont have returns
void Init() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Invaders");
  SetTargetFPS(60);
  HideCursor();
}

void UnloadTextures(Texture2D* textures, int length) {
  for (int i = 0; i < length; i++) {
    UnloadTexture(textures[i]);
  }
}

int main(void) {
  Init();
  Texture ship = LoadTexture("assets/ship_outline.png");
  Texture background = LoadTexture("assets/background.png");

  Texture2D textures[] = {
    ship,
    background
  };
  int textures_length = sizeof(textures)/sizeof(textures[0]);

  while (!WindowShouldClose()) {
    BeginDrawing();

    if (IsMouseButtonPressed(0)){
      printf("Mouse Button is being Pressed!!!!!!!!!!!!!!!!!!!");
    }
    DrawTexture(background, 0, 0, WHITE);
    ClearBackground(RAYWHITE);

    drawShip(ship);
    DrawCircle(100, 100, 30, BLUE);
    EndDrawing();
  }
  
  // Freeing the Textures
  UnloadTextures(textures,textures_length );  
  CloseWindow();

  return 0;
}
