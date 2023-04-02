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
	// Constructor
	SlideAnimationFrame(short int n, short int lBoundary, short int rBoundary, const char direction, short int state, short int speed, bool showComponent);

	// Getters
	// Get animation frame X
	short int getTargetCoordinate();

	// Get animation frame left boundary
	short int getStartBoundary();

	// Get animation frame right boundary
	short int getEndBoundary();

	// Get animation frame direction
	char getDirection();

	// Get animation frame state
	short int getState();

	// Get animation speed
	short int getSpeed();

	// Get animation frame driver boolean
	bool getShowComponent();

	// Setters
	// Set animation frame X
	void setTargetCoordinate(short int n);

	// Set animation frame direction
	void setDirection(short int bnoundary);

	// Set animation frame state
	void setState(short int state);

	// Set animation frame driver boolean
	void setShowComponent(bool showComponent);
};

// Universal slide animation 
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
	// Get animation frame X
	short int getTargetCoordinate();

	// Get animation frame left boundary
	short int getTopBoundary();

	// Get animation frame right boundary
	short int getBottomBoundary();

	//Setters
	// Set target coordinate
	void setTargetCoordinate(short int n);

	// Set start boundary
	void setTopBoundary(short int startBoundary);

	// Set end boundary
	void setBottomBoundary(short int endBoundary);
};

// Universal scroll animation
void manageScollAnimation(ScrollAnimation* animationFrame);