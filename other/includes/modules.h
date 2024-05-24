/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modules.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:46:25 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/19 19:30:24 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULES_H
# define MODULES_H

# include "minirt.h"

/**********CAMERA**********/
t_camera		*ft_create_camera(int hsize, int vsize, double fov);
void			ft_set_camera_transform(t_camera *camera, t_matrix transform);
t_ray			ft_ray_for_pixel(t_camera *c, int x, int y);
t_canvas		ft_render(t_camera *c, t_world *w);

/**********CAMERA*BONUS**********/
t_canvas		ft_render_bonus(t_camera *c, t_world *w);

/**********INTERSECTIONS**********/
void			ft_intersect(t_intersections **i, t_shapes *s, t_ray r);
t_intersection	*ft_create_intersection(double t, t_shapes *s);
void			ft_add_sorted_intersection(t_intersections **lst, t_shapes *s,
					double t);
t_intersection	*ft_hit(t_intersections *i);

/**********INTERSECTIONS*BONUS**********/
void			ft_intersect_bonus(t_intersections **i, t_shapes *s, t_ray r);

/**********MATERIALS**********/
t_material		ft_create_material(void);

/**********PATTERNS*UTILS**********/
t_color			ft_ring_at(t_pattern pattern, int shape_type, t_point point);
t_color			ft_checkers_at(t_pattern pattern, t_point point);
int				ft_secure_open(char *file, t_scene *scene, int *fd);

/**********PATTERNS**********/

t_pattern		ft_create_pattern(int pattern_type, t_color a, t_color b);
void			ft_set_pattern_transform(t_pattern *pattern,
					t_matrix transform);
t_color			ft_pattern_at_shape(t_pattern pattern, t_shapes *object,
					t_point world_point);
t_color			ft_stripe_at(t_pattern pattern, t_point point);
t_color			ft_gradient_at(t_pattern pattern, t_point point);

/**********REFLECTIONS**********/
t_color			ft_reflected_color(t_world *world, t_comps *comps,
					int remaining);
t_shapes		*ft_create_glass_sphere(void);
t_vec3			ft_refract_dir(t_comps *comps, double n_ratio);
t_color			ft_refracted_color(t_world *world, t_comps *comps,
					int remaining);
double			ft_schlick(t_comps *comps);
/**********REFLECTIONS*BONUS**********/
t_color			ft_reflected_color_bonus(t_world *world, t_comps *comps,
					int remaining);
t_color			ft_refracted_color_bonus(t_world *world, t_comps *comps,
					int remaining);

/**********TEXTURES**********/
void			ft_load_xpm_to_matrix(t_canvas *scene, char *xpm_file,
					t_scene *err);
t_canvas		ft_read_xpm(char *xpm_file, t_scene *err);
t_pattern		ft_create_xpm_pattern(int pattern_type, char *xpm_txt,
					t_scene *err);
t_color			ft_xpm_at(t_pattern pattern, t_point point);
t_color			ft_xpm_at_plane(t_pattern pattern, t_point point);
t_color			ft_xpm_at_sphere(t_pattern pattern, t_point point);

#endif