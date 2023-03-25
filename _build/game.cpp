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
    //ToggleFullscreen();
    SetTargetFPS(60);

    Player* player = Player::getinstance();

    Camera2D playerCam = { {screenWidth/2, screenHeight/2}, player->getPosition(), 0, 1};
    Texture2D background = LoadTexture("./../assets/UI/background.png");
    Rectangle boundaries[4] = {
        {-50, 0, 50, 2160},
        {3840, 0, 50, 2160},
        {0, -50, 3840, 50},
        {0, 2160, 3840, 50}
    };

    // float recY = 100;

    while (!WindowShouldClose())
    {
        // Move the player
        player->Move(player->getPosition());

        // Check and handle collision with the map boundary
        player->CheckMapBoundary(boundaries);

        // Update camera position
        playerCam.target = player->getPosition();

        // Draw
        BeginDrawing();

        ClearBackground(BLANK);

        BeginMode2D(playerCam);

        DrawTexture(background, 0, 0, RAYWHITE);

        // Scrolls
        // recY -= GetMouseWheelMove() * 4;

        // DrawRectangle(100, recY, 100, 100, RED);

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