#include "game/Player.h"
#include "core/Input.h"
#include "core/Renderer.h"

#include <SDL3/SDL.h>

#define BOUNDARY_X 100.0f
#define BOUNDARY_Y 50.0f
#define BOUNDARY_WIDTH 1080.0f
#define BOUNDARY_HEIGHT 620.0f

void Player_Init(Player *player)
{
    player->x = 500.0f;
    player->y = 300.0f;

    player->width = 100.0f;
    player->height = 50.0f;

    player->speed = 300.0f;
}

void Player_Update(Player *player, float delta_time)
{
    float movement = player->speed * delta_time;

    if (Input_IsKeyDown(SDL_SCANCODE_W) ||
        Input_IsKeyDown(SDL_SCANCODE_UP))
    {
        player->y -= movement;
    }

    if (Input_IsKeyDown(SDL_SCANCODE_S) ||
        Input_IsKeyDown(SDL_SCANCODE_DOWN))
    {
        player->y += movement;
    }

    if (Input_IsKeyDown(SDL_SCANCODE_A) ||
        Input_IsKeyDown(SDL_SCANCODE_LEFT))
    {
        player->x -= movement;
    }

    if (Input_IsKeyDown(SDL_SCANCODE_D) ||
        Input_IsKeyDown(SDL_SCANCODE_RIGHT))
    {
        player->x += movement;
    }



    if (player->x < 0.0f)
    {
        player->x = 0.0f;
    }

    if (player->x + player->width > WINDOW_WIDTH)
    {
        player->x = WINDOW_WIDTH - player->width;
    }

    if (player->y < 0.0f)
    {
        player->y = 0.0f;
    }

    if (player->y + player->height > WINDOW_HEIGHT)
    {
        player->y = WINDOW_HEIGHT - player->height;
    }



}

void Player_Render(const Player *player)
{
    Renderer_DrawRect(
        player->x,
        player->y,
        player->width,
        player->height
    );
}
