#include <iostream>﻿
#include "raylib.h"
#include "Game.h"

using namespace std;
int main()
{
    const int screenWidth = GetMonitorWidth(GetCurrentMonitor());
    const int screenHeight = GetMonitorHeight(GetCurrentMonitor());
    InitWindow(screenWidth, screenHeight, "game");

    Texture2D texture = LoadTexture("C:/Users/max_L/Downloads/hqdefault.jpg");
    ToggleFullscreen();
    SetTargetFPS(60);
    Game game;
    DisableCursor();
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        game.Update();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}