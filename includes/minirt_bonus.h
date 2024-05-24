/**
 * @file minirt_bonus.h
 * @brief Include file for the bonus functions.
 * 
 * This file contains declarations for bonus functions and structures used
 * in the MiniRT project. These functions include multi-threaded rendering
 * and file parsing.
 * 
 * @version 0.1
 * @date 2024-05-22
 * 
 * @note This file is part of the MiniRT project.
 * @see https://github.com/your-repo-url (replace with actual repo URL)
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# define THREADS 16 /**< Number of threads for multi-threaded rendering */
# define WIDTH_B 500 /**< Width of the bonus image */

# include "minirt.h"
# include "utils.h"
# include <pthread.h>

/**
 * @brief Rendering context structure for multi-threaded rendering.
 */
typedef struct s_context
{
    int num_threads; /**< Number of threads */
    t_world *image; /**< Pointer to the world image */
    int initial_height; /**< Initial height for thread */
    int final_height; /**< Final height for thread */
} t_context;

void ft_open_file_bonus(char *file, t_scene *scene);

void ft_render_bonus_thread(t_context *fun);

void ft_start_thread(t_world *scene);

#endif /* MINIRT_BONUS_H */
