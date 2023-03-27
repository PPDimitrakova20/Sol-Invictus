#pragma once
#include "raylib.h"
#include "box2d/box2d.h"
#include "player.h"
#include "activeTextAndObjects.h"
#include "chemicalElements.h"
#include "aminoAcids.h"
#include "animations.h"
#include <iostream>
#include <string>
#include <vector>

// Initialize new type
typedef enum ProgrammeLayer { LOGIC, PRESENT} ProgrammeLayer;

// Main game fuction
void Game();