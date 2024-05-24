/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:56:47 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/19 16:13:49 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules.h"

t_color	ft_ring_at(t_pattern pattern, int shape_type, t_point point)
{
	double	distance;

	distance = 1.5 * sqrt(pow(point.x, 2) + pow(point.z, 2));
	if (shape_type == SPHERE)
		distance = 4 * sqrt(pow(point.x, 2) + pow(point.y, 2));
	if (shape_type == CYLINDER)
		distance = 3 * sqrt(pow(point.x, 2) + pow(point.y, 2));
	if (shape_type == CONE)
		distance = 5 * sqrt(pow(point.x, 2) + pow(point.y, 2));
	if (shape_type == CUBE)
		distance = 5 * sqrt(pow(point.x, 2) + pow(point.y, 2)
				+ pow(point.z, 2));
	if ((int)distance % 2 == 0)
		return (pattern.a);
	else
		return (pattern.b);
}

t_color	ft_checkers_at(t_pattern pattern, t_point point)
{
	int		size;

	size = 1;
	if (((int)floor(point.x * size) + (int)floor(point.y * size)
			+ (int)floor(point.z * size)) % 2 == 0)
		return (pattern.a);
	else
		return (pattern.b);
}

int	ft_secure_open(char *file, t_scene *scene, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		ft_msg_error(scene, "Error open xpm file");
	return (*fd);
}

t_pattern	ft_create_xpm_pattern(int pattern_type, char *xpm_txt, t_scene *err)
{
	t_pattern	pattern;

	pattern.type = pattern_type;
	pattern.a = ft_color(0, 0, 0);
	pattern.b = ft_color(0, 0, 0);
	pattern.transform = ft_create_matrix(4, 4, YES);
	pattern.inverted = ft_create_matrix(4, 4, YES);
	pattern.xpm = ft_read_xpm(xpm_txt, err);
	return (pattern);
}

t_color	ft_xpm_at(t_pattern pattern, t_point point)
{
	double	u;
	double	v;
	int		x;
	int		y;

	u = (point.x + 1.0) / 2.0;
	v = 1.0 - ((point.y + 1.0) / 2.0);
	x = abs((int)(u * (pattern.xpm.width - 1) + 0.5));
	y = abs((int)(v * (pattern.xpm.height - 1) + 0.5));
	x = x % pattern.xpm.width;
	y = y % pattern.xpm.height;
	return (pattern.xpm.pixels[y][x]);
}
