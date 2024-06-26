/**
 * @file camera.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the camera functions.
 * @version 0.1
 * @date 2024-05-22 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "modules.h"

/**
 * @brief Creates a camera.
 * @param hsize The horizontal size.
 * @param vsize The vertical size.
 * @param fov The field of view.
 * @return t_camera The created camera.
 */
t_camera	*ft_create_camera(int hsize, int vsize, double fov)
{
	double		aspect;
	double		half_view;
	t_camera	*camera;

	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->hsize = hsize;
	camera->vsize = vsize;
	camera->fov = fov;
	camera->transform = ft_create_matrix(4, 4, YES);
	camera->inverted = ft_create_matrix(4, 4, YES);
	half_view = tan(fov / 2);
	aspect = (double)hsize / (double)vsize;
	if (aspect >= 1)
	{
		camera->half_width = half_view;
		camera->half_height = half_view / aspect;
	}
	else
	{
		camera->half_width = half_view * aspect;
		camera->half_height = half_view;
	}
	camera->pixel_size = (camera->half_width * 2) / hsize;
	return (camera);
}
/**
 * @brief Sets the camera transform.
 * @param camera The camera.
 * @param transform The transform.
 */
void	ft_set_camera_transform(t_camera *camera, t_matrix transform)
{
	camera->transform = transform;
	camera->inverted = ft_create_invert_matrix(transform);
}
/**
 * @brief Function that calculates the ray for a pixel.
 * @param c 
 * @param x 
 * @param y 
 * @return t_ray 
 */
t_ray	ft_ray_for_pixel(t_camera *c, int x, int y)
{
	t_vec3	global;
	t_point	pixel;
	t_point	origin;
	t_vec3	direction;

	global.x = (x + 0.5) * c->pixel_size;
	global.y = (y + 0.5) * c->pixel_size;
	global.z = c->half_width - global.x;
	global.w = c->half_height - global.y;
	pixel = ft_multiply_matrix_tuple(c->inverted, ft_point(global.z, global.w, -1));
	origin = ft_multiply_matrix_tuple(c->inverted, ft_point(0, 0, 0));
	direction = ft_normalize(ft_operations(pixel, '-', origin));
	return ((t_ray){origin, direction});
}
/**
 * @brief Function that renders the image.
 * @param c The camera.
 * @param w The world.
 * @return t_canvas The rendered image.
 */
t_canvas	ft_render(t_camera *c, t_world *w)
{
	int			x;
	int			y;
	t_canvas	image;
	t_ray		r;
	t_color		color;

	y = 0;
	image = ft_create_aperture(c->hsize, c->vsize);
	while (y < c->vsize)
	{
		x = 0;
		while (x < c->hsize)
		{
			r = ft_ray_for_pixel(c, x, y);
			color = ft_color_at(w, r, 5);
			ft_write_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
	return (image);
}
