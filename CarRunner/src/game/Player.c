#include "game/Player.h"
#include "core/Input.h"
#include "core/Renderer.h"
#include "core/GameConfig.h"

#include <SDL3/SDL.h>

#define LANE_SWITCH_SPEED 800.0f

void Player_Init(Player *player, const Road *road)
{
    float lane_width =
        road->width / road->lane_count;

    player->width =
        lane_width * 0.35f;

    player->height =
        player->width * 0.5f;

    player->speed =
        GAME_BASE_SPEED;

    /* Start in center lane */
    player->lane =
        road->lane_count / 2;

    player->target_lane =
        player->lane;

    /* Center player in starting lane */
    player->x =
        road->x +
        (player->lane * lane_width) +
        (lane_width - player->width) / 2.0f;

    /* Start near bottom of road */
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

    float vertical_movement =
    PLAYER_VERTICAL_SPEED * delta_time;

/* Accelerate */
if (Input_IsKeyDown(SDL_SCANCODE_W) ||
    Input_IsKeyDown(SDL_SCANCODE_UP))
{
    player->speed +=
        GAME_ACCELERATION * delta_time
;
    player->y -= vertical_movement;
}

/* Brake / slow down */
if (Input_IsKeyDown(SDL_SCANCODE_S) ||
    Input_IsKeyDown(SDL_SCANCODE_DOWN))
{
    player->speed -=
        GAME_BRAKE * delta_time;

    player->y += vertical_movement;

}


    /* =========================================
       W / UP - Move forward
       ========================================= */

    if (Input_IsKeyDown(SDL_SCANCODE_W) ||
        Input_IsKeyDown(SDL_SCANCODE_UP))
    {
        player->y -= vertical_movement;
    }


    /* =========================================
       S / DOWN - Move backward
       ========================================= */

    if (Input_IsKeyDown(SDL_SCANCODE_S) ||
        Input_IsKeyDown(SDL_SCANCODE_DOWN))
    {
        player->y += vertical_movement;
    }


/* Keep speed within limits */
if (player->speed > GAME_MAX_SPEED)
{
    player->speed = GAME_MAX_SPEED;
}

if (player->speed < GAME_MIN_SPEED)
{
    player->speed = GAME_MIN_SPEED;
}


    /* Request left lane */
if (Input_IsKeyPressed(SDL_SCANCODE_A) ||
    Input_IsKeyPressed(SDL_SCANCODE_LEFT))
{
    if (player->target_lane > 0)
    {
        player->target_lane--;
    }
}

/* Request right lane */
if (Input_IsKeyPressed(SDL_SCANCODE_D) ||
    Input_IsKeyPressed(SDL_SCANCODE_RIGHT))
{
    if (player->target_lane <
        road->lane_count - 1)
    {
        player->target_lane++;
    }
}


    /* =========================================
       Calculate target X
       ========================================= */

    float lane_width =
        road->width / road->lane_count;

    float target_x =
        road->x +
        (player->target_lane * lane_width) +
        (lane_width - player->width) / 2.0f;


    /* =========================================
       Smooth lane movement
       ========================================= */

    float lane_movement =
        LANE_SWITCH_SPEED * delta_time;

    if (player->x < target_x)
    {
        player->x += lane_movement;

        if (player->x > target_x)
        {
            player->x = target_x;
        }
    }
    else if (player->x > target_x)
    {
        player->x -= lane_movement;

        if (player->x < target_x)
        {
            player->x = target_x;
        }
    }


    /* =========================================
       Road boundaries
       ========================================= */

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
            road->x +
            road->width -
            player->width;
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
            road->y +
            road->height -
            player->height;
    }
}


void Player_Render(const Player *player)
{
    Renderer_SetDrawColor(
        255,
        255,
        255,
        255
    );

    Renderer_DrawRect(
        player->x,
        player->y,
        player->width,
        player->height
    );
}
