#pragma once
#include "raylib.h"
#include "Player.h"
class Game
{
public:
	Player player;
	Camera2D camera;
	Game()
	{
		camera.target = { 0,0 };
		player.Load();
	}
	void Update()
	{
		player.Update();
	}
};