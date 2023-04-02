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
	// Default constructor
	AminoAcid() {};

	// Parameterized constructor
	AminoAcid(std::string name, std::vector<short int> chemicalMakeup);

	// Getters
	// Get amino-acid name
	std::string getName();

	// Get amino-acid chemical makeup
	std::vector<short int> getChemicalMakeup();

	// Get amino-acid discovery status
	bool getIsDiscovered();

	// Setters
	// Set amino-acid discovery status
	void setIsDiscovered(bool isDiscovered);

	// Methods
	// Initialize amino-acids
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
	// Default constructor
	CraftingRecipe() {};

	// Parameterized constructor
	CraftingRecipe(Rectangle hitbox, std::string name, std::vector<short int> chemicalMakeup) : AminoAcid(name, chemicalMakeup)
	{
		_hitbox = hitbox;
	}

	// Getters
	// Get crafting recipe hitbox
	Rectangle getHitbox();

	// Get crafting recipe status
	short int getStatus();

	// Setters
	// Set crafting recipe hitbox
	void setHitbox(Rectangle hitbox);

	// Methods
	// Update the crafting recipes' status
	void updateCraftingRecipeStatus(short int* itemQuantity, AminoAcid* activeAcid);

	// Update inventory element count after crafting an amino-acid
	void CraftingRecipe::updateInventoryElementsCount(short int* itemQuantity, std::vector<CraftingRecipe> recipeList, short int craftingBenchX, bool* autoCloseCraftingBenchPtr);

	// Sort crafting recipes vector
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
	/// Constructors
	// Default constructor
	Barrier();

	// Parameterized constructor
	Barrier(short int x, short int y, short int boundary, Texture2D texture);

	// Getters
	// Get barrier X coordinate
	short int getX();

	// Get barrier scroll boundary
	short int getTopScrollBoundary();

	// Get barrier scroll Y coordinate
	short int getBottomScrollBoundary();

	// Get barrier texture
	Texture2D getTexture();

	// Setters
	//Set barrier X coordinate
	void setX(short int x);

	// Methods
	// Initialize barriers
	Barrier* initBarriers(Texture2D barriers[5]);
};