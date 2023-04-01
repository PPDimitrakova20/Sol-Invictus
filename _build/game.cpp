#include "game.h"

void Game()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Dev window");
    //ToggleFullscreen();
    SetTargetFPS(60);

    // Load font variants from the file structure
    Font taskbarTitleFont = LoadFontEx("../assets/fonts/Comfortaa-Bold.ttf", 40, 0, 250);
    Font quantityIndicatorsFont = LoadFontEx("../assets/fonts/Comfortaa-Regular.ttf", 30, 0, 250);
    Font craftingBenchFonts[3] = {
        LoadFontEx("../assets/fonts/Comfortaa-Bold.ttf", 20, 0, 250),
        LoadFontEx("../assets/fonts/Comfortaa-Bold.ttf", 30, 0, 250),
        LoadFontEx("../assets/fonts/Comfortaa-Bold.ttf", 15, 0, 250),
    };

    ProgramLayer currentLayer = MENU;

    // Initialize menu
    Menu gameMenu;
    bool isQuitButtonPressed = false;

    // Initialize tutorial
    Tutorial tutorialScreen;

    // Intialize player variables
    Player* player = Player::getinstance();
    Camera2D playerCam = { {screenWidth / 2, screenHeight / 2}, player->getPosition(), 0, 1 };

    // Intialize camera variables
    Texture2D background = LoadTexture("./../assets/UI/background.png");
    Rectangle boundaries[4] = {
        {-50, -50, 25, 3395},
        {5880, -50, 25, 3395},
        {-50, -50, 5955, 25},
        {-50, 3320, 5955, 25}
    };

    // Intialize inventory and crafting bench variables
    Color elementaColors[6] = { carbonColor, hydrogenColor, nitrogenColor, oxygenColor, sulfurColor, seleniumColor };
    Texture2D inventory = LoadTexture("./../assets/UI/craftingBench/inventory.png");
    short int* itemQuantity = new short int[6]();

    // -> Intialize crafting bench variables
    Texture2D craftingBenchBase = LoadTexture("./../assets/UI/craftingBench/craftingBenchBase.png");
    Texture2D craftingTableCover = LoadTexture("./../assets/UI/craftingBench/craftingBenchCover.png");
    Texture2D craftingRecipeBases[3] = {
        LoadTexture("./../assets/UI/craftingBench/craftingRecipes/taskRequired.png"),
        LoadTexture("./../assets/UI/craftingBench/craftingRecipes/craftable.png"),
        LoadTexture("./../assets/UI/craftingBench/craftingRecipes/insufficientMaterials.png")
    };
    std::vector<CraftingRecipe> craftingRecipes;
    CraftingRecipe accessPoint = CraftingRecipe();
    bool showCraftingBench = false, autoCloseCraftingBench = false, *autoCloseCraftingBenchPtr = &autoCloseCraftingBench;
    bool hasAminoAcid = false, taskRecipeComplete = false, taskRecipeCrafted = false;

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
    std::vector<ChemicalElement> carbon(25, ChemicalElement("./../assets/elements/carbon.png", 0));
    std::vector<ChemicalElement> hydrogen(25, ChemicalElement("./../assets/elements/hydrogen.png", 1));
    std::vector<ChemicalElement> nitrogen(5, ChemicalElement("./../assets/elements/nitrogen.png", 2));
    std::vector<ChemicalElement> oxygen(5, ChemicalElement("./../assets/elements/oxygen.png", 3));
    std::vector<ChemicalElement> sulfur(2, ChemicalElement("./../assets/elements/sulfur.png", 4));
    std::vector<ChemicalElement> selenium(2, ChemicalElement("./../assets/elements/selenium.png", 5));

    // Initialize an array containing all chemical elements arrays
    std::vector<std::vector <ChemicalElement>> elements = {carbon, hydrogen, nitrogen, oxygen, sulfur, selenium};

    // Randomise elements' positions
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            elements[i][j].randomisePosition();
        }
    }

    for (int i = 2; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            elements[i][j].randomisePosition();
        }
    }

    for (int i = 4; i < 6; i++)
    {
        for (int j = 0; j < 2; j++)
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
    slideAnimationFrames.push_back(constructAnimationFrame(1821, 1401, 1821, 'n', 0, 5, showCraftingBench));

    // Main game loop
    while (!WindowShouldClose())
    {

        switch (currentLayer)
        {
        case MENU:

            BeginDrawing();

            // Clear framebuffer
            ClearBackground(WHITE);

            gameMenu.drawMenu();
            gameMenu.manageMenu();

            switch (gameMenu.getSelectedOption())
            {
            case -1:
                currentLayer = MENU;
                break;
            case 0:
                currentLayer = GAMELOGIC;
                break;
            case 1:
                currentLayer = TUTORIAL;
                break;
            case 2:
                isQuitButtonPressed = true;
            }

            EndDrawing();
            break;

        case TUTORIAL:
            BeginDrawing();

            // Clear framebuffer
            ClearBackground(WHITE);
            
            switch (tutorialScreen.getTutorialProgress())
            {
            case -1:
            case 3:
                currentLayer = MENU;
                tutorialScreen.setTutorialProgress(0);
                gameMenu.setSelectedOption(-1);
                break;
            default:
                tutorialScreen.drawTutorial();
                break;
            }

            tutorialScreen.updateTutorialProgress();

            EndDrawing();
            break;

        case GAMELOGIC:

            // Move the player
            player->move(player->getPosition());

            player->rotatePlayer();

            player->movePlayerRec();

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
                if (itemQuantity[i] >= 20)
                {
                    itemQuantity[i] = 20;
                }
            }

            // Check player collision with all chemical elements
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 25; j++)
                {
                    elements[i][j].checkPlayerCollision(player, itemQuantity);
                }
            }

            for (int i = 2; i < 4; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    elements[i][j].checkPlayerCollision(player, itemQuantity);
                }
            }

            for (int i = 4; i < 6; i++)
            {
                for (int j = 0; j < 2; j++)
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

            /*---------- Crafting bench logic ----------*/
            // Check if the active acid is already in the recipe list
            if (!craftingRecipes.empty())
            {
                hasAminoAcid = false;
                for (int i = 0; i < craftingRecipes.size(); i++)
                {
                    if (craftingRecipes[i].getName() == activeAcid->getName())
                    {
                        hasAminoAcid = true;
                        break;
                    }
                }
            }

            // Add crafting recipes to the recipe list 
            if (!hasAminoAcid || craftingRecipes.empty())
            {
                craftingRecipes.push_back(CraftingRecipe(Rectangle{ 1446,float(155 + craftingRecipes.size() * 168),355,134 }, activeAcid->getName(), activeAcid->getChemicalMakeup()));
            }

            // Update the recipes' status
            for (CraftingRecipe& i : craftingRecipes)
            {
                i.updateCraftingRecipeStatus(itemQuantity, activeAcid);
            }

            // Sort the recipe list
            craftingRecipes = accessPoint.sortCraftingRecipes(craftingRecipes);

            // Check if the task required recipe is complete
            for (int i = 0; i < craftingRecipes[0].getChemicalMakeup().size(); i++)
            {
                if (craftingRecipes[0].getChemicalMakeup()[i] > itemQuantity[i])
                {
                    taskRecipeComplete = false;
                    break;
                }
                else
                {
                    taskRecipeComplete = true;
                }
            }

            // Reset the crafting requirement check 
            taskRecipeCrafted = false;
            autoCloseCraftingBench = false;

            // Set active acid discovery status
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
                CheckCollisionPointRec(GetMousePosition(), craftingRecipes[0].getHitbox()) &&
                taskRecipeComplete && slideAnimationFrames[25]->getTargetCoordinate() == 1401)
            {
                activeAcid->setIsDiscovered(true);
                taskRecipeCrafted = true;
                autoCloseCraftingBench = true;
            }

            // Update the iventory element count after crafting an acid
            accessPoint.updateInventoryElementsCount(itemQuantity, craftingRecipes, slideAnimationFrames[25]->getTargetCoordinate(), autoCloseCraftingBenchPtr);

            // Update the discovery status of the amino-acid corresponding to active acid
            for (short int i = 0; i < 21; i++)
            {
                if (aminoAcids[i].getName() == activeAcid->getName() && activeAcid->getIsDiscovered())
                {
                    aminoAcids[i].setIsDiscovered(true);
                    break;
                }
            }

            // Update active amino-acid
            if (activeAcid->getIsDiscovered() && taskRecipeCrafted)
            {
                activeAcid = aminoAcids->randomiseAcid(aminoAcids);
            }

            /*---------- Slide animation logic ----------*/
            // Update animation keys based of keyboard input
            for (short int i = 0; i < slideAnimationFrames.size(); i++)
            {
                if (i != slideAnimationFrames.size() - 1)
                {
                    if (!slideAnimationFrames[i]->getShowComponent())
                    {
                        if (IsKeyPressed(KEY_TAB))
                        {
                            slideAnimationFrames[i]->setShowComponent(true);
                        }
                    }
                    else
                    {
                        if (IsKeyPressed(KEY_TAB))
                        {
                            slideAnimationFrames[i]->setShowComponent(false);
                        }
                    }
                }
                else
                {
                    if (!slideAnimationFrames[i]->getShowComponent())
                    {
                        if (IsKeyPressed(KEY_E))
                        {
                            slideAnimationFrames[i]->setShowComponent(true);
                        }
                    }
                    else
                    {
                        if (IsKeyPressed(KEY_E))
                        {
                            slideAnimationFrames[i]->setShowComponent(false);
                        }
                    }
                }
            }

            // Update taskbar animation frame
            if (!slideAnimationFrames[21]->getShowComponent() && !slideAnimationFrames[25]->getShowComponent())
            {
                slideAnimationFrames[24]->setShowComponent(true);
            }
            else
            {
                slideAnimationFrames[24]->setShowComponent(false);
            }

            if (autoCloseCraftingBench)
            {
                slideAnimationFrames[25]->setShowComponent(false);
            }

            // Apply the slide animation to its frames
            for (short int i = 0; i < slideAnimationFrames.size(); i++)
            {

                manageSlideAnimation(slideAnimationFrames[i]);
            }

            currentLayer = GAMEPRESENT;
            break;

        case GAMEPRESENT:

            BeginDrawing();

            // Clear framebuffer
            ClearBackground(WHITE);

            BeginMode2D(playerCam);

            // Draw texture underglow
            DrawTexture(player->getUnderglowTexture(), int(player->getPosition().x - 400), int(player->getPosition().y - 400), RAYWHITE);

            // Draw background
            DrawTexture(background, -900, -500, RAYWHITE);

            // Draw chemical elements
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 25; j++)
                {
                    DrawTextureV(elements[i][j].getTexture(), elements[i][j].getPosition(), RAYWHITE);
                }
            }

            for (int i = 2; i < 4; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    DrawTextureV(elements[i][j].getTexture(), elements[i][j].getPosition(), RAYWHITE);
                }
            }

            for (int i = 4; i < 6; i++)
            {
                for (int j = 0; j < 2; j++)
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

            // Draw boundary when player is close to map border
            for (int i = 0; i < 4; i++)
            {
                player->drawMapBoundary(boundaries[i]);
            }

            EndMode2D();

            /*---------- Amino-acid repository -----------*/
            // Draw amino-acid repository base
            DrawTexture(base, slideAnimationFrames[21]->getTargetCoordinate(), -7, RAYWHITE);

            // Draw amino-acid repository data
            DrawTexture(data, slideAnimationFrames[22]->getTargetCoordinate(), dataY, RAYWHITE);

            /*----------- Cells barriers ----------*/
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

            /*---------- Crafting bench ----------*/
            // Draw crafting bench base
            DrawTexture(craftingBenchBase, slideAnimationFrames[25]->getTargetCoordinate(), 0, RAYWHITE);

            // Draw crafting bench base
            DrawTexture(craftingTableCover, slideAnimationFrames[25]->getTargetCoordinate() + 16, 0, RAYWHITE);

            // Draw crafting recipes
            drawCraftingRecipes(craftingBenchFonts, craftingRecipeBases, craftingRecipes, slideAnimationFrames[25]->getTargetCoordinate());

            /*---------- Inventory ----------*/
            // Draw inventory base
            DrawRectangle(1821, 0, 99, 1080, UIBase);

            // Draw inventory items(numbers and quantity indicators)
            drawInventoryQuantityIndicators(quantityIndicatorsFont, itemQuantity, elementaColors);

            // Draw inventory cover
            DrawTexture(inventory, 1752, 0, RAYWHITE);

            /*---------- Taskbar ---------*/
            // Draw sulfur and selenium task targets
            drawExtraTaskTarget(quantityIndicatorsFont, activeAcid, itemQuantity, slideAnimationFrames[24]->getTargetCoordinate(), extraTaskTargets, UIBase, elementaColors);

            // Draw taskbar base
            DrawRectangleRounded({ 526, float(slideAnimationFrames[24]->getTargetCoordinate() + 1), 903, 85 }, 0.3f, 1000, UIBase);

            // Draw taskbar items(numbers and quantity indicators)
            drawTaskbarQuantityIndicators(quantityIndicatorsFont, activeAcid, itemQuantity, slideAnimationFrames[24]->getTargetCoordinate(), elementaColors);

            // Draw taskbar
            DrawTexture(taskbar, 461, slideAnimationFrames[24]->getTargetCoordinate(), RAYWHITE);

            // Draw active amino-acid name
            drawTaskbarHeading(taskbarTitleFont, activeAcid, slideAnimationFrames[24]->getTargetCoordinate());

            EndDrawing();

            currentLayer = GAMELOGIC;
            break;

        default:
            break;
        }

        if (isQuitButtonPressed)
        {
            CloseWindow();
        }
    }
    
    // Free up alocated memory
    delete[] player;
    delete[] aminoAcids;
    delete[] barriers;
    delete[] itemQuantity;
}