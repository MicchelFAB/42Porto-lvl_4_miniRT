/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:55:27 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/13 18:42:01 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules.h"
#include "minirt_bonus.h"

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
