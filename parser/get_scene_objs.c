/**
 * @file get_scene_objs.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the objects of scene for the mandatory part.
 * @version 0.1
 * @date 2024-05-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "parse.h"
/**
 * @brief Function to get the sphere object.
 * 
 * @param scene 
 */
void	get_4_sp(t_scene *scene)
{
	t_matrix	scaling;
	t_matrix	final;

	scene->new = ft_create_shape(SPHERE);
	scene->new->sphere->center = ft_get_coord(scene->split[1], SP_COORD, scene);
	scene->new->sphere->center = ft_vector(scene->new->sphere->center.x, scene->new->sphere->center.y, scene->new->sphere->center.z);
	scene->new->sphere->diameter = ft_get_size(scene->split[2], SP_DIAM, scene) / 2;
	scene->new->material.color = ft_get_colour(scene->split[3], SP_RGB, scene);
	scene->new->material.color = ft_color(ft_normalize_color(scene->new->material.color.x),	ft_normalize_color(scene->new->material.color.y), ft_normalize_color(scene->new->material.color.z));
	scene->new->transform = ft_create_translation_matrix(scene->new->sphere->center.x, scene->new->sphere->center.y, scene->new->sphere->center.z);
	scaling = ft_create_scaling_matrix(scene->new->sphere->diameter, scene->new->sphere->diameter, scene->new->sphere->diameter);
	final = ft_multiply_matrix(scene->new->transform, scaling);
	ft_set_shape_transform(scene->new, final);
}
/**
 * @brief Function to get the plane object.
 * 
 * @param scene 
 */
void	get_5_pl(t_scene *scene)
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
	scene->new->transform = ft_create_translation_matrix(scene->new->plane->point.x, scene->new->plane->point.y, scene->new->plane->point.z);
	rotate = ft_aux_rotation(scene->new);
	final = ft_multiply_matrix(scene->new->transform, rotate);
	ft_set_shape_transform(scene->new, final);
}
/**
 * @brief Function to get the cylinder object.
 * 
 * @param scene 
 */
void	get_6_cy(t_scene *scene)
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
	scene->new->material.color = ft_color(ft_normalize_color(scene->new->material.color.x), ft_normalize_color(scene->new->material.color.y), ft_normalize_color(scene->new->material.color.z));
	scene->new->cylinder->minimum = -scene->new->cylinder->height / 2;
	scene->new->cylinder->maximum = scene->new->cylinder->height / 2;
	scene->new->cylinder->closed = true;
	translat = ft_create_translation_matrix(scene->new->cylinder->center.x, scene->new->cylinder->center.y, scene->new->cylinder->center.z);
	scaling = ft_create_scaling_matrix(scene->new->cylinder->diameter, scene->new->cylinder->diameter, scene->new->cylinder->diameter);
	scene->new->transform = ft_multiply_matrix(translat, scaling);
	rotate = ft_aux_rotation(scene->new);
	final = ft_multiply_matrix(scene->new->transform, rotate);
	ft_set_shape_transform(scene->new, final);
}
