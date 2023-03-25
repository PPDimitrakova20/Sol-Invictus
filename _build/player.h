#pragma once
#include "raylib.h"

// Player class
class Player
{
private:
	Texture2D _texture = LoadTexture("./../assets/player/player.png");
	Texture2D _underglow = LoadTexture("./../assets/player/playerUnderglow.png");
	Vector2 _position = {960, 540};

	// Constructor
	Player() {};

public:
	// Singleton instantiating
	static Player* getinstance()
	{
		static Player* s = new Player();
		return s;
	}

	Player(Player& s) = delete;
	void operator=(Player& s) = delete;

	// Setters
	void setPosition(Vector2 position);

	// Getters
	// Get player texture
	Texture2D getPlayerTexture();
	
	// Get underglowtexture
	Texture2D getUnderglowTexture();
	
	// Get player position
	Vector2 getPosition();

	// Methods
	// Plater movement
	void move(Vector2 position);

	// Check and handle collision with the map boundary
	void checkMapBoundary(Rectangle boundaries[4]);
};
