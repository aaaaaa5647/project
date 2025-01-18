#pragma once
#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <string>

using namespace std;
class Player
{
public:
    Vector2 position;
    Vector2 direction;
    Texture2D texture_stand_left;
    Texture2D texture_stand_back;
    Texture2D texture_stand_right;
    Texture2D texture_stand_front;
    Texture2D current_texture;
    vector <Texture2D> texture_move_left;
    vector <Texture2D> texture_move_back;
    vector <Texture2D> texture_move_right;
    vector <Texture2D> texture_move_front;
    bool moved;
    int speed;
    Player()
    {
        position = { 500,500 };
        direction = { 0, 0 };
        speed = 7;
    }
    void Load()
    {
        texture_stand_left = LoadTexture("player_stand_left.png");
        texture_stand_back = LoadTexture("player_stand_back.png");
        texture_stand_right = LoadTexture("player_stand_right.png");
        texture_stand_front = LoadTexture("player_stand_front.png");
        current_texture = texture_stand_right;
        string code1 = "player_walk_left";
        string code2 = "player_walk_back";
        string code3 = "player_walk_right";
        string code4 = "player_walk_front";
        for (int i = 0; i <= 5; i++)
        {
            texture_move_left.push_back(LoadTexture((code1 + to_string(i) + ".png").c_str()));
            texture_move_back.push_back(LoadTexture((code2 + to_string(i) + ".png").c_str()));
            texture_move_right.push_back(LoadTexture((code3 + to_string(i) + ".png").c_str()));
            texture_move_front.push_back(LoadTexture((code4 + to_string(i) + ".png").c_str()));
        }
    }
    void Update()
    {
        if (IsKeyDown(KEY_A))
        {
            direction.x = -1;
            current_texture = texture_stand_left;
        }
        if (IsKeyDown(KEY_W))
        {
            direction.y = -1;
            current_texture = texture_stand_back;
        }
        if (IsKeyDown(KEY_D))
        {
            direction.x = 1;
            current_texture = texture_stand_right;
        }
        if (IsKeyDown(KEY_S))
        {
            direction.y = 1;
            current_texture = texture_stand_front;
        }

        direction = Vector2Normalize(direction);
        position.x += direction.x * speed;
        position.y += direction.y * speed;
        direction = Vector2{ 0,0 };
        DrawTexture(current_texture, position.x, position.y, WHITE);
    }
};
