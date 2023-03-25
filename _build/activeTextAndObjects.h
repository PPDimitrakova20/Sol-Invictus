#pragma once
#include "raylib.h"

// Define custom colors
#define inventoryBase CLITERAL(Color){ 44, 44, 44, 255 }
#define carbonColor CLITERAL(Color){ 255, 138, 0, 255}
#define hydrogenColor CLITERAL(Color){ 97, 0, 255, 255}
#define nitrogenColor CLITERAL(Color){ 0, 102, 255, 255}
#define oxygenColor CLITERAL(Color){ 36, 255, 0, 255}
#define sulfurColor CLITERAL(Color){ 255, 215, 0, 255}
#define seleniumColor CLITERAL(Color){ 250, 1, 255, 255}

// Draw inventory items
void DrawInventoryItems(Font comfortaaRegular, short int inventoryItems[6], Color elementaColors[6]);