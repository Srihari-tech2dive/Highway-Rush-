#include "core/Engine.h"
#include "core/Application.h"
#include "core/Time.h"
#include "core/Window.h"
#include "core/Input.h"
#include "core/Renderer.h"

#include <SDL3/SDL.h>

static bool running = false;

bool Engine_Init(void)
{


    if (!SDL_Init(SDL_INIT_VIDEO))
    {

        return false;
    }

    if (!Window_Init())
    {

        SDL_Quit();
        return false;
    }


    if (!Renderer_Init())
    {
        Window_Shutdown();
        SDL_Quit();
        return false;
    }

    Time_Init();


    if (!Input_Init())
    {
        Renderer_Shutdown();
        Window_Shutdown();
        SDL_Quit();
        return false;
    }


    if (!Application_Init())
    {
        Input_Shutdown();
	Renderer_Shutdown();
        Window_Shutdown();
        SDL_Quit();
        return false;
    }


    running = true;


    return true;
}

void Engine_Run(void)
{


    while (running)
    {
        if (Input_Update())
        {

            running = false;
            continue;
        }

        Time_Update();
        float delta_time = Time_GetDelta();

        Application_Update(delta_time);
        Application_Render();
    }

}

void Engine_Shutdown(void)
{
    Application_Shutdown();

    Input_Shutdown();

    Renderer_Shutdown();

    Window_Shutdown();

    SDL_Quit();

    running = false;
}
