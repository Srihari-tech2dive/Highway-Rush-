#include "core/Application.h"
#include "core/Renderer.h"
#include "game/Player.h"

static Player player;

bool Application_Init(void)
{
     Player_Init(&player);

    return true;
}

void Application_Update(float delta_time)
{

    Player_Update(&player, delta_time);

}

void Application_Render(void)
{
    Renderer_Clear();

    /* Game rendering will go here */

    Renderer_DrawRectOutline(
        100.0f,
        50.0f,
        1080.0f,
        620.0f
    );


    Player_Render(&player);

    Renderer_Present();
}

void Application_Shutdown(void)
{
    /* Game cleanup logic will go here */
}
