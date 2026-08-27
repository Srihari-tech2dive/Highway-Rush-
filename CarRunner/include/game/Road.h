#ifndef ROAD_H
#define ROAD_H

typedef struct
{
    float x;
    float y;

    float width;
    float height;

    int lane_count;

    float scroll_offset;
    float scroll_speed;

} Road;

void Road_Init(Road *road);

void Road_Update(Road *road, float delta_time);

void Road_Render(const Road *road);

#endif /* ROAD_H */
