#pragma once
#include "raylib.h"

class SlideAnimationFrame
{
private:
	short int _targetCoordinate;
	short int _startBoundary;
	short int _endBoundary;
	char _direction;
	short int _state;
	short int _speed;
	bool _showComponent;

public:
	/**
	 * Constructor.
	 * 
	 * \param n
	 * \param lBoundary
	 * \param rBoundary
	 * \param direction
	 * \param state
	 * \param speed
	 * \param showComponent
	 * \return 
	 */
	SlideAnimationFrame(short int n, short int lBoundary, short int rBoundary, const char direction, short int state, short int speed, bool showComponent);

	// Getters
	/**
	 * Get animation frame X.
	 * 
	 * \return 
	 */
	short int getTargetCoordinate();

	/**
	 * Get animation frame left boundary.
	 * 
	 * \return 
	 */
	short int getStartBoundary();

	/**
	 * Get animation frame right boundary.
	 * 
	 * \return 
	 */
	short int getEndBoundary();

	/**
	 * Get animation frame direction.
	 * 
	 * \return 
	 */
	char getDirection();

	/**
	 * Get animation frame state.
	 * 
	 * \return 
	 */
	short int getState();

	/**
	 * Get animation speed.
	 * 
	 * \return 
	 */
	short int getSpeed();

	/**
	 * Get animation frame driver boolean.
	 * 
	 * \return 
	 */
	bool getShowComponent();

	// Setters
	/**
	 * Set animation frame X.
	 * 
	 * \param n
	 */
	void setTargetCoordinate(short int n);

	/**
	 * Set animation frame direction.
	 * 
	 * \param bnoundary
	 */
	void setDirection(short int bnoundary);

	/**
	 * Set animation frame state.
	 * 
	 * \param state
	 */
	void setState(short int state);

	/**
	 * Set animation frame driver boolean.
	 * 
	 * \param showComponent
	 */
	void setShowComponent(bool showComponent);
};

/**
 * Universal slide animation.
 */
void manageSlideAnimation(SlideAnimationFrame* animationFrame);

class ScrollAnimation
{
private:
	short int _targetCoordinate;
	short int _topBoundary;
	short int _bottomBoundary;

public:
	// Constructor
	ScrollAnimation(short int n, short int topBoundary, short int bottomBoundary);

	// Getters
	/**
	 * Get animation frame X.
	 * 
	 * \return 
	 */
	short int getTargetCoordinate();

	/**
	 * Get animation frame left boundary.
	 * 
	 * \return 
	 */
	short int getTopBoundary();

	/**
	 * Get animation frame right boundary.
	 * 
	 * \return 
	 */
	short int getBottomBoundary();

	//Setters
	/**
	 * Set target coordinate.
	 * 
	 * \param n
	 */
	void setTargetCoordinate(short int n);

	/**
	 * Set start boundary.
	 * 
	 * \param startBoundary
	 */
	void setTopBoundary(short int startBoundary);

	/**
	 * Set end boundary.
	 * 
	 * \param endBoundary
	 */
	void setBottomBoundary(short int endBoundary);
};

/**
 * Universal scroll animation.
 */
void manageScrollAnimation(ScrollAnimation* animationFrame);




