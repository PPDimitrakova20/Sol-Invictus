#include "player.h"

// Setters
// Set player position
void Player::setPosition(Vector2 position)
{
	_position = position;
}

// Getters
// Get player texture
Texture2D Player::getTexture()
{
	return _texture;
}

// Get player position
Vector2 Player::getPosition()
{
	return _position;
}

// Methods  
// Move the player
void Player::Move(Vector2 position)
{
	// Intialize X and Y offset
	float xOffset = 0, yOffset = 0;

	// Process keyboard movement input
	if (IsKeyDown(KEY_W))
	{
		yOffset -= 2;
	}	
	if (IsKeyDown(KEY_S))
	{
		yOffset += 2;
	}	
	if (IsKeyDown(KEY_A))
	{
		xOffset -= 2;
	}
	if (IsKeyDown(KEY_D))
	{
		xOffset += 2;
	}	

	// Update player position
	setPosition(Vector2{ getPosition().x + xOffset, getPosition().y + yOffset });
}