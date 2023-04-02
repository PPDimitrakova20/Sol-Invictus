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
	/**
	 * Constructor.
	 * 
	 * \param texturePath
	 * \param type
	 * \return 
	 */
	ChemicalElement(std::string texturePath, short int type);

	/**
	 * Getters.
	 * 
	 * \return 
	 */
	Texture2D getTexture();

	/**
	 * Get position.
	 * 
	 * \return 
	 */
	Vector2	getPosition();

	/**
	 * Get type.
	 * 
	 * \return 
	 */
	short int getType();

	// Setters
	/**
	 * Set the position.
	 * 
	 * \param position
	 */
	void setPosition(Vector2 position);

	/**
	 * Randomise position.
	 * 
	 */
	void randomisePosition();

	/**
	 * Check player collision with a chemical element.
	 * 
	 * \param player
	 * \param itemQuantity
	 */
	void checkPlayerCollision(Player* player, short int* itemQuantity);
};