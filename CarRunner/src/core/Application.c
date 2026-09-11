#include "core/Application.h"
#include "core/Renderer.h"
#include "game/Player.h"
#include "game/Road.h"

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
    Road_Update(&road, delta_time);

    Player_Update(&player, &road, delta_time);

}

void Application_Render(void)
{
    Renderer_Clear();

    /* Game rendering will go here */

    Road_Render(&road);


    Player_Render(&player);

    Renderer_Present();
}

void Application_Shutdown(void)
{
    /* Game cleanup logic will go here */
}
