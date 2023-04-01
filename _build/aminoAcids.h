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
	void CraftingRecipe::updateInventoryElementsCount(short int* itemQuantity, std::vector<CraftingRecipe> recipeList, short int craftingBenchX);

	// Sort crafting recipes vector
	std::vector<CraftingRecipe> sortCraftingRecipes(std::vector<CraftingRecipe> craftingRecipes);
};