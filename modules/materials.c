/**
 * @file materials.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the material functions.
 * @version 0.1
 * @date 2024-05-22 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "modules.h"
/**
 * @brief Creates a material.
 * @return t_material The created material.
 */
t_material	ft_create_material(void)
{
	t_material	material;

	material.color = ft_color(0.7, 0.7, 0.7);
	material.ambient = ft_color(0.1, 0.1, 0.1);
	material.diffuse = 0.9;
	material.specular = 0.9;
	material.shininess = 200;
	material.reflective = 0;
	material.transparency = 0;
	material.refractive_index = 1;
	material.pattern = ft_create_pattern(NONE, ft_color(1, 1, 1),
			ft_color(0, 0, 0));
	return (material);
}
