#ifndef PLAYER_H
#define PLAYER_H

typedef struct
{
    float x;
    float y;

    float width;
    float height;

    float speed;

} Player;

void Player_Init(Player *player);

void Player_Update(Player *player, float delta_time);

void Player_Render(const Player *player);

#endif /* PLAYER_H */
