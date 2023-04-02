#pragma once
#include "raylib.h"

class Tutorial
{
private:

    // Load tutorial textures
    Texture2D _tutorialPages[3] = {
        LoadTexture("./../assets/UI/tutorial/tutorial1.png"),
        LoadTexture("./../assets/UI/tutorial/tutorial2.png"),
        LoadTexture("./../assets/UI/tutorial/tutorial3.png")
    };

    Rectangle _arrows[2] = {
        {835, 910, 50, 40},
        {1044, 910, 50, 40}
    };

	int _tutorialProgess = 0;

public:
    // Gets tutorial progress
    int getTutorialProgress();

    // Sets tutorial progress
    void setTutorialProgress(int tutorialProgess);

    // Draws the tutorial
    void drawTutorial(Texture background);

    // Changes the tutorial pages depending on which arrow is clicked
    void updateTutorialProgress();
};