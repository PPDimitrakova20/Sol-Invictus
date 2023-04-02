#include <cmath>
#include <string>
#include "activeTextAndObjects.h"
#include "animations.h"

// Get inventory text x position
float GetInventoryTextX(int n, int caller)
{
	switch (n)
	{
	case 0:
		if (caller == 1)
		{
			return 0;
		}
		else
		{
			return 2;
		}
	case 1:
		return 3;
	case 11:
		return -3;
	case 20:
		return -7;
	case 2:	case 3:	case 4: case 5: case 6: case 7: case 8: case 9:
		return 1;
	case 10: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
		return -5;
	default:
		return -5;
	}
}

// Draw inventory quantity indicators
void drawInventoryQuantityIndicators(Font font, short int itemQuantity[6], Color colors[6])
{
	// Define relative rectangle portion
	float quantityBar = 0;

	for (int i = 0; i < 6; i++)
	{
		// Draw quantity bars 
		if (itemQuantity[i] == 0)
		{
			DrawRectangle(1848, 152 + i * 150, 55, 1, colors[i]);
		}
		else
		{
			quantityBar = float(itemQuantity[i] * 2.55);
			DrawRectangle(1847, (153 + i * 150) - int(quantityBar), 55, int(ceil(quantityBar)), colors[i]);
		}

		// Draw quantity number
		DrawTextEx(font, TextFormat("%i", itemQuantity[i]), Vector2{ 1868 + GetInventoryTextX(itemQuantity[i], 1), float(114 + 150 * i) }, 30, 1, WHITE);
	}
}

