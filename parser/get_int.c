/**
 * @file get_int.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the functions to get the integer values.
 * @version 0.1
 * @date 2024-05-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "parse.h"
/**
 * @brief Function to check if the string is an integer.
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool	ft_str_isint(char *str)
{
	int		i;

	i = 0;
	while (i < (int)ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0 || str[i] == '-')
			return (false);
		i++;
	}
	return (true);
}
/**
 * @brief Function to get the integer value.
 * 
 * @param str 
 * @param code 
 * @param scene 
 * @return int 
 */
int	ft_get_int(char *str, char *code, t_scene *scene)
{
	if (ft_str_isint(str) == false)
	{
		ft_msg_error(scene, code);
		return (0);
	}
	return (ft_atoi(str));
}
/**
 * @brief Function to get the positive integer value.
 * 
 * @param str 
 * @param code 
 * @param scene 
 * @return int 
 */
int	ft_get_posint(char *str, char *code, t_scene *scene)
{
	int		pos;

	pos = ft_get_int(str, code, scene);
	if (!(pos > 0))
	{
		ft_msg_error(scene, code);
		return (0);
	}
	return (pos);
}
/**
 * @brief Function to convert degrees to radians.
 * 
 * @param deg 
 * @return double 
 */
static double	ft_deg2rad(double deg)
{
	return ((M_PI_4 / 45) * deg);
}
/**
 * @brief Function to get the field of view.
 * 
 * @param str 
 * @param code 
 * @param scene 
 * @return double 
 */	
double	ft_get_fov(char *str, char *code, t_scene *scene)
{
	double	fov;

	fov = ft_get_int(str, code, scene);
	if (!(fov >= 0 && fov <= 180))
	{
		ft_msg_error(scene, code);
		return (0);
	}
	fov = ft_deg2rad(fov);
	return (fov);
}
