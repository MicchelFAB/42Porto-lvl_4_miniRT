/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ratio.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:40:00 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/19 19:31:32 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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

double	ft_get_double(char *str, char *code, t_scene *scene)
{
	if (ft_isdouble(str) == false || ft_check_rep_char(str, '.'))
	{
		ft_msg_error(scene, code);
		return (0);
	}
	return (ft_atod(str));
}

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

void	ft_check_lim_color(t_vec3 color, t_scene *scene, char *code)
{
	if (color.x < 0 || color.x > 255 || color.y < 0 || color.y > 255
		|| color.z < 0 || color.z > 255)
		ft_msg_error(scene, code);
}
