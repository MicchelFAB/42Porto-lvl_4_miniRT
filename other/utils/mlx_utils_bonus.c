/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:05:10 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/19 12:20:22 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "minirt_bonus.h"

int	ft_update(void *wrd)
{
	t_world	*w;

	w = (t_world *)wrd;
	if (w->key.status_key)
	{
		mlx_destroy_image(w->mlx, w->img.img);
		w->img.img = mlx_new_image(w->mlx, w->canvas.width, w->canvas.height);
		w->img.addr = mlx_get_data_addr(w->img.img, &w->img.bpp,
				&w->img.line_length, &w->img.endian);
		ft_set_camera_transform(w->camera, ft_handdle_keys(w));
		ft_free_canvas(w->canvas);
		w->canvas = ft_create_aperture(w->camera->hsize, w->camera->vsize);
		ft_start_thread(w);
		mlx_put_image_to_window(w->mlx, w->win, w->img.img, 0, 0);
		usleep(10000);
	}
	return (0);
}

void	ft_set_hooks_bonus(t_world *prog)
{
	mlx_do_key_autorepeatoff(prog->mlx);
	mlx_hook(prog->win, KeyPress, KeyPressMask, ft_button_press, prog);
	mlx_hook(prog->win, KeyRelease, KeyReleaseMask, ft_button_release, prog);
	mlx_hook(prog->win, DestroyNotify, ButtonPressMask, ft_close, prog);
	mlx_loop_hook(prog->mlx, ft_update, prog);
}

void	ft_open_window_bonus(t_world *prog)
{
	int	height;

	height = WIDTH_B / RATIO;
	prog->mlx = mlx_init();
	prog->win = mlx_new_window(prog->mlx, WIDTH_B, height, "MiniRT");
	if (!prog->win || !prog->mlx)
		ft_error("Failed to start program. MLX", NULL);
	prog->img.img = mlx_new_image(prog->mlx, WIDTH_B, height);
	if (!prog->img.img)
		ft_error("Failed to create image.", NULL);
	prog->img.addr = mlx_get_data_addr(prog->img.img, &prog->img.bpp,
			&prog->img.line_length, &prog->img.endian);
}
