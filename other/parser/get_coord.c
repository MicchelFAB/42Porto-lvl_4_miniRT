/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:33:52 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/19 16:47:27 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	ft_check_rep_char(char *str, char c)
{
	while (*str && *(str + 1))
	{
		if (*str == c && *(str + 1) == c)
			return (1);
		str++;
	}
	if (*str == ',')
		return (1);
	return (0);
}

bool	ft_isdouble(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (i < (int)ft_strlen(str))
	{
		if (!(ft_isdigit(str[i]) == true || str[i] == '-' || str[i] == '+'
				|| str[i] == '.'))
			return (false);
		i++;
	}
	return (true);
}

int	ft_isnormal(t_vec3 n)
{
	if (n.x >= -1.0 && n.x <= 1.0 && n.y >= -1.0 && n.y <= 1.0 && n.z >= -1.0
		&& n.z <= 1.0)
		return (1);
	return (0);
}

t_vec3	ft_get_coord(char *str, char *code, t_scene *scene)
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
	if (ft_strlen_2(split) != 3 || !(ft_isdouble(split[0]) == 1
			&& ft_isdouble(split[1]) == 1 && ft_isdouble(split[2]) == 1))
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
	return (coord);
}

t_vec3	ft_get_normal(char *str, char *code, t_scene *scene)
{
	t_vec3	coord;

	coord = ft_get_coord(str, code, scene);
	if (!ft_isnormal(coord))
		ft_msg_error(scene, code);
	return (coord);
}
