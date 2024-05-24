/**
 * @file reflection_bonus.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the reflection and refraction functions.
 * @version 0.1
 * @date 2024-05-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "minirt.h"
/**
 * @brief Calculates the reflected color.
 * 
 * @param world 
 * @param comps 
 * @param remaining 
 * @return t_color 
 */
t_color	ft_reflected_color_bonus(t_world *world, t_comps *comps, int remaining)
{
	t_ray	reflect_ray;
	t_color	color;

	if (remaining <= 0)
		return (ft_color(0, 0, 0));
	if (comps->object->material.reflective == 0)
		return (ft_color(0, 0, 0));
	reflect_ray = ft_create_ray(comps->over_point, comps->reflectv);
	color = ft_color_at_bonus(world, reflect_ray, remaining - 1);
	return (ft_oper_specular(color, '*', comps->object->material.reflective));
}
/**
 * @brief Calculates the refracted color.
 * 
 * @param world 
 * @param comps 
 * @param remaining 
 * @return t_color 
 */
t_color	ft_refracted_color_bonus(t_world *world, t_comps *comps, int remaining)
{
	double	n_ratio;
	t_vec3	dir;
	t_ray	refract_ray;
	t_color	color;

	if (remaining <= 0)
		return (ft_color(0, 0, 0));
	if (comps->object->material.transparency == 0)
		return (ft_color(0, 0, 0));
	n_ratio = comps->n1 / comps->n2;
	dir = ft_refract_dir(comps, n_ratio);
	if (ft_length(dir) == 0)
		return (ft_color(0, 0, 0));
	refract_ray = ft_create_ray(comps->under_point, dir);
	color = ft_oper_specular(ft_color_at_bonus(world, refract_ray, remaining
				- 1), '*', comps->object->material.transparency);
	return (color);
}
