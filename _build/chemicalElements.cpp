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
	float randX = GetRandomValue(10, 5800);
	float randY = GetRandomValue(10, 3170);

	// Set new position
	setPosition({ randX, randY });
}

// Check player collision with a chemical element
void ChemicalElement::checkPlayerCollision(Player* player, short int* itemQuantity)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			for (int k = 0; k < 15; k++)
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
		}
	}
}