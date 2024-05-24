/**
 * @file mlx_utils.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File with the complementary functions to handle the mlx events.
 * @version 0.1
 * @date 2024-05-24 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "utils.h"
/**
 * @brief Function to map a pixel to the image.
 * @param data 
 * @param x 
 * @param y 
 * @param color 
 */
void	ft_mlx_pixel_put(t_image *data, int x, int y, t_color color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = ft_rgb_to_int(color);
}
/**
 * @brief Function to create a new image.
 * @param data 
 * @param x 
 * @param y 
 * @param color 
 */
void	ft_panel_window(t_image *data, int x, int y, t_color **color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
		{
			ft_mlx_pixel_put(data, j, i, color[i][j]);
		}
	}
}
/**
 * @brief FUnciton to render the panel.
 * @param d 
 * @param up_lft 
 * @param dw_rht 
 * @param c 
 */
void	ft_panel_render(t_image *d, t_point up_lft, t_point dw_rht, t_color **c)
{
	int	x;
	int	y;

	x = up_lft.x - 1;
	while (++x < dw_rht.x + up_lft.x)
	{
		y = up_lft.y - 1;
		while (++y < dw_rht.y + up_lft.y)
		{
			ft_mlx_pixel_put(d, x, y, c[y][x]);
		}
	}
}
/**
 * @brief Function to open the window.
 * @param prog 
 */
void	ft_open_window(t_world *prog)
{
	int	height;

	height = WIDTH / RATIO;
	prog->mlx = mlx_init();
	prog->win = mlx_new_window(prog->mlx, WIDTH, height, "MiniRT");
	if (!prog->win || !prog->mlx)
		ft_error("Failed to start program. MLX", NULL);
	prog->img.img = mlx_new_image(prog->mlx, WIDTH, height);
	if (!prog->img.img)
		ft_error("Failed to create image.", NULL);
	prog->img.addr = mlx_get_data_addr(prog->img.img, &prog->img.bpp,
			&prog->img.line_length, &prog->img.endian);
}
/**
 * @brief Function to handdle the error events.
 * @param msg 
 * @param scene 
 */
void	ft_error(char *msg, t_scene *scene)
{
	(void)scene;
	ft_free_all_scene(scene);
	ft_putstr_fd("\033[1m\033[38;5;199mError\033[0m\n", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(EXIT_FAILURE);
}
