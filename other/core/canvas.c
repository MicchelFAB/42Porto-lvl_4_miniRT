/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:48:38 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/16 16:47:06 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_canvas	ft_create_aperture(int width, int height)
{
	int			i;
	int			j;
	t_canvas	c;

	i = 0;
	c.width = width;
	c.height = height;
	c.pixels = (t_color **)malloc(sizeof(t_color *) * height);
	while (i < height)
	{
		j = 0;
		c.pixels[i] = (t_color *)malloc(sizeof(t_color) * width);
		while (j < width)
		{
			c.pixels[i][j] = ft_color(0, 0, 0);
			j++;
		}
		i++;
	}
	return (c);
}

void	ft_free_canvas(t_canvas canvas)
{
	int	i;

	i = 0;
	if (canvas.width == 0 || canvas.height == 0)
		return ;
	while (i < canvas.height)
	{
		free(canvas.pixels[i]);
		i++;
	}
	free(canvas.pixels);
}

void	ft_write_pixel(t_canvas canvas, int x, int y, t_color color)
{
	if (x < 0 || x >= canvas.width || y < 0 || y >= canvas.height)
		return ;
	canvas.pixels[y][x] = color;
}

t_vec3	ft_pixel_at(t_canvas canvas, int x, int y)
{
	if (x < 0 || x >= canvas.width || y < 0 || y >= canvas.height)
		return (ft_color(0, 0, 0));
	return (canvas.pixels[y][x]);
}

int	ft_clamp(int value)
{
	if (value < 0)
		return (0);
	if (value > 255)
		return (255);
	return (value);
}
