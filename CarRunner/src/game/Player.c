#include "game/Player.h"
#include "core/Input.h"
#include "core/Renderer.h"

#include <SDL3/SDL.h>

#include "core/GameConfig.h"

#define LANE_SWITCH_SPEED 800.0f

void Player_Init(Player *player, const Road *road)
{
    float lane_width =
        road->width / road->lane_count;

	float target_x =
    		road->x +
  	 	 (player->target_lane * lane_width) +
    		(lane_width - player->width) / 2.0f;


    int center_lane =
        road->lane_count / 2;

	float lane_movement =
    		LANE_SWITCH_SPEED * delta_time;

    player->width =
        lane_width * 0.35f;

    player->height =
        player->width * 0.5f;

   player->lane = road->lane_count / 2;
   
   player->target_lane = player->lane;

    player->speed =
        GAME_BASE_SPEED;

    player->x =
        road->x +
        (center_lane * lane_width) +
        (lane_width - player->width) / 2.0f;

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
    /* Request left lane */
if (Input_IsKeyDown(SDL_SCANCODE_A) ||
    Input_IsKeyDown(SDL_SCANCODE_LEFT))
{
    if (player->target_lane > 0)
    {
        player->target_lane--;
    }
}

/* Request right lane */
if (Input_IsKeyDown(SDL_SCANCODE_D) ||
    Input_IsKeyDown(SDL_SCANCODE_RIGHT))
{
    if (player->target_lane < road->lane_count - 1)
    {
        player->target_lane++;
    }
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
