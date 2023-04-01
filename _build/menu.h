#pragma once
#include "raylib.h"

class Menu
{
private:
    Texture2D _menuBackground = LoadTexture("./../assets/UI/menu/menuBackground.png");
    Texture2D _menuButtons[3] = {
        LoadTexture("./../assets/UI/menu/playButton.png"),
        LoadTexture("./../assets/UI/menu/tutorialButton.png"),
        LoadTexture("./../assets/UI/menu/quitButton.png")
    };
    
    Vector2 _menuButtonCoordinates[3] = {
        {825, 461},
        {825, 641},
        {825, 819}
    };

    Rectangle _buttonHitBoxes[3] = {
        {825, 461, 484, 113},
        {825, 641, 484, 113},
        {825, 819, 484, 113}
    };
    
    short int _selectedOption = -1;

public:
    Menu(){};

    void drawMenu();

    void setSelectedOption(short int selectedOption);

    short int getSelectedOption();

    void manageMenu();
};