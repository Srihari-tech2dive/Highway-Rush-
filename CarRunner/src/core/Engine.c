#include "core/Engine.h"

static bool running = false;

bool Engine_Init(void)
{
    running = true;
    return true;
}

void Engine_Run(void)
{
    while (running)
    {
        /* Main engine loop */
    }
}

void Engine_Shutdown(void)
{
    running = false;
}
