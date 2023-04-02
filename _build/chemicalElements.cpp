#include "chemicalElements.h"

/**
 * Constructor.
 * 
 * \param texturePath
 * \param type
 * \return 
 */
ChemicalElement::ChemicalElement(std::string texturePath, short int type)
{
	_texture = LoadTexture(texturePath.c_str());
	_position = { 0,0 };
	_type = type;
}

// Getters
/**
 * Get texture.
 * 
 * \return 
 */
Texture2D ChemicalElement::getTexture()
{
	return _texture;
}

/**
 * Get position.
 * 
 * \return 
 */
Vector2 ChemicalElement::getPosition()
{
	return _position;
}

/**
 * Get type.
 * 
 * \return 
 */
short int ChemicalElement::getType()
{
	return _type;
}

// Setters
/**
 * Set position.
 * 
 * \param position
 */
void ChemicalElement::setPosition(Vector2 position)
{
	_position = position;
}

/**
 * Randomise position.
 * 
 */
void ChemicalElement::randomisePosition()
{
	// Initial randomisation
	int randX = GetRandomValue(10, 5800);
	int randY = GetRandomValue(10, 3170);

	// Set new position
	setPosition({ float(randX), float(randY) });
}

/**
 * Check player collision with a chemical element.
 * 
 * \param player
 * \param itemQuantity
 */
void ChemicalElement::checkPlayerCollision(Player* player, short int* itemQuantity)
{
	// Check player collision
	if (CheckCollisionCircles({ float(player->getPosition().x - 37.5), float(player->getPosition().y - 37.5) }, 37.5, _position, 40))
	{
		if (itemQuantity[_type] < 20)
		{
			// Update inventory
			itemQuantity[_type]++;

			// Update chemical element position
			randomisePosition();
		}
	}
}