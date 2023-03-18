#include "raylib.h"
#include "box2d/box2d.h"
#include "game.h"
#include "player.h"

void Game()
{
    //b2World phsWorld = b2World(b2Vec2(0, -9.8));

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Dev window");
    /*ToggleFullscreen();*/
    SetTargetFPS(60);

    Player* player = Player::getinstance();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        // Draw the player
        DrawTexturePro(
        player->getTexture(), 
        Rectangle{0,0,float(player->getTexture().width), float(player->getTexture().height)},
        Rectangle{player->getPosition().x, player->getPosition().y, float(player->getTexture().width), float(player->getTexture().height)},
        Vector2{float(player->getTexture().width / 2), float(player->getTexture().height / 2)},
        0,
        RAYWHITE
        );

        // Move the player
        player->Move(player->getPosition());

        EndDrawing();
    }
    CloseWindow();
    
}