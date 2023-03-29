#include "player.h"

// Setters
// Set player position
void Player::setPosition(Vector2 position)
{
	_position = position;
}

// Getters
// Get player texture
Texture2D Player::getPlayerTexture()
{
	return _texture;
}

// Get underglow texture
Texture2D Player::getUnderglowTexture()
{
	return _underglow;
}

// Get player position
Vector2 Player::getPosition()
{
	return _position;
}

// Get player rotation
float Player::getRotation()
{
	return _rotation;
}

// Methods  
// Move the player
void Player::move(Vector2 position)
{
	// Intialize X and Y offset
	float xOffset = 0, yOffset = 0;

	// Process keyboard movement input
	if (IsKeyDown(KEY_W))
	{
		yOffset -= 5;
	}	
	if (IsKeyDown(KEY_S))
	{
		yOffset += 5;
	}	
	if (IsKeyDown(KEY_A))
	{
		xOffset -= 5;
	}
	if (IsKeyDown(KEY_D))
	{
		xOffset += 5;
	}	

	// Update player position
	setPosition(Vector2{ getPosition().x + xOffset, getPosition().y + yOffset });
}

// Check and handle collision with the map boundary
void Player::checkMapBoundary(Rectangle boundaries[4])
{
	if (CheckCollisionCircleRec(_position, 93, boundaries[0]))
	{
		_position.x += 5;
	}
	if (CheckCollisionCircleRec(_position, 93, boundaries[1]))
	{
		_position.x -= 5;
	}
	if (CheckCollisionCircleRec(_position, 93, boundaries[2]))
	{
		_position.y += 5;
	}
	if (CheckCollisionCircleRec(_position, 93, boundaries[3]))
	{
		_position.y -= 5;
	}
}

void Player::roatePlayer()
{
	if (IsKeyDown(KEY_W))
	{
		_rotation = 0;
	}

	if (IsKeyDown(KEY_S))
	{
		_rotation = 180;
	}

	if (IsKeyDown(KEY_D))
	{
		_rotation = 90;
		if (IsKeyDown(KEY_W))
			_rotation = 45;
		if (IsKeyDown(KEY_S))
			_rotation = 135;
	}

	if (IsKeyDown(KEY_A))
	{
		_rotation = 270;
		if (IsKeyDown(KEY_S))
			_rotation = 225;
		if (IsKeyDown(KEY_W))
			_rotation = 315;
	}
}