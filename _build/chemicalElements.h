#pragma once
#include "raylib.h"
#include <string>
#include <time.h> // rand, srand

struct Circle
{
	// circle center positon
	Vector2 centerPos;

	// circle radius
	float radius;
};

class ChemicalElement
{
private:
	Texture2D _texture;
	Vector2 _position;
	std::string _type;
	Circle _hitbox;

public:

	ChemicalElement(std::string texturePath, std::string type)
	{
		_texture = LoadTexture(texturePath.c_str());
		_position = { 0,0 };
		_type = type;
		_hitbox = { {0,0}, 50 };
	};

	// Getters
	Texture2D getTexture();

	Vector2	getPosition();

	std::string getType();

	Circle getHitbox();

	// Setters
	void setPosition(Vector2 position);

	void setHitbox(Circle hitbox);

	// Randomise position
	void randomisePosition();
};