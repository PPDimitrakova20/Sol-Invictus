#pragma once
#include "raylib.h"
#include "aminoAcids.h"
#include <string>

// Define custom colors
#define UIBase CLITERAL(Color){ 44, 44, 44, 255 }
#define carbonColor CLITERAL(Color){ 255, 138, 0, 255}
#define hydrogenColor CLITERAL(Color){ 97, 0, 255, 255}
#define nitrogenColor CLITERAL(Color){ 0, 102, 255, 255}
#define oxygenColor CLITERAL(Color){ 36, 255, 0, 255}
#define sulfurColor CLITERAL(Color){ 255, 215, 0, 255}
#define seleniumColor CLITERAL(Color){ 250, 1, 255, 255}

// Draw inventory quantity indicators
void drawInventoryQuantityIndicators(Font comfortaaRegular, short int inventoryItems[6], Color elementaColors[6]);

// Draw taskbar quantity indicators
void drawTaskbarQuantityIndicators(Font items, AminoAcid* activeAcid, short int itemQuantity[6], short int base, Color colors[6]);

// Draw active amino-acid name
void drawTaskbarHeading(Font heading, AminoAcid* activeAcid, short int base);

// Draw sulfur and selenium task targets
void drawExtraTaskTarget(Font item, AminoAcid* activeAcid, short int itemQuantity[6], short int base, Texture2D extraTaskTargets[2], Color color, Color gradientSelection[6]);

// Draw crafting recipes
void drawCraftingRecipes(Font craftingBenchFonts[3], Texture2D craftingRecipeBases[3], std::vector<CraftingRecipe> craftingRecipes, short int baseX, short int baseY);