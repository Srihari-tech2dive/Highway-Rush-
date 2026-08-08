#include "core/Engine.h"

int main(void)
{
    if (!Engine_Init())
    {
        return 1;
    }

    Engine_Run();

    Engine_Shutdown();

    return 0;
}
