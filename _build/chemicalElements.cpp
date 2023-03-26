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