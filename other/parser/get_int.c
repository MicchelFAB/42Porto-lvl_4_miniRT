/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:34:43 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/14 13:43:16 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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

int	ft_get_int(char *str, char *code, t_scene *scene)
{
	if (ft_str_isint(str) == false)
	{
		ft_msg_error(scene, code);
		return (0);
	}
	return (ft_atoi(str));
}

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

static double	ft_deg2rad(double deg)
{
	return ((M_PI_4 / 45) * deg);
}

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
