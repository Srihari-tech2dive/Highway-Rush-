#ifndef PLAYER_H
#define PLAYER_H

#include "game/Road.h"

typedef struct
{
    float x;
    float y;

    float width;
    float height;

    float speed;

} Player;

void Player_Init(Player *player, const Road *road);

void Player_Update(
    Player *player,
    const Road *road,
    float delta_time
);

void Player_Render(const Player *player);

#endif /* PLAYER_H */
