#pragma once
#include "raylib.h"

/**
 * Player class.
 */
class Player
{
private:
	Texture2D _texture;
	Texture2D _underglow = LoadTexture("./../assets/player/playerUnderglow.png");
	Vector2 _position = {960, 540};
	float _rotation = 0;
	Rectangle _boundaryHitbox = { _position.x, _position.y, 300, 300 };

	/**
	 * Constructor.
	 */
	Player() {};

public:
	/**
	 * Singleton instantiating.
	 */
	static Player* getinstance()
	{
		static Player* s = new Player();
		return s;
	}

	/**
	 * Override the = operator.
	 */
	Player(Player& s) = delete;
	void operator=(Player& s) = delete;

	// Setters
	/**
	 * Set the position.
	 */
	void setPosition(Vector2 position);

	/**
	 * Set the texture.
	 */
	void setPlayerTexture(Texture2D texture);

	// Getters
	/**
	 * Get player texture.
	 */
	Texture2D getPlayerTexture();

	/**
	 * Get underglow texture.
	 */
	Texture2D getUnderglowTexture();

	/**
	 * Get player position.
	 * 
	 */
	Vector2 getPosition();

	/**
	 * Get boundary hitbox.
	 */
	Rectangle getBoundaryHitbox();

	/**
	 * Get player rotation.
	 */
	float getRotation();

	/**
	 * Plater movement.
	 */
	void move(Vector2 position);

	/**
	 * Checkand handle collision with the map boundary.
	 */
	void checkMapBoundary(Rectangle boundaries[4]);

	/**
	 * Rotate player.
	 */
	void rotatePlayer();

	/**
	 * Move boundary hitbox rectangle with player.
	 */
	void updatePlayerBoundaryHitbox();

	/**
	 * Draw boundary when player is close to map border.
	 */
	void drawMapBoundary(Rectangle mapBoundary);
};