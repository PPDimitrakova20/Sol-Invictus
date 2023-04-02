#pragma once
#include "raylib.h"
#include "player.h"
#include "activeTextAndObjects.h"
#include "chemicalElements.h"
#include "aminoAcids.h"
#include "animations.h"
#include "menu.h"
#include "tutorial.h"
#include <iostream>
#include <string>
#include <vector>

/**
 * Initialize new type.
 */
enum ProgramLayer { MENU, TUTORIAL, GAMELOGIC, GAMEPRESENT};

/**
 * Main game fuction.
 */
void game();




