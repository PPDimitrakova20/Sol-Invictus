#include "raylib.h"
#include "box2d/box2d.h"
#include "movement.h"
#include "player.h"

int main()
{
    //b2World phsWorld = b2World(b2Vec2(0, -9.8));

    const int screenWidth = 1920;
    const int screenHeight = 1080;
    
    InitWindow(screenWidth, screenHeight, "Dev window");
    ToggleFullscreen();
    SetTargetFPS(60);
    
    int playerPoxX = screenWidth / 2;
    int playerPoxy = screenHeight / 2;
    Player player;
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(player.texture, playerPoxX - 93, playerPoxy - 93, RAYWHITE);
        checkForMovement(playerPoxX, playerPoxy);
        EndDrawing();
    }
    CloseWindow();
}