/**
 * @file get_scene_transf_bonus.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the transformation functions for the bonus part.
 * @version 0.1
 * @date 2024-05-23 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "parse.h"
/**
 * @brief Function to transform the cone object.
 * @param new 
 */
void	ft_cone_transform(t_shapes *new)
{
	t_matrix	translat;
	t_matrix	scaling;
	t_matrix	rotate;
	t_matrix	final;

	translat = ft_create_translation_matrix(new->cone->center.x, new->cone->center.y, new->cone->center.z);
	scaling = ft_create_scaling_matrix(new->cone->diameter, 1, new->cone->diameter);
	new->transform = ft_multiply_matrix(translat, scaling);
	rotate = ft_aux_rotation(new);
	final = ft_multiply_matrix(new->transform, rotate);
	ft_set_shape_transform(new, final);
}
/**
 * @brief Function to transform the cube object.
 * @param new 
 */
void	ft_cube_transform(t_shapes *new)
{
	t_matrix	translat;
	t_matrix	scaling;
	t_matrix	rotate;
	t_matrix	final;

	translat = ft_create_translation_matrix(new->cube->center.x, new->cube->center.y, new->cube->center.z);
	scaling = ft_create_scaling_matrix(new->cube->side, new->cube->side, new->cube->side);
	new->transform = ft_multiply_matrix(translat, scaling);
	rotate = ft_aux_rotation(new);
	final = ft_multiply_matrix(new->transform, rotate);
	ft_set_shape_transform(new, final);
}
