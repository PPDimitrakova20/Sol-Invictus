#include "menu.h"

void Menu::drawMenu()
{
	DrawTexture(_menuBackground, 0, 0, RAYWHITE);
	
	for (int i = 0; i < 3; i++)
	{
		DrawTextureV(_menuButtons[i],_menuButtonCoordinates[i], RAYWHITE);
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