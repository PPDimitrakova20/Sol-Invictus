#include "raylib.h"
#include "box2d/box2d.h"

int main()
{
    b2World phsWorld = b2World(b2Vec2(0, -9.8));

    
    InitWindow(800, 450, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}