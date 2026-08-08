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
 */
void Application_Update(void);

/**
 * @brief Renders the game for one frame.
 */
void Application_Render(void);

/**
 * @brief Shuts down the game application and releases its resources.
 */
void Application_Shutdown(void);

#endif /* APPLICATION_H */
