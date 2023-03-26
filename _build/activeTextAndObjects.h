#pragma once
#include "raylib.h"
#include <string>

// Define custom colors
#define inventoryBase CLITERAL(Color){ 44, 44, 44, 255 }
#define carbonColor CLITERAL(Color){ 255, 138, 0, 255}
#define hydrogenColor CLITERAL(Color){ 97, 0, 255, 255}
#define nitrogenColor CLITERAL(Color){ 0, 102, 255, 255}
#define oxygenColor CLITERAL(Color){ 36, 255, 0, 255}
#define sulfurColor CLITERAL(Color){ 255, 215, 0, 255}
#define seleniumColor CLITERAL(Color){ 250, 1, 255, 255}

class Barrier
{
private:
	short int _x;
	short int _y;
	short int _scrollY;
	short int _scrollBoundary;
	Texture2D _texture;

public:
	/// Constructors
	// Default constructor
	Barrier();

	// Parameterized constructor
	Barrier(short int x, short int y, short int boundary, Texture2D texture);

	// Getters
	// Get barrier X coordinate
	short int getX();

	// Get barrier Y coordinate
	short int getY();

	// Get barrier scroll Y coordinate
	short int getScrollY();

	// Get barrier scroll boundary
	short int getScrollBoundary();

	// Get barrier texture
	Texture2D getTexture();

	// Setters
	// Set scroll Y coordinate
	void setScrollY(short int y);

	//Set barrier X coordinate
	void setX(short int x);

	// Methods
	// Initialize barriers
	Barrier* initBarriers(Texture2D barriers[5]);

	// Scoll the data barriers and check for boundaries
	void scrollBarrier(Barrier barrier);

};

// Draw inventory items
void DrawInventoryItems(Font comfortaaRegular, short int inventoryItems[6], Color elementaColors[6]);