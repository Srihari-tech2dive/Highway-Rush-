#include "core/Application.h"
#include "core/Renderer.h"

bool Application_Init(void)
{
    return true;
}

void Application_Update(float delta_time)
{
    /* Game update logic will go here */

    (void)delta_time;
}

void Application_Render(void)
{
    Renderer_Clear();

    /* Game rendering will go here */

    Renderer_Present();
}

void Application_Shutdown(void)
{
    /* Game cleanup logic will go here */
}
