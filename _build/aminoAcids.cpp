#include "aminoAcids.h"
#include <vector>

// Constructor
AminoAcid::AminoAcid(std::string name, std::vector<short int> chemicalMakeup)
{
	_name = name;
	_chemicalMakeup = chemicalMakeup;
}

// Getters
// Get amino-acid name
std::string AminoAcid::getName()
{
	return _name;
}

// Get amino-acid chemical makeup
std::vector<short int> AminoAcid::getChemicalMakeup()
{
	return _chemicalMakeup;
}

// Get amino-acid discovery status
bool AminoAcid::getIsDiscovered()
{
	return _isDiscovered;
}

// Setters
// Set amino-acid discovery status
void AminoAcid::setIsDiscovered(bool isDiscovered)
{
	_isDiscovered = isDiscovered;
}



// Methods
// Initialize amino-acids
AminoAcid* AminoAcid::initAminoAcids()
{
	AminoAcid* aminoAcids = new AminoAcid[21];
	aminoAcids[0] = { "Histidine",		 {6, 9, 3, 2} };
	aminoAcids[1] = { "Isoleucine",	     {6, 13, 1 ,2} };
	aminoAcids[2] = { "Leucine",		 {6, 13, 1, 2} };
	aminoAcids[3] = { "Lysine",		     {6, 14, 2, 2} };
	aminoAcids[4] = { "Methionine",	     {5, 11, 1, 2, 1} };
	aminoAcids[5] = { "Phenylalanine",   {9, 11, 1, 2} };
	aminoAcids[6] = { "Threonine",		 {4, 9, 1, 3} };
	aminoAcids[7] = { "Tryptophan",	     {11, 12, 2, 2} };
	aminoAcids[8] = { "Valine",		     {5, 11, 1, 2} };
	aminoAcids[9] = { "Arginine",		 {6, 14, 4, 2} };
	aminoAcids[10] = { "Cysteine",		 {3, 7, 1, 2, 1} };
	aminoAcids[11] = { "Glutamine",		 {5, 10, 2, 3} };
	aminoAcids[12] = { "Glycine",		 {2, 5, 1, 2} };
	aminoAcids[13] = { "Proline",		 {5, 9, 1, 2} };
	aminoAcids[14] = { "Tyrosine",		 {9, 11, 1, 3} };
	aminoAcids[15] = { "Alanine",		 {3, 7, 1, 2} };
	aminoAcids[16] = { "Aspartic acid",  {4, 7, 1, 4} };
	aminoAcids[17] = { "Asparagine",	 {4, 8, 2, 3} };
	aminoAcids[18] = { "Glutamic acid",  {5, 9, 1, 4} };
	aminoAcids[19] = { "Serine",		 {3, 7, 1, 3} };
	aminoAcids[20] = { "Selenocysteine", {3, 7, 1, 2, 1} };

	return aminoAcids;
}

// Return a random acid
AminoAcid* AminoAcid::randomiseAcid(AminoAcid* aminoAcids)
{
	// Define a rarity
	short int rarity = GetRandomValue(1, 10);

	// Define an active acid
	AminoAcid* activeAcid = new AminoAcid;

	// Check rarity
	// 6/10 chance
	if (rarity >= 1 && rarity <= 6)
	{
		*activeAcid = aminoAcids[GetRandomValue(0, 8)];
	}
	// 3/10 chance
	else if (rarity >= 7 && rarity <= 9)
	{
		*activeAcid = aminoAcids[GetRandomValue(9, 14)];
	}
	// 1/10 chance
	else
	{
		*activeAcid = aminoAcids[GetRandomValue(15, 20)];
	}

	return activeAcid;
}

// Get crafting recipe hitbox
Rectangle CraftingRecipe::getHitbox()
{
	return _hitbox;
}

// Get crafting recipe status
short int CraftingRecipe::getStatus()
{
	return _status;
}

// Set crafting recipe hitbox
void CraftingRecipe::setHitbox(Rectangle hitbox)
{
	_hitbox = hitbox;
}