// Draw taskbar quantity indicators
void drawTaskbarQuantityIndicators(Font items, AminoAcid* activeAcid, short int itemQuantity[6], short int base, Color colors[6])
{
	// Define relative quantity bar portion
	float quantityBar = 0;

	// Define local chemical element quantity
	short int activeItemQuantity[5] = { 0,0,0,0,0 };

	// Update local chemical element quantity
	for (int i = 0; i < 4; i++)
	{
		activeItemQuantity[i] = itemQuantity[i];

		// Check for relevant boundaries
		if (activeItemQuantity[i] >= activeAcid->getChemicalMakeup()[i])
		{
			activeItemQuantity[i] = activeAcid->getChemicalMakeup()[i];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		// Draw quantity bars
		if (itemQuantity[i] == 0)
		{
			DrawRectangle(968 + 128 * i, 67 + base, 55, 2, colors[i]);
		}
		else if (itemQuantity[i] >= activeAcid->getChemicalMakeup()[i])
		{
			// It's a feature now :D
			DrawRectangle(968 + 128 * i, 17, 55, 56 + base, colors[i]);
		}
		else
		{
			quantityBar = float(itemQuantity[i] * (51 / activeAcid->getChemicalMakeup()[i]));
			DrawRectangle(968 + 128 * i, 68 - int(quantityBar), 55, base + int(ceil(quantityBar)) + 1, colors[i]);
		}

		// Draw quantity number
		DrawTextEx(items, TextFormat("%i", activeItemQuantity[i]), Vector2{ (987 + 128 * i) + GetInventoryTextX(activeItemQuantity[i], 2), float(32 + base) }, 30, 1, WHITE);
	}
}

// Draw active amino-acid name
void drawTaskbarHeading(Font heading, AminoAcid* activeAcid, short int base)
{
	DrawTextEx(heading, TextFormat("%s", activeAcid->getName().c_str()), Vector2{ 558, float(25 + base) }, 40, 1, WHITE);
}

// Draw sulfur and selenium task targets
void drawExtraTaskTarget(Font item, AminoAcid* activeAcid, short int itemQuantity[6], short int base, Texture2D extraTaskTargets[2], Color color, Color gradientSelection[6])
{
	// Check if the amino-acid contains sulfur or selenium
	if (activeAcid->getChemicalMakeup().size() > 4)
	{
		// Draw extra task targets for amino-acids containing sulfur
		if (activeAcid->getName() == "Methionine" || activeAcid->getName() == "Cysteine")
		{
			// Draw sulfur task target base
			DrawRectangle(1412, base + 1, 125, 85, color);

			// Draw quantity indicators
			if (itemQuantity[4] > 0) // Full indicator varient
			{
				DrawRectangleGradientV(1480, 17, 51, 52 + base, gradientSelection[3], gradientSelection[4]);
				DrawTextEx(item, TextFormat("%i", 1), { 1499, float(30 + base) }, 30, 1, WHITE);
			}
			else // Empty indicator varient
			{
				DrawRectangleGradientH(1480, 68 + base, 51, 1, gradientSelection[3], gradientSelection[4]);
				DrawTextEx(item, TextFormat("%i", 0), { 1499, float(30 + base) }, 30, 1, WHITE);
			}

			// Draw sulfur task target cover
			DrawTexture(extraTaskTargets[0], 1412, base + 1, RAYWHITE);
		}
		else // Draw extra task targets for amino-acids containing selenium
		{
			// Draw selenium task target base
			DrawRectangle(1412, base + 1, 146, 85, color);

			// Draw quantity indicators
			if (itemQuantity[5] > 0) // Full indicator varient
			{
				DrawRectangleGradientV(1503, 17, 51, 52 + base, gradientSelection[5], gradientSelection[1]);
				DrawTextEx(item, TextFormat("%i", 1), { 1522, float(30 + base) }, 30, 1, WHITE);
			}
			else // Empty indicator varient
			{
				DrawRectangleGradientH(1503, 68 + base, 51, 1, gradientSelection[5], gradientSelection[1]);
				DrawTextEx(item, TextFormat("%i", 0), { 1522, float(30 + base) }, 30, 1, WHITE);
			}

			// Draw selenium task target cover
			DrawTexture(extraTaskTargets[1], 1412, base + 1, RAYWHITE);
		}
	}
}

// Draw crafting recipes
void drawCraftingRecipes(Font craftingBenchFonts[3], Texture2D craftingRecipeBases[3], std::vector<CraftingRecipe> craftingRecipes, short int baseX, short int baseY)
{
	for (short int i = 0; i < craftingRecipes.size(); i++)
	{
		// Draw recipe base
		DrawTexture(craftingRecipeBases[craftingRecipes[i].getStatus()], baseX + 45, baseY + i * 168, RAYWHITE);

		// Draw recipe number
		DrawTextEx(craftingBenchFonts[0], TextFormat("#%i", i + 1), { float(baseX + 56), float(baseY + 9 + i * 168) }, 20, 1, WHITE);

		// Draw recipe product name
		DrawTextEx(craftingBenchFonts[1], TextFormat("%s", craftingRecipes[i].getName().c_str()), { float(baseX + 56), float(baseY+ 51 + i * 168) }, 30, float(0.15), WHITE);

		// Draw recipe requirement text
		if (craftingRecipes[i].getName() == "Methionine" || craftingRecipes[i].getName() == "Cysteine")
		{
			DrawTextEx(craftingBenchFonts[2], TextFormat("Requirements: %i carbon, %i hydrogen, %i nitrogen,", craftingRecipes[i].getChemicalMakeup()[0], craftingRecipes[i].getChemicalMakeup()[1], craftingRecipes[i].getChemicalMakeup()[2]), { float(baseX + 56), float(baseY + 95 + i * 168) }, 15, float(0.15), WHITE);
			DrawTextEx(craftingBenchFonts[2], TextFormat("%i oxygen and 1 sulfur", craftingRecipes[i].getChemicalMakeup()[3]), { float(baseX + 56), float(baseY + 111 + i * 168) }, 15, float(0.15), WHITE);
		}
		else if (craftingRecipes[i].getName() == "Selenocysteine")
		{
			DrawTextEx(craftingBenchFonts[2], TextFormat("Requirements: %i carbon, %i hydrogen, %i nitrogen,", craftingRecipes[i].getChemicalMakeup()[0], craftingRecipes[i].getChemicalMakeup()[1], craftingRecipes[i].getChemicalMakeup()[2]), { float(baseX + 56), float(baseY + 95 + i * 168) }, 15, float(0.15), WHITE);
			DrawTextEx(craftingBenchFonts[2], TextFormat("%i oxygen and 1 selenium", craftingRecipes[i].getChemicalMakeup()[3]), { float(baseX + 56), float(baseY + 111 + i * 168) }, 15, float(0.15), WHITE);
		}
		else
		{
			DrawTextEx(craftingBenchFonts[2], TextFormat("Requirements: %i carbon, %i hydrogen, %i nitrogen", craftingRecipes[i].getChemicalMakeup()[0], craftingRecipes[i].getChemicalMakeup()[1], craftingRecipes[i].getChemicalMakeup()[2]), { float(baseX + 56), float(baseY + 95 + i * 168) }, 15, float(0.15), WHITE);
			DrawTextEx(craftingBenchFonts[2], TextFormat("and %i oxygen", craftingRecipes[i].getChemicalMakeup()[3]), { float(baseX + 56), float(baseY + 111 + i * 168) }, 15, float(0.15), WHITE);
		}
	}
}