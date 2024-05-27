/**
 * @file core.h
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief Include all the headers of the core module.
 * @version 0.1
 * @date 2024-05-22 * 
 *  * @note This file is part of the MiniRT project.
 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */

#ifndef CORE_H
# define CORE_H

# include "minirt.h"


t_canvas	ft_create_aperture(int width, int height);
void		ft_free_canvas(t_canvas canvas);
void		ft_write_pixel(t_canvas canvas, int x, int y, t_color color);
t_vec3		ft_pixel_at(t_canvas canvas, int x, int y);
int			ft_clamp(int value);

void		ft_calculate_refracted_indices(t_comps *comps, t_intersections **xs, t_intersection *hit);
t_comps		*ft_prepare_computations(t_intersections **lst, t_intersection *hit, t_ray r);
t_color		ft_surface(t_world *world, t_comps *comps);
t_color		ft_shade_hit(t_world *world, t_comps *comps, int remaining);

bool		ft_lst_contains(t_list *lst, t_shapes *shape);
void		ft_lst_remove(t_list **lst, t_shapes *shape);
double		ft_check_containers(t_list *containers);

t_comps		*ft_prepare_computations_bonus(t_intersections **lst, t_intersection *hit, t_ray r);
t_color		ft_surface_bonus(t_world *world, t_comps *comps);
t_color		ft_shade_hit_bonus(t_world *world, t_comps *comps, int remaining);

t_ray		ft_create_ray(t_point origin, t_vec3 direction);
t_point		ft_ray_position(t_ray ray, double t);
t_ray		ft_transform_ray(t_ray ray, t_matrix matrix);
t_color		ft_color_at(t_world *world, t_ray r, int remaining);

t_color		ft_color_at_bonus(t_world *world, t_ray r, int remaining);

t_world		*ft_create_world(void);
void		ft_free_world(t_world *world);
void		ft_world_intersections(t_intersections **i, t_world *world,	t_ray ray);

void		ft_world_intersections_b(t_intersections **i, t_world *world, t_ray ray);

#endif