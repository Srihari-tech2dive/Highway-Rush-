#include "game/Road.h"
#include "core/Renderer.h"

#include "core/GameConfig.h"

void Road_Init(Road *road)
{
    road->x = 100.0f;
    road->y = 50.0f;

    road->width = 1080.0f;
    road->height = 620.0f;

    road->lane_count = 3;

    road->scroll_offset = 0.0f;
    road->scroll_speed = GAME_BASE_SPEED;

    road->dash_height = 40.0f;
    road->dash_gap = 40.0f;

}

void Road_Update(Road *road, float delta_time)
{
    road->scroll_offset += road->scroll_speed * delta_time;

    float dash_cycle = 40.0f + 30.0f;

    if (road->scroll_offset >= dash_cycle)
    {
        road->scroll_offset -= dash_cycle;
    }

}

void Road_Render(const Road *road)
{
    /* Draw road area */
    Renderer_SetDrawColor(60, 60, 60, 255);

    Renderer_DrawRect(
        road->x,
        road->y,
        road->width,
        road->height
    );

    /* Draw road border */
    Renderer_SetDrawColor(255, 255, 255, 255);

    Renderer_DrawRectOutline(
        road->x,
        road->y,
        road->width,
        road->height
    );


/* Calculate lane width */
float lane_width = road->width / road->lane_count;

/* Dash settings */
float dash_cycle =
    road->dash_height + road->dash_gap;

/* Draw lane divider lines */
Renderer_SetDrawColor(255, 255, 255, 255);

for (int i = 1; i < road->lane_count; i++)
{
    float line_x = road->x + (lane_width * i);

    for (float y = road->y - dash_cycle + road->scroll_offset;
         y < road->y + road->height;
         y += dash_cycle)
    {
        /* Calculate visible part of dash */
        float dash_y = y;
        float dash_end = y + road->dash_height;

        /* Skip dash if completely outside the road */
        if (dash_end <= road->y ||
            dash_y >= road->y + road->height)
        {
            continue;
        }

        /* Clip top */
        if (dash_y < road->y)
        {
            dash_y = road->y;
        }

        /* Clip bottom */
        if (dash_end > road->y + road->height)
        {
            dash_end = road->y + road->height;
        }

        Renderer_DrawRect(
            line_x - 2.0f,
            dash_y,
            4.0f,
            dash_end - dash_y
        );
    }
}

}
