/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:56:35 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/11 19:21:25 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules.h"

// Create a material with default values.
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
