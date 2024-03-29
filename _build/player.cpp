#include "player.h"

// Setters
/**
 * / Set player position.
 * 
 * \param position
 */
void Player::setPosition(Vector2 position)
{
	_position = position;
}

void Player::setPlayerTexture(Texture2D texture)
{
	_texture = texture;
}

// Getters
/**
 * / Get player texture.
 * 
 * \return 
 */
Texture2D Player::getPlayerTexture()
{
	return _texture;
}

/**
 * Get underglow texture.
 * 
 * \return 
 */
Texture2D Player::getUnderglowTexture()
{
	return _underglow;
}

/**
 * Get player position.
 * 
 * \return 
 */
Vector2 Player::getPosition()
{
	return _position;
}

/**
 * Get player rotation.
 * 
 * \return 
 */
float Player::getRotation()
{
	return _rotation;
}

// Methods  
/**
 * Move the player.
 * 
 * \param position
 */
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

/**
 * Checkand handle collision with the map boundary.
 * 
 * \param boundaries
 */
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

/**
 * Rotate the player.
 * 
 */
void Player::rotatePlayer()
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
		{
			_rotation = 45;
		}	
		if (IsKeyDown(KEY_S))
		{
			_rotation = 135;
		}	
	}

	if (IsKeyDown(KEY_A))
	{
		_rotation = 270;
		if (IsKeyDown(KEY_S))
		{
			_rotation = 225;
		}		
		if (IsKeyDown(KEY_W))
		{
			_rotation = 315;
		}		
	}
}

/**
 * Move boundary hitbox rectangle with player.
 * 
 */
void Player::updatePlayerBoundaryHitbox()
{
	_boundaryHitbox = { getPosition().x - 480, getPosition().y - 480, 1000, 1000 };
}

/**
 * Get boundary hitbox.
 * 
 * \return 
 */
Rectangle Player::getBoundaryHitbox()
{
	return _boundaryHitbox;
}

/**
 * Draw boundary when player is close to map border.
 * 
 * \param mapBoundary
 */
void Player::drawMapBoundary(Rectangle mapBoundary)
{
	if (CheckCollisionRecs(mapBoundary, _boundaryHitbox))
	{
		DrawRectangleRounded(GetCollisionRec(mapBoundary, _boundaryHitbox), 30, 1, { 142,9,238,255 });
	}
}