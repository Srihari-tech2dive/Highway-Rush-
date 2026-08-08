#ifndef APPLICATION_H
#define APPLICATION_H

#include <stdbool.h>

/**
 * @brief Initializes the game application.
 *
 * @return true if initialization succeeds, otherwise false.
 */
bool Application_Init(void);

/**
 * @brief Updates the game state for one frame.
 *
 * @param delta_time Time elapsed since the previous frame, in seconds.
 */
void Application_Update(float delta_time);

/**
 * @brief Renders the game for one frame.
 */
void Application_Render(void);

/**
 * @brief Shuts down the game application and releases its resources.
 */
void Application_Shutdown(void);

#endif /* APPLICATION_H */
