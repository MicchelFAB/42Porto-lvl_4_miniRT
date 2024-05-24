/**
 * @file textures.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the texture functions.
 * @version 0.1
 * @date 2024-05-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "modules.h"
/**
 * @brief Function to load the xpm file to the matrix.
 * 
 * @param scene 
 * @param xpm_file 
 * @param err 
 */
void	ft_load_xpm_to_matrix(t_canvas *scene, char *xpm_file, t_scene *err)
{
	int	x;
	int	y;
	int	*color;
	t_image	img_ptr;
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	img_ptr.img = mlx_xpm_file_to_image(mlx_ptr, xpm_file, &scene->width,
			&scene->height);
	color = (int *)mlx_get_data_addr(img_ptr.img, &img_ptr.bpp,
			&img_ptr.line_length, &img_ptr.endian);
	if (!img_ptr.img)
	{
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
		ft_msg_error(err, "Error reading xpm file");
		return ;
	}
	y = -1;
	ft_putstr_fd("Importing texture\n", 1);
	while (++y < scene->height)
	{
		x = -1;
		while (++x < scene->width)
			scene->pixels[y][x] = ft_int_to_rgb(color[y * scene->width
					+ x]);
	}
	mlx_destroy_image(mlx_ptr, img_ptr.img);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
/**
 * @brief Function to read the xpm file.
 * 
 * @param xpm_file 
 * @param xpm_text 
 * @return t_canvas 
 */
t_canvas	ft_read_xpm(char *xpm_file, t_scene *xpm_text)
{
	int			fd;
	char		*line;
	t_canvas	texture;

	ft_bzero(&texture, sizeof(t_canvas));
	fd = open(xpm_file, O_RDONLY);
	if (fd < 0)
	{	
		ft_msg_error(xpm_text, "Error open xpm file");
		return (texture);
	}
	line = get_next_line(fd, NO);
	while (line)
	{
		if (line && line[0] == '"')
		{
			texture = ft_create_aperture(ft_atoi(line + 1),	ft_atoi(ft_strchr(line, ' ')));
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
/**
 * @brief Function to write the xpm pattern on an plane object.
 * 
 * @param pattern 
 * @param point 
 * @return t_color 
 */
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
/**
 * @brief Function to create a xpm pattern to a sphere.
 * 
 * @param pattern 
 * @param point 
 * @return t_color 
 */
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
