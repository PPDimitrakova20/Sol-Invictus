#include "raylib.h"
#include "box2d/box2d.h"
#include "game.h"
#include "player.h"
#include "activeTextAndObjects.h"

void Game()
{
    //b2World phsWorld = b2World(b2Vec2(0, -9.8));

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Dev window");
    //ToggleFullscreen();
    SetTargetFPS(60);

    // Load font variants from the file structure
    Font comfortaaRegular = LoadFontEx("../assets/fonts/Comfortaa-Regular.ttf", 30, 0, 250);
    Font comfortaaBold = LoadFontEx("../assets/fonts/Comfortaa-Bold.ttf", 25, 0, 250);

    // Intialize player variables
    Player* player = Player::getinstance();
    Camera2D playerCam = { {screenWidth/2, screenHeight/2}, player->getPosition(), 0, 1};

    // Intialize camera variables
    Texture2D background = LoadTexture("./../assets/UI/background.png");
    Rectangle boundaries[4] = {
        {-50, 0, 50, 2160},
        {3840, 0, 50, 2160},
        {0, -50, 3840, 50},
        {0, 2160, 3840, 50}
    };

    //Intialize inventory variables
    Texture2D inventory = LoadTexture("./../assets/UI/inventory.png");
    Color elementaColors[6] = { carbonColor, hydrogenColor, nitrogenColor, oxygenColor, sulfurColor, seleniumColor };
    short int itemQuantity[6] = { 0, 0, 0, 0, 0, 0 };

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

        // Draw background base
        DrawRectangle(0, 0, 3840, 2160, WHITE);

        // Draw texture underglow
        DrawTexture(player->getUnderglowTexture(), player->getPosition().x - 400, player->getPosition().y - 400, RAYWHITE);

        // Draw background
        DrawTexture(background, 0, 0, RAYWHITE);

        // Draw the player
        DrawTexturePro(
        player->getPlayerTexture(),
        Rectangle{0, 0, float(player->getPlayerTexture().width), float(player->getPlayerTexture().height)},
        Rectangle{player->getPosition().x, player->getPosition().y, float(player->getPlayerTexture().width), float(player->getPlayerTexture().height)},
        Vector2{float(player->getPlayerTexture().width / 2), float(player->getPlayerTexture().height / 2)}, 0, RAYWHITE);

        EndMode2D();

        // Draw inventory base
        DrawRectangle(1821, 0, 99, 1080, inventoryBase);

        // Draw inventory items
        DrawInventoryItems(comfortaaRegular, itemQuantity, elementaColors);

        // Draw inventory cover
        DrawTexture(inventory, 1752, 0, RAYWHITE);

        EndDrawing();
    }
    CloseWindow();
}