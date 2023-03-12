#pragma once
void checkForMovement(int &posX, int &posY)
{
	if (IsKeyDown(KEY_S))
		posY += 1;
	if (IsKeyDown(KEY_W))
		posY -= 1;
	if (IsKeyDown(KEY_D))
		posX += 1;
	if (IsKeyDown(KEY_A))
		posX -= 1;
}