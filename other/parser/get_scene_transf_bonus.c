/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_transf_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:43:40 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/13 12:21:45 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_cone_transform(t_shapes *new)
{
	t_matrix	translat;
	t_matrix	scaling;
	t_matrix	rotate;
	t_matrix	final;

	translat = ft_create_translation_matrix(new->cone->center.x,
			new->cone->center.y, new->cone->center.z);
	scaling = ft_create_scaling_matrix(new->cone->diameter, 1,
			new->cone->diameter);
	new->transform = ft_multiply_matrix(translat, scaling);
	rotate = ft_aux_rotation(new);
	final = ft_multiply_matrix(new->transform, rotate);
	ft_set_shape_transform(new, final);
}

void	ft_cube_transform(t_shapes *new)
{
	t_matrix	translat;
	t_matrix	scaling;
	t_matrix	rotate;
	t_matrix	final;

	translat = ft_create_translation_matrix(new->cube->center.x,
			new->cube->center.y, new->cube->center.z);
	scaling = ft_create_scaling_matrix(new->cube->side, new->cube->side,
			new->cube->side);
	new->transform = ft_multiply_matrix(translat, scaling);
	rotate = ft_aux_rotation(new);
	final = ft_multiply_matrix(new->transform, rotate);
	ft_set_shape_transform(new, final);
}
