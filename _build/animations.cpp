#include "animations.h"

// Constructor
SlideAnimationFrame::SlideAnimationFrame(short int n, short int startBoundary, short int endBoundary, const char direction, short int state, short int speed, bool showComponent)
{
	_targetCoordinate = n;
	_startBoundary = startBoundary;
	_endBoundary = endBoundary;
	_direction = direction;
	_state = state;
	_speed = speed;
	_showComponent = showComponent;
}

// Getters
// Get animation frame X
short int SlideAnimationFrame::getTargetCoordinate()
{
	return _targetCoordinate;
}

// Get animation frame left boundary
short int SlideAnimationFrame::getStartBoundary()
{
	return _startBoundary;
}

// Get animation frame right boundary
short int SlideAnimationFrame::getEndBoundary()
{
	return _endBoundary;
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

// Get animation speed
short int SlideAnimationFrame::getSpeed()
{
	return _speed;
}

// Get animation frame driver boolean
bool SlideAnimationFrame::getShowComponent()
{
	return _showComponent;
}

// Setters
// Set animation frame X
void SlideAnimationFrame::setTargetCoordinate(short int x)
{
	_targetCoordinate = x;
}

// Set animation frame direction
void SlideAnimationFrame::setDirection(short int boundary)
{
	_endBoundary = boundary;
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
SlideAnimationFrame* constructAnimationFrame(short int n, short int startBoundary, short int endBoundary, const char direction, short int state, short int speed, bool showComponent)
{
	SlideAnimationFrame* animationframe = new SlideAnimationFrame(n, startBoundary, endBoundary, direction, state, speed, showComponent);
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
	if (animationFrame->getDirection() == 'p')
	{
		switch (animationFrame->getState())
		{
		case 1:
			// Update animation frame X
			animationFrame->setTargetCoordinate(animationFrame->getTargetCoordinate() + animationFrame->getSpeed());

			// Check for right animation boundary
			if (animationFrame->getTargetCoordinate() >= animationFrame->getEndBoundary())
			{
				// Snap targeted element to the animation boundary
				animationFrame->setTargetCoordinate(animationFrame->getEndBoundary());

				// Update animation state
				animationFrame->setState(0);
			}
			break;
		case -1:
			// Update animation frame X
			animationFrame->setTargetCoordinate(animationFrame->getTargetCoordinate() - animationFrame->getSpeed());

			// Check for right animation boundary
			if (animationFrame->getTargetCoordinate() <= animationFrame->getStartBoundary())
			{
				// Snap targeted element to the animation boundary
				animationFrame->setTargetCoordinate(animationFrame->getStartBoundary());

				// Update animation state
				animationFrame->setState(0);
			}
			break;
		case 0:
			break;
		}
	}
	else if (animationFrame->getDirection() == 'n')
	{
		switch (animationFrame->getState())
		{
		case 1:
			// Update animation frame X
			animationFrame->setTargetCoordinate(animationFrame->getTargetCoordinate() - animationFrame->getSpeed());

			// Check for right animation boundary
			if (animationFrame->getTargetCoordinate() <= animationFrame->getStartBoundary())
			{
				// Snap targeted element to the animation boundary
				animationFrame->setTargetCoordinate(animationFrame->getStartBoundary());

				// Update animation state
				animationFrame->setState(0);
			}
			break;
		case -1:
			// Update animation frame X
			animationFrame->setTargetCoordinate(animationFrame->getTargetCoordinate() + animationFrame->getSpeed());

			// Check for right animation boundary
			if (animationFrame->getTargetCoordinate() >= animationFrame->getEndBoundary())
			{
				// Snap targeted element to the animation boundary
				animationFrame->setTargetCoordinate(animationFrame->getEndBoundary());

				// Update animation state
				animationFrame->setState(0);
			}
			break;
		case 0:
			break;
		}
	}
}