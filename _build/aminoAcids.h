#pragma once
#include "raylib.h"
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

class AminoAcid
{
protected:
	std::string _name;
	std::vector<short int> _chemicalMakeup;
	bool _isDiscovered = false;

public:

	// Constructors
	/**
	 * Default constructor.
	 */
	AminoAcid() {};

	/**
	 * Parameterized constructor.
	 * 
	 * \param name
	 * \param chemicalMakeup
	 * \return 
	 */
	AminoAcid(std::string name, std::vector<short int> chemicalMakeup);

	// Getters
	/**
	 * Get amino - acid name.
	 * 
	 * \return 
	 */
	std::string getName();

	/**
	 * Get amino - acid chemical makeup.
	 * 
	 * \return 
	 */
	std::vector<short int> getChemicalMakeup();

	/**
	 * Get amino - acid discovery status.
	 */
	bool getIsDiscovered();

	// Setters
	/**
	 * Set amino - acid discovery status.
	 * 
	 * \return 
	 */
	void setIsDiscovered(bool isDiscovered);

	// Methods
	/**
	 * Initialize amino - acids.
	 * 
	 * \return 
	 */
	AminoAcid* initAminoAcids();

	AminoAcid* randomiseAcid(AminoAcid* aminoAcids);
};

class CraftingRecipe : public AminoAcid
{
private:
	Rectangle _hitbox = { 0,0,0,0 };
	short int _status = 2;
	// 0 -> task required, 1 -> craftable, 2 -> insufficient materials

public:
	// Constructors
	/**
	 * Default constructor.
	 */
	CraftingRecipe() {};

	/**
	 * Parameterized constructor.
	 * 
	 * \param hitbox
	 * \param name
	 * \param chemicalMakeup
	 * \return 
	 */
	CraftingRecipe(Rectangle hitbox, std::string name, std::vector<short int> chemicalMakeup) : AminoAcid(name, chemicalMakeup)
	{
		_hitbox = hitbox;
	}

	// Getters
	/**
	 * Get crafting recipe hitbox.
	 * 
	 * \return 
	 */
	Rectangle getHitbox();

	/**
	 * Get crafting recipe status.
	 * 
	 * \return 
	 */
	short int getStatus();

	// Setters
	/**
	 * Set crafting recipe hitbox.
	 * 
	 * \param hitbox
	 */
	void setHitbox(Rectangle hitbox);

	// Methods
	/**
	 * Update the crafting recipes' status.
	 * 
	 * \param itemQuantity
	 * \param activeAcid
	 */
	void updateCraftingRecipeStatus(short int* itemQuantity, AminoAcid* activeAcid);

	/**
	 * Update inventory element count after crafting an amino - acid.
	 */
	void CraftingRecipe::updateInventoryElementsCount(short int* itemQuantity, std::vector<CraftingRecipe> recipeList, short int craftingBenchX, bool* autoCloseCraftingBenchPtr);

	/**
	 * Sort crafting recipes vector.
	 * 
	 * \param craftingRecipes
	 * \param baseY
	 * \return 
	 */
	std::vector<CraftingRecipe> sortCraftingRecipes(std::vector<CraftingRecipe> craftingRecipes, short int baseY);
};

class Barrier
{
private:
	short int _x;
	short int _topScrollBoundary;
	short int _bottomScrollBoundary;
	Texture2D _texture;

public:
	// Constructors
	/**
	 * Default constructor.
	 * 
	 * \return 
	 */
	Barrier();

	/**
	 * Parameterized constructor.
	 * 
	 * \param x
	 * \param y
	 * \param boundary
	 * \param texture
	 * \return 
	 */
	Barrier(short int x, short int y, short int boundary, Texture2D texture);

	// Getters
	/**
	 * Get barrier X coordinate.
	 * 
	 * \return 
	 */
	short int getX();

	/**
	 * Get barrier scroll boundary.
	 * 
	 * \return 
	 */
	short int getTopScrollBoundary();

	/**
	 * Get barrier scroll Y coordinate.
	 * 
	 * \return 
	 */
	short int getBottomScrollBoundary();

	/**
	 * Get barrier texture.
	 * 
	 * \return 
	 */
	Texture2D getTexture();

	// Setters
	/**
	 * Set barrier X coordinate.
	 * 
	 * \param x
	 */
	void setX(short int x);

	// Methods
	/**
	 * Initialize barriers.
	 * 
	 * \param barriers
	 * \return 
	 */
	Barrier* initBarriers(Texture2D barriers[5]);
};