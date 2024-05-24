/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:36:47 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/20 11:40:17 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "minirt.h"

/**********LIGHTS**********/
t_light		*ft_create_point_light(t_point position, t_color intensity,
				double ratio);
void		ft_lighting_specular(t_lighting *lighting, t_material m, t_comps *c,
				t_light *light);
t_color		ft_lighting(t_material material, t_comps *c, t_light *light,
				bool in_shadow);
t_vec3		ft_normal_at(t_shapes *s, t_point world_point);
t_vec3		ft_reflect(t_vec3 in, t_vec3 normal);

/**********LIGHTS*BONUS**********/
t_vec3		ft_normal_at_bonus(t_shapes *s, t_point world_point);

/**********SHADOWS**********/
bool		ft_is_shadowed(t_world *w, t_light *light, t_point point);
t_color		ft_shadow_color(bool in_shadow, t_lighting *lighting);
int			ft_chk_file(char *file);

/**********SHADOWS*BONUS**********/
bool		ft_is_shadowed_b(t_world *w, t_light *light, t_point point);

#endif