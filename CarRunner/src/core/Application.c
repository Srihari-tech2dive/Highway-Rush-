#include "core/Application.h"
#include "core/Renderer.h"
#include "game/Player.h"
#include "game/Road.h"

#define BOSS_DISTANCE 6000.0f

#define PROGRESS_X 100.0f
#define PROGRESS_Y 20.0f
#define PROGRESS_WIDTH 1080.0f
#define PROGRESS_HEIGHT 15.0f

static Player player;
static Road road;

bool Application_Init(void)
{
     Road_Init(&road);
     Player_Init(&player,&road);

    return true;
}

void Application_Update(float delta_time)
{

    Player_Update(&player, &road, delta_time);

    Road_Update(
    &road,
    player.speed,
    delta_time
    );
}


static void Application_RenderProgress(const Road *road)
{
    float progress =
        road->distance / BOSS_DISTANCE;

    if (progress > 1.0f)
        progress = 1.0f;

    /* Background */
    Renderer_SetDrawColor(80, 80, 80, 255);

    Renderer_DrawRect(
        PROGRESS_X,
        PROGRESS_Y,
        PROGRESS_WIDTH,
        PROGRESS_HEIGHT
    );

    /* Progress */
    Renderer_SetDrawColor(255, 255, 255, 255);

    Renderer_DrawRect(
        PROGRESS_X,
        PROGRESS_Y,
        PROGRESS_WIDTH * progress,
        PROGRESS_HEIGHT
    );

    /* Border */
    Renderer_SetDrawColor(255, 255, 255, 255);

    Renderer_DrawRectOutline(
        PROGRESS_X,
        PROGRESS_Y,
        PROGRESS_WIDTH,
        PROGRESS_HEIGHT
    );
}

    /* Game rendering will go here */

void Application_Render(void)
{
    Renderer_Clear();

    Application_RenderProgress(&road);

    Road_Render(&road);
    Player_Render(&player);

    Renderer_Present();
}

void Application_Shutdown(void)
{
    /* Game cleanup logic will go here */
}
