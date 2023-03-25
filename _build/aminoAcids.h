#pragma once
#include "raylib.h"
#include <vector>
#include <string>


class AminoAcid
{
private:

	// Class members
	std::string _name;
	std::vector<short int> _chemicalMakeup;
	bool _isDiscovered = false;

public:
	
	// Constructor
	
	AminoAcid() {};

	AminoAcid(std::string name, std::vector<short int> chemicalMakeup);

	// Getters
	std::string getName();
	
	std::vector<short int> getChemicalMakeup();
	
	bool getIsDiscovered();

	// Setters
	void setIsDiscovered(bool isDiscovered);

	AminoAcid* initAminoAcids();
};