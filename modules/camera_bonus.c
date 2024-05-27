/**
 * @file camera_bonus.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the camera functions. Complement to the main camera file.
 * used for the bonus part of the project.
 * @version 0.1
 * @date 2024-05-22 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "modules.h"
#include "minirt_bonus.h"
/**
 * @brief Renders the image.
 * @param c The camera.
 * @param w The world.
 * @return t_canvas The rendered image.
 */
t_canvas	ft_render_bonus(t_camera *c, t_world *w)
{
	int			x;
	int			y;
	t_canvas	image;
	t_ray		r;
	t_color		color;

	y = 0;
	image = ft_create_aperture(c->hsize, c->vsize);
	while (y < c->vsize)
	{
		x = 0;
		while (x < c->hsize)
		{
			r = ft_ray_for_pixel(c, x, y);
			color = ft_color_at_bonus(w, r, 5);
			ft_write_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
	return (image);
}
/**
 * @brief Renders the image. using threads.
 * @param fun 
 */
void	ft_render_bonus_thread(t_context *fun)
{
	int			x;
	int			y;
	t_ray		r;
	t_color		color;

	y = fun->initial_height - 1;
	while (++y < fun->final_height)
	{
		x = -1;
		while (++x < fun->image->camera->hsize)
		{
			r = ft_ray_for_pixel(fun->image->camera, x, y);
			color = ft_color_at_bonus(fun->image, r, 5);
			ft_mlx_pixel_put(&fun->image->img, x, y, color);
		}
	}
}
