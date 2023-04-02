#include "animations.h"

/**
 * Slide animation constructor.
 * 
 * \param n
 * \param startBoundary
 * \param endBoundary
 * \param direction
 * \param state
 * \param speed
 * \param showComponent
 * \return 
 */
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
/**
 * Get slide animation frame target coordinate.
 * 
 * \return 
 */
short int SlideAnimationFrame::getTargetCoordinate()
{
	return _targetCoordinate;
}

/**
 * Get slide animation frame left boundary.
 * 
 * \return 
 */
short int SlideAnimationFrame::getStartBoundary()
{
	return _startBoundary;
}

/**
 * Get slide animation frame right boundary.
 * 
 * \return 
 */
short int SlideAnimationFrame::getEndBoundary()
{
	return _endBoundary;
}

/**
 * Get slide animation frame direction.
 * 
 * \return 
 */
char SlideAnimationFrame::getDirection()
{
	return _direction;
}

/**
 * Get slide animation frame state.
 * 
 * \return 
 */
short int SlideAnimationFrame::getState()
{
	return _state;
}

/**
 * Get slide animation frame speed.
 * 
 * \return 
 */
short int SlideAnimationFrame::getSpeed()
{
	return _speed;
}

/**
 * Get slide animation frame driver boolean.
 * 
 * \return 
 */
bool SlideAnimationFrame::getShowComponent()
{
	return _showComponent;
}

// Setters
/**
 * Set slide animation frame X.
 * 
 * \param n
 */
void SlideAnimationFrame::setTargetCoordinate(short int n)
{
	_targetCoordinate = n;
}

/**
 * Set slide animation frame direction.
 * 
 * \param boundary
 */
void SlideAnimationFrame::setDirection(short int boundary)
{
	_endBoundary = boundary;
}

/**
 * Set slide animation frame state.
 * 
 * \param state
 */
void SlideAnimationFrame::setState(short int state)
{
	_state = state;
}

/**
 * Set slide animation frame driver boolean.
 * 
 * \param showComponent
 */
void SlideAnimationFrame::setShowComponent(bool showComponent)
{
	_showComponent = showComponent;
}

/**
 * Slide animation.
 * 
 * \param animationFrame
 */
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

/**
 * Scroll animation constructor.
 * 
 * \param n
 * \param startBoundary
 * \param endBoundary
 * \return 
 */
ScrollAnimation::ScrollAnimation(short int n, short int startBoundary, short int endBoundary)
{
	_targetCoordinate = n;
	_topBoundary = startBoundary;
	_bottomBoundary = endBoundary;
}

// Getters
/**
 * Get scroll animation frame target coordinate.
 * 
 * \return 
 */
short int ScrollAnimation::getTargetCoordinate()
{
	return _targetCoordinate;
}

/**
 * Get scroll animation frame top boundary.
 * 
 * \return 
 */
short int ScrollAnimation::getTopBoundary()
{
	return _topBoundary;
}

/**
 * Get scroll animation frame bottom boundary.
 * 
 * \return 
 */
short int ScrollAnimation::getBottomBoundary()
{
	return _bottomBoundary;
}

/**
 * Set scroll animation frame target coordinate.
 * 
 * \param n
 */
void ScrollAnimation::setTargetCoordinate(short int n)
{
	_targetCoordinate = n;
}
 
/**
 * Set scroll animation frame top boundary.
 * 
 * \param startBoundary
 */
void ScrollAnimation::setTopBoundary(short int startBoundary)
{
	_topBoundary = startBoundary;
}

/**
 * Set scroll animation frame bottom boundary.
 * 
 * \param endBoundary
 */
void ScrollAnimation::setBottomBoundary(short int endBoundary)
{
	_bottomBoundary = endBoundary;
}

/**
 * Scroll animation.
 * 
 * \param animationFrame
 */
void manageScrollAnimation(ScrollAnimation* animationFrame)
{
	// Update scroll animation target coordinate
	animationFrame->setTargetCoordinate(animationFrame->getTargetCoordinate() + int(GetMouseWheelMove() * 20));

	// Check and enforce top and bottom boundaries
	if (animationFrame->getTargetCoordinate() <= animationFrame->getTopBoundary())
	{
		animationFrame->setTargetCoordinate(animationFrame->getTopBoundary());
	}
	if(animationFrame->getTargetCoordinate() >= animationFrame->getBottomBoundary())
	{
		animationFrame->setTargetCoordinate(animationFrame->getBottomBoundary());
	}
}