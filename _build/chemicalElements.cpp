#include "chemicalElements.h"

// Get texture
Texture2D ChemicalElement::getTexture()
{
	return _texture;
}

// Get position
Vector2 ChemicalElement::getPosition()
{
	return _position;
}

// Get type
std::string ChemicalElement::getType()
{
	return _type;
}

// Get hitbox
Circle ChemicalElement::getHitbox()
{
	return _hitbox;
}

// Set position
void ChemicalElement::setPosition(Vector2 position)
{
	_position = position;
}

// Set hitbox
void ChemicalElement::setHitbox(Circle hitbox)
{
	_hitbox = hitbox;
}

// Randomise position
void ChemicalElement::randomisePosition()
{
	// Reset values
	srand(time(NULL));

	// Initial randomisation
	float randX = std::rand() % 3790 + 1;
	float randY = std::rand() % 2110 + 1;

	// Check if out of map
	while (randX < 50)
	{
		// Randomise again
		float randX = std::rand() % 3790 + 1;
	}

	// Check if out of map
	while (randY < 50)
	{
		// Randomise again
		float randY = std::rand() % 2110 + 1;
	}

	// Set new position
	setPosition({ randX, randY });
}