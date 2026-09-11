#include "game/Player.h"
#include "core/Input.h"
#include "core/Renderer.h"

#include <SDL3/SDL.h>

#include "core/GameConfig.h"

void Player_Init(Player *player, const Road *road)
{
    player->width = 100.0f;
    player->height = 50.0f;

    player->speed = GAME_BASE_SPEED;

    /* Start in the middle lane */
    player->x =
        road->x +
        (road->width - player->width) / 2.0f;

    /* Start near the bottom of the road */
    player->y =
        road->y +
        road->height -
        player->height -
        50.0f;
}

void Player_Update(
    Player *player,
    const Road *road,
    float delta_time
)
{
    float movement = player->speed * delta_time;

    /* Move up */
    if (Input_IsKeyDown(SDL_SCANCODE_W) ||
        Input_IsKeyDown(SDL_SCANCODE_UP))
    {
        player->y -= movement;
    }

    /* Move down */
    if (Input_IsKeyDown(SDL_SCANCODE_S) ||
        Input_IsKeyDown(SDL_SCANCODE_DOWN))
    {
        player->y += movement;
    }

    /* Move left */
    if (Input_IsKeyDown(SDL_SCANCODE_A) ||
        Input_IsKeyDown(SDL_SCANCODE_LEFT))
    {
        player->x -= movement;
    }

    /* Move right */
    if (Input_IsKeyDown(SDL_SCANCODE_D) ||
        Input_IsKeyDown(SDL_SCANCODE_RIGHT))
    {
        player->x += movement;
    }

    /* Left boundary */
    if (player->x < road->x)
    {
        player->x = road->x;
    }

    /* Right boundary */
    if (player->x + player->width >
        road->x + road->width)
    {
        player->x =
            road->x + road->width - player->width;
    }

    /* Top boundary */
    if (player->y < road->y)
    {
        player->y = road->y;
    }

    /* Bottom boundary */
    if (player->y + player->height >
        road->y + road->height)
    {
        player->y =
            road->y + road->height - player->height;
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
