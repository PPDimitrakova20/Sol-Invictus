#include "tutorial.h"

int Tutorial::getTutorialProgress()
{
	return _tutorialProgess;
}

void Tutorial::setTutorialProgress(int tutorialProgess)
{
	_tutorialProgess = tutorialProgess;
}

void Tutorial::drawTutorial(Texture background)
{
	DrawTexture(background, -900, -500, RAYWHITE);
	DrawTexture(_tutorialPages[_tutorialProgess], 360, 90,RAYWHITE);
}

void Tutorial::updateTutorialProgress()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		if (CheckCollisionPointRec(GetMousePosition(), _arrows[0]))
		{
			_tutorialProgess--;
		}
		if (CheckCollisionPointRec(GetMousePosition(), _arrows[1]))
		{
			_tutorialProgess++;
		}
	}
}
