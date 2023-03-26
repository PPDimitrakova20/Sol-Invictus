#include <cmath>
#include "activeTextAndObjects.h"

// Barrier class methods
// Default constructor
Barrier::Barrier()
{
	_x = 0;
	_y = 0;
	_scrollY = 0;
	_scrollBoundary = 0;
}

// Parameterized constructor
Barrier::Barrier(short int x, short int y, short int boundary, Texture2D texture)
{
	_x = x;
	_y = y;
	_scrollY = y;
	_scrollBoundary = boundary;
	_texture = texture;
};

// Getters
// Get barrier X coordinate
short int Barrier::getX()
{
	return _x;
}

// Get barrier Y coordinate
short int Barrier::getY()
{
	return _y;
}

// Get barrier scroll Y coordinate
short int Barrier::getScrollY()
{
	return _scrollY;
}

// Get barrier scroll boundary
short int Barrier::getScrollBoundary()
{
	return _scrollBoundary;
}

// Get barrier texture
Texture2D Barrier::getTexture()
{
	return _texture;
}

//Setters
// Set scroll Y coordinate
void Barrier::setScrollY(short int y)
{
	_scrollY = y;
}

// Set barrier X coordinate
void Barrier::setX(short int x)
{
	_x = x;
}

// Initialize barriers
Barrier* Barrier::initBarriers(Texture2D textures[5])
{
	Barrier* barriers = new Barrier[21];
	barriers[0] = { 37,  180, -1932, textures[1] }; // Tryptophan
	barriers[1] = { 303, 180, -1932, textures[1] }; // Valine
	barriers[2] = { 37,  447, -1666, textures[0] }; // Methonine
	barriers[3] = { 390, 446, -1666, textures[4] }; // Arginine
	barriers[4] = { 37,  800, -1312, textures[3] }; // Alanine
	barriers[5] = { 214, 800, -1312, textures[2] }; // Glutamic acid
	barriers[6] = { 37,  976, -1136, textures[1] }; // Histidine
	barriers[7] = { 303, 976, -1136, textures[1] }; // Threonine
	barriers[8] = { 37,  1239, -873, textures[3] }; // Serine
	barriers[9] = { 214, 1239, -873, textures[0] }; // Phenylalanine
	barriers[10] = { 37,  1416, -696, textures[4] }; // Proline
	barriers[11] = { 214, 1593, -519, textures[0] }; // Isoleucine
	barriers[12] = { 37,  1770, -342, textures[4] }; // Trosine
	barriers[13] = { 214, 1947, -165, textures[2] }; // Selenocysteine
	barriers[14] = { 37,  2124, 12,   textures[0] }; // Leucine
	barriers[15] = { 390, 2124, 12,   textures[4] }; // Cysteine
	barriers[16] = { 37,  2478, 366,  textures[4] }; // Glutamine
	barriers[17] = { 214, 2478, 366,  textures[0] }; // Lysine
	barriers[18] = { 37,  2832, 720,  textures[2] }; // Aspartic acid
	barriers[19] = { 390, 2832, 720,  textures[4] }; // Glycine
	barriers[20] = { 37,  3009, 897,  textures[2] }; // Asparagine

	return barriers;
}

// Scoll the data barriers and check for boundaries
void Barrier::scrollBarrier(Barrier temp)
{
	// Update barrier Y coordinate
	_scrollY += int(GetMouseWheelMove() * 20);

	// Check boundaries
	if (_scrollY >= _y)
	{
		_scrollY = _y;
	}
	if (_scrollY <= _scrollBoundary)
	{
		_scrollY = _scrollBoundary;
	}
}


// Get inventory text x position
float GetInventoryTextX(int n)
{
	switch (n)
	{
	case 0:
		return 1868;
	case 1:
		return 1871;
	case 11:
		return 1865;
	case 20:
		return 1861;
	case 2:	case 3:	case 4: case 5: case 6: case 7: case 8: case 9:
		return 1869;
	case 10: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
		return 1863;
	default:
		return 0;
	}
}

// Draw inventory items
void DrawInventoryItems(Font font, short int itemQuantity[6], Color color[6])
{
	float quantityBar = 0;

	for (int i = 0; i < 6; i++)
	{
		// Draw quantity bars
		if (itemQuantity[i] == 0)
		{
			DrawRectangle(1848, 152 + i * 150, 55, 1, color[i]);
		}
		else
		{
			quantityBar = float(itemQuantity[i] * 2.55);
			DrawRectangle(1847, (153 + i * 150) - int(quantityBar), 55, int(ceil(quantityBar)), color[i]);
		}

		// Draw quantity number
		DrawTextEx(font, TextFormat("%i", itemQuantity[i]), Vector2{ GetInventoryTextX(itemQuantity[i]), float(114 + 150 * i) }, 30, 1, WHITE);
	}
}