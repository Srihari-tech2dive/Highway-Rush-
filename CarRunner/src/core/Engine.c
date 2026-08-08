#include "core/Engine.h"
#include "core/Application.h"
#include "core/Time.h"

static bool running = false;

bool Engine_Init(void)
{
    if (!Application_Init())
    {
        return false;
    }

    Time_Init();

    running = true;

    return true;
}

void Engine_Run(void)
{
    while (running)
    {
        Time_Update();

	float delta_time = Time_GetDelta();

        Application_Update(delta_time);
        Application_Render();
    }
}

void Engine_Shutdown(void)
{
    Application_Shutdown();

    running = false;
}
