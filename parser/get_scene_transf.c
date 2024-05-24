/**
 * @file get_scene_transf.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the transformation functions for the mandatory part.
 * @version 0.1
 * @date 2024-05-23 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "parse.h"

void	ft_sphere_transform(t_shapes *new)
{
	t_matrix	transform;
	t_matrix	scaling;
	t_matrix	final;

	transform = ft_create_translation_matrix(new->sphere->center.x, new->sphere->center.y, new->sphere->center.z);
	scaling = ft_create_scaling_matrix(new->sphere->diameter, new->sphere->diameter, new->sphere->diameter);
	final = ft_multiply_matrix(transform, scaling);
	ft_set_shape_transform(new, final);
}

void	ft_plane_transform(t_shapes *new)
{
	t_matrix	rotate;
	t_matrix	final;

	new->transform = ft_create_translation_matrix(new->plane->point.x, new->plane->point.y, new->plane->point.z);
	rotate = ft_aux_rotation(new);
	final = ft_multiply_matrix(new->transform, rotate);
	ft_set_shape_transform(new, final);
}

void	ft_cylinder_transform(t_shapes *new)
{
	t_matrix	translat;
	t_matrix	scaling;
	t_matrix	rotate;
	t_matrix	final;

	translat = ft_create_translation_matrix(new->cylinder->center.x, new->cylinder->center.y, new->cylinder->center.z);
	scaling = ft_create_scaling_matrix(new->cylinder->diameter, new->cylinder->diameter, new->cylinder->diameter);
	new->transform = ft_multiply_matrix(translat, scaling);
	rotate = ft_aux_rotation(new);
	final = ft_multiply_matrix(new->transform, rotate);
	ft_set_shape_transform(new, final);
}
