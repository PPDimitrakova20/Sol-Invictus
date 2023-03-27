#pragma once
#include "raylib.h"

class SlideAnimationFrame 
{
private:
	short int _xCoordinate;
	short int _leftBoundary;
	short int _rightBoundary;
	char _direction;
	short int _state;
	bool _showComponent;

public:
	// Constructor
	SlideAnimationFrame(short int x, short int lBoundary, short int rBoundary, const char direction, short int state, bool showComponent);

	// Getters
	// Get animation frame X
	short int getX();

	// Get animation frame left boundary
	short int getLeftBoundary();

	// Get animation frame right boundary
	short int getRightBoundary();

	// Get animation frame direction
	char getDirection();

	// Get animation frame state
	short int getState();

	// Get animation frame driver boolean
	bool getShowComponent();

	// Setters
	// Set animation frame X
	void setX(short int x);

	// Set animation frame direction
	void setDirection(short int bnoundary);

	// Set animation frame state
	void setState(short int state);

	// Set animation frame driver boolean
	void setShowComponent(bool showComponent);
};

// Construct slide animation frames
SlideAnimationFrame* constructAnimationFrame(short int x, short int lBoundary, short int rBoundary, const char direction, short int state, bool showComponent);

// Universal slide animation 
void manageSlideAnimation(SlideAnimationFrame* animationFrame);