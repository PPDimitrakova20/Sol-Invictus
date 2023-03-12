#pragma once
#include "raylib.h"
class Player
{
public:
	Texture2D texture = LoadTexture("./../assets/player/player.png");
	Vector2 position;
};