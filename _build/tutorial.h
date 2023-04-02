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

    //
    Rectangle _arrows[2] = {
        {835, 890, 50, 40},
        {1044, 890, 50, 40}
    };

	int _tutorialProgess = 0;

public:

    int getTutorialProgress();

    void setTutorialProgress(int tutorialProgess);

    void drawTutorial(Texture background);

    void updateTutorialProgress();
};