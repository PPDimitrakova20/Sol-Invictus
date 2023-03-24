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

    Camera2D playerCam = { {screenWidth/2, screenHeight/2}, player->getPosition(), 0, 2};
    Texture2D a = LoadTexture("./../assets/player/player.png");

    while (!WindowShouldClose())
    {
        // Move the player
        player->Move(player->getPosition());

        // Update camera position
        playerCam.target = player->getPosition();

        // Draw
        BeginDrawing();

        ClearBackground(BLANK);

        BeginMode2D(playerCam);

        DrawTexture(a, 200, 200, RAYWHITE);

        // Draw the player
        DrawTexturePro(
        player->getTexture(), 
        Rectangle{0, 0, float(player->getTexture().width), float(player->getTexture().height)},
        
        Rectangle{player->getPosition().x, player->getPosition().y, float(player->getTexture().width), float(player->getTexture().height)},
        
        Vector2{float(player->getTexture().width / 2), float(player->getTexture().height / 2)}, 0, RAYWHITE);

        EndMode2D();
        EndDrawing();
    }
    CloseWindow();
}