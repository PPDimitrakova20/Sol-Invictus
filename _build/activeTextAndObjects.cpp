#include <cmath>
#include "activeTextAndObjects.h"

// Get inventory text x position
float GetInventoryTextX(int n)
{
	switch (n)
	{
	case 0:
		return 1868;
	case 1:
		return 1871;
	case 11:
		return 1865;
	case 20:
		return 1861;
	case 2:	case 3:	case 4: case 5: case 6: case 7: case 8: case 9:
		return 1869;
	case 10: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
		return 1863;
	}
}

// Draw inventory items
void DrawInventoryItems(Font font, short int itemQuantity[6], Color color[6])
{
	float quantityBar = 0;

	for (int i = 0; i < 6; i++)
	{
		// Draw quantity bars
		if (itemQuantity[i] == 0)
		{
			DrawRectangle(1848, float(152 + i * 150), 55, 1, color[i]);
		}
		else
		{
			quantityBar = itemQuantity[i] * 2.55;
			DrawRectangle(1847, float((153 + i * 150) - quantityBar), 55, ceil(quantityBar), color[i]);
		}

		// Draw quantity number
		DrawTextEx(font, TextFormat("%i", itemQuantity[i]), Vector2{ GetInventoryTextX(itemQuantity[i]), float(114 + 150 * i)}, 30, 1, WHITE);
	}
}