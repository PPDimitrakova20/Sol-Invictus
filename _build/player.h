#pragma once
#include "raylib.h"

// Player class
class Player
{
private:
	Texture2D _texture = LoadTexture("./../assets/player/player.png");
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
	Texture2D getTexture();
	Vector2 getPosition();

	// Methods
	void Move(Vector2 position);
};
