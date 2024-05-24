/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:04:24 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/19 19:39:18 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules.h"

void	ft_import_xpm(t_canvas **scene, t_image img_ptr)
{
	int	x;
	int	y;
	int	*color;

	color = (int *)mlx_get_data_addr(img_ptr.img, &img_ptr.bpp,
			&img_ptr.line_length, &img_ptr.endian);
	y = -1;
	ft_putstr_fd("Importing texture\n", 1);
	while (++y < (*scene)->height)
	{
		x = -1;
		while (++x < (*scene)->width)
			(*scene)->pixels[y][x] = ft_int_to_rgb(color[y * (*scene)->width
					+ x]);
	}
}

void	ft_load_xpm_to_matrix(t_canvas *scene, char *xpm_file, t_scene *err)
{
	t_image	img_ptr;
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	img_ptr.img = mlx_xpm_file_to_image(mlx_ptr, xpm_file, &scene->width,
			&scene->height);
	if (!img_ptr.img)
	{
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
		ft_msg_error(err, "Error reading xpm file");
		return ;
	}
	ft_import_xpm(&scene, img_ptr);
	mlx_destroy_image(mlx_ptr, img_ptr.img);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}

t_canvas	ft_read_xpm(char *xpm_file, t_scene *xpm_text)
{
	int			fd;
	char		*line;
	t_canvas	texture;

	ft_bzero(&texture, sizeof(t_canvas));
	if (ft_secure_open(xpm_file, xpm_text, &fd) == -1)
		return (texture);
	line = get_next_line(fd, NO);
	while (line)
	{
		if (line && line[0] == '"')
		{
			texture = ft_create_aperture(ft_atoi(line + 1),
					ft_atoi(ft_strchr(line, ' ')));
			break ;
		}
		free(line);
		line = get_next_line(fd, NO);
	}
	ft_load_xpm_to_matrix(&texture, xpm_file, xpm_text);
	free(line);
	get_next_line(fd, YES);
	close(fd);
	return (texture);
}

t_color	ft_xpm_at_plane(t_pattern pattern, t_point point)
{
	double	u;
	double	v;
	int		x;
	int		y;

	u = point.x / (pattern.xpm.width / 50) + 0.5;
	v = 0.5 - point.z / (pattern.xpm.height / 50);
	x = abs((int)(u * (pattern.xpm.width - 1) + 0.5));
	y = abs((int)(v * (pattern.xpm.height - 1) + 0.5));
	x = x % pattern.xpm.width;
	y = y % pattern.xpm.height;
	return (pattern.xpm.pixels[y][x]);
}

t_color	ft_xpm_at_sphere(t_pattern pattern, t_point point)
{
	double	u;
	double	v;
	int		x;
	int		y;

	u = atan2(point.x, point.z);
	v = acos(point.y);
	u = 1.0 - (u / (2.0 * M_PI) + 0.5);
	v = v / M_PI;
	x = (int)(u * (pattern.xpm.width - 1) + 0.5);
	y = (int)(v * (pattern.xpm.height - 1) + 0.5);
	x = x % pattern.xpm.width;
	y = y % pattern.xpm.height;
	if (x < 0)
		x += pattern.xpm.width;
	if (y < 0)
		y += pattern.xpm.height;
	return (pattern.xpm.pixels[y][x]);
}
