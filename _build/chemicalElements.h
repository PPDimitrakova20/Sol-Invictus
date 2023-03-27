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
	std::string _type;

public:
	// Constructor
	ChemicalElement(std::string texturePath, std::string type);

	// Getters
	Texture2D getTexture();

	// Get position
	Vector2	getPosition();

	// Get type
	std::string getType();

	// Setters
	void setPosition(Vector2 position);

	// Randomise position
	void randomisePosition();

	// Check player collision with a chemical element
	void checkPlayerCollision(Player* player, short int* itemQuantity);
};