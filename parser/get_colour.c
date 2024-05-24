/**
 * @file get_colour.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the functions to get the colour.
 * @version 0.1
 * @date 2024-05-23 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "parse.h"
/**
 * @brief Function to check if the number is between 0 and 255.
 * @param n 
 * @return true 
 * @return false 
 */
bool	ft_is_rgb(int n)
{
	if (n >= 0 && n <= 256)
		return (true);
	return (false);
}
/**
 * @brief Function to transform the colour from 0 to 255 to 0 to 1.
 * @param color 
 * @return double 
 */
double	ft_normalize_color(double color)
{
	return (color / 255.0);
}
/**
 * @brief Function to transform the colour from 0 to 1 to 0 to 255.
 * @param color 
 * @return int 
 */
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
/**
 * @brief Function to get the colour.
 * @param str 
 * @param code 
 * @param scene 
 * @return t_color 
 */
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
/**
 * @brief Function to transform the int to rgb.
 * @param color 
 * @return t_color 
 */
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
