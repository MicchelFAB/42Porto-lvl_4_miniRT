/**
 * @file get_scene_objs_bonus.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the elements of scene for the bonus part.
 * @version 0.1
 * @date 2024-05-23 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "parse.h"
/**
 * @brief Get the sphere bonus object * 
 * @param scene 
 */
void	get_4_sp_bonus(t_scene *scene)
{
	t_matrix	scaling;
	t_matrix	final;

	scene->new = ft_create_shape(SPHERE);
	scene->new->sphere->center = ft_get_coord(scene->split[1], SP_COORD, scene);
	scene->new->sphere->center = ft_vector(scene->new->sphere->center.x, scene->new->sphere->center.y, scene->new->sphere->center.z);
	scene->new->sphere->diameter = ft_get_size(scene->split[2], SP_DIAM, scene)	/ 2;
	scene->new->material.color = ft_get_colour(scene->split[3], SP_RGB, scene);
	scene->new->material.color = ft_color(ft_normalize_color(scene->new->material.color.x), ft_normalize_color(scene->new->material.color.y), ft_normalize_color(scene->new->material.color.z));
	ft_get_bonus_list(scene, 4);
	if (!ft_check_bonus_list(scene))
		ft_msg_error(scene, "Invalid number of bonus identifier");
	scene->new->transform = ft_create_translation_matrix(scene->new->sphere->center.x, scene->new->sphere->center.y, scene->new->sphere->center.z);
	scaling = ft_create_scaling_matrix(scene->new->sphere->diameter, scene->new->sphere->diameter, scene->new->sphere->diameter);
	final = ft_multiply_matrix(scene->new->transform, scaling);
	ft_set_shape_transform(scene->new, final);
}
/**
 * @brief Get the plane bonus object * 
 * @param scene 
 */
void	get_5_pl_bonus(t_scene *scene)
{
	t_matrix	rotate;
	t_matrix	final;

	scene->new = ft_create_shape(PLANE);
	scene->new->plane->point = ft_get_coord(scene->split[1], PL_COORD, scene);
	scene->new->plane->point = ft_vector(scene->new->plane->point.x, scene->new->plane->point.y, scene->new->plane->point.z);
	scene->new->plane->point = ft_oper_specular(scene->new->plane->point, '+', EPSILON);
	scene->new->normal = ft_get_normal(scene->split[2], PL_COORD, scene);
	scene->new->normal = ft_vector(scene->new->normal.x, scene->new->normal.y, scene->new->normal.z);
	scene->new->material.color = ft_get_colour(scene->split[3], PL_RGB, scene);
	scene->new->material.color = ft_color(ft_normalize_color(scene->new->material.color.x), ft_normalize_color(scene->new->material.color.y), ft_normalize_color(scene->new->material.color.z));
	ft_get_bonus_list(scene, 4);
	if (!ft_check_bonus_list(scene))
		ft_msg_error(scene, "Invalid number of bonus identifier");
	scene->new->transform = ft_create_translation_matrix(scene->new->plane->point.x, scene->new->plane->point.y, scene->new->plane->point.z);
	rotate = ft_aux_rotation(scene->new);
	final = ft_multiply_matrix(scene->new->transform, rotate);
	ft_set_shape_transform(scene->new, final);

}
/**
 * @brief Get the cylinder bonus object * 
 * @param scene 
 */
void	get_6_cy_bonus(t_scene *scene)
{
	t_matrix	translat;
	t_matrix	scaling;
	t_matrix	rotate;
	t_matrix	final;

	scene->new = ft_create_shape(CYLINDER);
	scene->new->cylinder->center = ft_get_coord(scene->split[1], CY_COORD, scene);
	scene->new->cylinder->center = ft_vector(scene->new->cylinder->center.x, scene->new->cylinder->center.y, scene->new->cylinder->center.z);
	scene->new->normal = (ft_get_normal(scene->split[2], CY_NORM, scene));
	scene->new->normal = ft_vector(scene->new->normal.x, scene->new->normal.y, scene->new->normal.z);
	scene->new->cylinder->diameter = ft_get_size(scene->split[3], CY_DIAM, scene) / 2;
	scene->new->cylinder->height = ft_get_size(scene->split[4], CY_HEIGHT, scene);
	scene->new->material.color = ft_get_colour(scene->split[5], CY_RGB, scene);
	scene->new->material.color = ft_color(ft_normalize_color(scene->new->material.color.x),ft_normalize_color(scene->new->material.color.y),ft_normalize_color(scene->new->material.color.z));
	scene->new->cylinder->minimum = -scene->new->cylinder->height / 2;
	scene->new->cylinder->maximum = scene->new->cylinder->height / 2;
	scene->new->cylinder->closed = true;
	ft_get_bonus_list(scene, 6);
	if (!ft_check_bonus_list(scene))
		ft_msg_error(scene, "Invalid number of bonus identifier");
	translat = ft_create_translation_matrix(scene->new->cylinder->center.x, scene->new->cylinder->center.y, scene->new->cylinder->center.z);
	scaling = ft_create_scaling_matrix(scene->new->cylinder->diameter, scene->new->cylinder->diameter, scene->new->cylinder->diameter);
	scene->new->transform = ft_multiply_matrix(translat, scaling);
	rotate = ft_aux_rotation(scene->new);
	final = ft_multiply_matrix(scene->new->transform, rotate);
	ft_set_shape_transform(scene->new, final);
}
/**
 * @brief Get the cone bonus object * 
 * @param scene 
 */
