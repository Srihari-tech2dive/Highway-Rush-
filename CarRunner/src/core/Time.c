#include "core/Time.h"

#include <time.h>

static double previous_time = 0.0;
static float delta_time = 0.0f;

static double Time_GetSeconds(void)
{
    struct timespec time;

    clock_gettime(CLOCK_MONOTONIC, &time);

    return (double)time.tv_sec +
           (double)time.tv_nsec / 1000000000.0;
}

void Time_Init(void)
{
    previous_time = Time_GetSeconds();
    delta_time = 0.0f;
}

void Time_Update(void)
{
    double current_time = Time_GetSeconds();

    delta_time = (float)(current_time - previous_time);

    previous_time = current_time;
}

float Time_GetDelta(void)
{
    return delta_time;
}
