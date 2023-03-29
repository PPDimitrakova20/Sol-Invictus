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
	SlideAnimationFrame(short int x, short int lBoundary, short int rBoundary, const char direction, short int state, short int speed, bool showComponent);

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
	void setTargetCoordinate(short int x);

	// Set animation frame direction
	void setDirection(short int bnoundary);

	// Set animation frame state
	void setState(short int state);

	// Set animation frame driver boolean
	void setShowComponent(bool showComponent);
};

// Construct slide animation frames
SlideAnimationFrame* constructAnimationFrame(short int n, short int startBoundary, short int endBoundary, const char direction, short int state, short int speed, bool showComponent);

// Universal slide animation 
void manageSlideAnimation(SlideAnimationFrame* animationFrame);