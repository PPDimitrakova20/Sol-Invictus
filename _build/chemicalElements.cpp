#include "chemicalElements.h"
#include <iostream>

// Constructor
ChemicalElement::ChemicalElement(std::string texturePath, short int type)
{
	_texture = LoadTexture(texturePath.c_str());
	_position = { 0,0 };
	_type = type;
}

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
short int ChemicalElement::getType()
{
	return _type;
}

// Set position
void ChemicalElement::setPosition(Vector2 position)
{
	_position = position;
}

// Randomise position
void ChemicalElement::randomisePosition()
{
	// Initial randomisation
	int randX = GetRandomValue(10, 5800);
	int randY = GetRandomValue(10, 3170);

	// Set new position
	setPosition({ float(randX), float(randY) });
}

// Check player collision with a chemical element
void ChemicalElement::checkPlayerCollision(Player* player, short int* itemQuantity)
{
	// Check player collision
	if (CheckCollisionCircles({ float(player->getPosition().x - 37.5), float(player->getPosition().y - 37.5) }, 37.5, _position, 40))
	{
		// Update inventory
		itemQuantity[_type]++;

		// Update chemical element position
		randomisePosition();
	}
}