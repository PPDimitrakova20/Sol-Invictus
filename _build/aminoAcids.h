#pragma once
#include "raylib.h"
#include <vector>
#include <string>


class AminoAcid
{
private:
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