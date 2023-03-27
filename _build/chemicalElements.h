#pragma once
#include "raylib.h"
#include "player.h"
#include <string>
#include <vector>

class ChemicalElement
{
private:
	Texture2D _texture;
	Vector2 _position;
	short int _type;

public:
	// Constructor
	ChemicalElement(std::string texturePath, short int type);

	// Getters
	Texture2D getTexture();

	// Get position
	Vector2	getPosition();

	// Get type
	short int getType();

	// Setters
	void setPosition(Vector2 position);

	// Randomise position
	void randomisePosition();

	// Check player collision with a chemical element
	void checkPlayerCollision(Player* player, short int* itemQuantity);
};