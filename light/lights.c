/**
 * @file lights.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the functions to calculate the normal at a point where
 *  the light hits the object.
 * @version 0.1
 * @date 2024-05-22 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "light.h"
/**
 * @brief Creates a point light.
 * @param position The position of the light.
 * @param intensity The intensity of the light.
 * @param ratio The ratio of the light.
 * @return t_light* The light created.
 */
t_light	*ft_create_point_light(t_point position, t_color intensity,	double ratio)
{
	t_light	*light;

	light = ft_calloc(1, sizeof(t_light));
	light->intensity = ft_oper_specular(intensity, '*', ratio);
	light->position = position;
	return (light);
}
/**
 * @brief Calculates the specular lighting.
 * @param lighting The lighting structure.
 * @param material The material of the object.
 * @param c The computations.
 * @param light The light.
 */
void	ft_lighting_specular(t_lighting *lighting, t_material material, t_comps *c, t_light *light)
{
	lighting->diffuse = ft_oper_specular(lighting->ef_color, '*', material.diffuse * lighting->light_dot_normal);
	lighting->reflectv = ft_operations(ft_oper_specular(lighting->lightv, '*', -1), '-', ft_oper_specular(c->normalv, '*', 2 * ft_dot(ft_oper_specular(lighting->lightv, '*', -1), c->normalv)));
	lighting->reflect_dot_eye = ft_dot(lighting->reflectv, c->eyev);
	if (lighting->reflect_dot_eye <= 0)
		lighting->specular = ft_color(0, 0, 0);
	else
	{
		lighting->factor = pow(lighting->reflect_dot_eye, material.shininess);
		lighting->specular = ft_oper_specular(light->intensity, '*', material.specular * lighting->factor);
	}
}
/**
 * @brief Calculates the lighting.
 * @param m The material of the object.
 * @param c The computations.
 * @param light The light.
 * @param in_shadow If the object is in shadow.
 * @return t_color The color of the light.
 */
t_color	ft_lighting(t_material m, t_comps *c, t_light *light, bool in_shadow)
{
	t_lighting	*lighting;
	t_color		color;

	lighting = ft_calloc(1, sizeof(t_lighting));
	if (m.pattern.type != NONE)
		lighting->color = ft_pattern_at_shape(m.pattern, c->object, c->point);
	else
		lighting->color = m.color;
	lighting->ef_color = ft_operations(lighting->color, '*', light->intensity);
	lighting->lightv = ft_normalize(ft_operations(light->position, '-',	c->point));
	lighting->amb = ft_operations(lighting->ef_color, '*', m.ambient);
	lighting->light_dot_normal = ft_dot(lighting->lightv, c->normalv);
	if (lighting->light_dot_normal < 0)
	{
		lighting->diffuse = ft_color(0, 0, 0);
		lighting->specular = ft_color(0, 0, 0);
	}
	else
		ft_lighting_specular(lighting, m, c, light);
	if (in_shadow)
		color = lighting->amb;
	else
		color = ft_operations(ft_operations(lighting->amb, '+',	lighting->diffuse), '+', lighting->specular);
	free(lighting);
	return (color);
}
/**
 * @brief Returns the normal at a point where the light hits the object.
 * @param s The shape.
 * @param world_point The point where the light hits the object.
 * @return t_vec3 The normal at the point.
 */
t_vec3	ft_normal_at(t_shapes *s, t_point world_point)
{
	t_point	object_point;
	t_vec3	object_normal;
	t_vec3	world_normal;

	object_point = ft_multiply_matrix_tuple(s->inverted, world_point);
	object_normal = ft_vector(0, 0, 0);
	if (s->type == SPHERE)
		object_normal = ft_operations(object_point, '-', ft_point(0, 0, 0));
	else if (s->type == PLANE)
		object_normal = ft_vector(0, 1, 0);
	else if (s->type == CYLINDER)
		object_normal = ft_cylinder_normal_at(s, object_point);
	world_normal = ft_multiply_matrix_tuple(ft_transpose_matrix(s->inverted), object_normal);
	world_normal.w = 0;
	return (ft_normalize(world_normal));
}
/**
 * @brief Returns the reflection of a vector.
 * @param in The vector to be reflected.
 * @param normal The normal vector.
 * @return t_vec3 The reflected vector.
 */
t_vec3	ft_reflect(t_vec3 in, t_vec3 normal)
{
	return (ft_operations(in, '-', ft_oper_specular(normal, '*', 2 * ft_dot(in,	normal))));
}
