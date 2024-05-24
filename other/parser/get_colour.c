/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:31:22 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/18 14:52:04 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	ft_is_rgb(int n)
{
	if (n >= 0 && n <= 256)
		return (true);
	return (false);
}

double	ft_normalize_color(double color)
{
	return (color / 255.0);
}

int	ft_rgb_to_int(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = ft_clamp((int)(255.999 * color.x));
	g = ft_clamp((int)(255.999 * color.y));
	b = ft_clamp((int)(255.999 * color.z));
	return (r << 16 | g << 8 | b);
}

t_color	ft_get_colour(char *str, char *code, t_scene *scene)
{
	t_vec3	coord;
	char	**split;

	if (!str)
	{
		ft_msg_error(scene, code);
		return (ft_vector(0, 0, 0));
	}
	if (ft_check_rep_char(str, ','))
		ft_msg_error(scene, code);
	split = ft_split(str, ',');
	if (ft_strlen_2(split) != 3 || !ft_str_isint(split[0])
		|| !ft_str_isint(split[1]) || !ft_str_isint(split[2]))
		ft_msg_error(scene, code);
	if (!split[0] || !split[1] || !split[2])
	{
		ft_msg_error(scene, code);
		coord = ft_vector(0, 0, 0);
	}
	else
		coord = ft_vector(ft_atod(split[0]), ft_atod(split[1]),
				ft_atod(split[2]));
	ft_split_free(split);
	ft_check_lim_color(coord, scene, code);
	return (coord);
}

t_color	ft_int_to_rgb(int color)
{
	t_color	c;

	c.x = (color >> 16) & 0xFF;
	c.y = (color >> 8) & 0xFF;
	c.z = color & 0xFF;
	c.x /= 255.999;
	c.y /= 255.999;
	c.z /= 255.999;
	c.w = 3;
	return (c);
}
