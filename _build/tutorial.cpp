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
	for (int i = 0; i < 2; i++)
	{
		// Check if the mouse is over one of the arrows
		if (CheckCollisionPointRec(GetMousePosition(), _arrows[i]))
		{
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);

			// Check if it is pressed
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				if (i == 0)
				{
					_tutorialProgess--;
				}
				else
				{
					_tutorialProgess++;
				}
			}
		}
	}
}
