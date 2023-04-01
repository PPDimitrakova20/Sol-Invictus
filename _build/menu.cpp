#include "menu.h"

void Menu::drawMenu()
{
	// Draw the menu background
	DrawTexture(_menuBackground, 0, 0, RAYWHITE);
	
	Rectangle coloredMenuRectangles[3] = {
		{825, 471, 484, 113},
		{825, 651, 484, 113},
		{825, 829, 484, 113}
	};

	Color coloredMenuRectanglesColors[3] = {menuOrange, menuPurple, menuBlue};

	for (int i = 0; i < 3; i++)
	{
		// Draw colored rectangles
		DrawRectangleRounded(coloredMenuRectangles[i], 0.45, 1, coloredMenuRectanglesColors[i]);

		// Chech if mouse is on button
		if (CheckCollisionPointRec(GetMousePosition(), _buttonHitboxes[i]))
		{
			// Add hover effect
			DrawTexture(_menuButtons[i], _menuButtonCoordinates[i].x, _menuButtonCoordinates[i]. y + 10, RAYWHITE);
		}
		else
		{
			// Draw normal texture
			DrawTextureV(_menuButtons[i],_menuButtonCoordinates[i], RAYWHITE);
		}
	}
}

void Menu::setSelectedOption(short int selectedOption)
{
	_selectedOption = selectedOption;
}

short int Menu::getSelectedOption()
{
	return _selectedOption;
}

void Menu::manageMenu()
{
	for (int i = 0; i < 3; i++)
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), _buttonHitboxes[i]))
		{
			_selectedOption = i;
		}
	}
}