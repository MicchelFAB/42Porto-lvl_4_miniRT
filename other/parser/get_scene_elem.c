/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:54:30 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/20 10:03:49 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	get_1_amb(t_scene *scene)
{
	scene->ambient.ratio = ft_get_ratio(scene->split[1], A_RATIO, scene);
	scene->ambient.color = ft_get_colour(scene->split[2], A_RGB, scene);
	scene->ambient.color = ft_color(ft_normalize_color(scene->ambient.color.x),
			ft_normalize_color(scene->ambient.color.y),
			ft_normalize_color(scene->ambient.color.z));
}

void	get_2_cam(t_scene *scene)
{
	double	fov;

	fov = ft_get_fov(scene->split[3], C_FOV, scene);
	scene->camera = ft_create_camera(WIDTH, WIDTH / RATIO, fov);
	scene->camera->point = ft_get_coord(scene->split[1], C_COORD, scene);
	if (scene->camera->point.x == scene->camera->point.y
		&& scene->camera->point.y == scene->camera->point.z)
		ft_msg_error(scene,
			"Camera point X, Y and Z cannot be equal at LEAST one of them must\
be different\n");
	scene->camera->normalized = (ft_get_normal(scene->split[2], C_NORM, scene));
	scene->camera->point = ft_point(scene->camera->point.x,
			scene->camera->point.y, scene->camera->point.z);
	scene->camera->normalized = ft_vector(scene->camera->normalized.x,
			scene->camera->normalized.y, scene->camera->normalized.z);
}

static t_vec3	set_camera(t_camera *camera)
{
	t_vec3		up;
	t_vec3		aux;
	t_matrix	tilt_transform;

	if (ft_double_compare(1, fabs(camera->normalized.y)))
		up = ft_vector(1, 0, 0);
	else
	{
		aux = ft_cross((t_vec3){0, 1, 0, 0}, camera->normalized);
		up = ft_cross(camera->normalized, aux);
		if (up.x == 0 && up.y == 0 && up.z == 0)
			up = ft_vector(0, 0.0000001, 0);
	}
	if (camera->normalized.z)
	{
		tilt_transform = ft_create_rotation_matrix('z',
				camera->normalized.z * M_PI);
		up = ft_multiply_matrix_tuple(tilt_transform, up);
	}
	return (up);
}

t_camera	*ft_setup_camera(t_scene *scene)
{
	t_matrix	transformation;
	t_vec3		up;
	t_matrix	rotation;
	t_point		direction;

	up = set_camera(scene->camera);
	direction = ft_negate(scene->camera->point);
	rotation = ft_cam_rotation(scene->camera);
	direction = ft_multiply_matrix_tuple(rotation, direction);
	direction = ft_operations(scene->camera->point, '+', direction);
	transformation = ft_view_transform_matrix(scene->camera->point, direction,
			up);
	ft_set_camera_transform(scene->camera, transformation);
	return (scene->camera);
}

void	get_3_light(t_scene *scene)
{
	scene->lights = malloc(sizeof(t_light));
	if (!scene->lights)
		ft_error("System error\n", NULL);
	scene->lights->position = (t_point)(ft_get_coord(scene->split[1], L_COORD,
				scene));
	scene->lights->position = ft_point(scene->lights->position.x,
			scene->lights->position.y, scene->lights->position.z);
	scene->lights->brightness = ft_get_ratio(scene->split[2], L_RATIO, scene);
	if (ft_strlen_2(scene->split) == 4)
	{
		scene->lights->intensity = ft_get_colour(scene->split[3], L_RGB, scene);
		scene->lights->intensity = ft_color(
				ft_normalize_color(scene->lights->intensity.x),
				ft_normalize_color(scene->lights->intensity.y),
				ft_normalize_color(scene->lights->intensity.z));
	}
	else
		scene->lights->intensity = ft_color(1, 1, 1);
	scene->lights->intensity = ft_oper_specular(scene->lights->intensity,
			'*', scene->lights->brightness);
}
