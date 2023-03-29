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
enum ProgrammeLayer { LOGIC, PRESENT};

// Main game fuction
void Game();