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
void CraftingRecipe::updateInventoryElementsCount(short int* itemQuantity, std::vector<CraftingRecipe> recipeList, short int craftingBenchX, bool* autoCloseCraftingBenchPtr)
{
	if (craftingBenchX == 1401)
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

				*autoCloseCraftingBenchPtr = true;
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
std::vector<CraftingRecipe> CraftingRecipe::sortCraftingRecipes(std::vector<CraftingRecipe> craftingRecipes, short int baseY)
{
	// Sort the crafting recipes vector in a increasing manner based on recipes status
	sort(craftingRecipes.begin(), craftingRecipes.end(), compareCraftingRecipes);

	// Update the recipes hitbox to suit the vector's new arrangement
	for (short int i = 0; i < craftingRecipes.size(); i++)
	{
		craftingRecipes[i].setHitbox(Rectangle{ 1446,float(baseY + i * 168),355,134 });
	}

	return craftingRecipes;
}

// Barrier class methods
// Default constructor
Barrier::Barrier()
{
	_x = 0;
	_bottomScrollBoundary = 0;
	_topScrollBoundary = 0;
}

// Parameterized constructor
Barrier::Barrier(short int x, short int y, short int boundary, Texture2D texture)
{
	_x = x;
	_bottomScrollBoundary = y;
	_topScrollBoundary = boundary;
	_texture = texture;
};

// Getters
// Get barrier X coordinate
short int Barrier::getX()
{
	return _x;
}

// Get barrier scroll boundary
short int Barrier::getTopScrollBoundary()
{
	return _topScrollBoundary;
}

// Get barrier scroll Y coordinate
short int Barrier::getBottomScrollBoundary()
{
	return _bottomScrollBoundary;
}

// Get barrier texture
Texture2D Barrier::getTexture()
{
	return _texture;
}

//Setters
// Set barrier X coordinate
void Barrier::setX(short int x)
{
	_x = x;
}

// Initialize barriers
Barrier* Barrier::initBarriers(Texture2D textures[5])
{
	Barrier* barriers = new Barrier[21];
	barriers[0] = { 37,  976, -1136, textures[1] }; // Histidine
	barriers[1] = { 214, 1593, -519, textures[0] }; // Isoleucine
	barriers[2] = { 37,  2124, 12,   textures[0] }; // Leucine
	barriers[3] = { 214, 2478, 366,  textures[0] }; // Lysine
	barriers[4] = { 37,  447, -1666, textures[0] }; // Methonine
	barriers[5] = { 214, 1239, -873, textures[0] }; // Phenylalanine
	barriers[6] = { 303, 976, -1136, textures[1] }; // Threonine
	barriers[7] = { 37,  180, -1932, textures[1] }; // Tryptophan
	barriers[8] = { 303, 180, -1932, textures[1] }; // Valine
	barriers[9] = { 389, 446, -1666, textures[4] }; // Arginine
	barriers[10] = { 390, 2124, 12,   textures[4] }; // Cysteine
	barriers[11] = { 37,  2478, 366,  textures[4] }; // Glutamine
	barriers[12] = { 390, 2832, 720,  textures[4] }; // Glycine
	barriers[13] = { 37,  1416, -696, textures[4] }; // Proline
	barriers[14] = { 37,  1770, -342, textures[4] }; // Trosine
	barriers[15] = { 37,  800, -1312, textures[3] }; // Alanine
	barriers[16] = { 37,  2832, 720,  textures[2] }; // Aspartic acid
	barriers[17] = { 37,  3009, 897,  textures[2] }; // Asparagine
	barriers[18] = { 214, 800, -1312, textures[2] }; // Glutamic acid
	barriers[19] = { 37,  1239, -873, textures[3] }; // Serine
	barriers[20] = { 214, 1947, -165, textures[2] }; // Selenocysteine

	return barriers;
}