// Update the crafting recipes' status
void CraftingRecipe::updateCraftingRecipeStatus(short int* itemQuantity, AminoAcid* activeAcid)
{
	if (_name == activeAcid->getName())
	{
		_status = 0;
	}
	else
	{
		if (_name != "Selenocysteine")
		{
			for (int i = 0; i < _chemicalMakeup.size(); i++)
			{
				if (_chemicalMakeup[i] > itemQuantity[i])
				{
					_status = 2;
					break;
				}
				else
				{
					_status = 1;
				}
			}
		}
		else
		{
			for (int i = 0; i < _chemicalMakeup.size(); i++)
			{
				if (i != _chemicalMakeup.size() - 1)
				{
					if (_chemicalMakeup[i] > itemQuantity[i])
					{
						_status = 2;
						break;
					}
					else
					{
						_status = 1;
					}
				}
				else
				{
					if (_chemicalMakeup[4] > itemQuantity[5])
					{
						_status = 2;
					}
					else
					{
						_status = 1;
					}
				}
			}
		}
	}
}

// Check if a crafting recipe has been completed
bool isRecipeComplete(short int* itemQuantity, CraftingRecipe recipe)
{
	bool check = false;

	if (recipe.getName() != "Selenocysteine")
	{
		for (int i = 0; i < recipe.getChemicalMakeup().size(); i++)
		{
			if (recipe.getChemicalMakeup()[i] > itemQuantity[i])
			{
				check = false;
				break;
			}
			else
			{
				check = true;
			}
		}
	}
	else
	{
		for (int i = 0; i < recipe.getChemicalMakeup().size(); i++)
		{
			if (i != recipe.getChemicalMakeup().size() - 1)
			{
				if (recipe.getChemicalMakeup()[i] > itemQuantity[i])
				{
					check = false;
					break;
				}
				else
				{
					check = true;
				}
			}
			else
			{
				if (recipe.getChemicalMakeup()[4] > itemQuantity[5])
				{
					check = false;
					break;
				}
				else
				{
					check = true;
				}
			}
		}
	}

	return check;
}

// Update inventory element count after crafting an amino-acid
void CraftingRecipe::updateInventoryElementsCount(short int* itemQuantity, std::vector<CraftingRecipe> recipeList)
{
	for (short int i = 0; i < recipeList.size(); i++)
	{

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
			CheckCollisionPointRec(GetMousePosition(), recipeList[i].getHitbox()) &&
			(recipeList[i].getStatus() == 1 || isRecipeComplete(itemQuantity, recipeList[i])))
		{
			if (recipeList[i].getName() != "Selenocysteine")
			{
				for (int j = 0; j < recipeList[i].getChemicalMakeup().size(); j++)
				{
					itemQuantity[j] -= recipeList[i].getChemicalMakeup()[j];
				}
			}
			else
			{
				for (int j = 0; j < recipeList[i].getChemicalMakeup().size(); j++)
				{
					if (j != recipeList[i].getChemicalMakeup().size() - 1)
					{
						itemQuantity[j] -= recipeList[i].getChemicalMakeup()[j];
					}
					else
					{
						itemQuantity[j + 1] -= recipeList[i].getChemicalMakeup()[j];
					}
				}
			}
		}
	}

}

// Get the difference between the target class members
bool compareCraftingRecipes(CraftingRecipe i1, CraftingRecipe i2)
{
	return(i1.getStatus() < i2.getStatus());
}

// Sort crafting recipes vector
std::vector<CraftingRecipe> CraftingRecipe::sortCraftingRecipes(std::vector<CraftingRecipe> craftingRecipes)
{
	// Sort the crafting recipes vector in a increasing manner based on recipes status
	sort(craftingRecipes.begin(), craftingRecipes.end(), compareCraftingRecipes);

	// Update the recipes hitbox to suit the vector's new arrangement
	for (short int i = 0; i < craftingRecipes.size(); i++)
	{
		craftingRecipes[i].setHitbox(Rectangle{ 1446,float(155 + i * 168),355,134 });
	}

	return craftingRecipes;
}