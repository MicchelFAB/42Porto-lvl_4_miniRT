/**
 * @file minirt.h
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief Include file for the main functions.
 * @version 0.1
 * @date 2024-05-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "structs.h"
# include "matrix.h"
# include "error.h"
# include "light.h"
# include "modules.h"
# include "core.h"
# include "shapes.h"
# include "parse.h"
# include "utils.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// DEFINES ---------------------------------------------------------------------

# define WIDTH	500
# define RATIO	1.7777777777777

# define MAX	0
# define MIN	1

# define EPSILON 0.00001

void		ft_free_intersections(t_intersections **lst);
t_canvas	ft_create_aperture(int width, int height);
void		ft_write_pixel(t_canvas canvas, int x, int y, t_color color);
void		ft_free_canvas(t_canvas canvas);
void		ft_check_main(int ac);

#endif
