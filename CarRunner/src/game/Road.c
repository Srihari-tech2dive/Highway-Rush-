#include "game/Road.h"
#include "core/Renderer.h"

void Road_Init(Road *road)
{
    road->x = 100.0f;
    road->y = 50.0f;

    road->width = 1080.0f;
    road->height = 620.0f;

    road->lane_count = 3;

    road->scroll_offset = 0.0f;
    road->scroll_speed = 300.0f;
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

    /* Draw lane divider lines */
float dash_height = 40.0f;
float dash_gap = 30.0f;
float dash_cycle = dash_height + dash_gap;

for (int i = 1; i < road->lane_count; i++)
{
    float line_x = road->x + (lane_width * i);

    for (float y = road->y - dash_cycle + road->scroll_offset;
         y < road->y + road->height;
         y += dash_cycle)
    {
        Renderer_DrawRect(
            line_x - 2.0f,
            y,
            4.0f,
            dash_height
        );
    }
}

}
