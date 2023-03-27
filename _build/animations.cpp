#include "animations.h"

// Constructor
SlideAnimationFrame::SlideAnimationFrame(short int x, short int lBoundary, short int rBoundary, const char direction, short int state, bool showComponent)
{
	_xCoordinate = x;
	_leftBoundary = lBoundary;
	_rightBoundary = rBoundary;
	_direction = direction;
	_state = state;
	_showComponent = showComponent;
}

// Getters
// Get animation frame X
short int SlideAnimationFrame::getX()
{
	return _xCoordinate;
}

// Get animation frame left boundary
short int SlideAnimationFrame::getLeftBoundary()
{
	return _leftBoundary;
}

// Get animation frame right boundary
short int SlideAnimationFrame::getRightBoundary()
{
	return _rightBoundary;
}

// Get animation frame direction
char SlideAnimationFrame::getDirection()
{
	return _direction;
}

// Get animation frame state
short int SlideAnimationFrame::getState()
{
	return _state;
}

// Get animation frame driver boolean
bool SlideAnimationFrame::getShowComponent()
{
	return _showComponent;
}

// Setters
// Set animation frame X
void SlideAnimationFrame::setX(short int x)
{
	_xCoordinate = x;
}

// Set animation frame direction
void SlideAnimationFrame::setDirection(short int boundary)
{
	_rightBoundary = boundary;
}

// Set animation frame state
void SlideAnimationFrame::setState(short int state)
{
	_state = state;
}

// Set animation frame driver boolean
void SlideAnimationFrame::setShowComponent(bool showComponent)
{
	_showComponent = showComponent;
}

// Construct slide animation frames
SlideAnimationFrame* constructAnimationFrame(short int x, short int lBoundary, short int rBoundary, const char direction, short int state, bool showComponent)
{
	SlideAnimationFrame* animationframe = new SlideAnimationFrame(x, lBoundary, rBoundary, direction, state, showComponent);
	return animationframe;
}

// Universal slide animation 
void manageSlideAnimation(SlideAnimationFrame* animationFrame)
{
	// Set animation status 
	if (animationFrame->getShowComponent())
	{
		// Update animation state to -1(decreasing)
		animationFrame->setState(1);
	}
	else if (!animationFrame->getShowComponent())
	{
		// Update animation state to 1(increasing)
		animationFrame->setState(-1);
	}

	// Update animation frames based of their direction
	if (animationFrame->getDirection() == 'r')
	{
		switch (animationFrame->getState())
		{
		case 1:
			// Update animation frame X
			animationFrame->setX(animationFrame->getX() + 5);

			// Check for right animation boundary
			if (animationFrame->getX() >= animationFrame->getRightBoundary())
			{
				// Snap targeted element to the animation boundary
				animationFrame->setX(animationFrame->getRightBoundary());

				// Update animation state
				animationFrame->setState(0);
			}
			break;
		case -1:
			// Update animation frame X
			animationFrame->setX(animationFrame->getX() - 5);

			// Check for right animation boundary
			if (animationFrame->getX() <= animationFrame->getLeftBoundary())
			{
				// Snap targeted element to the animation boundary
				animationFrame->setX(animationFrame->getLeftBoundary());

				// Update animation state
				animationFrame->setState(0);
			}
			break;
		case 0:
			break;
		}
	}
	else if(animationFrame->getDirection() == 'l')
	{
		switch (animationFrame->getState())
		{
		case 1:
			// Update animation frame X
			animationFrame->setX(animationFrame->getX() - 5);

			// Check for right animation boundary
			if (animationFrame->getX() <= animationFrame->getLeftBoundary())
			{
				// Snap targeted element to the animation boundary
				animationFrame->setX(animationFrame->getLeftBoundary());

				// Update animation state
				animationFrame->setState(0);
			}
			break;
		case -1:
			// Update animation frame X
			animationFrame->setX(animationFrame->getX() + 5);

			// Check for right animation boundary
			if (animationFrame->getX() >= animationFrame->getRightBoundary())
			{
				// Snap targeted element to the animation boundary
				animationFrame->setX(animationFrame->getRightBoundary());

				// Update animation state
				animationFrame->setState(0);
			}
			break;
		case 0:
			break;
		}
	}
}