void	get_7_co(t_scene *scene)
{
	t_matrix	translat;
	t_matrix	scaling;
	t_matrix	rotate;
	t_matrix	final;

	scene->new = ft_create_shape_bonus(CONE);
	scene->new->cone->center = ft_get_coord(scene->split[1], CO_COORD, scene);
	scene->new->cone->center = ft_vector(scene->new->cone->center.x, scene->new->cone->center.y, scene->new->cone->center.z);
	scene->new->normal = ft_get_normal(scene->split[2], CO_NORM, scene);
	scene->new->normal = ft_vector(scene->new->normal.x, scene->new->normal.y, scene->new->normal.z);
	scene->new->cone->diameter = ft_get_size(scene->split[3], CO_DIAM, scene) / 2;
	scene->new->cone->height = ft_get_size(scene->split[4], CO_HEIGHT, scene);
	scene->new->material.color = ft_get_colour(scene->split[5], CO_RGB, scene);
	scene->new->material.color = ft_color(ft_normalize_color(scene->new->material.color.x), ft_normalize_color(scene->new->material.color.y), ft_normalize_color(scene->new->material.color.z));
	scene->new->cone->minimum = -scene->new->cone->height / 2;
	scene->new->cone->maximum = 0;
	scene->new->cone->closed = true;
	ft_get_bonus_list(scene, 6);
	if (!ft_check_bonus_list(scene))
		ft_msg_error(scene, "Invalid number of bonus identifier");
	translat = ft_create_translation_matrix(scene->new->cone->center.x, scene->new->cone->center.y, scene->new->cone->center.z);
	scaling = ft_create_scaling_matrix(scene->new->cone->diameter, 1, scene->new->cone->diameter);
	scene->new->transform = ft_multiply_matrix(translat, scaling);
	rotate = ft_aux_rotation(scene->new);
	final = ft_multiply_matrix(scene->new->transform, rotate);
	ft_set_shape_transform(scene->new, final);
}
/**
 * @brief Get the cube bonus object * 
 * @param scene 
 */
void	get_8_cb(t_scene *scene)
{
	char	**split_bonus;
	t_matrix	translat;
	t_matrix	scaling;
	t_matrix	rotate;
	t_matrix	final;

	scene->new = ft_create_shape_bonus(CUBE);
	scene->new->cube->center = ft_get_coord(scene->split[1], CB_COORD, scene);
	scene->new->cube->center = ft_vector(scene->new->cube->center.x, scene->new->cube->center.y, scene->new->cube->center.z);
	scene->new->normal = ft_get_normal(scene->split[2], CB_NORM, scene);
	scene->new->normal = ft_vector(scene->new->normal.x, scene->new->normal.y, scene->new->normal.z);
	scene->new->cube->side = ft_get_size(scene->split[3], CB_SIZE, scene);
	scene->new->material.color = ft_get_colour(scene->split[4], CB_RGB, scene);
	scene->new->material.color = ft_color(ft_normalize_color(scene->new->material.color.x), ft_normalize_color(scene->new->material.color.y), ft_normalize_color(scene->new->material.color.z));
	if (scene->split[5] && ft_strncmp(scene->split[5], "rf", 2) == 0)
	{
		split_bonus = ft_split(scene->split[5], '|');
		ft_get_reflective(split_bonus, scene);
		ft_split_free(split_bonus);
	}
	if (!ft_check_bonus_list(scene))
		ft_msg_error(scene, "Invalid number of bonus identifier");
	translat = ft_create_translation_matrix(scene->new->cube->center.x, scene->new->cube->center.y, scene->new->cube->center.z);
	scaling = ft_create_scaling_matrix(scene->new->cube->side, scene->new->cube->side, scene->new->cube->side);
	scene->new->transform = ft_multiply_matrix(translat, scaling);
	rotate = ft_aux_rotation(scene->new);
	final = ft_multiply_matrix(scene->new->transform, rotate);
	ft_set_shape_transform(scene->new, final);
}
