#include <cmath>
#include <string>
#include "activeTextAndObjects.h"
#include "animations.h"


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
// Set barrier X coordinate
void Barrier::setX(short int x)
{
	_x = x;
}

// Set scroll Y coordinate
void Barrier::setScrollY(short int y)
{
	_scrollY = y;
}

// Initialize barriers
Barrier* Barrier::initBarriers(Texture2D textures[5])
{
	Barrier* barriers = new Barrier[21];
	barriers[0] = { 37,  180, -1932, textures[1] }; // Tryptophan
	barriers[1] = { 303, 180, -1932, textures[1] }; // Valine
	barriers[2] = { 37,  447, -1666, textures[0] }; // Methonine
	barriers[3] = { 389, 446, -1666, textures[4] }; // Arginine
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
float GetInventoryTextX(int n, int caller)
{
	switch (n)
	{
	case 0:
		if (caller == 1)
		{
			return 0;
		}
		else
		{
			return 2;
		}
	case 1:
		return 3;
	case 11:
		return -3;
	case 20:
		return -7;
	case 2:	case 3:	case 4: case 5: case 6: case 7: case 8: case 9:
		return 1;
	case 10: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
		return -5;
	default:
		return -5;
	}
}

// Draw inventory quantity indicators
void drawInventoryQuantityIndicators(Font font, short int itemQuantity[6], Color colors[6])
{
	// Define relative rectangle portion
	float quantityBar = 0;

	for (int i = 0; i < 6; i++)
	{
		// Draw quantity bars 
		if (itemQuantity[i] == 0)
		{
			DrawRectangle(1848, 152 + i * 150, 55, 1, colors[i]);
		}
		else
		{
			quantityBar = float(itemQuantity[i] * 2.55);
			DrawRectangle(1847, (153 + i * 150) - int(quantityBar), 55, int(ceil(quantityBar)), colors[i]);
		}

		// Draw quantity number
		DrawTextEx(font, TextFormat("%i", itemQuantity[i]), Vector2{ 1868 + GetInventoryTextX(itemQuantity[i], 1), float(114 + 150 * i) }, 30, 1, WHITE);
	}
}

// Draw taskbar quantity indicators
void drawTaskbarQuantityIndicators(Font items, AminoAcid* activeAcid, short int itemQuantity[6], short int base, Color colors[6])
{
	// Define relative quantity bar portion
	float quantityBar = 0;

	// Define local chemical element quantity
	short int activeItemQuantity[5] = { 0,0,0,0,0 };

	// Update local chemical element quantity
	for (int i = 0; i < 4; i++)
	{
		activeItemQuantity[i] = itemQuantity[i];

		// Check for relevant boundaries
		if (activeItemQuantity[i] >= activeAcid->getChemicalMakeup()[i])
		{
			activeItemQuantity[i] = activeAcid->getChemicalMakeup()[i];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		// Draw quantity bars
		if (itemQuantity[i] == 0)
		{
			DrawRectangle(968 + 128 * i, 67 + base, 55, 2, colors[i]);
		}
		else if (itemQuantity[i] >= activeAcid->getChemicalMakeup()[i])
		{
			// It's a feature now :D
			DrawRectangle(968 + 128 * i, 17, 55, 56 + base, colors[i]);
		}
		else
		{
			quantityBar = float(itemQuantity[i] * (51 / activeAcid->getChemicalMakeup()[i]));
			DrawRectangle(968 + 128 * i, 68 - int(quantityBar), 55, base + int(ceil(quantityBar)) + 1, colors[i]);
		}

		// Draw quantity number
		DrawTextEx(items, TextFormat("%i", activeItemQuantity[i]), Vector2{ (987 + 128 * i) + GetInventoryTextX(activeItemQuantity[i], 2), float(32 + base) }, 30, 1, WHITE);
	}
}

// Draw active amino-acid name
void drawTaskbarHeading(Font heading, AminoAcid* activeAcid, short int base)
{
	DrawTextEx(heading, TextFormat("%s", activeAcid->getName().c_str()), Vector2{ 558, float(25 + base) }, 40, 1, WHITE);
}

// Draw sulfur and selenium task targets
void drawExtraTaskTarget(Font item, AminoAcid* activeAcid, short int itemQuantity[6], short int base, Texture2D extraTaskTargets[2], Color color, Color gradientSelection[6])
{
	// Check if the amino-acid contains sulfur or selenium
	if (activeAcid->getChemicalMakeup().size() > 4)
	{
		// Draw extra task targets for amino-acids containing sulfur
		if (activeAcid->getName() == "Methionine" || activeAcid->getName() == "Cysteine")
		{
			// Draw sulfur task target base
			DrawRectangle(1412, base + 1, 125, 85, color);

			// Draw quantity indicators
			if (itemQuantity[4] > 0) // Full indicator varient
			{
				DrawRectangleGradientV(1480, 17, 51, 52 + base, gradientSelection[3], gradientSelection[4]);
				DrawTextEx(item, TextFormat("%i", 1), { 1499, float(30 + base) }, 30, 1, WHITE);
			}
			else // Empty indicator varient
			{
				DrawRectangleGradientH(1480, 68 + base, 51, 1, gradientSelection[3], gradientSelection[4]);
				DrawTextEx(item, TextFormat("%i", 0), { 1499, float(30 + base) }, 30, 1, WHITE);
			}

			// Draw sulfur task target cover
			DrawTexture(extraTaskTargets[0], 1412, base + 1, RAYWHITE);
		}
		else // Draw extra task targets for amino-acids containing selenium
		{
			// Draw selenium task target base
			DrawRectangle(1412, base + 1, 146, 85, color);

			// Draw quantity indicators
			if (itemQuantity[5] > 0) // Full indicator varient
			{
				DrawRectangleGradientV(1503, 17, 51, 52 + base, gradientSelection[5], gradientSelection[1]);
				DrawTextEx(item, TextFormat("%i", 1), { 1522, float(30 + base) }, 30, 1, WHITE);
			}
			else // Empty indicator varient
			{
				DrawRectangleGradientH(1503, 68 + base, 51, 1, gradientSelection[5], gradientSelection[1]);
				DrawTextEx(item, TextFormat("%i", 0), { 1522, float(30 + base) }, 30, 1, WHITE);
			}

			// Draw selenium task target cover
			DrawTexture(extraTaskTargets[1], 1412, base + 1, RAYWHITE);
		}
	}
}