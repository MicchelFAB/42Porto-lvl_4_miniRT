/**
 * @file get_ratio.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the functions to get the ratio values.
 * @version 0.1
 * @date 2024-05-23 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "parse.h"
/**
 * @brief Function to convert a string to a double.
 * @param str 
 * @return double 
 */
double	ft_atod(const char *str)
{
	double	int_p;
	double	dec_p;
	double	sign;
	int		i;

	int_p = 0.0;
	dec_p = 0.0;
	sign = 1.0;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1.0;
	while (ft_isdigit(*str))
		int_p = int_p * 10 + (*str++ - '0');
	i = -1;
	if (*str == '.' && *str++)
	{
		while (ft_isdigit(*str))
			dec_p += (pow(10, i--) * (*str++ - '0'));
	}
	return (sign * (int_p + dec_p));
}
/**
 * @brief Function to get the double value.
 * @param str 
 * @param code 
 * @param scene 
 * @return double 
 */
double	ft_get_double(char *str, char *code, t_scene *scene)
{
	if (ft_isdouble(str) == false || ft_check_rep_char(str, '.'))
	{
		ft_msg_error(scene, code);
		return (0);
	}
	return (ft_atod(str));
}
/**
 * @brief Function to get the ratio value.
 * @param str 
 * @param code 
 * @param scene 
 * @return double 
 */
double	ft_get_ratio(char *str, char *code, t_scene *scene)
{
	double	n;

	n = ft_get_double(str, code, scene);
	if (!(n >= 0.0 && n <= 1.0))
	{
		ft_msg_error(scene, code);
		return (0);
	}
	return (n);
}
/**
 * @brief Function to get the size value.
 * @param str 
 * @param code 
 * @param scene 
 * @return double 
 */
double	ft_get_size(char *str, char *code, t_scene *scene)
{
	double	n;

	n = ft_get_double(str, code, scene);
	if (!(n > 0.0))
	{
		ft_msg_error(scene, code);
		return (0);
	}
	return (n);
}
/**
 * @brief Function to check the limit of the colour.
 * @param color 
 * @param scene 
 * @param code 
 */
void	ft_check_lim_color(t_vec3 color, t_scene *scene, char *code)
{
	if (color.x < 0 || color.x > 255 || color.y < 0 || color.y > 255 || color.z < 0 || color.z > 255)
		ft_msg_error(scene, code);
}
