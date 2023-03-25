#include "raylib.h"
#include "box2d/box2d.h"
#include "game.h"
#include "player.h"
#include "activeTextAndObjects.h"
#include "aminoAcids.h"
#include <iostream>

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
    Camera2D playerCam = { {screenWidth / 2, screenHeight / 2}, player->getPosition(), 0, 1 };

    // Intialize camera variables
    Texture2D background = LoadTexture("./../assets/UI/background.png");
    Rectangle boundaries[4] = {
        {-50, 0, 50, 2160},
        {3840, 0, 50, 2160},
        {0, -50, 3840, 50},
        {0, 2160, 3840, 50}
    };

    // Intialize inventory variables
    Texture2D inventory = LoadTexture("./../assets/UI/inventory.png");
    Color elementaColors[6] = { carbonColor, hydrogenColor, nitrogenColor, oxygenColor, sulfurColor, seleniumColor };
    short int itemQuantity[6] = { 0, 0, 0, 0, 0, 0 };

    // Initialize amino-acid variables
    AminoAcid* aminoAcids = new AminoAcid[21];
    aminoAcids = aminoAcids->initAminoAcids();

    // Intialize amino-acid repository variables
    Texture2D base = LoadTexture("./../assets/UI/Amino-acid repository/base.png");
    Texture2D cover = LoadTexture("./../assets/UI/Amino-acid repository/base cover.png");
    Texture2D data = LoadTexture("./../assets/UI/Amino-acid repository/data.png");
    float dataY = 168, scrollSpeed = 20;

    while (!WindowShouldClose())
    {
        // Move the player
        player->move(player->getPosition());

        // Check and handle collision with the map boundary
        player->checkMapBoundary(boundaries);

        // Update camera position
        playerCam.target = player->getPosition();

        // Scoll the amino-acid repository up and down
        dataY += (GetMouseWheelMove() * scrollSpeed);

        // Scoll boundaries
        if (dataY >= 168)
        {
            dataY = 168;
        }
        if (dataY <= -1952)
        {
            dataY = -1952;
        }

        BeginDrawing();

        // Clear framebuffer
        ClearBackground(BLANK);

        BeginMode2D(playerCam);

        // Draw background base
        DrawRectangle(0, 0, 3840, 2160, WHITE);

        // Draw texture underglow
        DrawTexture(player->getUnderglowTexture(), int(player->getPosition().x - 400), int(player->getPosition().y - 400), RAYWHITE);

        // Draw background
        DrawTexture(background, 0, 0, RAYWHITE);

        // Draw the player
        DrawTexturePro(
        player->getPlayerTexture(),
        Rectangle{0, 0, float(player->getPlayerTexture().width), float(player->getPlayerTexture().height)},
        Rectangle{player->getPosition().x, player->getPosition().y, float(player->getPlayerTexture().width), float(player->getPlayerTexture().height)},
        Vector2{float(player->getPlayerTexture().width / 2), float(player->getPlayerTexture().height / 2)}, 0, RAYWHITE);

        EndMode2D();

        // Draw amino-acid repository base
        DrawTexture(base, -23, -7, RAYWHITE);

        // Draw amino-acid repository data
        DrawTexture(data, 13, int(dataY), RAYWHITE);

        // Draw amino-acid repository cover
        DrawTexture(cover, 13, 0, RAYWHITE);

        // Draw inventory base
        DrawRectangle(1821, 0, 99, 1080, inventoryBase);

        // Draw inventory items
        DrawInventoryItems(comfortaaRegular, itemQuantity, elementaColors);

        // Draw inventory cover
        DrawTexture(inventory, 1752, 0, RAYWHITE);

        EndDrawing();
    }
    CloseWindow();

    // Free up alocated memory
    delete [] aminoAcids;
}