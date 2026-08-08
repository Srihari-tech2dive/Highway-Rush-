#ifndef ENGINE_H
#define ENGINE_H

#include <stdbool.h>

/**
 * @brief Initializes the game engine.
 *
 * @return true if initialization succeeds, otherwise false.
 */
bool Engine_Init(void);

/**
 * @brief Runs the engine main loop.
 */
void Engine_Run(void);

/**
 * @brief Shuts down the game engine and releases resources.
 */
void Engine_Shutdown(void);

#endif /* ENGINE_H */
