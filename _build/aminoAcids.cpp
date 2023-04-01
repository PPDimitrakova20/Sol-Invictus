#include "aminoAcids.h"

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
	else if(rarity >= 7 && rarity <= 9)
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