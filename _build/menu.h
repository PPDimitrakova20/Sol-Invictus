#pragma once
#include "raylib.h"

#define menuOrange CLITERAL(Color){ 255, 138, 0, 255}
#define menuPurple CLITERAL(Color){ 143, 0, 255, 255}
#define menuBlue CLITERAL(Color){ 42, 191, 241, 255}

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

    Rectangle _buttonHitboxes[3] = {
        {825, 431, 484, 113},
        {825, 631, 484, 113},
        {825, 809, 484, 113}
    };
    
    short int _selectedOption = -1;

public:
    Menu(){};

    void drawMenu();

    void setSelectedOption(short int selectedOption);

    short int getSelectedOption();

    void manageMenu();
};