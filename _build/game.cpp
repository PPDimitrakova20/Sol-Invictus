#include "game.h"

void Game()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Dev window");
    //ToggleFullscreen();
    SetTargetFPS(60);

    // Load font variants from the file structure
    Font comfortaaRegular = LoadFontEx("../assets/fonts/Comfortaa-Regular.ttf", 30, 0, 250);
    Font comfortaaBold = LoadFontEx("../assets/fonts/Comfortaa-Bold.ttf", 40, 0, 250);

    ProgrammeLayer currentLayer = LOGIC;

    // Intialize player variables
    Player* player = Player::getinstance();
    Camera2D playerCam = { {screenWidth / 2, screenHeight / 2}, player->getPosition(), 0, 1 };

    // Intialize camera variables
    Texture2D background = LoadTexture("./../assets/UI/background.png");
    Rectangle boundaries[4] = {
        {-50, 0, 50, 3320},
        {5880, 0, 50, 3320},
        {0, -50, 5880, 50},
        {0, 3320, 5880, 50}
    };

    // Intialize inventory variables
    Texture2D inventory = LoadTexture("./../assets/UI/craftingBench/inventory.png");
    Color elementaColors[6] = { carbonColor, hydrogenColor, nitrogenColor, oxygenColor, sulfurColor, seleniumColor };
    short int * itemQuantity = new short int[6]();

    // Initialize amino-acid variables
    AminoAcid* aminoAcids = nullptr;
    aminoAcids = aminoAcids->initAminoAcids();
    AminoAcid* activeAcid = aminoAcids->randomiseAcid(aminoAcids);

    // Intialize amino-acid repository variables
    Texture2D base = LoadTexture("./../assets/UI/aminoAcidRepository/base.png");
    Texture2D cover = LoadTexture("./../assets/UI/aminoAcidRepository/baseCover.png");
    Texture2D data = LoadTexture("./../assets/UI/aminoAcidRepository/data.png");
    short int dataY = 160;
    bool showRepobase = false;

    // Intialize data barrier variables
    Texture2D barrierTextures[5] = {
        LoadTexture("./../assets/UI/barriers/barrier1.png"),
        LoadTexture("./../assets/UI/barriers/barrier2.png"),
        LoadTexture("./../assets/UI/barriers/barrier3.png"),
        LoadTexture("./../assets/UI/barriers/barrier4.png"),
        LoadTexture("./../assets/UI/barriers/barrier5.png")
    };
    Barrier* barriers = nullptr;
    barriers = barriers->initBarriers(barrierTextures);

    // Initialize taskbar variables
    Texture2D taskbar = LoadTexture("./../assets/UI/taskbar/taskbar.png");
    Texture2D extraTaskTargets[2] = {
        LoadTexture("./../assets/UI/taskbar/sulfurTaskTarget.png"),
        LoadTexture("./../assets/UI/taskbar/seleniumTaskTarget.png"),
    };
    bool showTaskbar = true;

    // Initialize chemical elements arrays
    // 0 -> carbon, 1 -> hydrogen, 2 -> nitrogen, 3 -> oxygen, 4 -> sulfur, 5 -> selenium
    std::vector<ChemicalElement> carbon(15, ChemicalElement("./../assets/elements/carbon.png", 0));
    std::vector<ChemicalElement> hydrogen(15, ChemicalElement("./../assets/elements/hydrogen.png", 1));
    std::vector<ChemicalElement> nitrogen(15, ChemicalElement("./../assets/elements/nitrogen.png", 2));
    std::vector<ChemicalElement> oxygen(15, ChemicalElement("./../assets/elements/oxygen.png", 3));
    std::vector<ChemicalElement> sulfur(5, ChemicalElement("./../assets/elements/sulfur.png", 4));
    std::vector<ChemicalElement> selenium(5, ChemicalElement("./../assets/elements/selenium.png", 5));

    // Initialize an array containing all chemical elements arrays
    std::vector<std::vector <ChemicalElement>> elements = {carbon, hydrogen, nitrogen, oxygen, sulfur, selenium};

    // Randomise elements' positions
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            elements[i][j].randomisePosition();
        }
    }

    for (int i = 4; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            elements[i][j].randomisePosition();
        }
    }

    // Initialize amino-acid repo slide animation variables
    std::vector<SlideAnimationFrame*> slideAnimationFrames;

    //-> Initialize barriers animation frames
    for (int i = 0; i < 21; i++)
    {
        slideAnimationFrames.push_back(constructAnimationFrame(barriers[i].getX() - 607, barriers[i].getX() - 607, barriers[i].getX(), 'p', 0, 5, showRepobase));
    }

    //-> Initialize remaining 4 animation frames(for base, data, cover)
    slideAnimationFrames.push_back(constructAnimationFrame(-630, -630, -23, 'p', 0, 5, showRepobase));
    slideAnimationFrames.push_back(constructAnimationFrame(-594, -594, 13, 'p', 0, 5, showRepobase));
    slideAnimationFrames.push_back(constructAnimationFrame(-594, -594, 13, 'p', 0, 5, showRepobase));
    slideAnimationFrames.push_back(constructAnimationFrame(-104, -104, -1, 'p', 0, 2, showTaskbar));

    // Main game loop
    while (!WindowShouldClose())
    {
        switch (currentLayer)
        {
        case LOGIC:

            // Move the player
            player->move(player->getPosition());

            player->roatePlayer();

            // Check and handle collision with the map boundary
            player->checkMapBoundary(boundaries);

            // Update camera position
            playerCam.target = player->getPosition();

            if (IsKeyPressed(KEY_UP))
            {
                activeAcid = aminoAcids->randomiseAcid(aminoAcids);
            }

            // Inventory item quantity boundary
            for (int i = 0; i < 6; i++)
            {
                if (itemQuantity[i] > 20)
                {
                    itemQuantity[i] = 20;
                }
            }

            // Check player collision with all chemical elements
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                
                    elements[i][j].checkPlayerCollision(player, itemQuantity);
                }
            }

            for (int i = 4; i < 6; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    elements[i][j].checkPlayerCollision(player, itemQuantity);
                }
            }

            // Scoll the amino-acid repository base up and down
            if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 0,0,607,1080 }))
            {
                dataY += int(GetMouseWheelMove() * 20);

                // Scoll boundaries
                if (dataY >= 160)
                {
                    dataY = 160;
                }
                if (dataY <= -1952)
                {
                    dataY = -1952;
                }
            }

            // Update barrier X coordinate for scroll functionality
            for (int i = 0; i < 21; i++)
            {
                if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 0,0,607,1080 }))
                {
                    barriers[i].scrollBarrier(barriers[i]);
                }
            }

            // Update animation keys based of keyboard input
            for (SlideAnimationFrame *i : slideAnimationFrames)
            {
                if (!i->getShowComponent())
                {
                    if (IsKeyPressed(KEY_TAB))
                    {
                        i->setShowComponent(true);
                    }
                }
                else
                {
                    if (IsKeyPressed(KEY_TAB))
                    {
                        i->setShowComponent(false);
                    }
                }    

                manageSlideAnimation(i);
            }

            currentLayer = PRESENT;
            break;

        case PRESENT:

            BeginDrawing();

            // Clear framebuffer
            ClearBackground(WHITE);

            BeginMode2D(playerCam);

            // Draw texture underglow
            DrawTexture(player->getUnderglowTexture(), int(player->getPosition().x - 400), int(player->getPosition().y - 400), RAYWHITE);

            // Draw background
            DrawTexture(background, -900, -500, RAYWHITE);

            // Draw chemical elements
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    DrawTextureV(elements[i][j].getTexture(), elements[i][j].getPosition(), RAYWHITE);
                }
            }

            for (int i = 4; i < 6; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    DrawTextureV(elements[i][j].getTexture(), elements[i][j].getPosition(), RAYWHITE);
                }
            }

            // Draw the player
            DrawTexturePro(
            player->getPlayerTexture(),
            Rectangle{ 0, 0, float(player->getPlayerTexture().width), float(player->getPlayerTexture().height) },
            Rectangle{ player->getPosition().x, player->getPosition().y, float(player->getPlayerTexture().width), float(player->getPlayerTexture().height) },
            Vector2{ float(player->getPlayerTexture().width / 2), float(player->getPlayerTexture().height / 2) }, player->getRotation(), RAYWHITE);

            EndMode2D();

            // Draw amino-acid repository base
            DrawTexture(base, slideAnimationFrames[21]->getTargetCoordinate(), -7, RAYWHITE);

            // Draw amino-acid repository data
            DrawTexture(data, slideAnimationFrames[22]->getTargetCoordinate(), dataY, RAYWHITE);

            // Draw data barriers
            for (int i = 0; i < 21; i++)
            {
                if (!aminoAcids[i].getIsDiscovered())
                {
                    DrawTexture(barriers[i].getTexture(), slideAnimationFrames[i]->getTargetCoordinate(), barriers[i].getScrollY(), RAYWHITE);
                }
            }

            // Draw amino-acid repository cover
            DrawTexture(cover, slideAnimationFrames[23]->getTargetCoordinate(), 0, RAYWHITE);

            // Draw inventory base
            DrawRectangle(1821, 0, 99, 1080, UIBase);

            // Draw inventory items(numbers and quantity indicators)
            drawInventoryQuantityIndicators(comfortaaRegular, itemQuantity, elementaColors);

            // Draw inventory cover
            DrawTexture(inventory, 1752, 0, RAYWHITE);

            // Draw sulfur and selenium task targets
            drawExtraTaskTarget(comfortaaRegular, activeAcid, itemQuantity, slideAnimationFrames[24]->getTargetCoordinate(), extraTaskTargets, UIBase, elementaColors);

            // Draw taskbar base
            DrawRectangleRounded({ 526, float(slideAnimationFrames[24]->getTargetCoordinate() + 1), 903, 85 }, 0.3f, 1000, UIBase);

            // Draw taskbar items(numbers and quantity indicators)
            drawTaskbarQuantityIndicators(comfortaaRegular, activeAcid, itemQuantity, slideAnimationFrames[24]->getTargetCoordinate(), elementaColors);

            // Draw taskbar
            DrawTexture(taskbar, 461, slideAnimationFrames[24]->getTargetCoordinate(), RAYWHITE);

            // Draw active amino-acid name
            drawTaskbarHeading(comfortaaBold, activeAcid, slideAnimationFrames[24]->getTargetCoordinate());

            EndDrawing();

            currentLayer = LOGIC;
            break;

        default:
            break;
        }
    }
    CloseWindow();

    // Free up alocated memory
    delete[] player;
    delete[] aminoAcids;
    delete[] barriers;
    delete[] itemQuantity;
}