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
void Tutorial::drawTutorial()
{
	DrawRectangle(0, 0, 1920, 1080, { 27, 27, 27, 255 });
	DrawTexture(_tutorialPages[_tutorialProgess], -1, 0,RAYWHITE);
}

/**
 * Change the tutorial pages depending on which arrow is clicked.
 * 
 */
void Tutorial::updateTutorialProgress()
{
	SetMouseCursor(MOUSE_CURSOR_DEFAULT);

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
