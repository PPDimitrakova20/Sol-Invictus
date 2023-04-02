#include "tutorial.h"

/**
 * Get tutorial progress.
 * 
 * \return 
 */
int Tutorial::getTutorialProgress()
{
	return _tutorialProgess;
}

/**
 * Set tutorial progress.
 * 
 * \param tutorialProgess
 */
void Tutorial::setTutorialProgress(int tutorialProgess)
{
	_tutorialProgess = tutorialProgess;
}

/**
 * Draw the tutorial.
 * 
 * \param background
 */
void Tutorial::drawTutorial(Texture background)
{
	DrawTexture(background, -900, -500, RAYWHITE);
	DrawTexture(_tutorialPages[_tutorialProgess], 360, 90,RAYWHITE);
}


/**
 * Change the tutorial pages depending on which arrow is clicked.
 * 
 */
void Tutorial::updateTutorialProgress()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		// Check if the back arrow is pressed
		if (CheckCollisionPointRec(GetMousePosition(), _arrows[0]))
		{
			_tutorialProgess--;
		}
		// Check if the forward arrow is pressed
		if (CheckCollisionPointRec(GetMousePosition(), _arrows[1]))
		{
			_tutorialProgess++;
		}
	}
}
